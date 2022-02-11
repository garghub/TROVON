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
struct V_3 * V_47 ;
struct V_48 * V_49 = V_4 -> V_49 ;
int V_50 = 0 ;
F_4 () ;
if ( V_4 -> V_51 . type == V_52 ) {
F_15 ( & V_4 -> V_49 -> V_53 ) ;
F_16 (subif, &sdata->local->interfaces, list) {
if ( V_47 != V_4 &&
V_47 -> V_51 . type == V_4 -> V_51 . type &&
F_17 ( V_47 ) ) {
F_18 ( & V_4 -> V_49 -> V_53 ) ;
return - V_39 ;
}
}
F_18 ( & V_4 -> V_49 -> V_53 ) ;
}
F_19 ( V_54 , & V_4 -> V_55 ) ;
if ( ! V_49 -> V_56 ) {
V_50 = F_20 ( V_49 ) ;
F_21 ( V_50 ) ;
if ( V_50 )
goto V_25;
}
V_49 -> V_56 ++ ;
F_22 ( V_2 ) ;
return 0 ;
V_25:
F_23 ( V_54 , & V_4 -> V_55 ) ;
return V_50 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_48 * V_49 = V_4 -> V_49 ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_57 * V_58 = V_4 -> V_49 -> V_58 ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
F_15 ( & V_58 -> V_59 ) ;
if ( V_49 -> V_60 . V_61 & V_62 ) {
V_8 = F_25 ( V_49 ,
V_7 -> V_63 ) ;
if ( V_8 < 0 )
goto V_64;
}
if ( V_49 -> V_60 . V_61 & V_65 ) {
V_8 = F_26 ( V_49 , V_7 -> V_13 ) ;
if ( V_8 < 0 )
goto V_64;
V_8 = F_27 ( V_49 , V_7 -> V_16 ) ;
if ( V_8 < 0 )
goto V_64;
V_8 = F_28 ( V_49 , V_7 -> V_29 ) ;
if ( V_8 < 0 )
goto V_64;
}
if ( V_49 -> V_60 . V_61 & V_66 ) {
V_8 = F_29 ( V_49 , V_7 -> V_67 ) ;
if ( V_8 < 0 )
goto V_64;
}
if ( V_49 -> V_60 . V_61 & V_68 ) {
V_8 = F_30 ( V_49 , V_7 -> V_69 ,
V_7 -> V_70 ,
V_7 -> V_71 ) ;
if ( V_8 < 0 )
goto V_64;
}
if ( V_49 -> V_60 . V_61 & V_72 ) {
V_8 = F_31 ( V_49 , V_7 -> V_73 ) ;
if ( V_8 < 0 )
goto V_64;
}
F_18 ( & V_58 -> V_59 ) ;
return 0 ;
V_64:
F_18 ( & V_58 -> V_59 ) ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_48 * V_49 = V_4 -> V_49 ;
F_4 () ;
F_33 ( & V_49 -> V_74 ) ;
F_34 ( V_2 ) ;
V_49 -> V_56 -- ;
F_23 ( V_54 , & V_4 -> V_55 ) ;
if ( ! V_49 -> V_56 )
F_35 ( V_49 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_10 V_11 ;
T_3 V_79 ;
F_37 ( & V_4 -> V_80 , & V_11 ) ;
if ( ! V_11 . V_81 && V_78 -> V_82 && V_78 -> V_83 )
return - V_41 ;
if ( ! V_11 . V_81 ||
( V_78 -> V_82 && ! V_78 -> V_83 ) ||
! V_11 . V_84 )
return 0 ;
if ( V_78 -> V_85 && ! V_78 -> V_86 )
return - V_41 ;
V_79 = V_78 -> V_85 ? V_78 -> V_86 : V_11 . V_84 ;
V_76 -> V_87 . V_88 = 1 ;
V_76 -> V_80 . V_79 = V_79 ;
V_76 -> V_80 . V_89 = V_11 . V_90 . V_91 ;
if ( V_11 . V_90 . V_91 == V_92 )
V_76 -> V_80 . V_93 = V_11 . V_90 . V_94 ;
else if ( V_11 . V_90 . V_91 == V_95 )
V_76 -> V_80 . V_96 = V_11 . V_90 . V_97 ;
V_76 -> V_80 . V_98 = V_11 . V_90 . V_99 ;
return 0 ;
}
static int F_38 ( struct V_100 * V_101 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_102 ,
const void * V_103 ,
unsigned V_104 )
{
struct V_75 V_76 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_4 -> V_7 ;
struct V_77 * V_78 = F_39 ( V_101 ) ;
int V_105 ;
if ( ! V_102 )
return - V_41 ;
memset ( & V_76 . V_87 , 0 , sizeof( V_76 . V_87 ) ) ;
V_76 . V_87 . type = V_78 -> type ;
V_76 . V_87 . V_88 = V_78 -> V_83 ;
V_76 . V_87 . V_106 = V_78 -> V_107 ;
V_76 . V_108 = V_5 ( V_2 ) -> F_40 ( V_2 ) ;
if ( F_36 ( V_4 , & V_76 , V_78 ) < 0 )
return - V_41 ;
if ( ! V_103 ) {
F_5 ( & V_4 -> V_27 ) ;
if ( V_7 -> V_29 == F_10 ( V_31 ) ||
V_7 -> V_29 == F_10 ( V_40 ) ||
V_7 -> V_13 == F_10 ( V_30 ) ) {
V_76 . V_109 . V_91 = V_110 ;
V_76 . V_109 . V_16 = V_7 -> V_16 ;
} else {
V_76 . V_109 . V_91 = V_37 ;
V_76 . V_109 . V_29 = V_7 -> V_29 ;
}
V_76 . V_109 . V_13 = V_7 -> V_13 ;
F_8 ( & V_4 -> V_27 ) ;
} else {
V_76 . V_109 = * ( const struct V_111 * ) V_103 ;
}
V_76 . V_112 = * ( const struct V_111 * ) V_102 ;
V_105 = F_41 ( V_101 , & V_76 ) ;
if ( V_105 < 0 )
return - V_41 ;
F_42 ( V_101 ) ;
V_101 -> V_113 = V_105 ;
if ( V_104 > F_43 ( & V_76 ) )
return - V_114 ;
return V_105 ;
}
static int
F_44 ( const struct V_100 * V_101 , unsigned char * V_115 )
{
struct V_75 V_76 ;
struct V_111 * V_35 = (struct V_111 * ) V_115 ;
if ( F_45 ( V_101 , & V_76 ) < 0 ) {
F_46 ( L_2 ) ;
return 0 ;
}
* V_35 = V_76 . V_109 ;
return sizeof( * V_35 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_48 ( & V_4 -> V_80 ) ;
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_46 = V_116 ;
memset ( V_2 -> V_117 , 0xff , V_116 ) ;
V_2 -> V_118 = V_119 ;
V_2 -> V_120 = 2 + 16 ;
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = 300 ;
V_2 -> V_61 = V_124 | V_125 ;
}
static int
F_51 ( struct V_3 * V_4 ,
enum V_126 type )
{
struct V_7 * V_7 = & V_4 -> V_7 ;
V_4 -> V_51 . type = type ;
V_4 -> V_7 . V_127 = type ;
F_52 ( & V_7 -> V_128 , 1 ) ;
F_52 ( & V_7 -> V_129 , 1 ) ;
V_7 -> V_69 = 3 ;
V_7 -> V_70 = 5 ;
V_7 -> V_71 = 4 ;
V_7 -> V_73 = - 1 ;
V_7 -> V_13 = F_10 ( V_30 ) ;
V_7 -> V_29 = F_10 ( V_31 ) ;
switch ( type ) {
case V_52 :
F_12 ( & V_7 -> V_16 ,
V_4 -> V_2 -> V_45 ) ;
V_4 -> V_2 -> V_130 = & V_131 ;
V_4 -> V_2 -> V_132 = F_47 ;
V_4 -> V_2 -> V_133 = & V_134 ;
V_4 -> V_2 -> V_135 = & V_136 ;
V_7 -> V_63 = false ;
F_53 ( & V_4 -> V_27 ) ;
F_54 ( & V_4 -> V_137 ) ;
F_55 ( & V_4 -> V_80 ) ;
break;
case V_138 :
V_4 -> V_2 -> V_132 = F_49 ;
V_4 -> V_2 -> V_133 = & V_139 ;
V_7 -> V_63 = true ;
break;
default:
F_56 () ;
}
return 0 ;
}
struct V_1 *
F_57 ( struct V_48 * V_49 , const char * V_140 ,
enum V_126 type , T_2 V_16 )
{
struct V_1 * V_141 = NULL ;
struct V_3 * V_4 = NULL ;
int V_142 = - V_143 ;
F_4 () ;
V_141 = F_58 ( sizeof( * V_4 ) + V_49 -> V_60 . V_144 , V_140 ,
V_145 , F_50 ) ;
if ( ! V_141 )
return F_59 ( - V_143 ) ;
V_141 -> V_146 = V_49 -> V_60 . V_147 ;
V_142 = F_60 ( V_141 , V_141 -> V_140 ) ;
if ( V_142 < 0 )
goto V_25;
F_61 ( V_141 -> V_148 ,
& V_49 -> V_60 . V_58 -> V_149 ) ;
switch ( type ) {
case V_52 :
V_141 -> type = V_150 ;
if ( F_13 ( V_16 ) )
F_61 ( V_141 -> V_45 , & V_16 ) ;
else
memcpy ( V_141 -> V_45 , V_141 -> V_148 ,
V_116 ) ;
break;
case V_138 :
V_141 -> type = V_151 ;
break;
default:
V_142 = - V_41 ;
goto V_25;
}
F_62 ( V_141 , & V_49 -> V_58 -> V_2 ) ;
V_4 = F_63 ( V_141 ) ;
V_141 -> V_152 = & V_4 -> V_7 ;
memcpy ( V_4 -> V_140 , V_141 -> V_140 , V_153 ) ;
V_4 -> V_2 = V_141 ;
V_4 -> V_7 . V_57 = V_49 -> V_60 . V_58 ;
V_4 -> V_49 = V_49 ;
V_142 = F_51 ( V_4 , type ) ;
if ( V_142 )
goto V_25;
V_142 = F_64 ( V_141 ) ;
if ( V_142 < 0 )
goto V_25;
F_15 ( & V_49 -> V_53 ) ;
F_65 ( & V_4 -> V_154 , & V_49 -> V_155 ) ;
F_18 ( & V_49 -> V_53 ) ;
return V_141 ;
V_25:
F_49 ( V_141 ) ;
return F_59 ( V_142 ) ;
}
void F_66 ( struct V_3 * V_4 )
{
F_4 () ;
F_15 ( & V_4 -> V_49 -> V_53 ) ;
F_67 ( & V_4 -> V_154 ) ;
F_18 ( & V_4 -> V_49 -> V_53 ) ;
F_68 () ;
F_69 ( V_4 -> V_2 ) ;
}
void F_70 ( struct V_48 * V_49 )
{
struct V_3 * V_4 , * V_156 ;
F_15 ( & V_49 -> V_53 ) ;
F_71 (sdata, tmp, &local->interfaces, list) {
F_72 ( & V_4 -> V_154 ) ;
F_69 ( V_4 -> V_2 ) ;
}
F_18 ( & V_49 -> V_53 ) ;
}
static int F_73 ( struct V_157 * V_158 ,
unsigned long V_55 , void * V_159 )
{
struct V_1 * V_2 = F_74 ( V_159 ) ;
struct V_3 * V_4 ;
if ( V_55 != V_160 )
return V_161 ;
if ( ! V_2 -> V_152 || ! V_2 -> V_152 -> V_57 )
return V_161 ;
if ( V_2 -> V_152 -> V_57 -> V_162 != V_163 )
return V_161 ;
V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 -> V_140 , V_2 -> V_140 , V_153 ) ;
return V_164 ;
}
int F_75 ( void )
{
return F_76 ( & V_165 ) ;
}
void F_77 ( void )
{
F_78 ( & V_165 ) ;
}
