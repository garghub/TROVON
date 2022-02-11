static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_4 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
F_1 ( V_7 -> V_8 , V_7 -> V_9 ) ;
F_5 ( V_7 -> V_8 ) ;
F_6 ( V_7 -> V_10 ) ;
F_6 ( V_7 ) ;
}
static int F_7 ( void )
{
static const struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = V_16 ,
} ;
struct V_17 args = {
. V_18 = & V_19 ,
. V_20 = V_21 ,
. V_22 = (struct V_23 * ) & V_12 ,
. V_24 = sizeof( V_12 ) ,
. V_25 = L_1 ,
. V_26 = & V_27 ,
. V_28 = V_29 ,
. V_30 = V_31 ,
} ;
struct V_32 * V_33 , * V_34 ;
int V_35 = 0 ;
V_33 = F_8 ( & args ) ;
if ( F_9 ( V_33 ) ) {
F_10 ( L_2
L_3 , F_11 ( V_33 ) ) ;
V_35 = - F_11 ( V_33 ) ;
goto V_36;
}
V_34 = F_12 ( V_33 , & V_27 , V_37 ) ;
if ( F_9 ( V_34 ) ) {
F_10 ( L_4
L_5 ,
F_11 ( V_34 ) ) ;
V_34 = NULL ;
}
V_38 = V_33 ;
V_39 = V_34 ;
V_36:
return V_35 ;
}
static int F_13 ( void )
{
static const struct V_40 V_41 = {
. V_42 = V_43 ,
. V_44 . V_45 = F_14 ( V_46 ) ,
. V_47 = F_15 ( V_48 ) ,
} ;
struct V_17 args = {
. V_18 = & V_19 ,
. V_20 = V_49 ,
. V_22 = (struct V_23 * ) & V_41 ,
. V_24 = sizeof( V_41 ) ,
. V_25 = L_1 ,
. V_26 = & V_27 ,
. V_28 = V_29 ,
. V_30 = V_50 ,
. V_51 = V_52 ,
} ;
struct V_32 * V_33 , * V_34 ;
int V_35 = 0 ;
V_33 = F_8 ( & args ) ;
if ( F_9 ( V_33 ) ) {
F_10 ( L_6
L_3 , F_11 ( V_33 ) ) ;
V_35 = - F_11 ( V_33 ) ;
goto V_36;
}
V_34 = F_12 ( V_33 , & V_27 , V_37 ) ;
if ( F_9 ( V_34 ) ) {
F_10 ( L_4
L_5 ,
F_11 ( V_34 ) ) ;
V_34 = NULL ;
}
V_38 = V_33 ;
V_39 = V_34 ;
V_36:
return V_35 ;
}
static int F_16 ( void )
{
static F_17 ( V_53 ) ;
int V_35 = 0 ;
if ( V_38 )
return V_35 ;
F_18 ( & V_53 ) ;
if ( V_38 )
goto V_36;
if ( F_7 () != 0 )
V_35 = F_13 () ;
V_36:
F_19 ( & V_53 ) ;
return V_35 ;
}
static struct V_32 * F_20 ( char * V_54 , struct V_23 * V_55 ,
T_1 V_56 , int V_57 , T_2 V_28 )
{
struct V_17 args = {
. V_18 = & V_19 ,
. V_20 = V_57 ,
. V_22 = V_55 ,
. V_24 = V_56 ,
. V_25 = V_54 ,
. V_26 = & V_27 ,
. V_28 = V_28 ,
. V_30 = V_50 ,
. V_51 = ( V_52 |
V_58 ) ,
} ;
switch ( V_55 -> V_59 ) {
case V_43 :
( (struct V_40 * ) V_55 ) -> V_47 = F_15 ( V_48 ) ;
break;
case V_60 :
( (struct V_61 * ) V_55 ) -> V_62 = F_15 ( V_48 ) ;
break;
default:
return F_21 ( - V_63 ) ;
}
return F_8 ( & args ) ;
}
static int F_22 ( struct V_32 * V_33 , struct V_64 * V_65 )
{
int V_35 , error = 0 ;
V_65 -> V_66 = & V_35 ;
error = F_23 ( V_33 , V_65 , V_67 ) ;
if ( error < 0 ) {
F_10 ( L_7
L_8 , - error ) ;
return error ;
}
if ( ! V_35 )
return - V_68 ;
return 0 ;
}
int F_24 ( T_2 V_69 , T_2 V_70 , int V_71 , unsigned short V_72 )
{
struct V_6 V_7 = {
. V_73 = V_69 ,
. V_74 = V_70 ,
. V_75 = V_71 ,
. V_76 = V_72 ,
} ;
struct V_64 V_65 = {
. V_77 = & V_7 ,
} ;
int error ;
error = F_16 () ;
if ( error )
return error ;
F_10 ( L_9
L_10 , ( V_72 ? L_11 : L_12 ) ,
V_69 , V_70 , V_71 , V_72 ) ;
V_65 . V_78 = & V_79 [ V_80 ] ;
if ( V_72 )
V_65 . V_78 = & V_79 [ V_81 ] ;
return F_22 ( V_38 , & V_65 ) ;
}
static int F_25 ( const struct V_23 * V_82 ,
struct V_64 * V_65 )
{
const struct V_40 * sin = ( const struct V_40 * ) V_82 ;
struct V_6 * V_7 = V_65 -> V_77 ;
unsigned short V_72 = F_26 ( sin -> V_47 ) ;
int V_35 ;
V_7 -> V_10 = F_27 ( V_82 ) ;
F_10 ( L_13
L_14 , ( V_72 ? L_11 : L_12 ) ,
V_7 -> V_73 , V_7 -> V_74 ,
V_7 -> V_10 , V_7 -> V_83 ) ;
V_65 -> V_78 = & V_84 [ V_80 ] ;
if ( V_72 )
V_65 -> V_78 = & V_84 [ V_81 ] ;
V_35 = F_22 ( V_39 , V_65 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_35 ;
}
static int F_28 ( const struct V_23 * V_82 ,
struct V_64 * V_65 )
{
const struct V_61 * V_85 = ( const struct V_61 * ) V_82 ;
struct V_6 * V_7 = V_65 -> V_77 ;
unsigned short V_72 = F_26 ( V_85 -> V_62 ) ;
int V_35 ;
V_7 -> V_10 = F_27 ( V_82 ) ;
F_10 ( L_13
L_14 , ( V_72 ? L_11 : L_12 ) ,
V_7 -> V_73 , V_7 -> V_74 ,
V_7 -> V_10 , V_7 -> V_83 ) ;
V_65 -> V_78 = & V_84 [ V_80 ] ;
if ( V_72 )
V_65 -> V_78 = & V_84 [ V_81 ] ;
V_35 = F_22 ( V_39 , V_65 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_35 ;
}
static int F_29 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = V_65 -> V_77 ;
F_10 ( L_15
L_14 ,
V_7 -> V_73 , V_7 -> V_74 , V_7 -> V_83 ) ;
V_7 -> V_10 = L_11 ;
V_65 -> V_78 = & V_84 [ V_80 ] ;
return F_22 ( V_39 , V_65 ) ;
}
int F_30 ( const T_2 V_26 , const T_2 V_28 ,
const struct V_23 * V_22 , const char * V_86 )
{
struct V_6 V_7 = {
. V_73 = V_26 ,
. V_74 = V_28 ,
. V_83 = V_86 ,
. V_87 = V_88 ,
} ;
struct V_64 V_65 = {
. V_77 = & V_7 ,
} ;
int error ;
error = F_16 () ;
if ( error )
return error ;
if ( V_39 == NULL )
return - V_89 ;
if ( V_22 == NULL )
return F_29 ( & V_65 ) ;
switch ( V_22 -> V_59 ) {
case V_43 :
return F_25 ( V_22 , & V_65 ) ;
case V_60 :
return F_28 ( V_22 , & V_65 ) ;
}
return - V_63 ;
}
static struct V_90 * F_31 ( struct V_32 * V_91 , struct V_6 * V_7 , struct V_92 * V_93 )
{
struct V_64 V_65 = {
. V_78 = V_93 ,
. V_77 = V_7 ,
. V_66 = V_7 ,
} ;
struct V_94 V_95 = {
. V_96 = V_91 ,
. V_64 = & V_65 ,
. V_97 = & V_98 ,
. V_99 = V_7 ,
. V_51 = V_100 | V_67 ,
} ;
return F_32 ( & V_95 ) ;
}
static struct V_32 * F_33 ( struct V_32 * V_33 )
{
struct V_32 * V_101 = V_33 -> V_102 ;
while ( V_101 != V_33 ) {
if ( V_101 -> V_103 != V_33 -> V_103 )
break;
if ( V_33 -> V_104 )
break;
V_33 = V_101 ;
V_101 = V_101 -> V_102 ;
}
return V_33 ;
}
void F_34 ( struct V_90 * V_105 )
{
struct V_32 * V_33 ;
struct V_92 * V_93 ;
T_2 V_106 ;
struct V_1 * V_2 ;
struct V_32 * V_91 ;
struct V_6 * V_7 ;
struct V_90 * V_107 ;
struct V_108 V_109 ;
struct V_23 * V_82 = (struct V_23 * ) & V_109 ;
T_1 V_56 ;
int V_3 ;
V_33 = F_33 ( V_105 -> V_110 ) ;
V_2 = V_33 -> V_103 ;
F_10 ( L_16 ,
V_105 -> V_111 , V_112 ,
V_33 -> V_113 , V_33 -> V_114 , V_33 -> V_115 , V_2 -> V_71 ) ;
F_35 ( & V_2 -> V_4 , V_105 , NULL ) ;
if ( F_36 ( V_2 ) ) {
F_10 ( L_17 ,
V_105 -> V_111 , V_112 ) ;
return;
}
if ( F_37 ( V_2 ) ) {
V_3 = 0 ;
F_10 ( L_18 ,
V_105 -> V_111 , V_112 ) ;
goto V_116;
}
V_56 = F_38 ( V_33 , V_82 , sizeof( V_109 ) ) ;
switch ( V_82 -> V_59 ) {
case V_43 :
V_93 = V_117 [ V_2 -> V_118 ] . V_78 ;
V_106 = V_117 [ V_2 -> V_118 ] . V_119 ;
break;
case V_60 :
V_93 = V_120 [ V_2 -> V_118 ] . V_78 ;
V_106 = V_120 [ V_2 -> V_118 ] . V_119 ;
break;
default:
V_3 = - V_63 ;
F_10 ( L_19 ,
V_105 -> V_111 , V_112 ) ;
goto V_116;
}
if ( V_93 == NULL ) {
V_2 -> V_118 = 0 ;
V_3 = - V_121 ;
F_10 ( L_20 ,
V_105 -> V_111 , V_112 ) ;
goto V_116;
}
F_10 ( L_21 ,
V_105 -> V_111 , V_112 , V_106 ) ;
V_91 = F_20 ( V_33 -> V_113 , V_82 , V_56 , V_2 -> V_71 ,
V_106 ) ;
if ( F_9 ( V_91 ) ) {
V_3 = F_11 ( V_91 ) ;
F_10 ( L_22 ,
V_105 -> V_111 , V_112 , F_11 ( V_91 ) ) ;
goto V_116;
}
V_7 = F_39 ( sizeof( struct V_6 ) , V_122 ) ;
if ( ! V_7 ) {
V_3 = - V_123 ;
F_10 ( L_23 ,
V_105 -> V_111 , V_112 ) ;
goto V_124;
}
V_7 -> V_73 = V_33 -> V_114 ;
V_7 -> V_74 = V_33 -> V_115 ;
V_7 -> V_75 = V_2 -> V_71 ;
V_7 -> V_76 = 0 ;
V_7 -> V_8 = F_40 ( V_2 ) ;
V_7 -> V_9 = - V_125 ;
switch ( V_106 ) {
case V_37 :
case V_126 :
V_7 -> V_83 = F_41 ( V_33 , V_127 ) ;
V_7 -> V_10 = F_27 ( V_82 ) ;
V_7 -> V_87 = L_11 ;
break;
case V_29 :
V_7 -> V_10 = NULL ;
break;
default:
F_42 () ;
}
V_107 = F_31 ( V_91 , V_7 , V_93 ) ;
F_43 ( V_91 ) ;
if ( F_9 ( V_107 ) ) {
F_10 ( L_24 ,
V_105 -> V_111 , V_112 ) ;
return;
}
V_2 -> V_128 . V_129 ++ ;
F_44 ( V_107 ) ;
return;
V_124:
F_43 ( V_91 ) ;
V_116:
F_1 ( V_2 , V_3 ) ;
V_105 -> V_130 = V_3 ;
}
static void F_45 ( struct V_90 * V_107 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_1 * V_2 = V_7 -> V_8 ;
int V_3 = V_107 -> V_130 ;
if ( V_3 == - V_125 )
V_3 = - V_89 ;
if ( V_3 == - V_89 )
V_2 -> V_118 ++ ;
if ( V_3 < 0 ) {
V_2 -> V_131 -> V_132 ( V_2 , 0 ) ;
} else if ( V_7 -> V_76 == 0 ) {
V_2 -> V_131 -> V_132 ( V_2 , 0 ) ;
V_3 = - V_68 ;
} else {
V_2 -> V_131 -> V_132 ( V_2 , V_7 -> V_76 ) ;
F_46 ( V_2 ) ;
V_3 = 0 ;
}
F_10 ( L_25 ,
V_107 -> V_111 , V_3 , V_7 -> V_76 ) ;
V_7 -> V_9 = V_3 ;
}
static void F_47 ( struct V_133 * V_134 , struct V_135 * V_136 ,
const struct V_6 * V_137 )
{
struct V_90 * V_105 = V_134 -> V_138 ;
T_3 * V_139 ;
F_10 ( L_26 ,
V_105 -> V_111 , V_105 -> V_140 . V_78 -> V_141 ,
V_137 -> V_73 , V_137 -> V_74 , V_137 -> V_75 , V_137 -> V_76 ) ;
V_139 = F_48 ( V_136 , V_142 << 2 ) ;
* V_139 ++ = F_49 ( V_137 -> V_73 ) ;
* V_139 ++ = F_49 ( V_137 -> V_74 ) ;
* V_139 ++ = F_49 ( V_137 -> V_75 ) ;
* V_139 = F_49 ( V_137 -> V_76 ) ;
}
static int F_50 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_6 * V_137 )
{
struct V_90 * V_105 = V_134 -> V_138 ;
unsigned long V_72 ;
T_3 * V_139 ;
V_137 -> V_76 = 0 ;
V_139 = F_51 ( V_136 , 4 ) ;
if ( F_52 ( V_139 == NULL ) )
return - V_125 ;
V_72 = F_53 ( V_139 ) ;
F_10 ( L_27 , V_105 -> V_111 ,
V_105 -> V_140 . V_78 -> V_141 , V_72 ) ;
if ( F_52 ( V_72 > V_143 ) )
return - V_125 ;
V_137 -> V_76 = V_72 ;
return 0 ;
}
static int F_54 ( struct V_133 * V_134 , struct V_135 * V_136 ,
unsigned int * V_144 )
{
struct V_90 * V_105 = V_134 -> V_138 ;
T_3 * V_139 ;
V_139 = F_51 ( V_136 , 4 ) ;
if ( F_52 ( V_139 == NULL ) )
return - V_125 ;
* V_144 = 0 ;
if ( * V_139 != V_145 )
* V_144 = 1 ;
F_10 ( L_28 ,
V_105 -> V_111 , V_105 -> V_140 . V_78 -> V_141 ,
( * V_144 ? L_29 : L_30 ) ) ;
return 0 ;
}
static void F_55 ( struct V_135 * V_136 , const char * string ,
const T_2 V_146 )
{
T_3 * V_139 ;
T_2 V_147 ;
V_147 = strlen ( string ) ;
F_56 ( V_147 > V_146 ) ;
V_139 = F_48 ( V_136 , 4 + V_147 ) ;
F_57 ( V_139 , string , V_147 ) ;
}
static void F_58 ( struct V_133 * V_134 , struct V_135 * V_136 ,
const struct V_6 * V_137 )
{
struct V_90 * V_105 = V_134 -> V_138 ;
T_3 * V_139 ;
F_10 ( L_31 ,
V_105 -> V_111 , V_105 -> V_140 . V_78 -> V_141 ,
V_137 -> V_73 , V_137 -> V_74 ,
V_137 -> V_83 , V_137 -> V_10 ) ;
V_139 = F_48 ( V_136 , ( V_148 + V_149 ) << 2 ) ;
* V_139 ++ = F_49 ( V_137 -> V_73 ) ;
* V_139 = F_49 ( V_137 -> V_74 ) ;
F_55 ( V_136 , V_137 -> V_83 , V_150 ) ;
F_55 ( V_136 , V_137 -> V_10 , V_151 ) ;
F_55 ( V_136 , V_137 -> V_87 , V_152 ) ;
}
static int F_59 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_6 * V_137 )
{
struct V_108 V_22 ;
struct V_23 * V_82 = (struct V_23 * ) & V_22 ;
struct V_90 * V_105 = V_134 -> V_138 ;
T_3 * V_139 ;
T_2 V_147 ;
V_137 -> V_76 = 0 ;
V_139 = F_51 ( V_136 , 4 ) ;
if ( F_52 ( V_139 == NULL ) )
goto V_153;
V_147 = F_53 ( V_139 ) ;
if ( V_147 == 0 ) {
F_10 ( L_32 ,
V_105 -> V_111 ) ;
return 0 ;
}
if ( F_52 ( V_147 > V_151 ) )
goto V_153;
V_139 = F_51 ( V_136 , V_147 ) ;
if ( F_52 ( V_139 == NULL ) )
goto V_153;
F_10 ( L_33 , V_105 -> V_111 ,
V_105 -> V_140 . V_78 -> V_141 , ( char * ) V_139 ) ;
if ( F_60 ( ( char * ) V_139 , V_147 , V_82 , sizeof( V_22 ) ) == 0 )
goto V_153;
V_137 -> V_76 = F_61 ( V_82 ) ;
return 0 ;
V_153:
F_10 ( L_34 ,
V_105 -> V_111 , V_105 -> V_140 . V_78 -> V_141 ) ;
return - V_125 ;
}
void F_62 ( void )
{
if ( V_39 )
F_63 ( V_39 ) ;
if ( V_38 )
F_63 ( V_38 ) ;
}
