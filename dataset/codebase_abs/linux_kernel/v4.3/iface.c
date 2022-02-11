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
unsigned short type ,
const void * V_99 ,
const void * V_100 ,
unsigned V_101 )
{
struct V_72 V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_74 * V_75 = F_38 ( V_98 ) ;
int V_102 ;
if ( ! V_99 )
return - V_40 ;
memset ( & V_73 . V_84 , 0 , sizeof( V_73 . V_84 ) ) ;
V_73 . V_84 . type = V_75 -> type ;
V_73 . V_84 . V_85 = V_75 -> V_80 ;
V_73 . V_84 . V_103 = V_75 -> V_104 ;
V_73 . V_105 = F_39 ( & V_2 -> V_106 -> V_107 ) & 0xFF ;
if ( F_35 ( V_4 , & V_73 , V_75 ) < 0 )
return - V_40 ;
if ( ! V_100 ) {
if ( V_7 -> V_29 == F_9 ( V_31 ) ||
V_7 -> V_29 == F_9 ( V_39 ) ||
V_7 -> V_13 == F_9 ( V_30 ) ) {
V_73 . V_108 . V_88 = V_109 ;
V_73 . V_108 . V_16 = V_7 -> V_16 ;
} else {
V_73 . V_108 . V_88 = V_37 ;
V_73 . V_108 . V_29 = V_7 -> V_29 ;
}
V_73 . V_108 . V_13 = V_7 -> V_13 ;
} else {
V_73 . V_108 = * ( const struct V_110 * ) V_100 ;
}
V_73 . V_111 = * ( const struct V_110 * ) V_99 ;
V_102 = F_40 ( V_98 , & V_73 ) ;
if ( V_102 < 0 )
return - V_40 ;
F_41 ( V_98 ) ;
V_98 -> V_112 = V_102 ;
if ( V_101 > F_42 ( & V_73 ) )
return - V_113 ;
return V_102 ;
}
static int
F_43 ( const struct V_97 * V_98 , unsigned char * V_114 )
{
struct V_72 V_73 ;
struct V_110 * V_35 = (struct V_110 * ) V_114 ;
if ( F_44 ( V_98 , & V_73 ) < 0 ) {
F_45 ( L_2 ) ;
return 0 ;
}
* V_35 = V_73 . V_108 ;
return sizeof( * V_35 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_47 ( & V_4 -> V_77 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
V_2 -> V_46 = V_115 ;
memset ( V_2 -> V_116 , 0xff , V_115 ) ;
V_2 -> V_117 = V_118 ;
V_2 -> V_119 = 2 + 16 ;
V_2 -> V_120 = V_121 ;
V_2 -> V_122 = 300 ;
V_2 -> V_51 = V_123 | V_124 ;
}
static int
F_50 ( struct V_3 * V_4 ,
enum V_68 type )
{
struct V_7 * V_7 = & V_4 -> V_7 ;
int V_49 ;
T_3 V_125 ;
V_4 -> V_7 . V_69 = type ;
F_51 ( & V_125 , sizeof( V_125 ) ) ;
F_52 ( & V_7 -> V_126 , V_125 ) ;
F_51 ( & V_125 , sizeof( V_125 ) ) ;
F_52 ( & V_7 -> V_107 , V_125 ) ;
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
V_4 -> V_2 -> V_127 = & V_128 ;
V_4 -> V_2 -> V_129 = F_46 ;
V_4 -> V_2 -> V_130 = & V_131 ;
V_4 -> V_2 -> V_132 = & V_133 ;
V_7 -> V_53 = false ;
F_53 ( & V_4 -> V_134 ) ;
F_54 ( & V_4 -> V_77 ) ;
V_49 = F_1 ( V_4 -> V_2 ) ;
if ( V_49 < 0 )
return V_49 ;
break;
case V_135 :
V_4 -> V_2 -> V_129 = F_48 ;
V_4 -> V_2 -> V_130 = & V_136 ;
V_7 -> V_53 = true ;
break;
default:
F_55 () ;
}
return 0 ;
}
struct V_1 *
F_56 ( struct V_47 * V_48 , const char * V_137 ,
unsigned char V_138 , enum V_68 type ,
T_2 V_16 )
{
struct V_1 * V_139 = NULL ;
struct V_3 * V_4 = NULL ;
int V_49 = - V_140 ;
F_22 () ;
V_139 = F_57 ( sizeof( * V_4 ) , V_137 ,
V_138 , F_49 ) ;
if ( ! V_139 )
return F_58 ( - V_140 ) ;
V_139 -> V_141 = V_48 -> V_50 . V_142 ;
V_49 = F_59 ( V_139 , V_139 -> V_137 ) ;
if ( V_49 < 0 )
goto V_25;
F_60 ( V_139 -> V_143 ,
& V_48 -> V_50 . V_144 -> V_145 ) ;
switch ( type ) {
case V_71 :
V_139 -> type = V_146 ;
if ( F_12 ( V_16 ) )
F_60 ( V_139 -> V_45 , & V_16 ) ;
else
memcpy ( V_139 -> V_45 , V_139 -> V_143 ,
V_115 ) ;
break;
case V_135 :
V_139 -> type = V_147 ;
break;
default:
V_49 = - V_40 ;
goto V_25;
}
F_61 ( V_139 , & V_48 -> V_144 -> V_2 ) ;
V_4 = F_62 ( V_139 ) ;
V_139 -> V_106 = & V_4 -> V_7 ;
memcpy ( V_4 -> V_137 , V_139 -> V_137 , V_148 ) ;
V_4 -> V_2 = V_139 ;
V_4 -> V_7 . V_149 = V_48 -> V_50 . V_144 ;
V_4 -> V_48 = V_48 ;
V_49 = F_50 ( V_4 , type ) ;
if ( V_49 )
goto V_25;
V_49 = F_63 ( V_139 ) ;
if ( V_49 < 0 )
goto V_25;
F_64 ( & V_48 -> V_150 ) ;
F_65 ( & V_4 -> V_151 , & V_48 -> V_152 ) ;
F_66 ( & V_48 -> V_150 ) ;
return V_139 ;
V_25:
F_48 ( V_139 ) ;
return F_58 ( V_49 ) ;
}
void F_67 ( struct V_3 * V_4 )
{
F_22 () ;
F_64 ( & V_4 -> V_48 -> V_150 ) ;
F_68 ( & V_4 -> V_151 ) ;
F_66 ( & V_4 -> V_48 -> V_150 ) ;
F_69 () ;
F_70 ( V_4 -> V_2 ) ;
}
void F_71 ( struct V_47 * V_48 )
{
struct V_3 * V_4 , * V_125 ;
F_64 ( & V_48 -> V_150 ) ;
F_72 (sdata, tmp, &local->interfaces, list) {
F_73 ( & V_4 -> V_151 ) ;
F_70 ( V_4 -> V_2 ) ;
}
F_66 ( & V_48 -> V_150 ) ;
}
static int F_74 ( struct V_153 * V_154 ,
unsigned long V_65 , void * V_155 )
{
struct V_1 * V_2 = F_75 ( V_155 ) ;
struct V_3 * V_4 ;
if ( V_65 != V_156 )
return V_157 ;
if ( ! V_2 -> V_106 || ! V_2 -> V_106 -> V_149 )
return V_157 ;
if ( V_2 -> V_106 -> V_149 -> V_158 != V_159 )
return V_157 ;
V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 -> V_137 , V_2 -> V_137 , V_148 ) ;
return V_160 ;
}
int F_76 ( void )
{
return F_77 ( & V_161 ) ;
}
void F_78 ( void )
{
F_79 ( & V_161 ) ;
}
