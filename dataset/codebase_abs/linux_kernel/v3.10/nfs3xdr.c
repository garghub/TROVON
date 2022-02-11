static void F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
unsigned int V_12 ;
V_12 = V_13 + V_9 -> V_14 + V_7 ;
F_2 ( & V_2 -> V_15 , V_12 << 2 , V_4 , V_5 , V_6 ) ;
}
static void F_3 ( const char * V_16 , const struct V_17 * V_18 )
{
F_4 ( L_1
L_2 ,
V_16 , V_18 -> V_19 - V_18 -> V_20 ) ;
}
static void F_5 ( struct V_17 * V_18 , T_1 V_21 )
{
T_2 * V_20 = F_6 ( V_18 , 4 ) ;
* V_20 = F_7 ( V_21 ) ;
}
static int F_8 ( struct V_17 * V_18 , T_1 * V_21 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
* V_21 = F_11 ( V_20 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_12 ( struct V_17 * V_18 , T_3 * V_21 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 8 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
F_13 ( V_20 , V_21 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static T_2 * F_14 ( T_2 * V_20 , T_3 * V_25 )
{
return F_13 ( V_20 , V_25 ) ;
}
static int F_15 ( struct V_17 * V_18 , T_3 * V_25 )
{
return F_12 ( V_18 , V_25 ) ;
}
static void F_16 ( struct V_17 * V_18 ,
const char * V_26 , T_1 V_27 )
{
T_2 * V_20 ;
F_17 ( V_27 > V_28 ) ;
V_20 = F_6 ( V_18 , 4 + V_27 ) ;
F_18 ( V_20 , V_26 , V_27 ) ;
}
static int F_19 ( struct V_17 * V_18 ,
const char * * V_26 , T_1 * V_27 )
{
T_2 * V_20 ;
T_1 V_29 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ) ;
if ( V_29 > V_28 )
goto V_30;
V_20 = F_9 ( V_18 , V_29 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
* V_26 = ( const char * ) V_20 ;
* V_27 = V_29 ;
return 0 ;
V_30:
F_4 ( L_3 , V_29 ) ;
return - V_31 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_20 ( struct V_17 * V_18 , struct V_3 * * V_4 ,
const T_1 V_27 )
{
F_5 ( V_18 , V_27 ) ;
F_21 ( V_18 , V_4 , 0 , V_27 ) ;
}
static int F_22 ( struct V_17 * V_18 )
{
T_1 V_32 , V_29 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ) ;
if ( F_10 ( V_29 >= V_18 -> V_33 -> V_34 || V_29 > V_35 ) )
goto V_30;
V_32 = F_23 ( V_18 , V_29 ) ;
if ( F_10 ( V_29 > V_32 ) )
goto V_36;
F_24 ( V_18 -> V_33 , V_29 ) ;
return 0 ;
V_30:
F_4 ( L_4 , V_29 ) ;
return - V_31 ;
V_36:
F_4 ( L_5
L_6 , V_29 , V_32 ) ;
return - V_24 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static T_2 * F_25 ( T_2 * V_20 , T_3 V_37 )
{
return F_26 ( V_20 , V_37 ) ;
}
static int F_27 ( struct V_17 * V_18 , T_3 * V_37 )
{
return F_12 ( V_18 , V_37 ) ;
}
static T_2 * F_28 ( T_2 * V_20 , const T_2 * V_38 )
{
memcpy ( V_20 , V_38 , V_39 ) ;
return V_20 + F_29 ( V_39 ) ;
}
static int F_30 ( struct V_17 * V_18 , T_2 * V_38 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_39 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
memcpy ( V_38 , V_20 , V_39 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_31 ( struct V_17 * V_18 , const T_2 * V_38 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , V_40 ) ;
memcpy ( V_20 , V_38 , V_40 ) ;
}
static int F_32 ( struct V_17 * V_18 , struct V_41 * V_38 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_42 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
memcpy ( V_38 -> V_43 , V_20 , V_42 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static T_2 * F_33 ( T_2 * V_20 , T_3 * V_44 )
{
return F_13 ( V_20 , V_44 ) ;
}
static int F_34 ( struct V_17 * V_18 , enum V_45 * V_46 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
* V_46 = F_11 ( V_20 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_35 ( struct V_17 * V_18 , const T_1 type )
{
F_5 ( V_18 , type ) ;
}
static T_2 * F_36 ( T_2 * V_20 , T_4 * V_47 )
{
T_1 type ;
type = F_11 ( V_20 ++ ) ;
if ( type > V_48 )
type = V_49 ;
* V_47 = V_50 [ type ] ;
return V_20 ;
}
static void F_37 ( struct V_17 * V_18 , const T_5 V_51 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , 8 ) ;
* V_20 ++ = F_7 ( F_38 ( V_51 ) ) ;
* V_20 = F_7 ( F_39 ( V_51 ) ) ;
}
static T_2 * F_40 ( T_2 * V_20 , T_5 * V_51 )
{
unsigned int V_52 , V_53 ;
V_52 = F_11 ( V_20 ++ ) ;
V_53 = F_11 ( V_20 ++ ) ;
* V_51 = F_41 ( V_52 , V_53 ) ;
if ( F_38 ( * V_51 ) != V_52 || F_39 ( * V_51 ) != V_53 )
* V_51 = 0 ;
return V_20 ;
}
static void F_42 ( struct V_17 * V_18 , const struct V_54 * V_55 )
{
T_2 * V_20 ;
F_17 ( V_55 -> V_44 > V_56 ) ;
V_20 = F_6 ( V_18 , 4 + V_55 -> V_44 ) ;
F_18 ( V_20 , V_55 -> V_43 , V_55 -> V_44 ) ;
}
static int F_43 ( struct V_17 * V_18 , struct V_54 * V_55 )
{
T_1 V_27 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_27 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_27 > V_56 ) )
goto V_57;
V_20 = F_9 ( V_18 , V_27 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_55 -> V_44 = V_27 ;
memcpy ( V_55 -> V_43 , V_20 , V_27 ) ;
return 0 ;
V_57:
F_4 ( L_7 , V_27 ) ;
return - V_58 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_44 ( struct V_54 * V_55 )
{
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
}
static T_2 * F_45 ( T_2 * V_20 , const struct V_59 * V_60 )
{
* V_20 ++ = F_7 ( V_60 -> V_61 ) ;
* V_20 ++ = F_7 ( V_60 -> V_62 ) ;
return V_20 ;
}
static T_2 * F_46 ( T_2 * V_20 , struct V_59 * V_60 )
{
V_60 -> V_61 = F_11 ( V_20 ++ ) ;
V_60 -> V_62 = F_11 ( V_20 ++ ) ;
return V_20 ;
}
static void F_47 ( struct V_17 * V_18 , const struct V_63 * V_64 )
{
T_1 V_65 ;
T_2 * V_20 ;
V_65 = 6 * 4 ;
if ( V_64 -> V_66 & V_67 )
V_65 += 4 ;
if ( V_64 -> V_66 & V_68 )
V_65 += 4 ;
if ( V_64 -> V_66 & V_69 )
V_65 += 4 ;
if ( V_64 -> V_66 & V_70 )
V_65 += 8 ;
if ( V_64 -> V_66 & V_71 )
V_65 += 8 ;
if ( V_64 -> V_66 & V_72 )
V_65 += 8 ;
V_20 = F_6 ( V_18 , V_65 ) ;
if ( V_64 -> V_66 & V_67 ) {
* V_20 ++ = V_73 ;
* V_20 ++ = F_7 ( V_64 -> V_74 & V_75 ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_68 ) {
* V_20 ++ = V_73 ;
* V_20 ++ = F_7 ( F_48 ( & V_77 , V_64 -> V_78 ) ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_69 ) {
* V_20 ++ = V_73 ;
* V_20 ++ = F_7 ( F_49 ( & V_77 , V_64 -> V_79 ) ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_70 ) {
* V_20 ++ = V_73 ;
V_20 = F_26 ( V_20 , ( T_3 ) V_64 -> V_80 ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_71 ) {
* V_20 ++ = V_81 ;
V_20 = F_45 ( V_20 , & V_64 -> V_82 ) ;
} else if ( V_64 -> V_66 & V_83 ) {
* V_20 ++ = V_73 ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_72 ) {
* V_20 ++ = V_81 ;
F_45 ( V_20 , & V_64 -> V_84 ) ;
} else if ( V_64 -> V_66 & V_85 ) {
* V_20 = V_73 ;
} else
* V_20 = V_76 ;
}
static int F_50 ( struct V_17 * V_18 , struct V_86 * V_87 )
{
T_4 V_88 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_89 << 2 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_20 = F_36 ( V_20 , & V_88 ) ;
V_87 -> V_47 = ( F_11 ( V_20 ++ ) & ~ V_90 ) | V_88 ;
V_87 -> V_91 = F_11 ( V_20 ++ ) ;
V_87 -> V_92 = F_51 ( & V_77 , F_11 ( V_20 ++ ) ) ;
if ( ! F_52 ( V_87 -> V_92 ) )
goto V_93;
V_87 -> V_94 = F_53 ( & V_77 , F_11 ( V_20 ++ ) ) ;
if ( ! F_54 ( V_87 -> V_94 ) )
goto V_95;
V_20 = F_33 ( V_20 , & V_87 -> V_44 ) ;
V_20 = F_33 ( V_20 , & V_87 -> V_96 . V_97 . V_98 ) ;
V_20 = F_40 ( V_20 , & V_87 -> V_51 ) ;
V_20 = F_13 ( V_20 , & V_87 -> V_99 . V_52 ) ;
V_87 -> V_99 . V_53 = 0 ;
V_20 = F_14 ( V_20 , & V_87 -> V_25 ) ;
V_20 = F_46 ( V_20 , & V_87 -> V_100 ) ;
V_20 = F_46 ( V_20 , & V_87 -> V_101 ) ;
F_46 ( V_20 , & V_87 -> ctime ) ;
V_87 -> V_102 = F_55 ( & V_87 -> ctime ) ;
V_87 -> V_103 |= V_104 ;
return 0 ;
V_93:
F_4 ( L_8 ) ;
return - V_105 ;
V_95:
F_4 ( L_9 ) ;
return - V_105 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_56 ( struct V_17 * V_18 , struct V_86 * V_87 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 )
return F_50 ( V_18 , V_87 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_57 ( struct V_17 * V_18 , struct V_86 * V_87 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_106 << 2 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_87 -> V_103 |= V_107
| V_108
| V_109
| V_110 ;
V_20 = F_33 ( V_20 , & V_87 -> V_111 ) ;
V_20 = F_46 ( V_20 , & V_87 -> V_112 ) ;
F_46 ( V_20 , & V_87 -> V_113 ) ;
V_87 -> V_114 = F_55 ( & V_87 -> V_113 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_58 ( struct V_17 * V_18 , struct V_86 * V_87 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 )
return F_57 ( V_18 , V_87 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_59 ( struct V_17 * V_18 , struct V_86 * V_87 )
{
int error ;
error = F_58 ( V_18 , V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_87 ) ;
V_115:
return error ;
}
static int F_60 ( struct V_17 * V_18 , struct V_54 * V_55 )
{
T_2 * V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 )
return F_43 ( V_18 , V_55 ) ;
F_44 ( V_55 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_61 ( struct V_17 * V_18 , const struct V_54 * V_55 ,
const char * V_26 , T_1 V_27 )
{
F_42 ( V_18 , V_55 ) ;
F_16 ( V_18 , V_26 , V_27 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_54 * V_55 )
{
F_42 ( V_18 , V_55 ) ;
}
static void F_63 ( struct V_17 * V_18 ,
const struct V_116 * args )
{
T_2 * V_20 ;
if ( args -> V_117 ) {
V_20 = F_6 ( V_18 , 4 + 8 ) ;
* V_20 ++ = V_73 ;
F_45 ( V_20 , & args -> V_118 ) ;
} else {
V_20 = F_6 ( V_18 , 4 ) ;
* V_20 = V_76 ;
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_116 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_47 ( V_18 , args -> V_119 ) ;
F_63 ( V_18 , args ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_120 * args )
{
F_61 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
}
static void F_66 ( struct V_17 * V_18 ,
const struct V_121 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_5 ( V_18 , args -> V_122 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_121 * args )
{
F_66 ( V_18 , args ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_123 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_1 ( V_2 , args -> V_4 , args -> V_124 ,
args -> V_125 , V_126 ) ;
}
static void F_69 ( struct V_17 * V_18 ,
const struct V_127 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_128 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_127 * args )
{
F_69 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , args -> V_124 ,
args -> V_29 , V_129 ) ;
V_2 -> V_15 . V_130 |= V_131 ;
}
static void F_71 ( struct V_17 * V_18 ,
const struct V_132 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + 4 + 4 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_128 ) ;
* V_20 ++ = F_7 ( args -> V_29 ) ;
* V_20 ++ = F_7 ( args -> V_133 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
F_21 ( V_18 , args -> V_4 , args -> V_124 , args -> V_29 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_132 * args )
{
F_71 ( V_18 , args ) ;
V_18 -> V_33 -> V_130 |= V_134 ;
}
static void F_73 ( struct V_17 * V_18 ,
const struct V_135 * args )
{
F_5 ( V_18 , args -> V_136 ) ;
switch ( args -> V_136 ) {
case V_137 :
case V_138 :
F_47 ( V_18 , args -> V_119 ) ;
break;
case V_139 :
F_31 ( V_18 , args -> V_38 ) ;
break;
default:
F_74 () ;
}
}
static void F_75 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_135 * args )
{
F_61 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
F_73 ( V_18 , args ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_140 * args )
{
F_61 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
F_47 ( V_18 , args -> V_119 ) ;
}
static void F_77 ( struct V_17 * V_18 ,
const struct V_141 * args )
{
F_47 ( V_18 , args -> V_119 ) ;
F_20 ( V_18 , args -> V_4 , args -> V_142 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_141 * args )
{
F_61 ( V_18 , args -> V_143 , args -> V_144 , args -> V_145 ) ;
F_77 ( V_18 , args ) ;
}
static void F_79 ( struct V_17 * V_18 ,
const struct V_146 * args )
{
F_47 ( V_18 , args -> V_119 ) ;
F_37 ( V_18 , args -> V_51 ) ;
}
static void F_80 ( struct V_17 * V_18 ,
const struct V_146 * args )
{
F_35 ( V_18 , args -> type ) ;
switch ( args -> type ) {
case V_147 :
case V_148 :
F_79 ( V_18 , args ) ;
break;
case V_149 :
case V_48 :
F_47 ( V_18 , args -> V_119 ) ;
break;
case V_150 :
case V_151 :
break;
default:
F_74 () ;
}
}
static void F_81 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_146 * args )
{
F_61 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
F_80 ( V_18 , args ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_152 * args )
{
F_61 ( V_18 , args -> V_55 , args -> V_26 . V_26 , args -> V_26 . V_6 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_153 * args )
{
const struct V_154 * V_155 = args -> V_156 ;
const struct V_154 * V_157 = args -> V_158 ;
F_61 ( V_18 , args -> V_159 , V_155 -> V_26 , V_155 -> V_6 ) ;
F_61 ( V_18 , args -> V_160 , V_157 -> V_26 , V_157 -> V_6 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_161 * args )
{
F_42 ( V_18 , args -> V_143 ) ;
F_61 ( V_18 , args -> V_162 , args -> V_163 , args -> V_164 ) ;
}
static void F_85 ( struct V_17 * V_18 ,
const struct V_165 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + V_39 + 4 ) ;
V_20 = F_25 ( V_20 , args -> V_37 ) ;
V_20 = F_28 ( V_20 , args -> V_166 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_165 * args )
{
F_85 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_29 , V_167 ) ;
}
static void F_87 ( struct V_17 * V_18 ,
const struct V_165 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + V_39 + 4 + 4 ) ;
V_20 = F_25 ( V_20 , args -> V_37 ) ;
V_20 = F_28 ( V_20 , args -> V_166 ) ;
* V_20 ++ = F_7 ( args -> V_29 >> 3 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_165 * args )
{
F_87 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_29 , V_167 ) ;
}
static void F_89 ( struct V_17 * V_18 ,
const struct V_168 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_128 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_168 * args )
{
F_89 ( V_18 , args ) ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_169 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_5 ( V_18 , args -> V_170 ) ;
if ( args -> V_170 & ( V_171 | V_172 ) )
F_1 ( V_2 , args -> V_4 , 0 ,
V_173 << V_174 ,
V_175 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_176 * args )
{
unsigned int V_5 ;
int error ;
F_42 ( V_18 , F_93 ( args -> V_177 ) ) ;
F_5 ( V_18 , args -> V_170 ) ;
V_5 = V_2 -> V_178 ;
if ( args -> V_179 != 0 )
F_21 ( V_18 , args -> V_4 , 0 , args -> V_6 ) ;
else
F_6 ( V_18 , V_180 ) ;
error = F_94 ( V_18 -> V_33 , V_5 , args -> V_177 ,
( args -> V_170 & V_171 ) ?
args -> V_181 : NULL , 1 , 0 ) ;
F_95 ( error < 0 ) ;
error = F_94 ( V_18 -> V_33 , V_5 + error , args -> V_177 ,
( args -> V_170 & V_172 ) ?
args -> V_182 : NULL , 1 ,
V_183 ) ;
F_95 ( error < 0 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_86 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_50 ( V_18 , V_184 ) ;
V_115:
return error ;
V_186:
return F_97 ( V_46 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_86 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_188 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_43 ( V_18 , V_184 -> V_55 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_189 ) ;
V_115:
return error ;
V_186:
error = F_56 ( V_18 , V_184 -> V_189 ) ;
if ( F_10 ( error ) )
goto V_115;
return F_97 ( V_46 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_190 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_8 ( V_18 , & V_184 -> V_122 ) ;
V_115:
return error ;
V_186:
return F_97 ( V_46 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_86 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_22 ( V_18 ) ;
V_115:
return error ;
V_186:
return F_97 ( V_46 ) ;
}
static int F_102 ( struct V_17 * V_18 ,
struct V_191 * V_184 )
{
T_1 V_192 , V_29 , V_193 , V_32 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 + 4 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ++ ) ;
V_192 = F_11 ( V_20 ++ ) ;
V_193 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_193 != V_29 ) )
goto V_194;
V_32 = F_23 ( V_18 , V_29 ) ;
if ( F_10 ( V_29 > V_32 ) )
goto V_36;
V_115:
V_184 -> V_192 = V_192 ;
V_184 -> V_29 = V_29 ;
return V_29 ;
V_194:
F_4 ( L_10
L_11 , V_29 , V_193 ) ;
return - V_24 ;
V_36:
F_4 ( L_12
L_6 , V_29 , V_32 ) ;
V_29 = V_32 ;
V_192 = 0 ;
goto V_115;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_191 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
error = F_102 ( V_18 , V_184 ) ;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_104 ( struct V_17 * V_18 ,
struct V_195 * V_184 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_184 -> V_29 = F_11 ( V_20 ++ ) ;
V_184 -> V_166 -> V_196 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_184 -> V_166 -> V_196 > V_197 ) )
goto V_198;
if ( F_32 ( V_18 , & V_184 -> V_166 -> V_38 ) )
goto V_199;
return V_184 -> V_29 ;
V_198:
F_4 ( L_13 , V_184 -> V_166 -> V_196 ) ;
return - V_24 ;
V_22:
F_3 ( V_23 , V_18 ) ;
V_199:
return - V_24 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_195 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
error = F_104 ( V_18 , V_184 ) ;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_106 ( struct V_17 * V_18 ,
struct V_188 * V_184 )
{
int error ;
error = F_60 ( V_18 , V_184 -> V_55 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_184 -> V_55 -> V_44 == 0 )
V_184 -> V_87 -> V_103 = 0 ;
error = F_59 ( V_18 , V_184 -> V_189 ) ;
V_115:
return error ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_188 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_106 ( V_18 , V_184 ) ;
V_115:
return error ;
V_186:
error = F_59 ( V_18 , V_184 -> V_189 ) ;
if ( F_10 ( error ) )
goto V_115;
return F_97 ( V_46 ) ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_200 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 -> V_189 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_201 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 -> V_202 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 -> V_203 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_110 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_204 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 -> V_189 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
int F_111 ( struct V_17 * V_18 , struct V_205 * V_206 ,
int V_207 )
{
struct V_205 V_155 = * V_206 ;
T_2 * V_20 ;
int error ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 == V_76 ) {
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 == V_76 )
return - V_208 ;
V_206 -> V_192 = 1 ;
return - V_209 ;
}
error = F_15 ( V_18 , & V_206 -> V_210 ) ;
if ( F_10 ( error ) )
return error ;
error = F_19 ( V_18 , & V_206 -> V_26 , & V_206 -> V_6 ) ;
if ( F_10 ( error ) )
return error ;
V_206 -> V_211 = V_206 -> V_37 ;
error = F_27 ( V_18 , & V_206 -> V_37 ) ;
if ( F_10 ( error ) )
return error ;
V_206 -> V_212 = V_213 ;
if ( V_207 ) {
V_206 -> V_87 -> V_103 = 0 ;
error = F_56 ( V_18 , V_206 -> V_87 ) ;
if ( F_10 ( error ) )
return error ;
if ( V_206 -> V_87 -> V_103 & V_104 )
V_206 -> V_212 = F_112 ( V_206 -> V_87 -> V_47 ) ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 ) {
error = F_43 ( V_18 , V_206 -> V_55 ) ;
if ( F_10 ( error ) ) {
if ( error == - V_58 )
goto V_214;
return error ;
}
} else
F_44 ( V_206 -> V_55 ) ;
}
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_208 ;
V_214:
F_4 ( L_14 ) ;
* V_206 = V_155 ;
return - V_208 ;
}
static int F_113 ( struct V_17 * V_18 )
{
return F_23 ( V_18 , V_18 -> V_33 -> V_34 ) ;
}
static int F_114 ( struct V_17 * V_18 ,
struct V_215 * V_184 )
{
int error ;
error = F_56 ( V_18 , V_184 -> V_189 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_30 ( V_18 , V_184 -> V_166 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_113 ( V_18 ) ;
V_115:
return error ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_215 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_114 ( V_18 , V_184 ) ;
V_115:
return error ;
V_186:
error = F_56 ( V_18 , V_184 -> V_189 ) ;
if ( F_10 ( error ) )
goto V_115;
return F_97 ( V_46 ) ;
}
static int F_116 ( struct V_17 * V_18 ,
struct V_216 * V_184 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 8 * 6 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_20 = F_33 ( V_20 , & V_184 -> V_217 ) ;
V_20 = F_33 ( V_20 , & V_184 -> V_218 ) ;
V_20 = F_33 ( V_20 , & V_184 -> V_219 ) ;
V_20 = F_33 ( V_20 , & V_184 -> V_220 ) ;
V_20 = F_33 ( V_20 , & V_184 -> V_221 ) ;
F_33 ( V_20 , & V_184 -> V_222 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_216 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
error = F_116 ( V_18 , V_184 ) ;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_118 ( struct V_17 * V_18 ,
struct V_223 * V_184 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 * 7 + 8 + 8 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_184 -> V_224 = F_11 ( V_20 ++ ) ;
V_184 -> V_225 = F_11 ( V_20 ++ ) ;
V_184 -> V_226 = F_11 ( V_20 ++ ) ;
V_184 -> V_227 = F_11 ( V_20 ++ ) ;
V_184 -> V_228 = F_11 ( V_20 ++ ) ;
V_184 -> V_229 = F_11 ( V_20 ++ ) ;
V_184 -> V_230 = F_11 ( V_20 ++ ) ;
V_20 = F_33 ( V_20 , & V_184 -> V_231 ) ;
F_46 ( V_20 , & V_184 -> V_232 ) ;
V_184 -> V_233 = 0 ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_223 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
error = F_118 ( V_18 , V_184 ) ;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_120 ( struct V_17 * V_18 ,
struct V_234 * V_184 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 * 6 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_184 -> V_235 = F_11 ( V_20 ++ ) ;
V_184 -> V_236 = F_11 ( V_20 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_234 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
error = F_120 ( V_18 , V_184 ) ;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_237 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_59 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_187;
error = F_32 ( V_18 , & V_184 -> V_166 -> V_38 ) ;
V_115:
return error ;
V_187:
return F_97 ( V_46 ) ;
}
static inline int F_123 ( struct V_17 * V_18 ,
struct V_238 * V_184 )
{
struct V_239 * * V_240 ;
unsigned int * V_241 ;
T_6 V_242 ;
int error ;
error = F_56 ( V_18 , V_184 -> V_87 ) ;
if ( F_10 ( error ) )
goto V_115;
error = F_8 ( V_18 , & V_184 -> V_170 ) ;
if ( F_10 ( error ) )
goto V_115;
error = - V_105 ;
if ( V_184 -> V_170 & ~ ( V_171 | V_243 | V_172 | V_244 ) )
goto V_115;
V_242 = F_124 ( V_18 ) ;
V_240 = NULL ;
if ( V_184 -> V_170 & V_171 )
V_240 = & V_184 -> V_181 ;
V_241 = NULL ;
if ( V_184 -> V_170 & V_243 )
V_241 = & V_184 -> V_245 ;
error = F_125 ( V_18 -> V_33 , V_242 , V_241 , V_240 ) ;
if ( F_10 ( error <= 0 ) )
goto V_115;
V_240 = NULL ;
if ( V_184 -> V_170 & V_172 )
V_240 = & V_184 -> V_182 ;
V_241 = NULL ;
if ( V_184 -> V_170 & V_244 )
V_241 = & V_184 -> V_246 ;
error = F_125 ( V_18 -> V_33 , V_242 + error , V_241 , V_240 ) ;
if ( F_10 ( error <= 0 ) )
return error ;
error = 0 ;
V_115:
return error ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_238 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_123 ( V_18 , V_184 ) ;
V_115:
return error ;
V_186:
return F_97 ( V_46 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_86 * V_184 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_115;
if ( V_46 != V_185 )
goto V_186;
error = F_56 ( V_18 , V_184 ) ;
V_115:
return error ;
V_186:
return F_97 ( V_46 ) ;
}
static int F_97 ( enum V_45 V_46 )
{
int V_247 ;
for ( V_247 = 0 ; V_248 [ V_247 ] . V_249 != - 1 ; V_247 ++ ) {
if ( V_248 [ V_247 ] . V_249 == ( int ) V_46 )
return V_248 [ V_247 ] . V_250 ;
}
F_4 ( L_15 , V_46 ) ;
return V_248 [ V_247 ] . V_250 ;
}
