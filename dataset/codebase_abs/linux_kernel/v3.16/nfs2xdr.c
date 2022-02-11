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
static int F_5 ( struct V_17 * V_18 , struct V_21 * V_22 )
{
T_1 V_23 , V_24 ;
T_2 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_24 = F_8 ( V_20 ) ;
V_23 = F_9 ( V_18 , V_24 ) ;
if ( F_7 ( V_24 > V_23 ) )
goto V_26;
V_27:
V_22 -> V_28 = 0 ;
V_22 -> V_24 = V_24 ;
return V_24 ;
V_26:
F_4 ( L_3
L_4 , V_24 , V_23 ) ;
V_24 = V_23 ;
goto V_27;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static int F_10 ( struct V_17 * V_18 , enum V_31 * V_32 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
* V_32 = F_8 ( V_20 ) ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static T_2 * F_11 ( T_2 * V_20 , T_1 * type )
{
* type = F_8 ( V_20 ++ ) ;
if ( F_7 ( * type > V_33 ) )
* type = V_34 ;
return V_20 ;
}
static void F_12 ( struct V_17 * V_18 , const struct V_35 * V_36 )
{
T_2 * V_20 ;
V_20 = F_13 ( V_18 , V_37 ) ;
memcpy ( V_20 , V_36 -> V_38 , V_37 ) ;
}
static int F_14 ( struct V_17 * V_18 , struct V_35 * V_36 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , V_37 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_36 -> V_39 = V_37 ;
memcpy ( V_36 -> V_38 , V_20 , V_37 ) ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static T_2 * F_15 ( T_2 * V_20 , const struct V_40 * V_41 )
{
* V_20 ++ = F_16 ( V_41 -> V_42 ) ;
if ( V_41 -> V_43 != 0 )
* V_20 ++ = F_16 ( V_41 -> V_43 / V_44 ) ;
else
* V_20 ++ = F_16 ( 0 ) ;
return V_20 ;
}
static T_2 * F_17 ( T_2 * V_20 ,
const struct V_40 * V_41 )
{
* V_20 ++ = F_16 ( V_41 -> V_42 ) ;
* V_20 ++ = F_16 ( 1000000 ) ;
return V_20 ;
}
static T_2 * F_18 ( T_2 * V_20 , struct V_40 * V_41 )
{
V_41 -> V_42 = F_8 ( V_20 ++ ) ;
V_41 -> V_43 = F_8 ( V_20 ++ ) * V_44 ;
return V_20 ;
}
static int F_19 ( struct V_17 * V_18 , struct V_45 * V_46 )
{
T_1 V_47 , type ;
T_2 * V_20 ;
V_20 = F_6 ( V_18 , V_48 << 2 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_46 -> V_49 |= V_50 ;
V_20 = F_11 ( V_20 , & type ) ;
V_46 -> V_51 = F_8 ( V_20 ++ ) ;
V_46 -> V_52 = F_8 ( V_20 ++ ) ;
V_46 -> V_53 = F_20 ( & V_54 , F_8 ( V_20 ++ ) ) ;
if ( ! F_21 ( V_46 -> V_53 ) )
goto V_55;
V_46 -> V_56 = F_22 ( & V_54 , F_8 ( V_20 ++ ) ) ;
if ( ! F_23 ( V_46 -> V_56 ) )
goto V_57;
V_46 -> V_39 = F_8 ( V_20 ++ ) ;
V_46 -> V_58 . V_59 . V_60 = F_8 ( V_20 ++ ) ;
V_47 = F_8 ( V_20 ++ ) ;
V_46 -> V_47 = F_24 ( V_47 ) ;
if ( type == ( T_1 ) V_61 && V_47 == ( T_1 ) V_62 ) {
V_46 -> V_51 = ( V_46 -> V_51 & ~ V_63 ) | V_64 ;
V_46 -> V_47 = 0 ;
}
V_46 -> V_58 . V_59 . V_65 = F_8 ( V_20 ++ ) ;
V_46 -> V_66 . V_67 = F_8 ( V_20 ++ ) ;
V_46 -> V_66 . V_68 = 0 ;
V_46 -> V_69 = F_8 ( V_20 ++ ) ;
V_20 = F_18 ( V_20 , & V_46 -> V_70 ) ;
V_20 = F_18 ( V_20 , & V_46 -> V_71 ) ;
F_18 ( V_20 , & V_46 -> ctime ) ;
V_46 -> V_72 = F_25 ( & V_46 -> ctime ) ;
return 0 ;
V_55:
F_4 ( L_5 ) ;
return - V_73 ;
V_57:
F_4 ( L_6 ) ;
return - V_73 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static T_2 * F_26 ( T_2 * V_20 )
{
* V_20 ++ = F_16 ( V_74 ) ;
* V_20 ++ = F_16 ( V_74 ) ;
return V_20 ;
}
static void F_27 ( struct V_17 * V_18 , const struct V_75 * V_76 )
{
T_2 * V_20 ;
V_20 = F_13 ( V_18 , V_77 << 2 ) ;
if ( V_76 -> V_78 & V_79 )
* V_20 ++ = F_16 ( V_76 -> V_80 ) ;
else
* V_20 ++ = F_16 ( V_74 ) ;
if ( V_76 -> V_78 & V_81 )
* V_20 ++ = F_16 ( F_28 ( & V_54 , V_76 -> V_82 ) ) ;
else
* V_20 ++ = F_16 ( V_74 ) ;
if ( V_76 -> V_78 & V_83 )
* V_20 ++ = F_16 ( F_29 ( & V_54 , V_76 -> V_84 ) ) ;
else
* V_20 ++ = F_16 ( V_74 ) ;
if ( V_76 -> V_78 & V_85 )
* V_20 ++ = F_16 ( ( T_1 ) V_76 -> V_86 ) ;
else
* V_20 ++ = F_16 ( V_74 ) ;
if ( V_76 -> V_78 & V_87 )
V_20 = F_15 ( V_20 , & V_76 -> V_88 ) ;
else if ( V_76 -> V_78 & V_89 )
V_20 = F_17 ( V_20 , & V_76 -> V_88 ) ;
else
V_20 = F_26 ( V_20 ) ;
if ( V_76 -> V_78 & V_90 )
F_15 ( V_20 , & V_76 -> V_91 ) ;
else if ( V_76 -> V_78 & V_92 )
F_17 ( V_20 , & V_76 -> V_91 ) ;
else
F_26 ( V_20 ) ;
}
static void F_30 ( struct V_17 * V_18 ,
const char * V_93 , T_1 V_94 )
{
T_2 * V_20 ;
F_31 ( V_94 > V_95 ) ;
V_20 = F_13 ( V_18 , 4 + V_94 ) ;
F_32 ( V_20 , V_93 , V_94 ) ;
}
static int F_33 ( struct V_17 * V_18 ,
const char * * V_93 , T_1 * V_94 )
{
T_2 * V_20 ;
T_1 V_24 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_24 = F_8 ( V_20 ) ;
if ( V_24 > V_96 )
goto V_97;
V_20 = F_6 ( V_18 , V_24 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
* V_93 = ( const char * ) V_20 ;
* V_94 = V_24 ;
return 0 ;
V_97:
F_4 ( L_7 , V_24 ) ;
return - V_98 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static void F_34 ( struct V_17 * V_18 , struct V_3 * * V_4 , T_1 V_94 )
{
T_2 * V_20 ;
V_20 = F_13 ( V_18 , 4 ) ;
* V_20 = F_16 ( V_94 ) ;
F_35 ( V_18 , V_4 , 0 , V_94 ) ;
}
static int F_36 ( struct V_17 * V_18 )
{
T_1 V_94 , V_23 ;
T_2 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_94 = F_8 ( V_20 ) ;
if ( F_7 ( V_94 >= V_18 -> V_99 -> V_100 || V_94 > V_101 ) )
goto V_102;
V_23 = F_9 ( V_18 , V_94 ) ;
if ( F_7 ( V_94 > V_23 ) )
goto V_26;
F_37 ( V_18 -> V_99 , V_94 ) ;
return 0 ;
V_102:
F_4 ( L_8 , V_94 ) ;
return - V_98 ;
V_26:
F_4 ( L_9
L_10 , V_94 , V_23 ) ;
return - V_30 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static int F_38 ( struct V_17 * V_18 , struct V_45 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
error = F_19 ( V_18 , V_22 ) ;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static void F_40 ( struct V_17 * V_18 , const struct V_35 * V_36 ,
const char * V_93 , T_1 V_94 )
{
F_12 ( V_18 , V_36 ) ;
F_30 ( V_18 , V_93 , V_94 ) ;
}
static int F_41 ( struct V_17 * V_18 , struct V_105 * V_22 )
{
int error ;
error = F_14 ( V_18 , V_22 -> V_36 ) ;
if ( F_7 ( error ) )
goto V_27;
error = F_19 ( V_18 , V_22 -> V_46 ) ;
V_27:
return error ;
}
static int F_42 ( struct V_17 * V_18 , struct V_105 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
error = F_41 ( V_18 , V_22 ) ;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_35 * V_36 )
{
F_12 ( V_18 , V_36 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_106 * args )
{
F_12 ( V_18 , args -> V_36 ) ;
F_27 ( V_18 , args -> V_107 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_108 * args )
{
F_40 ( V_18 , args -> V_36 , args -> V_93 , args -> V_6 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_109 * args )
{
F_12 ( V_18 , args -> V_36 ) ;
F_1 ( V_2 , args -> V_4 , args -> V_110 ,
args -> V_111 , V_112 ) ;
}
static void F_47 ( struct V_17 * V_18 ,
const struct V_113 * args )
{
T_1 V_114 = args -> V_114 ;
T_1 V_24 = args -> V_24 ;
T_2 * V_20 ;
F_12 ( V_18 , args -> V_36 ) ;
V_20 = F_13 ( V_18 , 4 + 4 + 4 ) ;
* V_20 ++ = F_16 ( V_114 ) ;
* V_20 ++ = F_16 ( V_24 ) ;
* V_20 = F_16 ( V_24 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_113 * args )
{
F_47 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , args -> V_110 ,
args -> V_24 , V_115 ) ;
V_2 -> V_15 . V_116 |= V_117 ;
}
static void F_49 ( struct V_17 * V_18 ,
const struct V_113 * args )
{
T_1 V_114 = args -> V_114 ;
T_1 V_24 = args -> V_24 ;
T_2 * V_20 ;
F_12 ( V_18 , args -> V_36 ) ;
V_20 = F_13 ( V_18 , 4 + 4 + 4 + 4 ) ;
* V_20 ++ = F_16 ( V_114 ) ;
* V_20 ++ = F_16 ( V_114 ) ;
* V_20 ++ = F_16 ( V_24 ) ;
* V_20 = F_16 ( V_24 ) ;
F_35 ( V_18 , args -> V_4 , args -> V_110 , V_24 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_113 * args )
{
F_49 ( V_18 , args ) ;
V_18 -> V_99 -> V_116 |= V_118 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_119 * args )
{
F_40 ( V_18 , args -> V_36 , args -> V_93 , args -> V_6 ) ;
F_27 ( V_18 , args -> V_107 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_120 * args )
{
F_40 ( V_18 , args -> V_36 , args -> V_93 . V_93 , args -> V_93 . V_6 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_121 * args )
{
const struct V_122 * V_123 = args -> V_124 ;
const struct V_122 * V_125 = args -> V_126 ;
F_40 ( V_18 , args -> V_127 , V_123 -> V_93 , V_123 -> V_6 ) ;
F_40 ( V_18 , args -> V_128 , V_125 -> V_93 , V_125 -> V_6 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_129 * args )
{
F_12 ( V_18 , args -> V_130 ) ;
F_40 ( V_18 , args -> V_131 , args -> V_132 , args -> V_133 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_134 * args )
{
F_40 ( V_18 , args -> V_130 , args -> V_135 , args -> V_136 ) ;
F_34 ( V_18 , args -> V_4 , args -> V_137 ) ;
F_27 ( V_18 , args -> V_107 ) ;
}
static void F_56 ( struct V_17 * V_18 ,
const struct V_138 * args )
{
T_2 * V_20 ;
F_12 ( V_18 , args -> V_36 ) ;
V_20 = F_13 ( V_18 , 4 + 4 ) ;
* V_20 ++ = F_16 ( args -> V_139 ) ;
* V_20 = F_16 ( args -> V_24 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_138 * args )
{
F_56 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_24 , V_140 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_17 * V_18 ,
void * V_141 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_45 * V_22 )
{
return F_38 ( V_18 , V_22 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_105 * V_22 )
{
return F_42 ( V_18 , V_22 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_17 * V_18 , void * V_141 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
error = F_36 ( V_18 ) ;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_21 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
error = F_19 ( V_18 , V_22 -> V_46 ) ;
if ( F_7 ( error ) )
goto V_27;
error = F_5 ( V_18 , V_22 ) ;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_21 * V_22 )
{
V_22 -> V_142 -> V_143 = V_144 ;
return F_38 ( V_18 , V_22 -> V_46 ) ;
}
int F_64 ( struct V_17 * V_18 , struct V_145 * V_146 ,
int V_147 )
{
T_2 * V_20 ;
int error ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
if ( * V_20 ++ == V_148 ) {
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
if ( * V_20 ++ == V_148 )
return - V_149 ;
V_146 -> V_28 = 1 ;
return - V_150 ;
}
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_146 -> V_151 = F_8 ( V_20 ) ;
error = F_33 ( V_18 , & V_146 -> V_93 , & V_146 -> V_6 ) ;
if ( F_7 ( error ) )
return error ;
V_146 -> V_152 = V_146 -> V_139 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_146 -> V_139 = F_8 ( V_20 ) ;
V_146 -> V_153 = V_154 ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_149 ;
}
static int F_65 ( struct V_17 * V_18 )
{
return F_9 ( V_18 , V_18 -> V_99 -> V_100 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_17 * V_18 , void * V_141 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
error = F_65 ( V_18 ) ;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static int F_67 ( struct V_17 * V_18 , struct V_155 * V_22 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , V_156 << 2 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_22 -> V_157 = F_8 ( V_20 ++ ) ;
V_22 -> V_158 = F_8 ( V_20 ++ ) ;
V_22 -> V_65 = F_8 ( V_20 ++ ) ;
V_22 -> V_159 = F_8 ( V_20 ++ ) ;
V_22 -> V_160 = F_8 ( V_20 ) ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_155 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_103 )
goto V_104;
error = F_67 ( V_18 , V_22 ) ;
V_27:
return error ;
V_104:
return F_39 ( V_32 ) ;
}
static int F_39 ( enum V_31 V_32 )
{
int V_161 ;
for ( V_161 = 0 ; V_162 [ V_161 ] . V_163 != - 1 ; V_161 ++ ) {
if ( V_162 [ V_161 ] . V_163 == ( int ) V_32 )
return V_162 [ V_161 ] . V_164 ;
}
F_4 ( L_11 , V_32 ) ;
return V_162 [ V_161 ] . V_164 ;
}
