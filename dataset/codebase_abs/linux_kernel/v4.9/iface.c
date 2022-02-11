int F_1 ( struct V_1 * V_2 )
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
if ( V_21 != V_27 && V_21 != V_28 )
return V_25 ;
F_4 () ;
switch ( V_21 ) {
case V_27 :
{
T_1 V_13 , V_29 ;
V_13 = F_5 ( V_7 -> V_13 ) ;
V_29 = F_5 ( V_7 -> V_29 ) ;
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
case V_28 :
if ( F_6 ( V_2 ) ) {
F_7 () ;
return - V_38 ;
}
F_8 ( & V_2 -> V_2 ,
L_1 ) ;
if ( V_23 -> V_33 != V_34 ||
V_23 -> V_35 . V_36 != V_37 ||
V_23 -> V_35 . V_13 == V_30 ||
V_23 -> V_35 . V_29 == V_31 ||
V_23 -> V_35 . V_29 == V_39 ) {
V_25 = - V_40 ;
break;
}
V_7 -> V_13 = F_9 ( V_23 -> V_35 . V_13 ) ;
V_7 -> V_29 = F_9 ( V_23 -> V_35 . V_29 ) ;
V_25 = F_1 ( V_2 ) ;
break;
}
F_7 () ;
return V_25 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_35 = V_41 ;
T_2 V_16 ;
if ( F_6 ( V_2 ) )
return - V_38 ;
if ( V_4 -> V_7 . V_43 ) {
if ( F_6 ( V_4 -> V_7 . V_43 ) )
return - V_38 ;
}
F_11 ( & V_16 , V_35 -> V_44 ) ;
if ( ! F_12 ( V_16 ) )
return - V_40 ;
memcpy ( V_2 -> V_45 , V_35 -> V_44 , V_2 -> V_46 ) ;
V_4 -> V_7 . V_16 = V_16 ;
if ( V_4 -> V_7 . V_43 )
memcpy ( V_4 -> V_7 . V_43 -> V_45 , V_2 -> V_45 ,
V_2 -> V_46 ) ;
return F_1 ( V_2 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_47 * V_48 = V_4 -> V_48 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
int V_49 ;
if ( V_48 -> V_50 . V_51 & V_52 ) {
V_49 = F_14 ( V_48 ,
V_7 -> V_53 ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( V_48 -> V_50 . V_51 & V_54 ) {
V_49 = F_15 ( V_48 , V_7 -> V_13 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_16 ( V_48 , V_7 -> V_16 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_17 ( V_48 , V_7 -> V_29 ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( V_48 -> V_50 . V_51 & V_55 ) {
V_49 = F_18 ( V_48 , V_7 -> V_56 ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( V_48 -> V_50 . V_51 & V_57 ) {
V_49 = F_19 ( V_48 , V_7 -> V_58 ,
V_7 -> V_59 ,
V_7 -> V_60 ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( V_48 -> V_50 . V_51 & V_61 ) {
V_49 = F_20 ( V_48 , V_7 -> V_62 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 = V_4 -> V_48 ;
int V_63 ;
F_22 () ;
F_23 ( V_64 , & V_4 -> V_65 ) ;
if ( ! V_48 -> V_66 ) {
V_63 = F_13 ( V_4 ) ;
if ( V_63 )
goto V_25;
V_63 = F_24 ( V_48 ) ;
if ( V_63 )
goto V_25;
}
V_48 -> V_66 ++ ;
F_25 ( V_2 ) ;
return 0 ;
V_25:
F_26 ( V_64 , & V_4 -> V_65 ) ;
return V_63 ;
}
static int
F_27 ( struct V_47 * V_48 ,
struct V_7 * V_7 ,
struct V_7 * V_67 )
{
F_22 () ;
if ( V_48 -> V_50 . V_51 & V_52 ) {
if ( V_7 -> V_53 != V_67 -> V_53 )
return - V_38 ;
}
if ( V_48 -> V_50 . V_51 & V_54 ) {
if ( V_7 -> V_13 != V_67 -> V_13 ||
V_7 -> V_29 != V_67 -> V_29 ||
V_7 -> V_16 != V_67 -> V_16 )
return - V_38 ;
}
if ( V_48 -> V_50 . V_51 & V_57 ) {
if ( V_7 -> V_58 != V_67 -> V_58 ||
V_7 -> V_59 != V_67 -> V_59 ||
V_7 -> V_60 != V_67 -> V_60 )
return - V_38 ;
}
if ( V_48 -> V_50 . V_51 & V_61 ) {
if ( V_7 -> V_62 != V_67 -> V_62 )
return - V_38 ;
}
if ( V_48 -> V_50 . V_51 & V_55 ) {
if ( V_7 -> V_56 != V_67 -> V_56 )
return - V_38 ;
}
return 0 ;
}
static int
F_28 ( struct V_3 * V_4 ,
enum V_68 V_69 )
{
struct V_47 * V_48 = V_4 -> V_48 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_3 * V_70 ;
F_29 (nsdata, &local->interfaces, list) {
if ( V_70 != V_4 && F_30 ( V_70 ) ) {
int V_49 ;
if ( V_7 -> V_69 == V_71 &&
V_70 -> V_7 . V_69 == V_71 )
return - V_38 ;
V_49 = F_27 ( V_48 , V_7 ,
& V_70 -> V_7 ) ;
if ( V_49 < 0 )
return V_49 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
V_8 = F_28 ( V_4 , V_7 -> V_69 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_21 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 = V_4 -> V_48 ;
F_22 () ;
F_33 ( V_2 ) ;
V_48 -> V_66 -- ;
F_26 ( V_64 , & V_4 -> V_65 ) ;
if ( ! V_48 -> V_66 )
F_34 ( V_48 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_10 V_11 ;
T_3 V_76 ;
F_36 ( & V_4 -> V_77 , & V_11 ) ;
if ( ! V_11 . V_78 && V_75 -> V_79 && V_75 -> V_80 )
return - V_40 ;
if ( ! V_11 . V_78 ||
( V_75 -> V_79 && ! V_75 -> V_80 ) ||
! V_11 . V_81 )
return 0 ;
if ( V_75 -> V_82 && ! V_75 -> V_83 )
return - V_40 ;
V_76 = V_75 -> V_82 ? V_75 -> V_83 : V_11 . V_81 ;
V_73 -> V_84 . V_85 = 1 ;
V_73 -> V_77 . V_76 = V_76 ;
V_73 -> V_77 . V_86 = V_11 . V_87 . V_88 ;
if ( V_11 . V_87 . V_88 == V_89 )
V_73 -> V_77 . V_90 = V_11 . V_87 . V_91 ;
else if ( V_11 . V_87 . V_88 == V_92 )
V_73 -> V_77 . V_93 = V_11 . V_87 . V_94 ;
V_73 -> V_77 . V_95 = V_11 . V_87 . V_96 ;
return 0 ;
}
static int F_37 ( struct V_97 * V_98 ,
struct V_1 * V_2 ,
const struct V_99 * V_100 ,
const struct V_99 * V_101 ,
unsigned V_102 )
{
struct V_72 V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_74 * V_75 = F_38 ( V_98 ) ;
int V_103 ;
if ( ! V_100 )
return - V_40 ;
memset ( & V_73 . V_84 , 0 , sizeof( V_73 . V_84 ) ) ;
V_73 . V_84 . type = V_75 -> type ;
V_73 . V_84 . V_85 = V_75 -> V_80 ;
V_73 . V_84 . V_104 = V_75 -> V_105 ;
V_73 . V_106 = F_39 ( & V_2 -> V_107 -> V_108 ) & 0xFF ;
if ( F_35 ( V_4 , & V_73 , V_75 ) < 0 )
return - V_40 ;
if ( ! V_101 ) {
if ( V_7 -> V_29 == F_9 ( V_31 ) ||
V_7 -> V_29 == F_9 ( V_39 ) ||
V_7 -> V_13 == F_9 ( V_30 ) ) {
V_73 . V_109 . V_88 = V_110 ;
V_73 . V_109 . V_16 = V_7 -> V_16 ;
} else {
V_73 . V_109 . V_88 = V_37 ;
V_73 . V_109 . V_29 = V_7 -> V_29 ;
}
V_73 . V_109 . V_13 = V_7 -> V_13 ;
} else {
V_73 . V_109 = * ( const struct V_99 * ) V_101 ;
}
V_73 . V_111 = * ( const struct V_99 * ) V_100 ;
V_103 = F_40 ( V_98 , & V_73 ) ;
if ( V_103 < 0 )
return - V_40 ;
F_41 ( V_98 ) ;
V_98 -> V_112 = V_103 ;
if ( V_102 > F_42 ( & V_73 ) )
return - V_113 ;
return V_103 ;
}
static int F_43 ( struct V_97 * V_98 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_100 ,
const void * V_101 ,
unsigned V_102 )
{
struct V_72 V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_74 V_75 = { } ;
int V_103 ;
if ( ! V_100 )
return - V_40 ;
memset ( & V_73 . V_84 , 0 , sizeof( V_73 . V_84 ) ) ;
V_73 . V_84 . type = V_114 ;
V_73 . V_84 . V_104 = V_7 -> V_105 ;
V_73 . V_106 = F_39 ( & V_2 -> V_107 -> V_108 ) & 0xFF ;
if ( F_35 ( V_4 , & V_73 , & V_75 ) < 0 )
return - V_40 ;
V_73 . V_111 . V_13 = V_7 -> V_13 ;
V_73 . V_111 . V_88 = V_110 ;
F_11 ( & V_73 . V_111 . V_16 , V_100 ) ;
V_73 . V_109 . V_13 = V_73 . V_111 . V_13 ;
V_73 . V_109 . V_88 = V_110 ;
if ( ! V_101 )
V_73 . V_109 . V_16 = V_7 -> V_16 ;
else
F_11 ( & V_73 . V_109 . V_16 , V_101 ) ;
V_103 = F_40 ( V_98 , & V_73 ) ;
if ( V_103 < 0 )
return - V_40 ;
F_41 ( V_98 ) ;
V_98 -> V_112 = V_103 ;
if ( V_102 > F_42 ( & V_73 ) )
return - V_113 ;
return V_103 ;
}
static int
F_44 ( const struct V_97 * V_98 , unsigned char * V_115 )
{
struct V_72 V_73 ;
if ( F_45 ( V_98 , & V_73 ) < 0 ) {
F_46 ( L_2 ) ;
return 0 ;
}
if ( V_73 . V_109 . V_88 == V_110 ) {
F_47 ( V_115 , & V_73 . V_109 . V_16 ) ;
return V_116 ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_49 ( & V_4 -> V_77 ) ;
F_50 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_46 = V_116 ;
memset ( V_2 -> V_117 , 0xff , V_116 ) ;
V_2 -> V_118 = V_119 - 1 ;
V_2 -> V_120 = V_121 +
V_122 ;
V_2 -> V_123 = V_124 - V_122 -
V_2 -> V_118 ;
V_2 -> V_125 = 300 ;
V_2 -> V_51 = V_126 | V_127 ;
}
static int
F_52 ( struct V_3 * V_4 ,
enum V_68 type )
{
struct V_7 * V_7 = & V_4 -> V_7 ;
int V_49 ;
T_3 V_128 ;
V_4 -> V_7 . V_69 = type ;
F_53 ( & V_128 , sizeof( V_128 ) ) ;
F_54 ( & V_7 -> V_129 , V_128 ) ;
F_53 ( & V_128 , sizeof( V_128 ) ) ;
F_54 ( & V_7 -> V_108 , V_128 ) ;
V_7 -> V_58 = 3 ;
V_7 -> V_59 = 5 ;
V_7 -> V_60 = 4 ;
V_7 -> V_62 = 3 ;
V_7 -> V_13 = F_9 ( V_30 ) ;
V_7 -> V_29 = F_9 ( V_31 ) ;
switch ( type ) {
case V_71 :
F_11 ( & V_7 -> V_16 ,
V_4 -> V_2 -> V_45 ) ;
V_4 -> V_2 -> V_130 = & V_131 ;
V_4 -> V_2 -> V_132 = F_48 ;
V_4 -> V_2 -> V_133 = & V_134 ;
V_4 -> V_2 -> V_135 = & V_136 ;
V_7 -> V_53 = false ;
V_7 -> V_130 = & V_137 ;
F_55 ( & V_4 -> V_138 ) ;
F_56 ( & V_4 -> V_77 ) ;
V_49 = F_1 ( V_4 -> V_2 ) ;
if ( V_49 < 0 )
return V_49 ;
break;
case V_139 :
V_4 -> V_2 -> V_132 = F_50 ;
V_4 -> V_2 -> V_133 = & V_140 ;
V_7 -> V_53 = true ;
break;
default:
F_57 () ;
}
return 0 ;
}
struct V_1 *
F_58 ( struct V_47 * V_48 , const char * V_141 ,
unsigned char V_142 , enum V_68 type ,
T_2 V_16 )
{
struct V_1 * V_143 = NULL ;
struct V_3 * V_4 = NULL ;
int V_49 = - V_144 ;
F_22 () ;
V_143 = F_59 ( sizeof( * V_4 ) , V_141 ,
V_142 , F_51 ) ;
if ( ! V_143 )
return F_60 ( - V_144 ) ;
V_143 -> V_145 = V_48 -> V_50 . V_146 +
V_147 ;
V_49 = F_61 ( V_143 , V_143 -> V_141 ) ;
if ( V_49 < 0 )
goto V_25;
F_47 ( V_143 -> V_148 ,
& V_48 -> V_50 . V_149 -> V_150 ) ;
switch ( type ) {
case V_71 :
V_143 -> type = V_151 ;
if ( F_12 ( V_16 ) )
F_47 ( V_143 -> V_45 , & V_16 ) ;
else
memcpy ( V_143 -> V_45 , V_143 -> V_148 ,
V_116 ) ;
break;
case V_139 :
V_143 -> type = V_152 ;
break;
default:
V_49 = - V_40 ;
goto V_25;
}
F_62 ( V_143 , & V_48 -> V_149 -> V_2 ) ;
F_63 ( V_143 , F_64 ( V_48 -> V_50 . V_149 ) ) ;
V_4 = F_65 ( V_143 ) ;
V_143 -> V_107 = & V_4 -> V_7 ;
memcpy ( V_4 -> V_141 , V_143 -> V_141 , V_153 ) ;
V_4 -> V_2 = V_143 ;
V_4 -> V_7 . V_154 = V_48 -> V_50 . V_149 ;
V_4 -> V_48 = V_48 ;
V_49 = F_52 ( V_4 , type ) ;
if ( V_49 )
goto V_25;
V_49 = F_66 ( V_143 ) ;
if ( V_49 < 0 )
goto V_25;
F_67 ( & V_48 -> V_155 ) ;
F_68 ( & V_4 -> V_156 , & V_48 -> V_157 ) ;
F_69 ( & V_48 -> V_155 ) ;
return V_143 ;
V_25:
F_50 ( V_143 ) ;
return F_60 ( V_49 ) ;
}
void F_70 ( struct V_3 * V_4 )
{
F_22 () ;
F_67 ( & V_4 -> V_48 -> V_155 ) ;
F_71 ( & V_4 -> V_156 ) ;
F_69 ( & V_4 -> V_48 -> V_155 ) ;
F_72 () ;
F_73 ( V_4 -> V_2 ) ;
}
void F_74 ( struct V_47 * V_48 )
{
struct V_3 * V_4 , * V_128 ;
F_67 ( & V_48 -> V_155 ) ;
F_75 (sdata, tmp, &local->interfaces, list) {
F_76 ( & V_4 -> V_156 ) ;
F_73 ( V_4 -> V_2 ) ;
}
F_69 ( & V_48 -> V_155 ) ;
}
static int F_77 ( struct V_158 * V_159 ,
unsigned long V_65 , void * V_160 )
{
struct V_1 * V_2 = F_78 ( V_160 ) ;
struct V_3 * V_4 ;
if ( V_65 != V_161 )
return V_162 ;
if ( ! V_2 -> V_107 || ! V_2 -> V_107 -> V_154 )
return V_162 ;
if ( V_2 -> V_107 -> V_154 -> V_163 != V_164 )
return V_162 ;
V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 -> V_141 , V_2 -> V_141 , V_153 ) ;
return V_165 ;
}
int F_79 ( void )
{
return F_80 ( & V_166 ) ;
}
void F_81 ( void )
{
F_82 ( & V_166 ) ;
}
