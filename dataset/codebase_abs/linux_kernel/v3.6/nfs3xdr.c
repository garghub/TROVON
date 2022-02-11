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
F_17 ( V_27 > V_32 ) ;
F_5 ( V_18 , V_27 ) ;
F_21 ( V_18 , V_4 , 0 , V_27 ) ;
}
static int F_22 ( struct V_17 * V_18 )
{
T_1 V_33 , V_29 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ) ;
if ( F_10 ( V_29 >= V_18 -> V_34 -> V_35 || V_29 > V_32 ) )
goto V_30;
V_33 = F_23 ( V_18 , V_29 ) ;
if ( F_10 ( V_29 > V_33 ) )
goto V_36;
F_24 ( V_18 -> V_34 , V_29 ) ;
return 0 ;
V_30:
F_4 ( L_4 , V_29 ) ;
return - V_31 ;
V_36:
F_4 ( L_5
L_6 , V_29 , V_33 ) ;
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
F_17 ( type > V_47 ) ;
F_5 ( V_18 , type ) ;
}
static T_2 * F_36 ( T_2 * V_20 , T_4 * V_48 )
{
T_1 type ;
type = F_11 ( V_20 ++ ) ;
if ( type > V_47 )
type = V_49 ;
* V_48 = V_50 [ type ] ;
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
* V_20 ++ = F_7 ( V_64 -> V_77 ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_69 ) {
* V_20 ++ = V_73 ;
* V_20 ++ = F_7 ( V_64 -> V_78 ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_70 ) {
* V_20 ++ = V_73 ;
V_20 = F_26 ( V_20 , ( T_3 ) V_64 -> V_79 ) ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_71 ) {
* V_20 ++ = V_80 ;
V_20 = F_45 ( V_20 , & V_64 -> V_81 ) ;
} else if ( V_64 -> V_66 & V_82 ) {
* V_20 ++ = V_73 ;
} else
* V_20 ++ = V_76 ;
if ( V_64 -> V_66 & V_72 ) {
* V_20 ++ = V_80 ;
F_45 ( V_20 , & V_64 -> V_83 ) ;
} else if ( V_64 -> V_66 & V_84 ) {
* V_20 = V_73 ;
} else
* V_20 = V_76 ;
}
static int F_48 ( struct V_17 * V_18 , struct V_85 * V_86 )
{
T_4 V_87 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_88 << 2 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_20 = F_36 ( V_20 , & V_87 ) ;
V_86 -> V_48 = ( F_11 ( V_20 ++ ) & ~ V_89 ) | V_87 ;
V_86 -> V_90 = F_11 ( V_20 ++ ) ;
V_86 -> V_91 = F_11 ( V_20 ++ ) ;
V_86 -> V_92 = F_11 ( V_20 ++ ) ;
V_20 = F_33 ( V_20 , & V_86 -> V_44 ) ;
V_20 = F_33 ( V_20 , & V_86 -> V_93 . V_94 . V_95 ) ;
V_20 = F_40 ( V_20 , & V_86 -> V_51 ) ;
V_20 = F_13 ( V_20 , & V_86 -> V_96 . V_52 ) ;
V_86 -> V_96 . V_53 = 0 ;
V_20 = F_14 ( V_20 , & V_86 -> V_25 ) ;
V_20 = F_46 ( V_20 , & V_86 -> V_97 ) ;
V_20 = F_46 ( V_20 , & V_86 -> V_98 ) ;
F_46 ( V_20 , & V_86 -> ctime ) ;
V_86 -> V_99 = F_49 ( & V_86 -> ctime ) ;
V_86 -> V_100 |= V_101 ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_50 ( struct V_17 * V_18 , struct V_85 * V_86 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 )
return F_48 ( V_18 , V_86 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_51 ( struct V_17 * V_18 , struct V_85 * V_86 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_102 << 2 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_86 -> V_100 |= V_103
| V_104
| V_105
| V_106 ;
V_20 = F_33 ( V_20 , & V_86 -> V_107 ) ;
V_20 = F_46 ( V_20 , & V_86 -> V_108 ) ;
F_46 ( V_20 , & V_86 -> V_109 ) ;
V_86 -> V_110 = F_49 ( & V_86 -> V_109 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_52 ( struct V_17 * V_18 , struct V_85 * V_86 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 )
return F_51 ( V_18 , V_86 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_53 ( struct V_17 * V_18 , struct V_85 * V_86 )
{
int error ;
error = F_52 ( V_18 , V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_86 ) ;
V_111:
return error ;
}
static int F_54 ( struct V_17 * V_18 , struct V_54 * V_55 )
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
static void F_55 ( struct V_17 * V_18 , const struct V_54 * V_55 ,
const char * V_26 , T_1 V_27 )
{
F_42 ( V_18 , V_55 ) ;
F_16 ( V_18 , V_26 , V_27 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_54 * V_55 )
{
F_42 ( V_18 , V_55 ) ;
}
static void F_57 ( struct V_17 * V_18 ,
const struct V_112 * args )
{
T_2 * V_20 ;
if ( args -> V_113 ) {
V_20 = F_6 ( V_18 , 4 + 8 ) ;
* V_20 ++ = V_73 ;
F_45 ( V_20 , & args -> V_114 ) ;
} else {
V_20 = F_6 ( V_18 , 4 ) ;
* V_20 = V_76 ;
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_112 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_47 ( V_18 , args -> V_115 ) ;
F_57 ( V_18 , args ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_116 * args )
{
F_55 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
}
static void F_60 ( struct V_17 * V_18 ,
const struct V_117 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_5 ( V_18 , args -> V_118 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_117 * args )
{
F_60 ( V_18 , args ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_119 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_1 ( V_2 , args -> V_4 , args -> V_120 ,
args -> V_121 , V_122 ) ;
}
static void F_63 ( struct V_17 * V_18 ,
const struct V_123 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_124 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_123 * args )
{
F_63 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , args -> V_120 ,
args -> V_29 , V_125 ) ;
V_2 -> V_15 . V_126 |= V_127 ;
}
static void F_65 ( struct V_17 * V_18 ,
const struct V_128 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + 4 + 4 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_124 ) ;
* V_20 ++ = F_7 ( args -> V_29 ) ;
* V_20 ++ = F_7 ( args -> V_129 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
F_21 ( V_18 , args -> V_4 , args -> V_120 , args -> V_29 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_128 * args )
{
F_65 ( V_18 , args ) ;
V_18 -> V_34 -> V_126 |= V_130 ;
}
static void F_67 ( struct V_17 * V_18 ,
const struct V_131 * args )
{
F_5 ( V_18 , args -> V_132 ) ;
switch ( args -> V_132 ) {
case V_133 :
case V_134 :
F_47 ( V_18 , args -> V_115 ) ;
break;
case V_135 :
F_31 ( V_18 , args -> V_38 ) ;
break;
default:
F_68 () ;
}
}
static void F_69 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_131 * args )
{
F_55 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
F_67 ( V_18 , args ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_136 * args )
{
F_55 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
F_47 ( V_18 , args -> V_115 ) ;
}
static void F_71 ( struct V_17 * V_18 ,
const struct V_137 * args )
{
F_47 ( V_18 , args -> V_115 ) ;
F_20 ( V_18 , args -> V_4 , args -> V_138 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_137 * args )
{
F_55 ( V_18 , args -> V_139 , args -> V_140 , args -> V_141 ) ;
F_71 ( V_18 , args ) ;
}
static void F_73 ( struct V_17 * V_18 ,
const struct V_142 * args )
{
F_47 ( V_18 , args -> V_115 ) ;
F_37 ( V_18 , args -> V_51 ) ;
}
static void F_74 ( struct V_17 * V_18 ,
const struct V_142 * args )
{
F_35 ( V_18 , args -> type ) ;
switch ( args -> type ) {
case V_143 :
case V_144 :
F_73 ( V_18 , args ) ;
break;
case V_145 :
case V_47 :
F_47 ( V_18 , args -> V_115 ) ;
break;
case V_146 :
case V_147 :
break;
default:
F_68 () ;
}
}
static void F_75 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_142 * args )
{
F_55 ( V_18 , args -> V_55 , args -> V_26 , args -> V_6 ) ;
F_74 ( V_18 , args ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_148 * args )
{
F_55 ( V_18 , args -> V_55 , args -> V_26 . V_26 , args -> V_26 . V_6 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_149 * args )
{
const struct V_150 * V_151 = args -> V_152 ;
const struct V_150 * V_153 = args -> V_154 ;
F_55 ( V_18 , args -> V_155 , V_151 -> V_26 , V_151 -> V_6 ) ;
F_55 ( V_18 , args -> V_156 , V_153 -> V_26 , V_153 -> V_6 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_157 * args )
{
F_42 ( V_18 , args -> V_139 ) ;
F_55 ( V_18 , args -> V_158 , args -> V_159 , args -> V_160 ) ;
}
static void F_79 ( struct V_17 * V_18 ,
const struct V_161 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + V_39 + 4 ) ;
V_20 = F_25 ( V_20 , args -> V_37 ) ;
V_20 = F_28 ( V_20 , args -> V_162 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_161 * args )
{
F_79 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_29 , V_163 ) ;
}
static void F_81 ( struct V_17 * V_18 ,
const struct V_161 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + V_39 + 4 + 4 ) ;
V_20 = F_25 ( V_20 , args -> V_37 ) ;
V_20 = F_28 ( V_20 , args -> V_162 ) ;
* V_20 ++ = F_7 ( args -> V_29 >> 3 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_161 * args )
{
F_81 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_29 , V_163 ) ;
}
static void F_83 ( struct V_17 * V_18 ,
const struct V_164 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_55 ) ;
V_20 = F_6 ( V_18 , 8 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_124 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_164 * args )
{
F_83 ( V_18 , args ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_165 * args )
{
F_42 ( V_18 , args -> V_55 ) ;
F_5 ( V_18 , args -> V_166 ) ;
if ( args -> V_166 & ( V_167 | V_168 ) )
F_1 ( V_2 , args -> V_4 , 0 ,
V_169 << V_170 ,
V_171 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_172 * args )
{
unsigned int V_5 ;
int error ;
F_42 ( V_18 , F_87 ( args -> V_173 ) ) ;
F_5 ( V_18 , args -> V_166 ) ;
V_5 = V_2 -> V_174 ;
if ( args -> V_175 != 0 )
F_21 ( V_18 , args -> V_4 , 0 , args -> V_6 ) ;
else
F_6 ( V_18 , V_176 ) ;
error = F_88 ( V_18 -> V_34 , V_5 , args -> V_173 ,
( args -> V_166 & V_167 ) ?
args -> V_177 : NULL , 1 , 0 ) ;
F_17 ( error < 0 ) ;
error = F_88 ( V_18 -> V_34 , V_5 + error , args -> V_173 ,
( args -> V_166 & V_168 ) ?
args -> V_178 : NULL , 1 ,
V_179 ) ;
F_17 ( error < 0 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_85 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_48 ( V_18 , V_180 ) ;
V_111:
return error ;
V_182:
return F_90 ( V_46 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_85 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_184 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_43 ( V_18 , V_180 -> V_55 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_185 ) ;
V_111:
return error ;
V_182:
error = F_50 ( V_18 , V_180 -> V_185 ) ;
if ( F_10 ( error ) )
goto V_111;
return F_90 ( V_46 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_186 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_8 ( V_18 , & V_180 -> V_118 ) ;
V_111:
return error ;
V_182:
return F_90 ( V_46 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_85 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_22 ( V_18 ) ;
V_111:
return error ;
V_182:
return F_90 ( V_46 ) ;
}
static int F_95 ( struct V_17 * V_18 ,
struct V_187 * V_180 )
{
T_1 V_188 , V_29 , V_189 , V_33 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 + 4 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ++ ) ;
V_188 = F_11 ( V_20 ++ ) ;
V_189 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_189 != V_29 ) )
goto V_190;
V_33 = F_23 ( V_18 , V_29 ) ;
if ( F_10 ( V_29 > V_33 ) )
goto V_36;
V_111:
V_180 -> V_188 = V_188 ;
V_180 -> V_29 = V_29 ;
return V_29 ;
V_190:
F_4 ( L_8
L_9 , V_29 , V_189 ) ;
return - V_24 ;
V_36:
F_4 ( L_10
L_6 , V_29 , V_33 ) ;
V_29 = V_33 ;
V_188 = 0 ;
goto V_111;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_187 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
error = F_95 ( V_18 , V_180 ) ;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_97 ( struct V_17 * V_18 ,
struct V_191 * V_180 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_180 -> V_29 = F_11 ( V_20 ++ ) ;
V_180 -> V_162 -> V_192 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_180 -> V_162 -> V_192 > V_193 ) )
goto V_194;
if ( F_32 ( V_18 , & V_180 -> V_162 -> V_38 ) )
goto V_195;
return V_180 -> V_29 ;
V_194:
F_4 ( L_11 , V_180 -> V_162 -> V_192 ) ;
return - V_24 ;
V_22:
F_3 ( V_23 , V_18 ) ;
V_195:
return - V_24 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_191 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
error = F_97 ( V_18 , V_180 ) ;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_99 ( struct V_17 * V_18 ,
struct V_184 * V_180 )
{
int error ;
error = F_54 ( V_18 , V_180 -> V_55 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_180 -> V_55 -> V_44 == 0 )
V_180 -> V_86 -> V_100 = 0 ;
error = F_53 ( V_18 , V_180 -> V_185 ) ;
V_111:
return error ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_184 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_99 ( V_18 , V_180 ) ;
V_111:
return error ;
V_182:
error = F_53 ( V_18 , V_180 -> V_185 ) ;
if ( F_10 ( error ) )
goto V_111;
return F_90 ( V_46 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_196 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 -> V_185 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_197 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 -> V_198 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 -> V_199 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_103 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_200 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 -> V_185 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
int F_104 ( struct V_17 * V_18 , struct V_201 * V_202 ,
int V_203 )
{
struct V_201 V_151 = * V_202 ;
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
return - V_204 ;
V_202 -> V_188 = 1 ;
return - V_205 ;
}
error = F_15 ( V_18 , & V_202 -> V_206 ) ;
if ( F_10 ( error ) )
return error ;
error = F_19 ( V_18 , & V_202 -> V_26 , & V_202 -> V_6 ) ;
if ( F_10 ( error ) )
return error ;
V_202 -> V_207 = V_202 -> V_37 ;
error = F_27 ( V_18 , & V_202 -> V_37 ) ;
if ( F_10 ( error ) )
return error ;
V_202 -> V_208 = V_209 ;
if ( V_203 ) {
V_202 -> V_86 -> V_100 = 0 ;
error = F_50 ( V_18 , V_202 -> V_86 ) ;
if ( F_10 ( error ) )
return error ;
if ( V_202 -> V_86 -> V_100 & V_101 )
V_202 -> V_208 = F_105 ( V_202 -> V_86 -> V_48 ) ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_76 ) {
error = F_43 ( V_18 , V_202 -> V_55 ) ;
if ( F_10 ( error ) ) {
if ( error == - V_58 )
goto V_210;
return error ;
}
} else
F_44 ( V_202 -> V_55 ) ;
}
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_204 ;
V_210:
F_4 ( L_12 ) ;
* V_202 = V_151 ;
return - V_204 ;
}
static int F_106 ( struct V_17 * V_18 )
{
return F_23 ( V_18 , V_18 -> V_34 -> V_35 ) ;
}
static int F_107 ( struct V_17 * V_18 ,
struct V_211 * V_180 )
{
int error ;
error = F_50 ( V_18 , V_180 -> V_185 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_30 ( V_18 , V_180 -> V_162 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_106 ( V_18 ) ;
V_111:
return error ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_211 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_107 ( V_18 , V_180 ) ;
V_111:
return error ;
V_182:
error = F_50 ( V_18 , V_180 -> V_185 ) ;
if ( F_10 ( error ) )
goto V_111;
return F_90 ( V_46 ) ;
}
static int F_109 ( struct V_17 * V_18 ,
struct V_212 * V_180 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 8 * 6 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_20 = F_33 ( V_20 , & V_180 -> V_213 ) ;
V_20 = F_33 ( V_20 , & V_180 -> V_214 ) ;
V_20 = F_33 ( V_20 , & V_180 -> V_215 ) ;
V_20 = F_33 ( V_20 , & V_180 -> V_216 ) ;
V_20 = F_33 ( V_20 , & V_180 -> V_217 ) ;
F_33 ( V_20 , & V_180 -> V_218 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_212 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
error = F_109 ( V_18 , V_180 ) ;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_111 ( struct V_17 * V_18 ,
struct V_219 * V_180 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 * 7 + 8 + 8 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_180 -> V_220 = F_11 ( V_20 ++ ) ;
V_180 -> V_221 = F_11 ( V_20 ++ ) ;
V_180 -> V_222 = F_11 ( V_20 ++ ) ;
V_180 -> V_223 = F_11 ( V_20 ++ ) ;
V_180 -> V_224 = F_11 ( V_20 ++ ) ;
V_180 -> V_225 = F_11 ( V_20 ++ ) ;
V_180 -> V_226 = F_11 ( V_20 ++ ) ;
V_20 = F_33 ( V_20 , & V_180 -> V_227 ) ;
F_46 ( V_20 , & V_180 -> V_228 ) ;
V_180 -> V_229 = 0 ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_219 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
error = F_111 ( V_18 , V_180 ) ;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_113 ( struct V_17 * V_18 ,
struct V_230 * V_180 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 * 6 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_180 -> V_231 = F_11 ( V_20 ++ ) ;
V_180 -> V_232 = F_11 ( V_20 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_230 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
error = F_113 ( V_18 , V_180 ) ;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_233 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_53 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_183;
error = F_32 ( V_18 , & V_180 -> V_162 -> V_38 ) ;
V_111:
return error ;
V_183:
return F_90 ( V_46 ) ;
}
static inline int F_116 ( struct V_17 * V_18 ,
struct V_234 * V_180 )
{
struct V_235 * * V_236 ;
unsigned int * V_237 ;
T_6 V_238 ;
int error ;
error = F_50 ( V_18 , V_180 -> V_86 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_8 ( V_18 , & V_180 -> V_166 ) ;
if ( F_10 ( error ) )
goto V_111;
error = - V_239 ;
if ( V_180 -> V_166 & ~ ( V_167 | V_240 | V_168 | V_241 ) )
goto V_111;
V_238 = F_117 ( V_18 ) ;
V_236 = NULL ;
if ( V_180 -> V_166 & V_167 )
V_236 = & V_180 -> V_177 ;
V_237 = NULL ;
if ( V_180 -> V_166 & V_240 )
V_237 = & V_180 -> V_242 ;
error = F_118 ( V_18 -> V_34 , V_238 , V_237 , V_236 ) ;
if ( F_10 ( error <= 0 ) )
goto V_111;
V_236 = NULL ;
if ( V_180 -> V_166 & V_168 )
V_236 = & V_180 -> V_178 ;
V_237 = NULL ;
if ( V_180 -> V_166 & V_241 )
V_237 = & V_180 -> V_243 ;
error = F_118 ( V_18 -> V_34 , V_238 + error , V_237 , V_236 ) ;
if ( F_10 ( error <= 0 ) )
return error ;
error = 0 ;
V_111:
return error ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_234 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_116 ( V_18 , V_180 ) ;
V_111:
return error ;
V_182:
return F_90 ( V_46 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_85 * V_180 )
{
enum V_45 V_46 ;
int error ;
error = F_34 ( V_18 , & V_46 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_46 != V_181 )
goto V_182;
error = F_50 ( V_18 , V_180 ) ;
V_111:
return error ;
V_182:
return F_90 ( V_46 ) ;
}
static int F_90 ( enum V_45 V_46 )
{
int V_244 ;
for ( V_244 = 0 ; V_245 [ V_244 ] . V_246 != - 1 ; V_244 ++ ) {
if ( V_245 [ V_244 ] . V_246 == ( int ) V_46 )
return V_245 [ V_244 ] . V_247 ;
}
F_4 ( L_13 , V_46 ) ;
return V_245 [ V_244 ] . V_247 ;
}
