static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_6 -> V_9 ) {
struct V_10 V_11 ;
int V_12 = 0 ;
V_11 . V_13 = V_7 -> V_13 ;
V_12 |= V_14 ;
V_11 . V_15 = V_7 -> V_16 ;
V_12 |= V_17 ;
V_8 = V_6 -> V_9 -> V_18 ( V_2 , & V_11 , V_12 ) ;
}
return V_8 ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_19 * V_20 , int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_22 * V_23 =
(struct V_22 * ) & V_20 -> V_24 ;
int V_25 = - V_26 ;
F_4 () ;
F_5 ( & V_4 -> V_27 ) ;
switch ( V_21 ) {
case V_28 :
{
T_1 V_13 , V_29 ;
V_13 = F_6 ( V_7 -> V_13 ) ;
V_29 = F_6 ( V_7 -> V_29 ) ;
if ( V_13 == V_30 ||
V_29 == V_31 ) {
V_25 = - V_32 ;
break;
}
V_23 -> V_33 = V_34 ;
V_23 -> V_35 . V_36 = V_37 ;
V_23 -> V_35 . V_13 = V_13 ;
V_23 -> V_35 . V_29 = V_29 ;
V_25 = 0 ;
break;
}
case V_38 :
if ( F_7 ( V_2 ) ) {
F_8 ( & V_4 -> V_27 ) ;
return - V_39 ;
}
F_9 ( & V_2 -> V_2 ,
L_1 ) ;
if ( V_23 -> V_33 != V_34 ||
V_23 -> V_35 . V_36 != V_37 ||
V_23 -> V_35 . V_13 == V_30 ||
V_23 -> V_35 . V_29 == V_31 ||
V_23 -> V_35 . V_29 == V_40 ) {
V_25 = - V_41 ;
break;
}
V_7 -> V_13 = F_10 ( V_23 -> V_35 . V_13 ) ;
V_7 -> V_29 = F_10 ( V_23 -> V_35 . V_29 ) ;
V_25 = F_1 ( V_2 ) ;
break;
}
F_8 ( & V_4 -> V_27 ) ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_35 = V_42 ;
T_2 V_16 ;
if ( F_7 ( V_2 ) )
return - V_39 ;
F_12 ( & V_16 , V_35 -> V_44 ) ;
if ( ! F_13 ( V_16 ) )
return - V_41 ;
memcpy ( V_2 -> V_45 , V_35 -> V_44 , V_2 -> V_46 ) ;
V_4 -> V_7 . V_16 = V_16 ;
return F_1 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 = V_4 -> V_48 ;
int V_49 = 0 ;
F_4 () ;
F_15 ( V_50 , & V_4 -> V_51 ) ;
if ( ! V_48 -> V_52 ) {
V_49 = F_16 ( V_48 ) ;
F_17 ( V_49 ) ;
if ( V_49 )
goto V_25;
}
V_48 -> V_52 ++ ;
F_18 ( V_2 ) ;
return 0 ;
V_25:
F_19 ( V_50 , & V_4 -> V_51 ) ;
return V_49 ;
}
static int
F_20 ( struct V_47 * V_48 ,
struct V_7 * V_7 ,
struct V_7 * V_53 )
{
F_4 () ;
if ( V_48 -> V_54 . V_55 & V_56 ) {
if ( V_7 -> V_57 != V_53 -> V_57 )
return - V_39 ;
}
if ( V_48 -> V_54 . V_55 & V_58 ) {
if ( V_7 -> V_13 != V_53 -> V_13 )
return - V_39 ;
if ( V_7 -> V_29 != V_53 -> V_29 )
return - V_39 ;
if ( V_7 -> V_16 != V_53 -> V_16 )
return - V_39 ;
}
if ( V_48 -> V_54 . V_55 & V_59 ) {
if ( V_7 -> V_60 != V_53 -> V_60 )
return - V_39 ;
if ( V_7 -> V_61 != V_53 -> V_61 )
return - V_39 ;
if ( V_7 -> V_62 != V_53 -> V_62 )
return - V_39 ;
}
if ( V_48 -> V_54 . V_55 & V_63 ) {
if ( V_7 -> V_64 != V_53 -> V_64 )
return - V_39 ;
}
if ( V_48 -> V_54 . V_55 & V_65 ) {
if ( V_7 -> V_66 != V_53 -> V_66 )
return - V_39 ;
}
return 0 ;
}
static int
F_21 ( struct V_3 * V_4 ,
enum V_67 V_68 )
{
struct V_47 * V_48 = V_4 -> V_48 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_3 * V_69 ;
F_22 (nsdata, &local->interfaces, list) {
if ( V_69 != V_4 && F_23 ( V_69 ) ) {
int V_70 ;
if ( V_4 -> V_71 . type == V_72 &&
V_69 -> V_71 . type == V_72 )
return - V_39 ;
V_70 = F_20 ( V_48 , V_7 ,
& V_69 -> V_7 ) ;
if ( V_70 < 0 )
return V_70 ;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 = V_4 -> V_48 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_73 * V_74 = V_4 -> V_48 -> V_74 ;
V_8 = F_21 ( V_4 , V_4 -> V_71 . type ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
F_25 ( & V_74 -> V_75 ) ;
if ( V_48 -> V_54 . V_55 & V_56 ) {
V_8 = F_26 ( V_48 ,
V_7 -> V_57 ) ;
if ( V_8 < 0 )
goto V_76;
}
if ( V_48 -> V_54 . V_55 & V_58 ) {
V_8 = F_27 ( V_48 , V_7 -> V_13 ) ;
if ( V_8 < 0 )
goto V_76;
V_8 = F_28 ( V_48 , V_7 -> V_16 ) ;
if ( V_8 < 0 )
goto V_76;
V_8 = F_29 ( V_48 , V_7 -> V_29 ) ;
if ( V_8 < 0 )
goto V_76;
}
if ( V_48 -> V_54 . V_55 & V_65 ) {
V_8 = F_30 ( V_48 , V_7 -> V_66 ) ;
if ( V_8 < 0 )
goto V_76;
}
if ( V_48 -> V_54 . V_55 & V_59 ) {
V_8 = F_31 ( V_48 , V_7 -> V_60 ,
V_7 -> V_61 ,
V_7 -> V_62 ) ;
if ( V_8 < 0 )
goto V_76;
}
if ( V_48 -> V_54 . V_55 & V_63 ) {
V_8 = F_32 ( V_48 , V_7 -> V_64 ) ;
if ( V_8 < 0 )
goto V_76;
}
F_33 ( & V_74 -> V_75 ) ;
return 0 ;
V_76:
F_33 ( & V_74 -> V_75 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 = V_4 -> V_48 ;
F_4 () ;
F_35 ( & V_48 -> V_77 ) ;
F_36 ( V_2 ) ;
V_48 -> V_52 -- ;
F_19 ( V_50 , & V_4 -> V_51 ) ;
if ( ! V_48 -> V_52 )
F_37 ( V_48 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_78 * V_79 ,
const struct V_80 * V_81 )
{
struct V_10 V_11 ;
T_3 V_82 ;
F_39 ( & V_4 -> V_83 , & V_11 ) ;
if ( ! V_11 . V_84 && V_81 -> V_85 && V_81 -> V_86 )
return - V_41 ;
if ( ! V_11 . V_84 ||
( V_81 -> V_85 && ! V_81 -> V_86 ) ||
! V_11 . V_87 )
return 0 ;
if ( V_81 -> V_88 && ! V_81 -> V_89 )
return - V_41 ;
V_82 = V_81 -> V_88 ? V_81 -> V_89 : V_11 . V_87 ;
V_79 -> V_90 . V_91 = 1 ;
V_79 -> V_83 . V_82 = V_82 ;
V_79 -> V_83 . V_92 = V_11 . V_93 . V_94 ;
if ( V_11 . V_93 . V_94 == V_95 )
V_79 -> V_83 . V_96 = V_11 . V_93 . V_97 ;
else if ( V_11 . V_93 . V_94 == V_98 )
V_79 -> V_83 . V_99 = V_11 . V_93 . V_100 ;
V_79 -> V_83 . V_101 = V_11 . V_93 . V_102 ;
return 0 ;
}
static int F_40 ( struct V_103 * V_104 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_105 ,
const void * V_106 ,
unsigned V_107 )
{
struct V_78 V_79 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_80 * V_81 = F_41 ( V_104 ) ;
int V_108 ;
if ( ! V_105 )
return - V_41 ;
memset ( & V_79 . V_90 , 0 , sizeof( V_79 . V_90 ) ) ;
V_79 . V_90 . type = V_81 -> type ;
V_79 . V_90 . V_91 = V_81 -> V_86 ;
V_79 . V_90 . V_109 = V_81 -> V_110 ;
V_79 . V_111 = V_5 ( V_2 ) -> F_42 ( V_2 ) ;
if ( F_38 ( V_4 , & V_79 , V_81 ) < 0 )
return - V_41 ;
if ( ! V_106 ) {
F_5 ( & V_4 -> V_27 ) ;
if ( V_7 -> V_29 == F_10 ( V_31 ) ||
V_7 -> V_29 == F_10 ( V_40 ) ||
V_7 -> V_13 == F_10 ( V_30 ) ) {
V_79 . V_112 . V_94 = V_113 ;
V_79 . V_112 . V_16 = V_7 -> V_16 ;
} else {
V_79 . V_112 . V_94 = V_37 ;
V_79 . V_112 . V_29 = V_7 -> V_29 ;
}
V_79 . V_112 . V_13 = V_7 -> V_13 ;
F_8 ( & V_4 -> V_27 ) ;
} else {
V_79 . V_112 = * ( const struct V_114 * ) V_106 ;
}
V_79 . V_115 = * ( const struct V_114 * ) V_105 ;
V_108 = F_43 ( V_104 , & V_79 ) ;
if ( V_108 < 0 )
return - V_41 ;
F_44 ( V_104 ) ;
V_104 -> V_116 = V_108 ;
if ( V_107 > F_45 ( & V_79 ) )
return - V_117 ;
return V_108 ;
}
static int
F_46 ( const struct V_103 * V_104 , unsigned char * V_118 )
{
struct V_78 V_79 ;
struct V_114 * V_35 = (struct V_114 * ) V_118 ;
if ( F_47 ( V_104 , & V_79 ) < 0 ) {
F_48 ( L_2 ) ;
return 0 ;
}
* V_35 = V_79 . V_112 ;
return sizeof( * V_35 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_50 ( & V_4 -> V_83 ) ;
F_51 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_46 = V_119 ;
memset ( V_2 -> V_120 , 0xff , V_119 ) ;
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = 2 + 16 ;
V_2 -> V_124 = V_125 ;
V_2 -> V_126 = 300 ;
V_2 -> V_55 = V_127 | V_128 ;
}
static int
F_53 ( struct V_3 * V_4 ,
enum V_67 type )
{
struct V_7 * V_7 = & V_4 -> V_7 ;
V_4 -> V_71 . type = type ;
V_4 -> V_7 . V_68 = type ;
F_54 ( & V_7 -> V_129 , 1 ) ;
F_54 ( & V_7 -> V_130 , 1 ) ;
V_7 -> V_60 = 3 ;
V_7 -> V_61 = 5 ;
V_7 -> V_62 = 4 ;
V_7 -> V_64 = - 1 ;
V_7 -> V_13 = F_10 ( V_30 ) ;
V_7 -> V_29 = F_10 ( V_31 ) ;
switch ( type ) {
case V_72 :
F_12 ( & V_7 -> V_16 ,
V_4 -> V_2 -> V_45 ) ;
V_4 -> V_2 -> V_131 = & V_132 ;
V_4 -> V_2 -> V_133 = F_49 ;
V_4 -> V_2 -> V_134 = & V_135 ;
V_4 -> V_2 -> V_136 = & V_137 ;
V_7 -> V_57 = false ;
F_55 ( & V_4 -> V_27 ) ;
F_56 ( & V_4 -> V_138 ) ;
F_57 ( & V_4 -> V_83 ) ;
break;
case V_139 :
V_4 -> V_2 -> V_133 = F_51 ;
V_4 -> V_2 -> V_134 = & V_140 ;
V_7 -> V_57 = true ;
break;
default:
F_58 () ;
}
return 0 ;
}
struct V_1 *
F_59 ( struct V_47 * V_48 , const char * V_141 ,
enum V_67 type , T_2 V_16 )
{
struct V_1 * V_142 = NULL ;
struct V_3 * V_4 = NULL ;
int V_70 = - V_143 ;
F_4 () ;
V_142 = F_60 ( sizeof( * V_4 ) + V_48 -> V_54 . V_144 , V_141 ,
V_145 , F_52 ) ;
if ( ! V_142 )
return F_61 ( - V_143 ) ;
V_142 -> V_146 = V_48 -> V_54 . V_147 ;
V_70 = F_62 ( V_142 , V_142 -> V_141 ) ;
if ( V_70 < 0 )
goto V_25;
F_63 ( V_142 -> V_148 ,
& V_48 -> V_54 . V_74 -> V_149 ) ;
switch ( type ) {
case V_72 :
V_142 -> type = V_150 ;
if ( F_13 ( V_16 ) )
F_63 ( V_142 -> V_45 , & V_16 ) ;
else
memcpy ( V_142 -> V_45 , V_142 -> V_148 ,
V_119 ) ;
break;
case V_139 :
V_142 -> type = V_151 ;
break;
default:
V_70 = - V_41 ;
goto V_25;
}
F_64 ( V_142 , & V_48 -> V_74 -> V_2 ) ;
V_4 = F_65 ( V_142 ) ;
V_142 -> V_152 = & V_4 -> V_7 ;
memcpy ( V_4 -> V_141 , V_142 -> V_141 , V_153 ) ;
V_4 -> V_2 = V_142 ;
V_4 -> V_7 . V_73 = V_48 -> V_54 . V_74 ;
V_4 -> V_48 = V_48 ;
V_70 = F_53 ( V_4 , type ) ;
if ( V_70 )
goto V_25;
V_70 = F_66 ( V_142 ) ;
if ( V_70 < 0 )
goto V_25;
F_25 ( & V_48 -> V_154 ) ;
F_67 ( & V_4 -> V_155 , & V_48 -> V_156 ) ;
F_33 ( & V_48 -> V_154 ) ;
return V_142 ;
V_25:
F_51 ( V_142 ) ;
return F_61 ( V_70 ) ;
}
void F_68 ( struct V_3 * V_4 )
{
F_4 () ;
F_25 ( & V_4 -> V_48 -> V_154 ) ;
F_69 ( & V_4 -> V_155 ) ;
F_33 ( & V_4 -> V_48 -> V_154 ) ;
F_70 () ;
F_71 ( V_4 -> V_2 ) ;
}
void F_72 ( struct V_47 * V_48 )
{
struct V_3 * V_4 , * V_157 ;
F_25 ( & V_48 -> V_154 ) ;
F_73 (sdata, tmp, &local->interfaces, list) {
F_74 ( & V_4 -> V_155 ) ;
F_71 ( V_4 -> V_2 ) ;
}
F_33 ( & V_48 -> V_154 ) ;
}
static int F_75 ( struct V_158 * V_159 ,
unsigned long V_51 , void * V_160 )
{
struct V_1 * V_2 = F_76 ( V_160 ) ;
struct V_3 * V_4 ;
if ( V_51 != V_161 )
return V_162 ;
if ( ! V_2 -> V_152 || ! V_2 -> V_152 -> V_73 )
return V_162 ;
if ( V_2 -> V_152 -> V_73 -> V_163 != V_164 )
return V_162 ;
V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 -> V_141 , V_2 -> V_141 , V_153 ) ;
return V_165 ;
}
int F_77 ( void )
{
return F_78 ( & V_166 ) ;
}
void F_79 ( void )
{
F_80 ( & V_166 ) ;
}
