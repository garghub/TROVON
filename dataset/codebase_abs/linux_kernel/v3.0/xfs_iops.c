void
F_1 (
T_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
V_1 -> V_3 . V_4 . V_5 = ( V_6 ) V_2 -> V_7 . V_8 ;
V_1 -> V_3 . V_4 . V_9 = ( V_6 ) V_2 -> V_7 . V_10 ;
V_1 -> V_3 . V_11 . V_5 = ( V_6 ) V_2 -> V_12 . V_8 ;
V_1 -> V_3 . V_11 . V_9 = ( V_6 ) V_2 -> V_12 . V_10 ;
V_1 -> V_3 . V_13 . V_5 = ( V_6 ) V_2 -> V_14 . V_8 ;
V_1 -> V_3 . V_13 . V_9 = ( V_6 ) V_2 -> V_14 . V_10 ;
}
void
F_3 (
T_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
if ( ! ( V_2 -> V_15 & ( V_16 | V_17 ) ) )
F_4 ( V_2 ) ;
}
void
F_5 (
T_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
if ( ! ( V_2 -> V_15 & ( V_16 | V_17 ) ) )
F_6 ( V_2 ) ;
}
STATIC int
F_7 (
struct V_2 * V_2 ,
struct V_2 * V_18 ,
const struct V_19 * V_19 )
{
struct V_20 * V_1 = F_8 ( V_2 ) ;
T_2 V_21 ;
void * V_22 ;
unsigned char * V_23 ;
int error ;
error = F_9 ( V_2 , V_18 , V_19 , ( char * * ) & V_23 ,
& V_22 , & V_21 ) ;
if ( error ) {
if ( error == - V_24 )
return 0 ;
return - error ;
}
error = F_10 ( V_1 , V_23 , V_22 , V_21 , V_25 ) ;
F_11 ( V_23 ) ;
F_11 ( V_22 ) ;
return error ;
}
static void
F_12 (
struct V_26 * V_27 ,
struct V_28 * V_28 )
{
V_27 -> V_23 = V_28 -> V_29 . V_23 ;
V_27 -> V_30 = V_28 -> V_29 . V_30 ;
}
STATIC void
F_13 (
struct V_2 * V_18 ,
struct V_2 * V_2 ,
struct V_28 * V_28 )
{
struct V_26 V_31 ;
F_12 ( & V_31 , V_28 ) ;
F_14 ( F_8 ( V_18 ) , & V_31 , F_8 ( V_2 ) ) ;
F_15 ( V_2 ) ;
}
STATIC int
F_16 (
struct V_2 * V_18 ,
struct V_28 * V_28 ,
int V_32 ,
T_3 V_33 )
{
struct V_2 * V_2 ;
struct V_20 * V_1 = NULL ;
struct V_34 * V_35 = NULL ;
struct V_26 V_23 ;
int error ;
if ( F_17 ( V_32 ) || F_18 ( V_32 ) ) {
if ( F_19 ( ! F_20 ( V_33 ) || F_21 ( V_33 ) & ~ 0x1ff ) )
return - V_36 ;
V_33 = F_22 ( V_33 ) ;
} else {
V_33 = 0 ;
}
if ( F_23 ( V_18 ) ) {
V_35 = F_24 ( V_18 , V_37 ) ;
if ( F_25 ( V_35 ) )
return F_26 ( V_35 ) ;
if ( ! V_35 )
V_32 &= ~ F_27 () ;
}
F_12 ( & V_23 , V_28 ) ;
error = F_28 ( F_8 ( V_18 ) , & V_23 , V_32 , V_33 , & V_1 ) ;
if ( F_19 ( error ) )
goto V_38;
V_2 = F_2 ( V_1 ) ;
error = F_7 ( V_2 , V_18 , & V_28 -> V_29 ) ;
if ( F_19 ( error ) )
goto V_39;
if ( V_35 ) {
error = - F_29 ( V_2 , V_35 ) ;
if ( F_19 ( error ) )
goto V_39;
F_30 ( V_35 ) ;
}
F_31 ( V_28 , V_2 ) ;
return - error ;
V_39:
F_13 ( V_18 , V_2 , V_28 ) ;
V_38:
F_30 ( V_35 ) ;
return - error ;
}
STATIC int
F_32 (
struct V_2 * V_18 ,
struct V_28 * V_28 ,
int V_32 ,
struct V_40 * V_41 )
{
return F_16 ( V_18 , V_28 , V_32 , 0 ) ;
}
STATIC int
F_33 (
struct V_2 * V_18 ,
struct V_28 * V_28 ,
int V_32 )
{
return F_16 ( V_18 , V_28 , V_32 | V_42 , 0 ) ;
}
STATIC struct V_28 *
F_34 (
struct V_2 * V_18 ,
struct V_28 * V_28 ,
struct V_40 * V_41 )
{
struct V_20 * V_43 ;
struct V_26 V_23 ;
int error ;
if ( V_28 -> V_29 . V_30 >= V_44 )
return F_35 ( - V_45 ) ;
F_12 ( & V_23 , V_28 ) ;
error = F_36 ( F_8 ( V_18 ) , & V_23 , & V_43 , NULL ) ;
if ( F_19 ( error ) ) {
if ( F_19 ( error != V_46 ) )
return F_35 ( - error ) ;
F_37 ( V_28 , NULL ) ;
return NULL ;
}
return F_38 ( F_2 ( V_43 ) , V_28 ) ;
}
STATIC struct V_28 *
F_39 (
struct V_2 * V_18 ,
struct V_28 * V_28 ,
struct V_40 * V_41 )
{
struct V_20 * V_1 ;
struct V_26 V_47 ;
struct V_26 V_48 ;
struct V_19 V_49 ;
int error ;
if ( V_28 -> V_29 . V_30 >= V_44 )
return F_35 ( - V_45 ) ;
F_12 ( & V_47 , V_28 ) ;
error = F_36 ( F_8 ( V_18 ) , & V_47 , & V_1 , & V_48 ) ;
if ( F_19 ( error ) ) {
if ( F_19 ( error != V_46 ) )
return F_35 ( - error ) ;
return NULL ;
}
if ( ! V_48 . V_23 )
return F_38 ( F_2 ( V_1 ) , V_28 ) ;
V_49 . V_23 = V_48 . V_23 ;
V_49 . V_30 = V_48 . V_30 ;
V_28 = F_40 ( V_28 , F_2 ( V_1 ) , & V_49 ) ;
F_41 ( V_48 . V_23 ) ;
return V_28 ;
}
STATIC int
F_42 (
struct V_28 * V_50 ,
struct V_2 * V_18 ,
struct V_28 * V_28 )
{
struct V_2 * V_2 = V_50 -> V_51 ;
struct V_26 V_23 ;
int error ;
F_12 ( & V_23 , V_28 ) ;
error = F_43 ( F_8 ( V_18 ) , F_8 ( V_2 ) , & V_23 ) ;
if ( F_19 ( error ) )
return - error ;
F_44 ( V_2 ) ;
F_31 ( V_28 , V_2 ) ;
return 0 ;
}
STATIC int
F_45 (
struct V_2 * V_18 ,
struct V_28 * V_28 )
{
struct V_26 V_23 ;
int error ;
F_12 ( & V_23 , V_28 ) ;
error = - F_14 ( F_8 ( V_18 ) , & V_23 , F_8 ( V_28 -> V_51 ) ) ;
if ( error )
return error ;
if ( F_46 ( & F_47 ( V_18 -> V_52 ) -> V_53 ) )
F_48 ( V_28 ) ;
return 0 ;
}
STATIC int
F_49 (
struct V_2 * V_18 ,
struct V_28 * V_28 ,
const char * V_54 )
{
struct V_2 * V_2 ;
struct V_20 * V_43 = NULL ;
struct V_26 V_23 ;
int error ;
T_4 V_32 ;
V_32 = V_55 |
( V_56 ? 0777 & ~ F_27 () : V_57 ) ;
F_12 ( & V_23 , V_28 ) ;
error = F_50 ( F_8 ( V_18 ) , & V_23 , V_54 , V_32 , & V_43 ) ;
if ( F_19 ( error ) )
goto V_58;
V_2 = F_2 ( V_43 ) ;
error = F_7 ( V_2 , V_18 , & V_28 -> V_29 ) ;
if ( F_19 ( error ) )
goto V_39;
F_31 ( V_28 , V_2 ) ;
return 0 ;
V_39:
F_13 ( V_18 , V_2 , V_28 ) ;
V_58:
return - error ;
}
STATIC int
F_51 (
struct V_2 * V_59 ,
struct V_28 * V_60 ,
struct V_2 * V_61 ,
struct V_28 * V_62 )
{
struct V_2 * V_63 = V_62 -> V_51 ;
struct V_26 V_64 ;
struct V_26 V_65 ;
F_12 ( & V_64 , V_60 ) ;
F_12 ( & V_65 , V_62 ) ;
return - F_52 ( F_8 ( V_59 ) , & V_64 , F_8 ( V_60 -> V_51 ) ,
F_8 ( V_61 ) , & V_65 , V_63 ?
F_8 ( V_63 ) : NULL ) ;
}
STATIC void *
F_53 (
struct V_28 * V_28 ,
struct V_40 * V_41 )
{
char * V_66 ;
int error = - V_67 ;
V_66 = F_54 ( V_68 + 1 , V_69 ) ;
if ( ! V_66 )
goto V_70;
error = - F_55 ( F_8 ( V_28 -> V_51 ) , V_66 ) ;
if ( F_19 ( error ) )
goto V_71;
F_56 ( V_41 , V_66 ) ;
return NULL ;
V_71:
F_11 ( V_66 ) ;
V_70:
F_56 ( V_41 , F_35 ( error ) ) ;
return NULL ;
}
STATIC void
F_57 (
struct V_28 * V_28 ,
struct V_40 * V_41 ,
void * V_72 )
{
char * V_73 = F_58 ( V_41 ) ;
if ( ! F_25 ( V_73 ) )
F_11 ( V_73 ) ;
}
STATIC int
F_59 (
struct V_74 * V_75 ,
struct V_28 * V_28 ,
struct V_76 * V_77 )
{
struct V_2 * V_2 = V_28 -> V_51 ;
struct V_20 * V_1 = F_8 ( V_2 ) ;
struct V_78 * V_79 = V_1 -> V_80 ;
F_60 ( V_1 ) ;
if ( F_61 ( V_79 ) )
return F_62 ( V_81 ) ;
V_77 -> V_82 = F_63 ( V_1 ) ;
V_77 -> V_83 = V_2 -> V_52 -> V_84 ;
V_77 -> V_32 = V_1 -> V_3 . V_85 ;
V_77 -> V_86 = V_1 -> V_3 . V_87 ;
V_77 -> V_88 = V_1 -> V_3 . V_89 ;
V_77 -> V_90 = V_1 -> V_3 . V_91 ;
V_77 -> V_92 = V_1 -> V_93 ;
V_77 -> V_94 = V_2 -> V_7 ;
V_77 -> V_95 = V_2 -> V_14 ;
V_77 -> ctime = V_2 -> V_12 ;
V_77 -> V_96 =
F_64 ( V_79 , V_1 -> V_3 . V_97 + V_1 -> V_98 ) ;
switch ( V_2 -> V_99 & V_100 ) {
case V_101 :
case V_102 :
V_77 -> V_103 = V_104 ;
V_77 -> V_33 = F_65 ( F_66 ( V_1 -> V_105 . V_106 . V_107 ) & 0x1ff ,
F_67 ( V_1 -> V_105 . V_106 . V_107 ) ) ;
break;
default:
if ( F_68 ( V_1 ) ) {
V_77 -> V_103 =
F_69 ( V_1 ) << V_79 -> V_53 . V_108 ;
} else
V_77 -> V_103 = F_70 ( V_79 ) ;
V_77 -> V_33 = 0 ;
break;
}
return 0 ;
}
STATIC int
F_71 (
struct V_28 * V_28 ,
struct V_109 * V_109 )
{
return - F_72 ( F_8 ( V_28 -> V_51 ) , V_109 , 0 ) ;
}
STATIC int
F_73 (
void * * V_110 ,
struct V_111 * V_112 ,
int * V_113 )
{
int error ;
struct V_114 * V_115 = * V_110 ;
T_5 V_116 = 0 ;
T_6 V_117 , V_118 , V_21 ;
if ( V_112 -> V_119 == - 1LL )
return 0 ;
V_117 = F_74 ( V_112 -> V_120 ) ;
V_118 = F_74 ( V_112 -> V_119 ) ;
V_21 = F_74 ( V_112 -> V_121 ) ;
if ( V_112 -> V_122 & V_123 )
V_116 |= V_124 ;
else if ( V_112 -> V_122 & V_125 ) {
V_116 |= V_126 ;
V_118 = 0 ;
}
if ( V_112 -> V_122 & V_127 )
V_116 |= V_128 ;
error = F_75 ( V_115 , V_117 , V_118 ,
V_21 , V_116 ) ;
if ( error > 0 ) {
error = 0 ;
* V_113 = 1 ;
}
return - error ;
}
STATIC int
F_76 (
struct V_2 * V_2 ,
struct V_114 * V_115 ,
T_6 V_129 ,
T_6 V_21 )
{
T_1 * V_1 = F_8 ( V_2 ) ;
struct V_111 V_130 ;
int error ;
error = F_77 ( V_115 , V_131 ) ;
if ( error )
return error ;
V_130 . V_120 = F_78 ( V_129 ) ;
if ( V_21 == V_132 )
V_130 . V_121 = - 1LL ;
else
V_130 . V_121 = F_78 ( V_21 ) ;
V_130 . V_133 = ! V_115 -> V_134 ? V_135 :
V_115 -> V_134 + 1 ;
V_130 . V_133 = F_79 ( V_136 , V_130 . V_133 ,
( V_137 * 16 / sizeof( struct V_111 ) ) ) ;
V_130 . V_138 = V_139 | V_140 ;
if ( V_115 -> V_141 & V_142 )
V_130 . V_138 |= V_143 ;
if ( ! ( V_115 -> V_141 & V_144 ) )
V_130 . V_138 |= V_145 ;
error = F_80 ( V_1 , & V_130 , F_73 , V_115 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_81 (
struct V_2 * V_2 ,
struct V_20 * V_1 )
{
if ( V_1 -> V_3 . V_146 & V_147 )
V_2 -> V_148 |= V_149 ;
else
V_2 -> V_148 &= ~ V_149 ;
if ( V_1 -> V_3 . V_146 & V_150 )
V_2 -> V_148 |= V_151 ;
else
V_2 -> V_148 &= ~ V_151 ;
if ( V_1 -> V_3 . V_146 & V_152 )
V_2 -> V_148 |= V_153 ;
else
V_2 -> V_148 &= ~ V_153 ;
if ( V_1 -> V_3 . V_146 & V_154 )
V_2 -> V_148 |= V_155 ;
else
V_2 -> V_148 &= ~ V_155 ;
}
void
F_82 (
struct V_20 * V_1 )
{
struct V_2 * V_2 = & V_1 -> V_156 ;
V_2 -> V_93 = V_1 -> V_93 ;
V_2 -> V_15 = V_157 ;
F_83 ( V_2 ) ;
F_84 ( & V_2 -> V_158 ) ;
V_2 -> V_99 = V_1 -> V_3 . V_85 ;
V_2 -> V_159 = V_1 -> V_3 . V_87 ;
V_2 -> V_160 = V_1 -> V_3 . V_89 ;
V_2 -> V_161 = V_1 -> V_3 . V_91 ;
switch ( V_2 -> V_99 & V_100 ) {
case V_101 :
case V_102 :
V_2 -> V_162 =
F_65 ( F_66 ( V_1 -> V_105 . V_106 . V_107 ) & 0x1ff ,
F_67 ( V_1 -> V_105 . V_106 . V_107 ) ) ;
break;
default:
V_2 -> V_162 = 0 ;
break;
}
V_2 -> V_163 = V_1 -> V_3 . V_164 ;
F_85 ( V_2 , V_1 -> V_3 . V_165 ) ;
V_2 -> V_7 . V_8 = V_1 -> V_3 . V_4 . V_5 ;
V_2 -> V_7 . V_10 = V_1 -> V_3 . V_4 . V_9 ;
V_2 -> V_14 . V_8 = V_1 -> V_3 . V_13 . V_5 ;
V_2 -> V_14 . V_10 = V_1 -> V_3 . V_13 . V_9 ;
V_2 -> V_12 . V_8 = V_1 -> V_3 . V_11 . V_5 ;
V_2 -> V_12 . V_10 = V_1 -> V_3 . V_11 . V_9 ;
F_81 ( V_2 , V_1 ) ;
switch ( V_2 -> V_99 & V_100 ) {
case V_166 :
V_2 -> V_167 = & V_168 ;
V_2 -> V_169 = & V_170 ;
V_2 -> V_171 -> V_172 = & V_173 ;
break;
case V_42 :
if ( F_46 ( & F_47 ( V_2 -> V_52 ) -> V_53 ) )
V_2 -> V_167 = & V_174 ;
else
V_2 -> V_167 = & V_175 ;
V_2 -> V_169 = & V_176 ;
break;
case V_55 :
V_2 -> V_167 = & V_177 ;
if ( ! ( V_1 -> V_105 . V_178 & V_179 ) )
V_2 -> V_171 -> V_172 = & V_173 ;
break;
default:
V_2 -> V_167 = & V_168 ;
F_86 ( V_2 , V_2 -> V_99 , V_2 -> V_162 ) ;
break;
}
F_87 ( V_1 , V_180 ) ;
F_88 () ;
F_89 ( V_2 ) ;
}
