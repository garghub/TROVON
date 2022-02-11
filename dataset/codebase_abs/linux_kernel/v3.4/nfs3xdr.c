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
T_4 V_34 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ) ;
if ( F_10 ( V_29 >= V_18 -> V_35 -> V_36 || V_29 > V_32 ) )
goto V_30;
V_34 = ( V_37 * ) V_18 -> V_20 - ( V_37 * ) V_18 -> V_38 -> V_39 ;
V_33 = V_18 -> V_35 -> V_6 - V_34 ;
if ( F_10 ( V_29 > V_33 ) )
goto V_40;
F_23 ( V_18 , V_29 ) ;
F_24 ( V_18 -> V_35 , V_29 ) ;
return 0 ;
V_30:
F_4 ( L_4 , V_29 ) ;
return - V_31 ;
V_40:
F_4 ( L_5
L_6 , V_29 , V_33 ) ;
return - V_24 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static T_2 * F_25 ( T_2 * V_20 , T_3 V_41 )
{
return F_26 ( V_20 , V_41 ) ;
}
static int F_27 ( struct V_17 * V_18 , T_3 * V_41 )
{
return F_12 ( V_18 , V_41 ) ;
}
static T_2 * F_28 ( T_2 * V_20 , const T_2 * V_42 )
{
memcpy ( V_20 , V_42 , V_43 ) ;
return V_20 + F_29 ( V_43 ) ;
}
static int F_30 ( struct V_17 * V_18 , T_2 * V_42 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_43 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
memcpy ( V_42 , V_20 , V_43 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_31 ( struct V_17 * V_18 , const T_2 * V_42 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , V_44 ) ;
memcpy ( V_20 , V_42 , V_44 ) ;
}
static int F_32 ( struct V_17 * V_18 , T_2 * V_42 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_45 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
memcpy ( V_42 , V_20 , V_45 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static T_2 * F_33 ( T_2 * V_20 , T_3 * V_46 )
{
return F_13 ( V_20 , V_46 ) ;
}
static int F_34 ( struct V_17 * V_18 , enum V_47 * V_48 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
* V_48 = F_11 ( V_20 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_35 ( struct V_17 * V_18 , const T_1 type )
{
F_17 ( type > V_49 ) ;
F_5 ( V_18 , type ) ;
}
static T_2 * F_36 ( T_2 * V_20 , T_5 * V_50 )
{
T_1 type ;
type = F_11 ( V_20 ++ ) ;
if ( type > V_49 )
type = V_51 ;
* V_50 = V_52 [ type ] ;
return V_20 ;
}
static void F_37 ( struct V_17 * V_18 , const T_6 V_53 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , 8 ) ;
* V_20 ++ = F_7 ( F_38 ( V_53 ) ) ;
* V_20 = F_7 ( F_39 ( V_53 ) ) ;
}
static T_2 * F_40 ( T_2 * V_20 , T_6 * V_53 )
{
unsigned int V_54 , V_55 ;
V_54 = F_11 ( V_20 ++ ) ;
V_55 = F_11 ( V_20 ++ ) ;
* V_53 = F_41 ( V_54 , V_55 ) ;
if ( F_38 ( * V_53 ) != V_54 || F_39 ( * V_53 ) != V_55 )
* V_53 = 0 ;
return V_20 ;
}
static void F_42 ( struct V_17 * V_18 , const struct V_56 * V_57 )
{
T_2 * V_20 ;
F_17 ( V_57 -> V_46 > V_58 ) ;
V_20 = F_6 ( V_18 , 4 + V_57 -> V_46 ) ;
F_18 ( V_20 , V_57 -> V_59 , V_57 -> V_46 ) ;
}
static int F_43 ( struct V_17 * V_18 , struct V_56 * V_57 )
{
T_1 V_27 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_27 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_27 > V_58 ) )
goto V_60;
V_20 = F_9 ( V_18 , V_27 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_57 -> V_46 = V_27 ;
memcpy ( V_57 -> V_59 , V_20 , V_27 ) ;
return 0 ;
V_60:
F_4 ( L_7 , V_27 ) ;
return - V_61 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_44 ( struct V_56 * V_57 )
{
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
}
static T_2 * F_45 ( T_2 * V_20 , const struct V_62 * V_63 )
{
* V_20 ++ = F_7 ( V_63 -> V_64 ) ;
* V_20 ++ = F_7 ( V_63 -> V_65 ) ;
return V_20 ;
}
static T_2 * F_46 ( T_2 * V_20 , struct V_62 * V_63 )
{
V_63 -> V_64 = F_11 ( V_20 ++ ) ;
V_63 -> V_65 = F_11 ( V_20 ++ ) ;
return V_20 ;
}
static void F_47 ( struct V_17 * V_18 , const struct V_66 * V_67 )
{
T_1 V_68 ;
T_2 * V_20 ;
V_68 = 6 * 4 ;
if ( V_67 -> V_69 & V_70 )
V_68 += 4 ;
if ( V_67 -> V_69 & V_71 )
V_68 += 4 ;
if ( V_67 -> V_69 & V_72 )
V_68 += 4 ;
if ( V_67 -> V_69 & V_73 )
V_68 += 8 ;
if ( V_67 -> V_69 & V_74 )
V_68 += 8 ;
if ( V_67 -> V_69 & V_75 )
V_68 += 8 ;
V_20 = F_6 ( V_18 , V_68 ) ;
if ( V_67 -> V_69 & V_70 ) {
* V_20 ++ = V_76 ;
* V_20 ++ = F_7 ( V_67 -> V_77 & V_78 ) ;
} else
* V_20 ++ = V_79 ;
if ( V_67 -> V_69 & V_71 ) {
* V_20 ++ = V_76 ;
* V_20 ++ = F_7 ( V_67 -> V_80 ) ;
} else
* V_20 ++ = V_79 ;
if ( V_67 -> V_69 & V_72 ) {
* V_20 ++ = V_76 ;
* V_20 ++ = F_7 ( V_67 -> V_81 ) ;
} else
* V_20 ++ = V_79 ;
if ( V_67 -> V_69 & V_73 ) {
* V_20 ++ = V_76 ;
V_20 = F_26 ( V_20 , ( T_3 ) V_67 -> V_82 ) ;
} else
* V_20 ++ = V_79 ;
if ( V_67 -> V_69 & V_74 ) {
* V_20 ++ = V_83 ;
V_20 = F_45 ( V_20 , & V_67 -> V_84 ) ;
} else if ( V_67 -> V_69 & V_85 ) {
* V_20 ++ = V_76 ;
} else
* V_20 ++ = V_79 ;
if ( V_67 -> V_69 & V_75 ) {
* V_20 ++ = V_83 ;
F_45 ( V_20 , & V_67 -> V_86 ) ;
} else if ( V_67 -> V_69 & V_87 ) {
* V_20 = V_76 ;
} else
* V_20 = V_79 ;
}
static int F_48 ( struct V_17 * V_18 , struct V_88 * V_89 )
{
T_5 V_90 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_91 << 2 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_20 = F_36 ( V_20 , & V_90 ) ;
V_89 -> V_50 = ( F_11 ( V_20 ++ ) & ~ V_92 ) | V_90 ;
V_89 -> V_93 = F_11 ( V_20 ++ ) ;
V_89 -> V_94 = F_11 ( V_20 ++ ) ;
V_89 -> V_95 = F_11 ( V_20 ++ ) ;
V_20 = F_33 ( V_20 , & V_89 -> V_46 ) ;
V_20 = F_33 ( V_20 , & V_89 -> V_96 . V_97 . V_98 ) ;
V_20 = F_40 ( V_20 , & V_89 -> V_53 ) ;
V_20 = F_13 ( V_20 , & V_89 -> V_99 . V_54 ) ;
V_89 -> V_99 . V_55 = 0 ;
V_20 = F_14 ( V_20 , & V_89 -> V_25 ) ;
V_20 = F_46 ( V_20 , & V_89 -> V_100 ) ;
V_20 = F_46 ( V_20 , & V_89 -> V_101 ) ;
F_46 ( V_20 , & V_89 -> ctime ) ;
V_89 -> V_102 |= V_103 ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_49 ( struct V_17 * V_18 , struct V_88 * V_89 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_79 )
return F_48 ( V_18 , V_89 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_50 ( struct V_17 * V_18 , struct V_88 * V_89 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , V_104 << 2 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_89 -> V_102 |= V_105
| V_106
| V_107 ;
V_20 = F_33 ( V_20 , & V_89 -> V_108 ) ;
V_20 = F_46 ( V_20 , & V_89 -> V_109 ) ;
F_46 ( V_20 , & V_89 -> V_110 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_51 ( struct V_17 * V_18 , struct V_88 * V_89 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_79 )
return F_50 ( V_18 , V_89 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_52 ( struct V_17 * V_18 , struct V_88 * V_89 )
{
int error ;
error = F_51 ( V_18 , V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_89 ) ;
V_111:
return error ;
}
static int F_53 ( struct V_17 * V_18 , struct V_56 * V_57 )
{
T_2 * V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_79 )
return F_43 ( V_18 , V_57 ) ;
F_44 ( V_57 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static void F_54 ( struct V_17 * V_18 , const struct V_56 * V_57 ,
const char * V_26 , T_1 V_27 )
{
F_42 ( V_18 , V_57 ) ;
F_16 ( V_18 , V_26 , V_27 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_56 * V_57 )
{
F_42 ( V_18 , V_57 ) ;
}
static void F_56 ( struct V_17 * V_18 ,
const struct V_112 * args )
{
T_2 * V_20 ;
if ( args -> V_113 ) {
V_20 = F_6 ( V_18 , 4 + 8 ) ;
* V_20 ++ = V_76 ;
F_45 ( V_20 , & args -> V_114 ) ;
} else {
V_20 = F_6 ( V_18 , 4 ) ;
* V_20 = V_79 ;
}
}
static void F_57 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_112 * args )
{
F_42 ( V_18 , args -> V_57 ) ;
F_47 ( V_18 , args -> V_115 ) ;
F_56 ( V_18 , args ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_116 * args )
{
F_54 ( V_18 , args -> V_57 , args -> V_26 , args -> V_6 ) ;
}
static void F_59 ( struct V_17 * V_18 ,
const struct V_117 * args )
{
F_42 ( V_18 , args -> V_57 ) ;
F_5 ( V_18 , args -> V_118 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_117 * args )
{
F_59 ( V_18 , args ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_119 * args )
{
F_42 ( V_18 , args -> V_57 ) ;
F_1 ( V_2 , args -> V_4 , args -> V_120 ,
args -> V_121 , V_122 ) ;
}
static void F_62 ( struct V_17 * V_18 ,
const struct V_123 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_57 ) ;
V_20 = F_6 ( V_18 , 8 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_124 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_123 * args )
{
F_62 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , args -> V_120 ,
args -> V_29 , V_125 ) ;
V_2 -> V_15 . V_126 |= V_127 ;
}
static void F_64 ( struct V_17 * V_18 ,
const struct V_128 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_57 ) ;
V_20 = F_6 ( V_18 , 8 + 4 + 4 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_124 ) ;
* V_20 ++ = F_7 ( args -> V_29 ) ;
* V_20 ++ = F_7 ( args -> V_129 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
F_21 ( V_18 , args -> V_4 , args -> V_120 , args -> V_29 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_128 * args )
{
F_64 ( V_18 , args ) ;
V_18 -> V_35 -> V_126 |= V_130 ;
}
static void F_66 ( struct V_17 * V_18 ,
const struct V_131 * args )
{
F_5 ( V_18 , args -> V_132 ) ;
switch ( args -> V_132 ) {
case V_133 :
case V_134 :
F_47 ( V_18 , args -> V_115 ) ;
break;
case V_135 :
F_31 ( V_18 , args -> V_42 ) ;
break;
default:
F_67 () ;
}
}
static void F_68 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_131 * args )
{
F_54 ( V_18 , args -> V_57 , args -> V_26 , args -> V_6 ) ;
F_66 ( V_18 , args ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_136 * args )
{
F_54 ( V_18 , args -> V_57 , args -> V_26 , args -> V_6 ) ;
F_47 ( V_18 , args -> V_115 ) ;
}
static void F_70 ( struct V_17 * V_18 ,
const struct V_137 * args )
{
F_47 ( V_18 , args -> V_115 ) ;
F_20 ( V_18 , args -> V_4 , args -> V_138 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_137 * args )
{
F_54 ( V_18 , args -> V_139 , args -> V_140 , args -> V_141 ) ;
F_70 ( V_18 , args ) ;
}
static void F_72 ( struct V_17 * V_18 ,
const struct V_142 * args )
{
F_47 ( V_18 , args -> V_115 ) ;
F_37 ( V_18 , args -> V_53 ) ;
}
static void F_73 ( struct V_17 * V_18 ,
const struct V_142 * args )
{
F_35 ( V_18 , args -> type ) ;
switch ( args -> type ) {
case V_143 :
case V_144 :
F_72 ( V_18 , args ) ;
break;
case V_145 :
case V_49 :
F_47 ( V_18 , args -> V_115 ) ;
break;
case V_146 :
case V_147 :
break;
default:
F_67 () ;
}
}
static void F_74 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_142 * args )
{
F_54 ( V_18 , args -> V_57 , args -> V_26 , args -> V_6 ) ;
F_73 ( V_18 , args ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_148 * args )
{
F_54 ( V_18 , args -> V_57 , args -> V_26 . V_26 , args -> V_26 . V_6 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_149 * args )
{
const struct V_150 * V_151 = args -> V_152 ;
const struct V_150 * V_153 = args -> V_154 ;
F_54 ( V_18 , args -> V_155 , V_151 -> V_26 , V_151 -> V_6 ) ;
F_54 ( V_18 , args -> V_156 , V_153 -> V_26 , V_153 -> V_6 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_157 * args )
{
F_42 ( V_18 , args -> V_139 ) ;
F_54 ( V_18 , args -> V_158 , args -> V_159 , args -> V_160 ) ;
}
static void F_78 ( struct V_17 * V_18 ,
const struct V_161 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_57 ) ;
V_20 = F_6 ( V_18 , 8 + V_43 + 4 ) ;
V_20 = F_25 ( V_20 , args -> V_41 ) ;
V_20 = F_28 ( V_20 , args -> V_162 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_161 * args )
{
F_78 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_29 , V_163 ) ;
}
static void F_80 ( struct V_17 * V_18 ,
const struct V_161 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_57 ) ;
V_20 = F_6 ( V_18 , 8 + V_43 + 4 + 4 ) ;
V_20 = F_25 ( V_20 , args -> V_41 ) ;
V_20 = F_28 ( V_20 , args -> V_162 ) ;
* V_20 ++ = F_7 ( args -> V_29 >> 3 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_161 * args )
{
F_80 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_29 , V_163 ) ;
}
static void F_82 ( struct V_17 * V_18 ,
const struct V_128 * args )
{
T_2 * V_20 ;
F_42 ( V_18 , args -> V_57 ) ;
V_20 = F_6 ( V_18 , 8 + 4 ) ;
V_20 = F_26 ( V_20 , args -> V_124 ) ;
* V_20 = F_7 ( args -> V_29 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_128 * args )
{
F_82 ( V_18 , args ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_164 * args )
{
F_42 ( V_18 , args -> V_57 ) ;
F_5 ( V_18 , args -> V_165 ) ;
if ( args -> V_165 & ( V_166 | V_167 ) )
F_1 ( V_2 , args -> V_4 , 0 ,
V_168 << V_169 ,
V_170 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_171 * args )
{
unsigned int V_5 ;
int error ;
F_42 ( V_18 , F_86 ( args -> V_172 ) ) ;
F_5 ( V_18 , args -> V_165 ) ;
V_5 = V_2 -> V_173 ;
if ( args -> V_174 != 0 )
F_21 ( V_18 , args -> V_4 , 0 , args -> V_6 ) ;
else
F_6 ( V_18 , V_175 ) ;
error = F_87 ( V_18 -> V_35 , V_5 , args -> V_172 ,
( args -> V_165 & V_166 ) ?
args -> V_176 : NULL , 1 , 0 ) ;
F_17 ( error < 0 ) ;
error = F_87 ( V_18 -> V_35 , V_5 + error , args -> V_172 ,
( args -> V_165 & V_167 ) ?
args -> V_177 : NULL , 1 ,
V_178 ) ;
F_17 ( error < 0 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_88 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_48 ( V_18 , V_179 ) ;
V_111:
return error ;
V_181:
return F_89 ( V_48 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_88 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_183 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_43 ( V_18 , V_179 -> V_57 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_184 ) ;
V_111:
return error ;
V_181:
error = F_49 ( V_18 , V_179 -> V_184 ) ;
if ( F_10 ( error ) )
goto V_111;
return F_89 ( V_48 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_185 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_8 ( V_18 , & V_179 -> V_118 ) ;
V_111:
return error ;
V_181:
return F_89 ( V_48 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_88 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_22 ( V_18 ) ;
V_111:
return error ;
V_181:
return F_89 ( V_48 ) ;
}
static int F_94 ( struct V_17 * V_18 ,
struct V_186 * V_179 )
{
T_1 V_187 , V_29 , V_188 , V_33 ;
T_4 V_34 ;
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 + 4 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_29 = F_11 ( V_20 ++ ) ;
V_187 = F_11 ( V_20 ++ ) ;
V_188 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_188 != V_29 ) )
goto V_189;
V_34 = ( V_37 * ) V_18 -> V_20 - ( V_37 * ) V_18 -> V_38 -> V_39 ;
V_33 = V_18 -> V_35 -> V_6 - V_34 ;
if ( F_10 ( V_29 > V_33 ) )
goto V_40;
V_111:
F_23 ( V_18 , V_29 ) ;
V_179 -> V_187 = V_187 ;
V_179 -> V_29 = V_29 ;
return V_29 ;
V_189:
F_4 ( L_8
L_9 , V_29 , V_188 ) ;
return - V_24 ;
V_40:
F_4 ( L_10
L_6 , V_29 , V_33 ) ;
V_29 = V_33 ;
V_187 = 0 ;
goto V_111;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_186 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
error = F_94 ( V_18 , V_179 ) ;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_96 ( struct V_17 * V_18 ,
struct V_190 * V_179 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 + 4 + V_45 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_179 -> V_29 = F_11 ( V_20 ++ ) ;
V_179 -> V_162 -> V_191 = F_11 ( V_20 ++ ) ;
if ( F_10 ( V_179 -> V_162 -> V_191 > V_192 ) )
goto V_193;
memcpy ( V_179 -> V_162 -> V_42 , V_20 , V_45 ) ;
return V_179 -> V_29 ;
V_193:
F_4 ( L_11 , V_179 -> V_162 -> V_191 ) ;
return - V_24 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_190 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
error = F_96 ( V_18 , V_179 ) ;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_98 ( struct V_17 * V_18 ,
struct V_183 * V_179 )
{
int error ;
error = F_53 ( V_18 , V_179 -> V_57 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_179 -> V_57 -> V_46 == 0 )
V_179 -> V_89 -> V_102 = 0 ;
error = F_52 ( V_18 , V_179 -> V_184 ) ;
V_111:
return error ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_183 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_98 ( V_18 , V_179 ) ;
V_111:
return error ;
V_181:
error = F_52 ( V_18 , V_179 -> V_184 ) ;
if ( F_10 ( error ) )
goto V_111;
return F_89 ( V_48 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_194 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 -> V_184 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_195 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 -> V_196 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 -> V_197 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_102 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_198 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 -> V_184 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
int F_103 ( struct V_17 * V_18 , struct V_199 * V_200 ,
int V_201 )
{
struct V_199 V_151 = * V_200 ;
T_2 * V_20 ;
int error ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 == V_79 ) {
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 == V_79 )
return - V_202 ;
V_200 -> V_187 = 1 ;
return - V_203 ;
}
error = F_15 ( V_18 , & V_200 -> V_204 ) ;
if ( F_10 ( error ) )
return error ;
error = F_19 ( V_18 , & V_200 -> V_26 , & V_200 -> V_6 ) ;
if ( F_10 ( error ) )
return error ;
V_200 -> V_205 = V_200 -> V_41 ;
error = F_27 ( V_18 , & V_200 -> V_41 ) ;
if ( F_10 ( error ) )
return error ;
V_200 -> V_206 = V_207 ;
if ( V_201 ) {
V_200 -> V_89 -> V_102 = 0 ;
error = F_49 ( V_18 , V_200 -> V_89 ) ;
if ( F_10 ( error ) )
return error ;
if ( V_200 -> V_89 -> V_102 & V_103 )
V_200 -> V_206 = F_104 ( V_200 -> V_89 -> V_50 ) ;
V_20 = F_9 ( V_18 , 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
if ( * V_20 != V_79 ) {
error = F_43 ( V_18 , V_200 -> V_57 ) ;
if ( F_10 ( error ) ) {
if ( error == - V_61 )
goto V_208;
return error ;
}
} else
F_44 ( V_200 -> V_57 ) ;
}
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_202 ;
V_208:
F_4 ( L_12 ) ;
* V_200 = V_151 ;
return - V_202 ;
}
static int F_105 ( struct V_17 * V_18 )
{
T_1 V_33 , V_121 ;
T_4 V_34 ;
V_121 = V_18 -> V_35 -> V_36 ;
V_34 = ( V_37 * ) V_18 -> V_20 - ( V_37 * ) V_18 -> V_38 -> V_39 ;
V_33 = V_18 -> V_35 -> V_6 - V_34 ;
if ( F_10 ( V_121 > V_33 ) )
goto V_40;
V_111:
F_23 ( V_18 , V_121 ) ;
return V_121 ;
V_40:
F_4 ( L_13
L_14 , V_121 , V_33 ) ;
V_121 = V_33 ;
goto V_111;
}
static int F_106 ( struct V_17 * V_18 ,
struct V_209 * V_179 )
{
int error ;
error = F_49 ( V_18 , V_179 -> V_184 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_30 ( V_18 , V_179 -> V_162 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_105 ( V_18 ) ;
V_111:
return error ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_209 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_106 ( V_18 , V_179 ) ;
V_111:
return error ;
V_181:
error = F_49 ( V_18 , V_179 -> V_184 ) ;
if ( F_10 ( error ) )
goto V_111;
return F_89 ( V_48 ) ;
}
static int F_108 ( struct V_17 * V_18 ,
struct V_210 * V_179 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 8 * 6 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_20 = F_33 ( V_20 , & V_179 -> V_211 ) ;
V_20 = F_33 ( V_20 , & V_179 -> V_212 ) ;
V_20 = F_33 ( V_20 , & V_179 -> V_213 ) ;
V_20 = F_33 ( V_20 , & V_179 -> V_214 ) ;
V_20 = F_33 ( V_20 , & V_179 -> V_215 ) ;
F_33 ( V_20 , & V_179 -> V_216 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_210 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
error = F_108 ( V_18 , V_179 ) ;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_110 ( struct V_17 * V_18 ,
struct V_217 * V_179 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 * 7 + 8 + 8 + 4 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_179 -> V_218 = F_11 ( V_20 ++ ) ;
V_179 -> V_219 = F_11 ( V_20 ++ ) ;
V_179 -> V_220 = F_11 ( V_20 ++ ) ;
V_179 -> V_221 = F_11 ( V_20 ++ ) ;
V_179 -> V_222 = F_11 ( V_20 ++ ) ;
V_179 -> V_223 = F_11 ( V_20 ++ ) ;
V_179 -> V_224 = F_11 ( V_20 ++ ) ;
V_20 = F_33 ( V_20 , & V_179 -> V_225 ) ;
F_46 ( V_20 , & V_179 -> V_226 ) ;
V_179 -> V_227 = 0 ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_217 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
error = F_110 ( V_18 , V_179 ) ;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_112 ( struct V_17 * V_18 ,
struct V_228 * V_179 )
{
T_2 * V_20 ;
V_20 = F_9 ( V_18 , 4 * 6 ) ;
if ( F_10 ( V_20 == NULL ) )
goto V_22;
V_179 -> V_229 = F_11 ( V_20 ++ ) ;
V_179 -> V_230 = F_11 ( V_20 ) ;
return 0 ;
V_22:
F_3 ( V_23 , V_18 ) ;
return - V_24 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_228 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
error = F_112 ( V_18 , V_179 ) ;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_190 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_52 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_182;
error = F_32 ( V_18 , V_179 -> V_162 -> V_42 ) ;
V_111:
return error ;
V_182:
return F_89 ( V_48 ) ;
}
static inline int F_115 ( struct V_17 * V_18 ,
struct V_231 * V_179 )
{
struct V_232 * * V_233 ;
unsigned int * V_234 ;
T_4 V_34 ;
int error ;
error = F_49 ( V_18 , V_179 -> V_89 ) ;
if ( F_10 ( error ) )
goto V_111;
error = F_8 ( V_18 , & V_179 -> V_165 ) ;
if ( F_10 ( error ) )
goto V_111;
error = - V_235 ;
if ( V_179 -> V_165 & ~ ( V_166 | V_236 | V_167 | V_237 ) )
goto V_111;
V_34 = ( V_37 * ) V_18 -> V_20 - ( V_37 * ) V_18 -> V_38 -> V_39 ;
V_233 = NULL ;
if ( V_179 -> V_165 & V_166 )
V_233 = & V_179 -> V_176 ;
V_234 = NULL ;
if ( V_179 -> V_165 & V_236 )
V_234 = & V_179 -> V_238 ;
error = F_116 ( V_18 -> V_35 , V_34 , V_234 , V_233 ) ;
if ( F_10 ( error <= 0 ) )
goto V_111;
V_233 = NULL ;
if ( V_179 -> V_165 & V_167 )
V_233 = & V_179 -> V_177 ;
V_234 = NULL ;
if ( V_179 -> V_165 & V_237 )
V_234 = & V_179 -> V_239 ;
error = F_116 ( V_18 -> V_35 , V_34 + error , V_234 , V_233 ) ;
if ( F_10 ( error <= 0 ) )
return error ;
error = 0 ;
V_111:
return error ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_231 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_115 ( V_18 , V_179 ) ;
V_111:
return error ;
V_181:
return F_89 ( V_48 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_88 * V_179 )
{
enum V_47 V_48 ;
int error ;
error = F_34 ( V_18 , & V_48 ) ;
if ( F_10 ( error ) )
goto V_111;
if ( V_48 != V_180 )
goto V_181;
error = F_49 ( V_18 , V_179 ) ;
V_111:
return error ;
V_181:
return F_89 ( V_48 ) ;
}
