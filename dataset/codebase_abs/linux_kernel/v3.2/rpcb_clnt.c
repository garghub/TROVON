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
int V_11 ;
F_8 ( & V_12 ) ;
if ( V_13 )
V_13 ++ ;
V_11 = V_13 ;
F_9 ( & V_12 ) ;
return V_11 ;
}
void F_10 ( void )
{
struct V_14 * V_15 = V_16 ;
struct V_14 * V_17 = V_18 ;
int V_19 ;
F_8 ( & V_12 ) ;
if ( -- V_13 == 0 ) {
V_16 = NULL ;
V_18 = NULL ;
}
V_19 = ! V_13 ;
F_9 ( & V_12 ) ;
if ( V_19 ) {
if ( V_17 )
F_11 ( V_17 ) ;
if ( V_15 )
F_11 ( V_15 ) ;
}
}
static void F_12 ( struct V_14 * V_15 , struct V_14 * V_17 )
{
V_16 = V_15 ;
V_18 = V_17 ;
F_13 () ;
V_13 = 1 ;
F_14 ( L_1
L_2 , V_16 ,
V_18 ) ;
}
static int F_15 ( void )
{
static const struct V_20 V_21 = {
. V_22 = V_23 ,
. V_24 = V_25 ,
} ;
struct V_26 args = {
. V_27 = & V_28 ,
. V_29 = V_30 ,
. V_31 = (struct V_32 * ) & V_21 ,
. V_33 = sizeof( V_21 ) ,
. V_34 = L_3 ,
. V_35 = & V_36 ,
. V_37 = V_38 ,
. V_39 = V_40 ,
} ;
struct V_14 * V_15 , * V_17 ;
int V_41 = 0 ;
V_15 = F_16 ( & args ) ;
if ( F_17 ( V_15 ) ) {
F_14 ( L_4
L_5 , F_18 ( V_15 ) ) ;
V_41 = - F_18 ( V_15 ) ;
goto V_42;
}
V_17 = F_19 ( V_15 , & V_36 , V_43 ) ;
if ( F_17 ( V_17 ) ) {
F_14 ( L_6
L_7 ,
F_18 ( V_17 ) ) ;
V_17 = NULL ;
}
F_12 ( V_15 , V_17 ) ;
V_42:
return V_41 ;
}
static int F_20 ( void )
{
static const struct V_44 V_45 = {
. V_46 = V_47 ,
. V_48 . V_49 = F_21 ( V_50 ) ,
. V_51 = F_22 ( V_52 ) ,
} ;
struct V_26 args = {
. V_27 = & V_28 ,
. V_29 = V_53 ,
. V_31 = (struct V_32 * ) & V_45 ,
. V_33 = sizeof( V_45 ) ,
. V_34 = L_3 ,
. V_35 = & V_36 ,
. V_37 = V_38 ,
. V_39 = V_54 ,
. V_55 = V_56 ,
} ;
struct V_14 * V_15 , * V_17 ;
int V_41 = 0 ;
V_15 = F_16 ( & args ) ;
if ( F_17 ( V_15 ) ) {
F_14 ( L_8
L_5 , F_18 ( V_15 ) ) ;
V_41 = - F_18 ( V_15 ) ;
goto V_42;
}
V_17 = F_19 ( V_15 , & V_36 , V_43 ) ;
if ( F_17 ( V_17 ) ) {
F_14 ( L_6
L_7 ,
F_18 ( V_17 ) ) ;
V_17 = NULL ;
}
F_12 ( V_15 , V_17 ) ;
V_42:
return V_41 ;
}
int F_23 ( void )
{
static F_24 ( V_57 ) ;
int V_41 = 0 ;
if ( F_7 () )
return V_41 ;
F_25 ( & V_57 ) ;
if ( F_7 () )
goto V_42;
if ( F_15 () != 0 )
V_41 = F_20 () ;
V_42:
F_26 ( & V_57 ) ;
return V_41 ;
}
static struct V_14 * F_27 ( char * V_58 , struct V_32 * V_59 ,
T_1 V_60 , int V_61 , T_2 V_37 )
{
struct V_26 args = {
. V_27 = & V_28 ,
. V_29 = V_61 ,
. V_31 = V_59 ,
. V_33 = V_60 ,
. V_34 = V_58 ,
. V_35 = & V_36 ,
. V_37 = V_37 ,
. V_39 = V_54 ,
. V_55 = ( V_56 |
V_62 ) ,
} ;
switch ( V_59 -> V_63 ) {
case V_47 :
( (struct V_44 * ) V_59 ) -> V_51 = F_22 ( V_52 ) ;
break;
case V_64 :
( (struct V_65 * ) V_59 ) -> V_66 = F_22 ( V_52 ) ;
break;
default:
return F_28 ( - V_67 ) ;
}
return F_16 ( & args ) ;
}
static int F_29 ( struct V_14 * V_15 , struct V_68 * V_69 )
{
int V_41 , error = 0 ;
V_69 -> V_70 = & V_41 ;
error = F_30 ( V_15 , V_69 , V_71 ) ;
if ( error < 0 ) {
F_14 ( L_9
L_10 , - error ) ;
return error ;
}
if ( ! V_41 )
return - V_72 ;
return 0 ;
}
int F_31 ( T_2 V_73 , T_2 V_74 , int V_75 , unsigned short V_76 )
{
struct V_6 V_7 = {
. V_77 = V_73 ,
. V_78 = V_74 ,
. V_79 = V_75 ,
. V_80 = V_76 ,
} ;
struct V_68 V_69 = {
. V_81 = & V_7 ,
} ;
F_14 ( L_11
L_12 , ( V_76 ? L_13 : L_14 ) ,
V_73 , V_74 , V_75 , V_76 ) ;
V_69 . V_82 = & V_83 [ V_84 ] ;
if ( V_76 )
V_69 . V_82 = & V_83 [ V_85 ] ;
return F_29 ( V_16 , & V_69 ) ;
}
static int F_32 ( const struct V_32 * V_86 ,
struct V_68 * V_69 )
{
const struct V_44 * sin = ( const struct V_44 * ) V_86 ;
struct V_6 * V_7 = V_69 -> V_81 ;
unsigned short V_76 = F_33 ( sin -> V_51 ) ;
int V_41 ;
V_7 -> V_10 = F_34 ( V_86 , V_87 ) ;
F_14 ( L_15
L_16 , ( V_76 ? L_13 : L_14 ) ,
V_7 -> V_77 , V_7 -> V_78 ,
V_7 -> V_10 , V_7 -> V_88 ) ;
V_69 -> V_82 = & V_89 [ V_84 ] ;
if ( V_76 )
V_69 -> V_82 = & V_89 [ V_85 ] ;
V_41 = F_29 ( V_18 , V_69 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_41 ;
}
static int F_35 ( const struct V_32 * V_86 ,
struct V_68 * V_69 )
{
const struct V_65 * V_90 = ( const struct V_65 * ) V_86 ;
struct V_6 * V_7 = V_69 -> V_81 ;
unsigned short V_76 = F_33 ( V_90 -> V_66 ) ;
int V_41 ;
V_7 -> V_10 = F_34 ( V_86 , V_87 ) ;
F_14 ( L_15
L_16 , ( V_76 ? L_13 : L_14 ) ,
V_7 -> V_77 , V_7 -> V_78 ,
V_7 -> V_10 , V_7 -> V_88 ) ;
V_69 -> V_82 = & V_89 [ V_84 ] ;
if ( V_76 )
V_69 -> V_82 = & V_89 [ V_85 ] ;
V_41 = F_29 ( V_18 , V_69 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_41 ;
}
static int F_36 ( struct V_68 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_81 ;
F_14 ( L_17
L_16 ,
V_7 -> V_77 , V_7 -> V_78 , V_7 -> V_88 ) ;
V_7 -> V_10 = L_13 ;
V_69 -> V_82 = & V_89 [ V_84 ] ;
return F_29 ( V_18 , V_69 ) ;
}
int F_37 ( const T_2 V_35 , const T_2 V_37 ,
const struct V_32 * V_31 , const char * V_91 )
{
struct V_6 V_7 = {
. V_77 = V_35 ,
. V_78 = V_37 ,
. V_88 = V_91 ,
. V_92 = V_93 ,
} ;
struct V_68 V_69 = {
. V_81 = & V_7 ,
} ;
if ( V_18 == NULL )
return - V_94 ;
if ( V_31 == NULL )
return F_36 ( & V_69 ) ;
switch ( V_31 -> V_63 ) {
case V_47 :
return F_32 ( V_31 , & V_69 ) ;
case V_64 :
return F_35 ( V_31 , & V_69 ) ;
}
return - V_67 ;
}
static struct V_95 * F_38 ( struct V_14 * V_96 , struct V_6 * V_7 , struct V_97 * V_98 )
{
struct V_68 V_69 = {
. V_82 = V_98 ,
. V_81 = V_7 ,
. V_70 = V_7 ,
} ;
struct V_99 V_100 = {
. V_101 = V_96 ,
. V_68 = & V_69 ,
. V_102 = & V_103 ,
. V_104 = V_7 ,
. V_55 = V_105 | V_71 ,
} ;
return F_39 ( & V_100 ) ;
}
static struct V_14 * F_40 ( struct V_14 * V_15 )
{
struct V_14 * V_106 = V_15 -> V_107 ;
while ( V_106 != V_15 ) {
if ( V_106 -> V_108 != V_15 -> V_108 )
break;
if ( V_15 -> V_109 )
break;
V_15 = V_106 ;
V_106 = V_106 -> V_107 ;
}
return V_15 ;
}
void F_41 ( struct V_95 * V_110 )
{
struct V_14 * V_15 ;
struct V_97 * V_98 ;
T_2 V_111 ;
struct V_1 * V_2 ;
struct V_14 * V_96 ;
struct V_6 * V_7 ;
struct V_95 * V_112 ;
struct V_113 V_114 ;
struct V_32 * V_86 = (struct V_32 * ) & V_114 ;
T_1 V_60 ;
int V_3 ;
V_15 = F_40 ( V_110 -> V_115 ) ;
V_2 = V_15 -> V_108 ;
F_14 ( L_18 ,
V_110 -> V_116 , V_117 ,
V_15 -> V_118 , V_15 -> V_119 , V_15 -> V_120 , V_2 -> V_75 ) ;
F_42 ( & V_2 -> V_4 , V_110 , NULL ) ;
if ( F_43 ( V_2 ) ) {
F_14 ( L_19 ,
V_110 -> V_116 , V_117 ) ;
return;
}
if ( F_44 ( V_2 ) ) {
V_3 = 0 ;
F_14 ( L_20 ,
V_110 -> V_116 , V_117 ) ;
goto V_121;
}
V_60 = F_45 ( V_15 , V_86 , sizeof( V_114 ) ) ;
switch ( V_86 -> V_63 ) {
case V_47 :
V_98 = V_122 [ V_2 -> V_123 ] . V_82 ;
V_111 = V_122 [ V_2 -> V_123 ] . V_124 ;
break;
case V_64 :
V_98 = V_125 [ V_2 -> V_123 ] . V_82 ;
V_111 = V_125 [ V_2 -> V_123 ] . V_124 ;
break;
default:
V_3 = - V_67 ;
F_14 ( L_21 ,
V_110 -> V_116 , V_117 ) ;
goto V_121;
}
if ( V_98 == NULL ) {
V_2 -> V_123 = 0 ;
V_3 = - V_126 ;
F_14 ( L_22 ,
V_110 -> V_116 , V_117 ) ;
goto V_121;
}
F_14 ( L_23 ,
V_110 -> V_116 , V_117 , V_111 ) ;
V_96 = F_27 ( V_15 -> V_118 , V_86 , V_60 , V_2 -> V_75 ,
V_111 ) ;
if ( F_17 ( V_96 ) ) {
V_3 = F_18 ( V_96 ) ;
F_14 ( L_24 ,
V_110 -> V_116 , V_117 , F_18 ( V_96 ) ) ;
goto V_121;
}
V_7 = F_46 ( sizeof( struct V_6 ) , V_127 ) ;
if ( ! V_7 ) {
V_3 = - V_128 ;
F_14 ( L_25 ,
V_110 -> V_116 , V_117 ) ;
goto V_129;
}
V_7 -> V_77 = V_15 -> V_119 ;
V_7 -> V_78 = V_15 -> V_120 ;
V_7 -> V_79 = V_2 -> V_75 ;
V_7 -> V_80 = 0 ;
V_7 -> V_8 = F_47 ( V_2 ) ;
V_7 -> V_9 = - V_130 ;
switch ( V_111 ) {
case V_43 :
case V_131 :
V_7 -> V_88 = F_48 ( V_15 , V_132 ) ;
V_7 -> V_10 = F_34 ( V_86 , V_127 ) ;
V_7 -> V_92 = L_13 ;
break;
case V_38 :
V_7 -> V_10 = NULL ;
break;
default:
F_49 () ;
}
V_112 = F_38 ( V_96 , V_7 , V_98 ) ;
F_50 ( V_96 ) ;
if ( F_17 ( V_112 ) ) {
F_14 ( L_26 ,
V_110 -> V_116 , V_117 ) ;
return;
}
V_2 -> V_133 . V_134 ++ ;
F_51 ( V_112 ) ;
return;
V_129:
F_50 ( V_96 ) ;
V_121:
F_1 ( V_2 , V_3 ) ;
V_110 -> V_135 = V_3 ;
}
static void F_52 ( struct V_95 * V_112 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_1 * V_2 = V_7 -> V_8 ;
int V_3 = V_112 -> V_135 ;
if ( V_3 == - V_130 )
V_3 = - V_94 ;
if ( V_3 == - V_94 )
V_2 -> V_123 ++ ;
if ( V_3 < 0 ) {
V_2 -> V_136 -> V_137 ( V_2 , 0 ) ;
} else if ( V_7 -> V_80 == 0 ) {
V_2 -> V_136 -> V_137 ( V_2 , 0 ) ;
V_3 = - V_72 ;
} else {
V_2 -> V_136 -> V_137 ( V_2 , V_7 -> V_80 ) ;
F_53 ( V_2 ) ;
V_3 = 0 ;
}
F_14 ( L_27 ,
V_112 -> V_116 , V_3 , V_7 -> V_80 ) ;
V_7 -> V_9 = V_3 ;
}
static void F_54 ( struct V_138 * V_139 , struct V_140 * V_141 ,
const struct V_6 * V_142 )
{
struct V_95 * V_110 = V_139 -> V_143 ;
T_3 * V_144 ;
F_14 ( L_28 ,
V_110 -> V_116 , V_110 -> V_145 . V_82 -> V_146 ,
V_142 -> V_77 , V_142 -> V_78 , V_142 -> V_79 , V_142 -> V_80 ) ;
V_144 = F_55 ( V_141 , V_147 << 2 ) ;
* V_144 ++ = F_56 ( V_142 -> V_77 ) ;
* V_144 ++ = F_56 ( V_142 -> V_78 ) ;
* V_144 ++ = F_56 ( V_142 -> V_79 ) ;
* V_144 = F_56 ( V_142 -> V_80 ) ;
}
static int F_57 ( struct V_138 * V_139 , struct V_140 * V_141 ,
struct V_6 * V_142 )
{
struct V_95 * V_110 = V_139 -> V_143 ;
unsigned long V_76 ;
T_3 * V_144 ;
V_142 -> V_80 = 0 ;
V_144 = F_58 ( V_141 , 4 ) ;
if ( F_59 ( V_144 == NULL ) )
return - V_130 ;
V_76 = F_60 ( V_144 ) ;
F_14 ( L_29 , V_110 -> V_116 ,
V_110 -> V_145 . V_82 -> V_146 , V_76 ) ;
if ( F_59 ( V_76 > V_148 ) )
return - V_130 ;
V_142 -> V_80 = V_76 ;
return 0 ;
}
static int F_61 ( struct V_138 * V_139 , struct V_140 * V_141 ,
unsigned int * V_149 )
{
struct V_95 * V_110 = V_139 -> V_143 ;
T_3 * V_144 ;
V_144 = F_58 ( V_141 , 4 ) ;
if ( F_59 ( V_144 == NULL ) )
return - V_130 ;
* V_149 = 0 ;
if ( * V_144 != V_150 )
* V_149 = 1 ;
F_14 ( L_30 ,
V_110 -> V_116 , V_110 -> V_145 . V_82 -> V_146 ,
( * V_149 ? L_31 : L_32 ) ) ;
return 0 ;
}
static void F_62 ( struct V_140 * V_141 , const char * string ,
const T_2 V_151 )
{
T_3 * V_144 ;
T_2 V_152 ;
V_152 = strlen ( string ) ;
F_63 ( V_152 > V_151 ) ;
V_144 = F_55 ( V_141 , 4 + V_152 ) ;
F_64 ( V_144 , string , V_152 ) ;
}
static void F_65 ( struct V_138 * V_139 , struct V_140 * V_141 ,
const struct V_6 * V_142 )
{
struct V_95 * V_110 = V_139 -> V_143 ;
T_3 * V_144 ;
F_14 ( L_33 ,
V_110 -> V_116 , V_110 -> V_145 . V_82 -> V_146 ,
V_142 -> V_77 , V_142 -> V_78 ,
V_142 -> V_88 , V_142 -> V_10 ) ;
V_144 = F_55 ( V_141 , ( V_153 + V_154 ) << 2 ) ;
* V_144 ++ = F_56 ( V_142 -> V_77 ) ;
* V_144 = F_56 ( V_142 -> V_78 ) ;
F_62 ( V_141 , V_142 -> V_88 , V_155 ) ;
F_62 ( V_141 , V_142 -> V_10 , V_156 ) ;
F_62 ( V_141 , V_142 -> V_92 , V_157 ) ;
}
static int F_66 ( struct V_138 * V_139 , struct V_140 * V_141 ,
struct V_6 * V_142 )
{
struct V_113 V_31 ;
struct V_32 * V_86 = (struct V_32 * ) & V_31 ;
struct V_95 * V_110 = V_139 -> V_143 ;
T_3 * V_144 ;
T_2 V_152 ;
V_142 -> V_80 = 0 ;
V_144 = F_58 ( V_141 , 4 ) ;
if ( F_59 ( V_144 == NULL ) )
goto V_158;
V_152 = F_60 ( V_144 ) ;
if ( V_152 == 0 ) {
F_14 ( L_34 ,
V_110 -> V_116 ) ;
return 0 ;
}
if ( F_59 ( V_152 > V_156 ) )
goto V_158;
V_144 = F_58 ( V_141 , V_152 ) ;
if ( F_59 ( V_144 == NULL ) )
goto V_158;
F_14 ( L_35 , V_110 -> V_116 ,
V_110 -> V_145 . V_82 -> V_146 , ( char * ) V_144 ) ;
if ( F_67 ( ( char * ) V_144 , V_152 , V_86 , sizeof( V_31 ) ) == 0 )
goto V_158;
V_142 -> V_80 = F_68 ( V_86 ) ;
return 0 ;
V_158:
F_14 ( L_36 ,
V_110 -> V_116 , V_110 -> V_145 . V_82 -> V_146 ) ;
return - V_130 ;
}
