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
V_46 -> V_53 = F_8 ( V_20 ++ ) ;
V_46 -> V_54 = F_8 ( V_20 ++ ) ;
V_46 -> V_39 = F_8 ( V_20 ++ ) ;
V_46 -> V_55 . V_56 . V_57 = F_8 ( V_20 ++ ) ;
V_47 = F_8 ( V_20 ++ ) ;
V_46 -> V_47 = F_20 ( V_47 ) ;
if ( type == ( T_1 ) V_58 && V_47 == ( T_1 ) V_59 ) {
V_46 -> V_51 = ( V_46 -> V_51 & ~ V_60 ) | V_61 ;
V_46 -> V_47 = 0 ;
}
V_46 -> V_55 . V_56 . V_62 = F_8 ( V_20 ++ ) ;
V_46 -> V_63 . V_64 = F_8 ( V_20 ++ ) ;
V_46 -> V_63 . V_65 = 0 ;
V_46 -> V_66 = F_8 ( V_20 ++ ) ;
V_20 = F_18 ( V_20 , & V_46 -> V_67 ) ;
V_20 = F_18 ( V_20 , & V_46 -> V_68 ) ;
F_18 ( V_20 , & V_46 -> ctime ) ;
V_46 -> V_69 = F_21 ( & V_46 -> ctime ) ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static T_2 * F_22 ( T_2 * V_20 )
{
* V_20 ++ = F_16 ( V_70 ) ;
* V_20 ++ = F_16 ( V_70 ) ;
return V_20 ;
}
static void F_23 ( struct V_17 * V_18 , const struct V_71 * V_72 )
{
T_2 * V_20 ;
V_20 = F_13 ( V_18 , V_73 << 2 ) ;
if ( V_72 -> V_74 & V_75 )
* V_20 ++ = F_16 ( V_72 -> V_76 ) ;
else
* V_20 ++ = F_16 ( V_70 ) ;
if ( V_72 -> V_74 & V_77 )
* V_20 ++ = F_16 ( V_72 -> V_78 ) ;
else
* V_20 ++ = F_16 ( V_70 ) ;
if ( V_72 -> V_74 & V_79 )
* V_20 ++ = F_16 ( V_72 -> V_80 ) ;
else
* V_20 ++ = F_16 ( V_70 ) ;
if ( V_72 -> V_74 & V_81 )
* V_20 ++ = F_16 ( ( T_1 ) V_72 -> V_82 ) ;
else
* V_20 ++ = F_16 ( V_70 ) ;
if ( V_72 -> V_74 & V_83 )
V_20 = F_15 ( V_20 , & V_72 -> V_84 ) ;
else if ( V_72 -> V_74 & V_85 )
V_20 = F_17 ( V_20 , & V_72 -> V_84 ) ;
else
V_20 = F_22 ( V_20 ) ;
if ( V_72 -> V_74 & V_86 )
F_15 ( V_20 , & V_72 -> V_87 ) ;
else if ( V_72 -> V_74 & V_88 )
F_17 ( V_20 , & V_72 -> V_87 ) ;
else
F_22 ( V_20 ) ;
}
static void F_24 ( struct V_17 * V_18 ,
const char * V_89 , T_1 V_90 )
{
T_2 * V_20 ;
F_25 ( V_90 > V_91 ) ;
V_20 = F_13 ( V_18 , 4 + V_90 ) ;
F_26 ( V_20 , V_89 , V_90 ) ;
}
static int F_27 ( struct V_17 * V_18 ,
const char * * V_89 , T_1 * V_90 )
{
T_2 * V_20 ;
T_1 V_24 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_24 = F_8 ( V_20 ) ;
if ( V_24 > V_92 )
goto V_93;
V_20 = F_6 ( V_18 , V_24 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
* V_89 = ( const char * ) V_20 ;
* V_90 = V_24 ;
return 0 ;
V_93:
F_4 ( L_5 , V_24 ) ;
return - V_94 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static void F_28 ( struct V_17 * V_18 , struct V_3 * * V_4 , T_1 V_90 )
{
T_2 * V_20 ;
V_20 = F_13 ( V_18 , 4 ) ;
* V_20 = F_16 ( V_90 ) ;
F_29 ( V_18 , V_4 , 0 , V_90 ) ;
}
static int F_30 ( struct V_17 * V_18 )
{
T_1 V_90 , V_23 ;
T_2 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_90 = F_8 ( V_20 ) ;
if ( F_7 ( V_90 >= V_18 -> V_95 -> V_96 || V_90 > V_97 ) )
goto V_98;
V_23 = F_9 ( V_18 , V_90 ) ;
if ( F_7 ( V_90 > V_23 ) )
goto V_26;
F_31 ( V_18 -> V_95 , V_90 ) ;
return 0 ;
V_98:
F_4 ( L_6 , V_90 ) ;
return - V_94 ;
V_26:
F_4 ( L_7
L_8 , V_90 , V_23 ) ;
return - V_30 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static int F_32 ( struct V_17 * V_18 , struct V_45 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
error = F_19 ( V_18 , V_22 ) ;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static void F_34 ( struct V_17 * V_18 , const struct V_35 * V_36 ,
const char * V_89 , T_1 V_90 )
{
F_12 ( V_18 , V_36 ) ;
F_24 ( V_18 , V_89 , V_90 ) ;
}
static int F_35 ( struct V_17 * V_18 , struct V_101 * V_22 )
{
int error ;
error = F_14 ( V_18 , V_22 -> V_36 ) ;
if ( F_7 ( error ) )
goto V_27;
error = F_19 ( V_18 , V_22 -> V_46 ) ;
V_27:
return error ;
}
static int F_36 ( struct V_17 * V_18 , struct V_101 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
error = F_35 ( V_18 , V_22 ) ;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_35 * V_36 )
{
F_12 ( V_18 , V_36 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_102 * args )
{
F_12 ( V_18 , args -> V_36 ) ;
F_23 ( V_18 , args -> V_103 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_104 * args )
{
F_34 ( V_18 , args -> V_36 , args -> V_89 , args -> V_6 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_105 * args )
{
F_12 ( V_18 , args -> V_36 ) ;
F_1 ( V_2 , args -> V_4 , args -> V_106 ,
args -> V_107 , V_108 ) ;
}
static void F_41 ( struct V_17 * V_18 ,
const struct V_109 * args )
{
T_1 V_110 = args -> V_110 ;
T_1 V_24 = args -> V_24 ;
T_2 * V_20 ;
F_12 ( V_18 , args -> V_36 ) ;
V_20 = F_13 ( V_18 , 4 + 4 + 4 ) ;
* V_20 ++ = F_16 ( V_110 ) ;
* V_20 ++ = F_16 ( V_24 ) ;
* V_20 = F_16 ( V_24 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_109 * args )
{
F_41 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , args -> V_106 ,
args -> V_24 , V_111 ) ;
V_2 -> V_15 . V_112 |= V_113 ;
}
static void F_43 ( struct V_17 * V_18 ,
const struct V_114 * args )
{
T_1 V_110 = args -> V_110 ;
T_1 V_24 = args -> V_24 ;
T_2 * V_20 ;
F_12 ( V_18 , args -> V_36 ) ;
V_20 = F_13 ( V_18 , 4 + 4 + 4 + 4 ) ;
* V_20 ++ = F_16 ( V_110 ) ;
* V_20 ++ = F_16 ( V_110 ) ;
* V_20 ++ = F_16 ( V_24 ) ;
* V_20 = F_16 ( V_24 ) ;
F_29 ( V_18 , args -> V_4 , args -> V_106 , V_24 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_114 * args )
{
F_43 ( V_18 , args ) ;
V_18 -> V_95 -> V_112 |= V_115 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_116 * args )
{
F_34 ( V_18 , args -> V_36 , args -> V_89 , args -> V_6 ) ;
F_23 ( V_18 , args -> V_103 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_117 * args )
{
F_34 ( V_18 , args -> V_36 , args -> V_89 . V_89 , args -> V_89 . V_6 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_118 * args )
{
const struct V_119 * V_120 = args -> V_121 ;
const struct V_119 * V_122 = args -> V_123 ;
F_34 ( V_18 , args -> V_124 , V_120 -> V_89 , V_120 -> V_6 ) ;
F_34 ( V_18 , args -> V_125 , V_122 -> V_89 , V_122 -> V_6 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_126 * args )
{
F_12 ( V_18 , args -> V_127 ) ;
F_34 ( V_18 , args -> V_128 , args -> V_129 , args -> V_130 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_131 * args )
{
F_34 ( V_18 , args -> V_127 , args -> V_132 , args -> V_133 ) ;
F_28 ( V_18 , args -> V_4 , args -> V_134 ) ;
F_23 ( V_18 , args -> V_103 ) ;
}
static void F_50 ( struct V_17 * V_18 ,
const struct V_135 * args )
{
T_2 * V_20 ;
F_12 ( V_18 , args -> V_36 ) ;
V_20 = F_13 ( V_18 , 4 + 4 ) ;
* V_20 ++ = F_16 ( args -> V_136 ) ;
* V_20 = F_16 ( args -> V_24 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_135 * args )
{
F_50 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_24 , V_137 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_17 * V_18 ,
void * V_138 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_45 * V_22 )
{
return F_32 ( V_18 , V_22 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_101 * V_22 )
{
return F_36 ( V_18 , V_22 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_17 * V_18 , void * V_138 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
error = F_30 ( V_18 ) ;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_21 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
error = F_19 ( V_18 , V_22 -> V_46 ) ;
if ( F_7 ( error ) )
goto V_27;
error = F_5 ( V_18 , V_22 ) ;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_139 * V_22 )
{
V_22 -> V_140 -> V_141 = V_142 ;
return F_32 ( V_18 , V_22 -> V_46 ) ;
}
int F_58 ( struct V_17 * V_18 , struct V_143 * V_144 ,
int V_145 )
{
T_2 * V_20 ;
int error ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
if ( * V_20 ++ == V_146 ) {
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
if ( * V_20 ++ == V_146 )
return - V_147 ;
V_144 -> V_28 = 1 ;
return - V_148 ;
}
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_144 -> V_149 = F_8 ( V_20 ) ;
error = F_27 ( V_18 , & V_144 -> V_89 , & V_144 -> V_6 ) ;
if ( F_7 ( error ) )
return error ;
V_144 -> V_150 = V_144 -> V_136 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_144 -> V_136 = F_8 ( V_20 ) ;
V_144 -> V_151 = V_152 ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_147 ;
}
static int F_59 ( struct V_17 * V_18 )
{
return F_9 ( V_18 , V_18 -> V_95 -> V_96 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_17 * V_18 , void * V_138 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
error = F_59 ( V_18 ) ;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static int F_61 ( struct V_17 * V_18 , struct V_153 * V_22 )
{
T_2 * V_20 ;
V_20 = F_6 ( V_18 , V_154 << 2 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_25;
V_22 -> V_155 = F_8 ( V_20 ++ ) ;
V_22 -> V_156 = F_8 ( V_20 ++ ) ;
V_22 -> V_62 = F_8 ( V_20 ++ ) ;
V_22 -> V_157 = F_8 ( V_20 ++ ) ;
V_22 -> V_158 = F_8 ( V_20 ) ;
return 0 ;
V_25:
F_3 ( V_29 , V_18 ) ;
return - V_30 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_153 * V_22 )
{
enum V_31 V_32 ;
int error ;
error = F_10 ( V_18 , & V_32 ) ;
if ( F_7 ( error ) )
goto V_27;
if ( V_32 != V_99 )
goto V_100;
error = F_61 ( V_18 , V_22 ) ;
V_27:
return error ;
V_100:
return F_33 ( V_32 ) ;
}
static int F_33 ( enum V_31 V_32 )
{
int V_159 ;
for ( V_159 = 0 ; V_160 [ V_159 ] . V_161 != - 1 ; V_159 ++ ) {
if ( V_160 [ V_159 ] . V_161 == ( int ) V_32 )
return V_160 [ V_159 ] . V_162 ;
}
F_4 ( L_9 , V_32 ) ;
return V_160 [ V_159 ] . V_162 ;
}
