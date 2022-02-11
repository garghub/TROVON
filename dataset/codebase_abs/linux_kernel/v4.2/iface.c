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
F_11 ( & V_16 , V_35 -> V_43 ) ;
if ( ! F_12 ( V_16 ) )
return - V_40 ;
memcpy ( V_2 -> V_44 , V_35 -> V_43 , V_2 -> V_45 ) ;
V_4 -> V_7 . V_16 = V_16 ;
return F_1 ( V_2 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_46 * V_47 = V_4 -> V_47 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
int V_48 ;
if ( V_47 -> V_49 . V_50 & V_51 ) {
V_48 = F_14 ( V_47 ,
V_7 -> V_52 ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( V_47 -> V_49 . V_50 & V_53 ) {
V_48 = F_15 ( V_47 , V_7 -> V_13 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_16 ( V_47 , V_7 -> V_16 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_17 ( V_47 , V_7 -> V_29 ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( V_47 -> V_49 . V_50 & V_54 ) {
V_48 = F_18 ( V_47 , V_7 -> V_55 ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( V_47 -> V_49 . V_50 & V_56 ) {
V_48 = F_19 ( V_47 , V_7 -> V_57 ,
V_7 -> V_58 ,
V_7 -> V_59 ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( V_47 -> V_49 . V_50 & V_60 ) {
V_48 = F_20 ( V_47 , V_7 -> V_61 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_46 * V_47 = V_4 -> V_47 ;
int V_62 ;
F_22 () ;
F_23 ( V_63 , & V_4 -> V_64 ) ;
if ( ! V_47 -> V_65 ) {
V_62 = F_13 ( V_4 ) ;
if ( V_62 )
goto V_25;
V_62 = F_24 ( V_47 ) ;
if ( V_62 )
goto V_25;
}
V_47 -> V_65 ++ ;
F_25 ( V_2 ) ;
return 0 ;
V_25:
F_26 ( V_63 , & V_4 -> V_64 ) ;
return V_62 ;
}
static int
F_27 ( struct V_46 * V_47 ,
struct V_7 * V_7 ,
struct V_7 * V_66 )
{
F_22 () ;
if ( V_47 -> V_49 . V_50 & V_51 ) {
if ( V_7 -> V_52 != V_66 -> V_52 )
return - V_38 ;
}
if ( V_47 -> V_49 . V_50 & V_53 ) {
if ( V_7 -> V_13 != V_66 -> V_13 ||
V_7 -> V_29 != V_66 -> V_29 ||
V_7 -> V_16 != V_66 -> V_16 )
return - V_38 ;
}
if ( V_47 -> V_49 . V_50 & V_56 ) {
if ( V_7 -> V_57 != V_66 -> V_57 ||
V_7 -> V_58 != V_66 -> V_58 ||
V_7 -> V_59 != V_66 -> V_59 )
return - V_38 ;
}
if ( V_47 -> V_49 . V_50 & V_60 ) {
if ( V_7 -> V_61 != V_66 -> V_61 )
return - V_38 ;
}
if ( V_47 -> V_49 . V_50 & V_54 ) {
if ( V_7 -> V_55 != V_66 -> V_55 )
return - V_38 ;
}
return 0 ;
}
static int
F_28 ( struct V_3 * V_4 ,
enum V_67 V_68 )
{
struct V_46 * V_47 = V_4 -> V_47 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_3 * V_69 ;
F_29 (nsdata, &local->interfaces, list) {
if ( V_69 != V_4 && F_30 ( V_69 ) ) {
int V_48 ;
if ( V_7 -> V_68 == V_70 &&
V_69 -> V_7 . V_68 == V_70 )
return - V_38 ;
V_48 = F_27 ( V_47 , V_7 ,
& V_69 -> V_7 ) ;
if ( V_48 < 0 )
return V_48 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
V_8 = F_28 ( V_4 , V_7 -> V_68 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_21 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_46 * V_47 = V_4 -> V_47 ;
F_22 () ;
F_33 ( V_2 ) ;
V_47 -> V_65 -- ;
F_26 ( V_63 , & V_4 -> V_64 ) ;
if ( ! V_47 -> V_65 ) {
F_34 ( V_47 -> V_71 ) ;
F_35 ( & V_47 -> V_72 ) ;
F_36 ( V_47 ) ;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_10 V_11 ;
T_3 V_77 ;
F_38 ( & V_4 -> V_78 , & V_11 ) ;
if ( ! V_11 . V_79 && V_76 -> V_80 && V_76 -> V_81 )
return - V_40 ;
if ( ! V_11 . V_79 ||
( V_76 -> V_80 && ! V_76 -> V_81 ) ||
! V_11 . V_82 )
return 0 ;
if ( V_76 -> V_83 && ! V_76 -> V_84 )
return - V_40 ;
V_77 = V_76 -> V_83 ? V_76 -> V_84 : V_11 . V_82 ;
V_74 -> V_85 . V_86 = 1 ;
V_74 -> V_78 . V_77 = V_77 ;
V_74 -> V_78 . V_87 = V_11 . V_88 . V_89 ;
if ( V_11 . V_88 . V_89 == V_90 )
V_74 -> V_78 . V_91 = V_11 . V_88 . V_92 ;
else if ( V_11 . V_88 . V_89 == V_93 )
V_74 -> V_78 . V_94 = V_11 . V_88 . V_95 ;
V_74 -> V_78 . V_96 = V_11 . V_88 . V_97 ;
return 0 ;
}
static int F_39 ( struct V_98 * V_99 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_100 ,
const void * V_101 ,
unsigned V_102 )
{
struct V_73 V_74 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_75 * V_76 = F_40 ( V_99 ) ;
int V_103 ;
if ( ! V_100 )
return - V_40 ;
memset ( & V_74 . V_85 , 0 , sizeof( V_74 . V_85 ) ) ;
V_74 . V_85 . type = V_76 -> type ;
V_74 . V_85 . V_86 = V_76 -> V_81 ;
V_74 . V_85 . V_104 = V_76 -> V_105 ;
V_74 . V_106 = F_41 ( & V_2 -> V_107 -> V_108 ) & 0xFF ;
if ( F_37 ( V_4 , & V_74 , V_76 ) < 0 )
return - V_40 ;
if ( ! V_101 ) {
if ( V_7 -> V_29 == F_9 ( V_31 ) ||
V_7 -> V_29 == F_9 ( V_39 ) ||
V_7 -> V_13 == F_9 ( V_30 ) ) {
V_74 . V_109 . V_89 = V_110 ;
V_74 . V_109 . V_16 = V_7 -> V_16 ;
} else {
V_74 . V_109 . V_89 = V_37 ;
V_74 . V_109 . V_29 = V_7 -> V_29 ;
}
V_74 . V_109 . V_13 = V_7 -> V_13 ;
} else {
V_74 . V_109 = * ( const struct V_111 * ) V_101 ;
}
V_74 . V_112 = * ( const struct V_111 * ) V_100 ;
V_103 = F_42 ( V_99 , & V_74 ) ;
if ( V_103 < 0 )
return - V_40 ;
F_43 ( V_99 ) ;
V_99 -> V_113 = V_103 ;
if ( V_102 > F_44 ( & V_74 ) )
return - V_114 ;
return V_103 ;
}
static int
F_45 ( const struct V_98 * V_99 , unsigned char * V_115 )
{
struct V_73 V_74 ;
struct V_111 * V_35 = (struct V_111 * ) V_115 ;
if ( F_46 ( V_99 , & V_74 ) < 0 ) {
F_47 ( L_2 ) ;
return 0 ;
}
* V_35 = V_74 . V_109 ;
return sizeof( * V_35 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_49 ( & V_4 -> V_78 ) ;
F_50 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_45 = V_116 ;
memset ( V_2 -> V_117 , 0xff , V_116 ) ;
V_2 -> V_118 = V_119 ;
V_2 -> V_120 = 2 + 16 ;
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = 300 ;
V_2 -> V_50 = V_124 | V_125 ;
}
static int
F_52 ( struct V_3 * V_4 ,
enum V_67 type )
{
struct V_7 * V_7 = & V_4 -> V_7 ;
T_3 V_126 ;
V_4 -> V_7 . V_68 = type ;
F_53 ( & V_126 , sizeof( V_126 ) ) ;
F_54 ( & V_7 -> V_127 , V_126 ) ;
F_53 ( & V_126 , sizeof( V_126 ) ) ;
F_54 ( & V_7 -> V_108 , V_126 ) ;
V_7 -> V_57 = 3 ;
V_7 -> V_58 = 5 ;
V_7 -> V_59 = 4 ;
V_7 -> V_61 = - 1 ;
V_7 -> V_13 = F_9 ( V_30 ) ;
V_7 -> V_29 = F_9 ( V_31 ) ;
switch ( type ) {
case V_70 :
F_11 ( & V_7 -> V_16 ,
V_4 -> V_2 -> V_44 ) ;
V_4 -> V_2 -> V_128 = & V_129 ;
V_4 -> V_2 -> V_130 = F_48 ;
V_4 -> V_2 -> V_131 = & V_132 ;
V_4 -> V_2 -> V_133 = & V_134 ;
V_7 -> V_52 = false ;
F_55 ( & V_4 -> V_135 ) ;
F_56 ( & V_4 -> V_78 ) ;
break;
case V_136 :
V_4 -> V_2 -> V_130 = F_50 ;
V_4 -> V_2 -> V_131 = & V_137 ;
V_7 -> V_52 = true ;
break;
default:
F_57 () ;
}
return 0 ;
}
struct V_1 *
F_58 ( struct V_46 * V_47 , const char * V_138 ,
unsigned char V_139 , enum V_67 type ,
T_2 V_16 )
{
struct V_1 * V_140 = NULL ;
struct V_3 * V_4 = NULL ;
int V_48 = - V_141 ;
F_22 () ;
V_140 = F_59 ( sizeof( * V_4 ) , V_138 ,
V_139 , F_51 ) ;
if ( ! V_140 )
return F_60 ( - V_141 ) ;
V_140 -> V_142 = V_47 -> V_49 . V_143 ;
V_48 = F_61 ( V_140 , V_140 -> V_138 ) ;
if ( V_48 < 0 )
goto V_25;
F_62 ( V_140 -> V_144 ,
& V_47 -> V_49 . V_145 -> V_146 ) ;
switch ( type ) {
case V_70 :
V_140 -> type = V_147 ;
if ( F_12 ( V_16 ) )
F_62 ( V_140 -> V_44 , & V_16 ) ;
else
memcpy ( V_140 -> V_44 , V_140 -> V_144 ,
V_116 ) ;
break;
case V_136 :
V_140 -> type = V_148 ;
break;
default:
V_48 = - V_40 ;
goto V_25;
}
F_63 ( V_140 , & V_47 -> V_145 -> V_2 ) ;
V_4 = F_64 ( V_140 ) ;
V_140 -> V_107 = & V_4 -> V_7 ;
memcpy ( V_4 -> V_138 , V_140 -> V_138 , V_149 ) ;
V_4 -> V_2 = V_140 ;
V_4 -> V_7 . V_150 = V_47 -> V_49 . V_145 ;
V_4 -> V_47 = V_47 ;
V_48 = F_52 ( V_4 , type ) ;
if ( V_48 )
goto V_25;
V_48 = F_65 ( V_140 ) ;
if ( V_48 < 0 )
goto V_25;
F_66 ( & V_47 -> V_151 ) ;
F_67 ( & V_4 -> V_152 , & V_47 -> V_153 ) ;
F_68 ( & V_47 -> V_151 ) ;
return V_140 ;
V_25:
F_50 ( V_140 ) ;
return F_60 ( V_48 ) ;
}
void F_69 ( struct V_3 * V_4 )
{
F_22 () ;
F_66 ( & V_4 -> V_47 -> V_151 ) ;
F_70 ( & V_4 -> V_152 ) ;
F_68 ( & V_4 -> V_47 -> V_151 ) ;
F_71 () ;
F_72 ( V_4 -> V_2 ) ;
}
void F_73 ( struct V_46 * V_47 )
{
struct V_3 * V_4 , * V_126 ;
F_66 ( & V_47 -> V_151 ) ;
F_74 (sdata, tmp, &local->interfaces, list) {
F_75 ( & V_4 -> V_152 ) ;
F_72 ( V_4 -> V_2 ) ;
}
F_68 ( & V_47 -> V_151 ) ;
}
static int F_76 ( struct V_154 * V_155 ,
unsigned long V_64 , void * V_156 )
{
struct V_1 * V_2 = F_77 ( V_156 ) ;
struct V_3 * V_4 ;
if ( V_64 != V_157 )
return V_158 ;
if ( ! V_2 -> V_107 || ! V_2 -> V_107 -> V_150 )
return V_158 ;
if ( V_2 -> V_107 -> V_150 -> V_159 != V_160 )
return V_158 ;
V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 -> V_138 , V_2 -> V_138 , V_149 ) ;
return V_161 ;
}
int F_78 ( void )
{
return F_79 ( & V_162 ) ;
}
void F_80 ( void )
{
F_81 ( & V_162 ) ;
}
