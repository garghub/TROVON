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
T_2 V_25 ;
T_3 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_24 = F_8 ( V_20 ) ;
V_25 = ( V_27 * ) V_18 -> V_20 - ( V_27 * ) V_18 -> V_28 -> V_29 ;
V_23 = V_18 -> V_30 -> V_6 - V_25 ;
if ( F_7 ( V_24 > V_23 ) )
goto V_31;
V_32:
F_9 ( V_18 , V_24 ) ;
V_22 -> V_33 = 0 ;
V_22 -> V_24 = V_24 ;
return V_24 ;
V_31:
F_4 ( L_3
L_4 , V_24 , V_23 ) ;
V_24 = V_23 ;
goto V_32;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static int F_10 ( struct V_17 * V_18 , enum V_36 * V_37 )
{
T_3 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
* V_37 = F_8 ( V_20 ) ;
return 0 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static T_3 * F_11 ( T_3 * V_20 , T_1 * type )
{
* type = F_8 ( V_20 ++ ) ;
if ( F_7 ( * type > V_38 ) )
* type = V_39 ;
return V_20 ;
}
static void F_12 ( struct V_17 * V_18 , const struct V_40 * V_41 )
{
T_3 * V_20 ;
F_13 ( V_41 -> V_42 != V_43 ) ;
V_20 = F_14 ( V_18 , V_43 ) ;
memcpy ( V_20 , V_41 -> V_44 , V_43 ) ;
}
static int F_15 ( struct V_17 * V_18 , struct V_40 * V_41 )
{
T_3 * V_20 ;
V_20 = F_6 ( V_18 , V_43 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_41 -> V_42 = V_43 ;
memcpy ( V_41 -> V_44 , V_20 , V_43 ) ;
return 0 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static T_3 * F_16 ( T_3 * V_20 , const struct V_45 * V_46 )
{
* V_20 ++ = F_17 ( V_46 -> V_47 ) ;
if ( V_46 -> V_48 != 0 )
* V_20 ++ = F_17 ( V_46 -> V_48 / V_49 ) ;
else
* V_20 ++ = F_17 ( 0 ) ;
return V_20 ;
}
static T_3 * F_18 ( T_3 * V_20 ,
const struct V_45 * V_46 )
{
* V_20 ++ = F_17 ( V_46 -> V_47 ) ;
* V_20 ++ = F_17 ( 1000000 ) ;
return V_20 ;
}
static T_3 * F_19 ( T_3 * V_20 , struct V_45 * V_46 )
{
V_46 -> V_47 = F_8 ( V_20 ++ ) ;
V_46 -> V_48 = F_8 ( V_20 ++ ) * V_49 ;
return V_20 ;
}
static int F_20 ( struct V_17 * V_18 , struct V_50 * V_51 )
{
T_1 V_52 , type ;
T_3 * V_20 ;
V_20 = F_6 ( V_18 , V_53 << 2 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_51 -> V_54 |= V_55 ;
V_20 = F_11 ( V_20 , & type ) ;
V_51 -> V_56 = F_8 ( V_20 ++ ) ;
V_51 -> V_57 = F_8 ( V_20 ++ ) ;
V_51 -> V_58 = F_8 ( V_20 ++ ) ;
V_51 -> V_59 = F_8 ( V_20 ++ ) ;
V_51 -> V_42 = F_8 ( V_20 ++ ) ;
V_51 -> V_60 . V_61 . V_62 = F_8 ( V_20 ++ ) ;
V_52 = F_8 ( V_20 ++ ) ;
V_51 -> V_52 = F_21 ( V_52 ) ;
if ( type == ( T_1 ) V_63 && V_52 == ( T_1 ) V_64 ) {
V_51 -> V_56 = ( V_51 -> V_56 & ~ V_65 ) | V_66 ;
V_51 -> V_52 = 0 ;
}
V_51 -> V_60 . V_61 . V_67 = F_8 ( V_20 ++ ) ;
V_51 -> V_68 . V_69 = F_8 ( V_20 ++ ) ;
V_51 -> V_68 . V_70 = 0 ;
V_51 -> V_71 = F_8 ( V_20 ++ ) ;
V_20 = F_19 ( V_20 , & V_51 -> V_72 ) ;
V_20 = F_19 ( V_20 , & V_51 -> V_73 ) ;
F_19 ( V_20 , & V_51 -> ctime ) ;
V_51 -> V_74 = F_22 ( & V_51 -> ctime ) ;
return 0 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static T_3 * F_23 ( T_3 * V_20 )
{
* V_20 ++ = F_17 ( V_75 ) ;
* V_20 ++ = F_17 ( V_75 ) ;
return V_20 ;
}
static void F_24 ( struct V_17 * V_18 , const struct V_76 * V_77 )
{
T_3 * V_20 ;
V_20 = F_14 ( V_18 , V_78 << 2 ) ;
if ( V_77 -> V_79 & V_80 )
* V_20 ++ = F_17 ( V_77 -> V_81 ) ;
else
* V_20 ++ = F_17 ( V_75 ) ;
if ( V_77 -> V_79 & V_82 )
* V_20 ++ = F_17 ( V_77 -> V_83 ) ;
else
* V_20 ++ = F_17 ( V_75 ) ;
if ( V_77 -> V_79 & V_84 )
* V_20 ++ = F_17 ( V_77 -> V_85 ) ;
else
* V_20 ++ = F_17 ( V_75 ) ;
if ( V_77 -> V_79 & V_86 )
* V_20 ++ = F_17 ( ( T_1 ) V_77 -> V_87 ) ;
else
* V_20 ++ = F_17 ( V_75 ) ;
if ( V_77 -> V_79 & V_88 )
V_20 = F_16 ( V_20 , & V_77 -> V_89 ) ;
else if ( V_77 -> V_79 & V_90 )
V_20 = F_18 ( V_20 , & V_77 -> V_89 ) ;
else
V_20 = F_23 ( V_20 ) ;
if ( V_77 -> V_79 & V_91 )
F_16 ( V_20 , & V_77 -> V_92 ) ;
else if ( V_77 -> V_79 & V_93 )
F_18 ( V_20 , & V_77 -> V_92 ) ;
else
F_23 ( V_20 ) ;
}
static void F_25 ( struct V_17 * V_18 ,
const char * V_94 , T_1 V_95 )
{
T_3 * V_20 ;
F_13 ( V_95 > V_96 ) ;
V_20 = F_14 ( V_18 , 4 + V_95 ) ;
F_26 ( V_20 , V_94 , V_95 ) ;
}
static int F_27 ( struct V_17 * V_18 ,
const char * * V_94 , T_1 * V_95 )
{
T_3 * V_20 ;
T_1 V_24 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_24 = F_8 ( V_20 ) ;
if ( V_24 > V_97 )
goto V_98;
V_20 = F_6 ( V_18 , V_24 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
* V_94 = ( const char * ) V_20 ;
* V_95 = V_24 ;
return 0 ;
V_98:
F_4 ( L_5 , V_24 ) ;
return - V_99 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static void F_28 ( struct V_17 * V_18 , struct V_3 * * V_4 , T_1 V_95 )
{
T_3 * V_20 ;
F_13 ( V_95 > V_100 ) ;
V_20 = F_14 ( V_18 , 4 ) ;
* V_20 = F_17 ( V_95 ) ;
F_29 ( V_18 , V_4 , 0 , V_95 ) ;
}
static int F_30 ( struct V_17 * V_18 )
{
T_1 V_95 , V_23 ;
T_2 V_25 ;
T_3 * V_20 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_95 = F_8 ( V_20 ) ;
if ( F_7 ( V_95 >= V_18 -> V_30 -> V_101 || V_95 > V_102 ) )
goto V_103;
V_25 = ( V_27 * ) V_18 -> V_20 - ( V_27 * ) V_18 -> V_28 -> V_29 ;
V_23 = V_18 -> V_30 -> V_6 - V_25 ;
if ( F_7 ( V_95 > V_23 ) )
goto V_31;
F_9 ( V_18 , V_95 ) ;
F_31 ( V_18 -> V_30 , V_95 ) ;
return 0 ;
V_103:
F_4 ( L_6 , V_95 ) ;
return - V_99 ;
V_31:
F_4 ( L_7
L_8 , V_95 , V_23 ) ;
return - V_35 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static int F_32 ( struct V_17 * V_18 , struct V_50 * V_22 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
error = F_20 ( V_18 , V_22 ) ;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static void F_34 ( struct V_17 * V_18 , const struct V_40 * V_41 ,
const char * V_94 , T_1 V_95 )
{
F_12 ( V_18 , V_41 ) ;
F_25 ( V_18 , V_94 , V_95 ) ;
}
static int F_35 ( struct V_17 * V_18 , struct V_106 * V_22 )
{
int error ;
error = F_15 ( V_18 , V_22 -> V_41 ) ;
if ( F_7 ( error ) )
goto V_32;
error = F_20 ( V_18 , V_22 -> V_51 ) ;
V_32:
return error ;
}
static int F_36 ( struct V_17 * V_18 , struct V_106 * V_22 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
error = F_35 ( V_18 , V_22 ) ;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_40 * V_41 )
{
F_12 ( V_18 , V_41 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_107 * args )
{
F_12 ( V_18 , args -> V_41 ) ;
F_24 ( V_18 , args -> V_108 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_109 * args )
{
F_34 ( V_18 , args -> V_41 , args -> V_94 , args -> V_6 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_110 * args )
{
F_12 ( V_18 , args -> V_41 ) ;
F_1 ( V_2 , args -> V_4 , args -> V_111 ,
args -> V_112 , V_113 ) ;
}
static void F_41 ( struct V_17 * V_18 ,
const struct V_114 * args )
{
T_1 V_115 = args -> V_115 ;
T_1 V_24 = args -> V_24 ;
T_3 * V_20 ;
F_12 ( V_18 , args -> V_41 ) ;
V_20 = F_14 ( V_18 , 4 + 4 + 4 ) ;
* V_20 ++ = F_17 ( V_115 ) ;
* V_20 ++ = F_17 ( V_24 ) ;
* V_20 = F_17 ( V_24 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_114 * args )
{
F_41 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , args -> V_111 ,
args -> V_24 , V_116 ) ;
V_2 -> V_15 . V_117 |= V_118 ;
}
static void F_43 ( struct V_17 * V_18 ,
const struct V_119 * args )
{
T_1 V_115 = args -> V_115 ;
T_1 V_24 = args -> V_24 ;
T_3 * V_20 ;
F_12 ( V_18 , args -> V_41 ) ;
V_20 = F_14 ( V_18 , 4 + 4 + 4 + 4 ) ;
* V_20 ++ = F_17 ( V_115 ) ;
* V_20 ++ = F_17 ( V_115 ) ;
* V_20 ++ = F_17 ( V_24 ) ;
* V_20 = F_17 ( V_24 ) ;
F_29 ( V_18 , args -> V_4 , args -> V_111 , V_24 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_119 * args )
{
F_43 ( V_18 , args ) ;
V_18 -> V_30 -> V_117 |= V_120 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_121 * args )
{
F_34 ( V_18 , args -> V_41 , args -> V_94 , args -> V_6 ) ;
F_24 ( V_18 , args -> V_108 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_122 * args )
{
F_34 ( V_18 , args -> V_41 , args -> V_94 . V_94 , args -> V_94 . V_6 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_123 * args )
{
const struct V_124 * V_125 = args -> V_126 ;
const struct V_124 * V_127 = args -> V_128 ;
F_34 ( V_18 , args -> V_129 , V_125 -> V_94 , V_125 -> V_6 ) ;
F_34 ( V_18 , args -> V_130 , V_127 -> V_94 , V_127 -> V_6 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_131 * args )
{
F_12 ( V_18 , args -> V_132 ) ;
F_34 ( V_18 , args -> V_133 , args -> V_134 , args -> V_135 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_136 * args )
{
F_34 ( V_18 , args -> V_132 , args -> V_137 , args -> V_138 ) ;
F_28 ( V_18 , args -> V_4 , args -> V_139 ) ;
F_24 ( V_18 , args -> V_108 ) ;
}
static void F_50 ( struct V_17 * V_18 ,
const struct V_140 * args )
{
T_3 * V_20 ;
F_12 ( V_18 , args -> V_41 ) ;
V_20 = F_14 ( V_18 , 4 + 4 ) ;
* V_20 ++ = F_17 ( args -> V_141 ) ;
* V_20 = F_17 ( args -> V_24 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_140 * args )
{
F_50 ( V_18 , args ) ;
F_1 ( V_2 , args -> V_4 , 0 ,
args -> V_24 , V_142 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_17 * V_18 ,
void * V_143 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_50 * V_22 )
{
return F_32 ( V_18 , V_22 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_106 * V_22 )
{
return F_36 ( V_18 , V_22 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_17 * V_18 , void * V_143 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
error = F_30 ( V_18 ) ;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_21 * V_22 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
error = F_20 ( V_18 , V_22 -> V_51 ) ;
if ( F_7 ( error ) )
goto V_32;
error = F_5 ( V_18 , V_22 ) ;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_144 * V_22 )
{
V_22 -> V_145 -> V_146 = V_147 ;
return F_32 ( V_18 , V_22 -> V_51 ) ;
}
int F_58 ( struct V_17 * V_18 , struct V_148 * V_149 ,
int V_150 )
{
T_3 * V_20 ;
int error ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
if ( * V_20 ++ == V_151 ) {
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
if ( * V_20 ++ == V_151 )
return - V_152 ;
V_149 -> V_33 = 1 ;
return - V_153 ;
}
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_149 -> V_154 = F_8 ( V_20 ) ;
error = F_27 ( V_18 , & V_149 -> V_94 , & V_149 -> V_6 ) ;
if ( F_7 ( error ) )
return error ;
V_149 -> V_155 = V_149 -> V_141 ;
V_20 = F_6 ( V_18 , 4 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_149 -> V_141 = F_8 ( V_20 ) ;
V_149 -> V_156 = V_157 ;
return 0 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_152 ;
}
static int F_59 ( struct V_17 * V_18 )
{
T_1 V_23 , V_112 ;
T_2 V_25 ;
V_112 = V_18 -> V_30 -> V_101 ;
V_25 = ( V_27 * ) V_18 -> V_20 - ( V_27 * ) V_18 -> V_28 -> V_29 ;
V_23 = V_18 -> V_30 -> V_6 - V_25 ;
if ( F_7 ( V_112 > V_23 ) )
goto V_31;
V_32:
F_9 ( V_18 , V_112 ) ;
return V_112 ;
V_31:
F_4 ( L_9
L_10 , V_112 , V_23 ) ;
V_112 = V_23 ;
goto V_32;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_17 * V_18 , void * V_143 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
error = F_59 ( V_18 ) ;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static int F_61 ( struct V_17 * V_18 , struct V_158 * V_22 )
{
T_3 * V_20 ;
V_20 = F_6 ( V_18 , V_159 << 2 ) ;
if ( F_7 ( V_20 == NULL ) )
goto V_26;
V_22 -> V_160 = F_8 ( V_20 ++ ) ;
V_22 -> V_161 = F_8 ( V_20 ++ ) ;
V_22 -> V_67 = F_8 ( V_20 ++ ) ;
V_22 -> V_162 = F_8 ( V_20 ++ ) ;
V_22 -> V_163 = F_8 ( V_20 ) ;
return 0 ;
V_26:
F_3 ( V_34 , V_18 ) ;
return - V_35 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_158 * V_22 )
{
enum V_36 V_37 ;
int error ;
error = F_10 ( V_18 , & V_37 ) ;
if ( F_7 ( error ) )
goto V_32;
if ( V_37 != V_104 )
goto V_105;
error = F_61 ( V_18 , V_22 ) ;
V_32:
return error ;
V_105:
return F_33 ( V_37 ) ;
}
static int F_33 ( enum V_36 V_37 )
{
int V_164 ;
for ( V_164 = 0 ; V_165 [ V_164 ] . V_166 != - 1 ; V_164 ++ ) {
if ( V_165 [ V_164 ] . V_166 == ( int ) V_37 )
return V_165 [ V_164 ] . V_167 ;
}
F_4 ( L_11 , V_37 ) ;
return V_165 [ V_164 ] . V_167 ;
}
