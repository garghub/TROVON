void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const T_1 * V_5 , T_2 V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_5 ;
T_1 * V_16 = V_15 -> V_17 . V_18 . V_19 ;
int V_20 = F_3 ( struct V_14 , V_17 . V_18 . V_19 ) ;
T_3 V_21 = F_4 ( V_15 -> V_17 . V_18 . V_21 ) ;
F_5 ( V_2 , V_4 ) ;
if ( F_6 ( V_9 , V_21 ) ) {
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_11 , V_4 ) ;
return;
}
F_10 ( V_13 , V_2 , V_5 , V_6 , V_22 , V_7 ) ;
F_11 ( V_2 , V_15 -> V_23 , NULL , 0 , V_16 , V_6 - V_20 ,
V_21 ,
V_21 == V_24 , V_4 ) ;
}
static void F_12 ( struct V_8 * V_9 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
F_13 ( V_13 , V_9 -> V_25 , V_5 , V_6 , V_22 ) ;
F_14 ( V_9 , V_5 , V_6 ) ;
}
static void F_15 ( struct V_8 * V_9 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_5 ;
const T_1 * V_23 = V_15 -> V_23 ;
T_3 V_26 = F_4 ( V_15 -> V_17 . V_27 . V_26 ) ;
bool V_28 = ! F_16 ( V_15 -> V_29 , V_9 -> V_25 -> V_30 ) ;
F_17 ( V_13 , V_9 -> V_25 , V_5 , V_6 , V_22 ) ;
if ( ! V_9 -> V_31 ||
! F_16 ( V_9 -> V_31 -> V_32 . V_23 , V_23 ) )
return;
F_18 ( V_9 -> V_25 , NULL , 0 , V_26 , V_28 ) ;
F_19 ( V_9 ) ;
}
static void F_20 ( struct V_8 * V_9 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_5 ;
const T_1 * V_23 = V_15 -> V_23 ;
T_3 V_26 = F_4 ( V_15 -> V_17 . V_33 . V_26 ) ;
bool V_28 = ! F_16 ( V_15 -> V_29 , V_9 -> V_25 -> V_30 ) ;
F_21 ( V_13 , V_9 -> V_25 , V_5 , V_6 , V_22 ) ;
if ( F_22 ( ! V_9 -> V_31 ||
! F_16 ( V_9 -> V_31 -> V_32 . V_23 , V_23 ) ) )
return;
F_18 ( V_9 -> V_25 , NULL , 0 , V_26 , V_28 ) ;
F_23 ( V_9 ) ;
}
void F_24 ( struct V_1 * V_2 , const T_1 * V_5 , T_2 V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_14 * V_15 = ( void * ) V_5 ;
F_25 ( V_9 ) ;
F_26 ( V_2 , V_5 , V_6 ) ;
if ( F_22 ( V_6 < 2 ) )
return;
if ( F_27 ( V_15 -> V_34 ) )
F_12 ( V_9 , V_5 , V_6 ) ;
else if ( F_28 ( V_15 -> V_34 ) )
F_15 ( V_9 , V_5 , V_6 ) ;
else if ( F_29 ( V_15 -> V_34 ) )
F_20 ( V_9 , V_5 , V_6 ) ;
}
void F_30 ( struct V_1 * V_2 , const T_1 * V_35 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_31 ( V_2 , V_35 ) ;
F_32 ( V_13 , V_2 , V_35 , V_22 ) ;
F_33 ( V_9 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_35 ( V_2 , V_4 -> V_23 ) ;
F_36 ( V_13 , V_2 , V_4 -> V_23 , V_22 ) ;
F_37 ( V_9 ) ;
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_11 , V_4 ) ;
}
void F_38 ( struct V_1 * V_2 , const T_1 * V_5 , T_2 V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_14 * V_15 = ( void * ) V_5 ;
F_25 ( V_9 ) ;
F_39 ( V_2 , V_5 , V_6 ) ;
if ( F_22 ( V_6 < 2 ) )
return;
if ( F_28 ( V_15 -> V_34 ) )
F_15 ( V_9 , V_5 , V_6 ) ;
else
F_20 ( V_9 , V_5 , V_6 ) ;
}
void F_40 ( struct V_1 * V_2 , const T_1 * V_35 ,
enum V_36 V_37 , int V_38 ,
const T_1 * V_39 , T_4 V_40 )
{
struct V_11 * V_11 = V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
#ifdef F_41
union V_41 V_42 ;
char * V_5 = F_42 ( 128 , V_40 ) ;
if ( V_5 ) {
sprintf ( V_5 , L_1
L_2 , V_38 ,
V_37 == V_43 ? L_3 : L_4 ,
V_35 ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_44 . V_45 = strlen ( V_5 ) ;
F_43 ( V_2 , V_46 , & V_42 , V_5 ) ;
F_44 ( V_5 ) ;
}
#endif
F_45 ( V_2 , V_35 , V_37 , V_38 , V_39 ) ;
F_46 ( V_13 , V_2 , V_35 , V_37 , V_38 , V_39 , V_40 ) ;
}
int F_47 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_47 * V_48 ,
enum V_49 V_50 ,
const T_1 * V_23 ,
const T_1 * V_51 , int V_52 ,
const T_1 * V_16 , int V_53 ,
const T_1 * V_54 , int V_55 , int V_56 ,
const T_1 * V_57 , int V_58 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_59 V_60 = {
. V_16 = V_16 ,
. V_53 = V_53 ,
. V_57 = V_57 ,
. V_58 = V_58 ,
. V_50 = V_50 ,
. V_54 = V_54 ,
. V_55 = V_55 ,
. V_56 = V_56 ,
} ;
int V_61 ;
F_25 ( V_9 ) ;
if ( V_50 == V_62 )
if ( ! V_54 || ! V_55 || V_56 < 0 || V_56 > 4 )
return - V_63 ;
if ( V_9 -> V_31 &&
F_16 ( V_23 , V_9 -> V_31 -> V_32 . V_23 ) )
return - V_64 ;
V_60 . V_4 = F_48 ( & V_13 -> V_11 , V_48 , V_23 , V_51 , V_52 ,
V_65 , V_65 ) ;
if ( ! V_60 . V_4 )
return - V_66 ;
V_61 = F_49 ( V_13 , V_2 , & V_60 ) ;
F_9 ( & V_13 -> V_11 , V_60 . V_4 ) ;
return V_61 ;
}
void F_50 ( struct V_67 * V_68 ,
const struct V_67 * V_69 )
{
int V_70 ;
T_1 * V_71 , * V_72 ;
if ( ! V_69 ) {
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
return;
}
V_71 = ( T_1 * ) ( V_68 ) ;
V_72 = ( T_1 * ) ( V_69 ) ;
for ( V_70 = 0 ; V_70 < sizeof( * V_68 ) ; V_70 ++ )
V_71 [ V_70 ] &= V_72 [ V_70 ] ;
}
void F_51 ( struct V_73 * V_74 ,
const struct V_73 * V_75 )
{
int V_70 ;
T_1 * V_71 , * V_72 ;
if ( ! V_75 ) {
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
return;
}
V_71 = ( T_1 * ) ( V_74 ) ;
V_72 = ( T_1 * ) ( V_75 ) ;
for ( V_70 = 0 ; V_70 < sizeof( * V_74 ) ; V_70 ++ )
V_71 [ V_70 ] &= V_72 [ V_70 ] ;
}
int F_52 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_47 * V_48 ,
const T_1 * V_23 ,
const T_1 * V_51 , int V_52 ,
struct V_76 * V_60 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_61 ;
F_25 ( V_9 ) ;
if ( V_9 -> V_31 &&
( ! V_60 -> V_77 || ! F_16 ( V_9 -> V_31 -> V_32 . V_23 ,
V_60 -> V_77 ) ) )
return - V_64 ;
F_50 ( & V_60 -> V_69 ,
V_13 -> V_11 . V_78 ) ;
F_51 ( & V_60 -> V_75 ,
V_13 -> V_11 . V_79 ) ;
V_60 -> V_4 = F_48 ( & V_13 -> V_11 , V_48 , V_23 , V_51 , V_52 ,
V_65 , V_65 ) ;
if ( ! V_60 -> V_4 )
return - V_66 ;
V_61 = F_53 ( V_13 , V_2 , V_60 ) ;
if ( ! V_61 )
F_54 ( F_8 ( V_60 -> V_4 ) ) ;
else
F_9 ( & V_13 -> V_11 , V_60 -> V_4 ) ;
return V_61 ;
}
int F_55 ( struct V_12 * V_13 ,
struct V_1 * V_2 , const T_1 * V_23 ,
const T_1 * V_16 , int V_53 , T_3 V_80 ,
bool V_81 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_82 V_60 = {
. V_23 = V_23 ,
. V_26 = V_80 ,
. V_16 = V_16 ,
. V_53 = V_53 ,
. V_81 = V_81 ,
} ;
F_25 ( V_9 ) ;
if ( V_81 &&
( ! V_9 -> V_31 ||
! F_16 ( V_9 -> V_31 -> V_32 . V_23 , V_23 ) ) )
return 0 ;
return F_56 ( V_13 , V_2 , & V_60 ) ;
}
int F_57 ( struct V_12 * V_13 ,
struct V_1 * V_2 , const T_1 * V_23 ,
const T_1 * V_16 , int V_53 , T_3 V_80 ,
bool V_81 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_83 V_60 = {
. V_26 = V_80 ,
. V_81 = V_81 ,
. V_16 = V_16 ,
. V_53 = V_53 ,
} ;
int V_61 ;
F_25 ( V_9 ) ;
if ( ! V_9 -> V_31 )
return - V_84 ;
if ( F_16 ( V_9 -> V_31 -> V_32 . V_23 , V_23 ) )
V_60 . V_4 = & V_9 -> V_31 -> V_32 ;
else
return - V_84 ;
V_61 = F_58 ( V_13 , V_2 , & V_60 ) ;
if ( V_61 )
return V_61 ;
F_22 ( V_9 -> V_31 ) ;
return 0 ;
}
void F_59 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_23 [ V_85 ] ;
F_25 ( V_9 ) ;
if ( ! V_13 -> V_86 -> V_27 )
return;
if ( ! V_9 -> V_31 )
return;
memcpy ( V_23 , V_9 -> V_31 -> V_32 . V_23 , V_85 ) ;
F_55 ( V_13 , V_2 , V_23 , NULL , 0 ,
V_87 , false ) ;
}
int F_60 ( struct V_8 * V_9 , T_5 V_88 ,
T_3 V_89 , const T_1 * V_90 ,
int V_91 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_92 * V_93 , * V_94 ;
int V_61 = 0 ;
T_3 V_95 ;
if ( ! V_9 -> V_11 -> V_96 )
return - V_97 ;
if ( ( V_89 & V_98 ) != V_99 )
return - V_63 ;
if ( V_89 & ~ ( V_98 | V_100 ) )
return - V_63 ;
V_95 = ( V_89 & V_100 ) >> 4 ;
if ( ! ( V_9 -> V_11 -> V_96 [ V_9 -> V_101 ] . V_102 & F_61 ( V_95 ) ) )
return - V_63 ;
V_94 = F_62 ( sizeof( * V_93 ) + V_91 , V_22 ) ;
if ( ! V_94 )
return - V_103 ;
F_63 ( & V_9 -> V_104 ) ;
F_64 (reg, &wdev->mgmt_registrations, list) {
int V_105 = F_65 ( V_91 , V_93 -> V_91 ) ;
if ( V_89 != F_4 ( V_93 -> V_89 ) )
continue;
if ( memcmp ( V_93 -> V_106 , V_90 , V_105 ) == 0 ) {
V_61 = - V_64 ;
break;
}
}
if ( V_61 ) {
F_44 ( V_94 ) ;
goto V_107;
}
memcpy ( V_94 -> V_106 , V_90 , V_91 ) ;
V_94 -> V_91 = V_91 ;
V_94 -> V_108 = V_88 ;
V_94 -> V_89 = F_66 ( V_89 ) ;
F_67 ( & V_94 -> V_109 , & V_9 -> V_110 ) ;
if ( V_13 -> V_86 -> V_111 )
F_68 ( V_13 , V_9 , V_89 , true ) ;
V_107:
F_69 ( & V_9 -> V_104 ) ;
return V_61 ;
}
void F_70 ( struct V_8 * V_9 , T_5 V_108 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_92 * V_93 , * V_112 ;
F_63 ( & V_9 -> V_104 ) ;
F_71 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_93 -> V_108 != V_108 )
continue;
if ( V_13 -> V_86 -> V_111 ) {
T_3 V_89 = F_4 ( V_93 -> V_89 ) ;
F_68 ( V_13 , V_9 ,
V_89 , false ) ;
}
F_72 ( & V_93 -> V_109 ) ;
F_44 ( V_93 ) ;
}
F_69 ( & V_9 -> V_104 ) ;
if ( V_108 && V_13 -> V_113 == V_108 ) {
V_13 -> V_113 = 0 ;
F_73 ( V_13 , V_9 ) ;
}
if ( V_108 == V_9 -> V_114 )
V_9 -> V_114 = 0 ;
}
void F_74 ( struct V_8 * V_9 )
{
struct V_92 * V_93 , * V_112 ;
F_63 ( & V_9 -> V_104 ) ;
F_71 (reg, tmp, &wdev->mgmt_registrations, list) {
F_72 ( & V_93 -> V_109 ) ;
F_44 ( V_93 ) ;
}
F_69 ( & V_9 -> V_104 ) ;
}
int F_75 ( struct V_12 * V_13 ,
struct V_8 * V_9 ,
struct V_115 * V_116 , T_6 * V_117 )
{
const struct V_14 * V_15 ;
T_3 V_118 ;
if ( ! V_9 -> V_11 -> V_96 )
return - V_97 ;
if ( ! V_13 -> V_86 -> V_119 )
return - V_97 ;
if ( V_116 -> V_6 < 24 + 1 )
return - V_63 ;
V_15 = ( const struct V_14 * ) V_116 -> V_5 ;
if ( ! F_76 ( V_15 -> V_34 ) )
return - V_63 ;
V_118 = F_4 ( V_15 -> V_34 ) & V_100 ;
if ( ! ( V_9 -> V_11 -> V_96 [ V_9 -> V_101 ] . V_120 & F_61 ( V_118 >> 4 ) ) )
return - V_63 ;
if ( F_77 ( V_15 -> V_34 ) &&
V_15 -> V_17 . V_121 . V_122 != V_123 ) {
int V_61 = 0 ;
F_78 ( V_9 ) ;
switch ( V_9 -> V_101 ) {
case V_124 :
case V_125 :
case V_126 :
if ( ! V_9 -> V_31 ) {
V_61 = - V_84 ;
break;
}
if ( ! F_16 ( V_9 -> V_31 -> V_32 . V_23 ,
V_15 -> V_23 ) ) {
V_61 = - V_84 ;
break;
}
if ( V_9 -> V_101 == V_124 )
break;
if ( ! F_16 ( V_9 -> V_31 -> V_32 . V_23 ,
V_15 -> V_127 ) ) {
V_61 = - V_84 ;
break;
}
break;
case V_128 :
case V_129 :
case V_130 :
if ( ! F_16 ( V_15 -> V_23 , F_79 ( V_9 ) ) )
V_61 = - V_63 ;
break;
case V_131 :
if ( ! F_16 ( V_15 -> V_29 , V_15 -> V_23 ) ) {
V_61 = - V_63 ;
break;
}
break;
case V_132 :
default:
V_61 = - V_97 ;
break;
}
F_80 ( V_9 ) ;
if ( V_61 )
return V_61 ;
}
if ( ! F_16 ( V_15 -> V_29 , F_79 ( V_9 ) ) )
return - V_63 ;
return F_81 ( V_13 , V_9 , V_116 , V_117 ) ;
}
bool F_82 ( struct V_8 * V_9 , int V_133 , int V_134 ,
const T_1 * V_5 , T_2 V_6 , T_5 V_135 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_92 * V_93 ;
const struct V_136 * V_137 =
& V_11 -> V_96 [ V_9 -> V_101 ] ;
struct V_14 * V_15 = ( void * ) V_5 ;
const T_1 * V_44 ;
int V_138 ;
bool V_139 = false ;
T_7 V_140 = V_15 -> V_34 &
F_66 ( V_98 | V_100 ) ;
T_3 V_118 ;
F_83 ( V_9 , V_133 , V_134 ) ;
V_118 = ( F_4 ( V_15 -> V_34 ) & V_100 ) >> 4 ;
if ( ! ( V_137 -> V_102 & F_61 ( V_118 ) ) ) {
F_84 ( false ) ;
return false ;
}
V_44 = V_5 + F_85 ( V_15 -> V_34 ) ;
V_138 = V_6 - F_85 ( V_15 -> V_34 ) ;
F_63 ( & V_9 -> V_104 ) ;
F_64 (reg, &wdev->mgmt_registrations, list) {
if ( V_93 -> V_89 != V_140 )
continue;
if ( V_93 -> V_91 > V_138 )
continue;
if ( memcmp ( V_93 -> V_106 , V_44 , V_93 -> V_91 ) )
continue;
if ( F_86 ( V_13 , V_9 , V_93 -> V_108 ,
V_133 , V_134 ,
V_5 , V_6 , V_135 , V_141 ) )
continue;
V_139 = true ;
break;
}
F_69 ( & V_9 -> V_104 ) ;
F_84 ( V_139 ) ;
return V_139 ;
}
void F_87 ( struct V_142 * V_143 )
{
struct V_144 * V_144 ;
struct V_12 * V_13 ;
struct V_145 V_146 ;
struct V_147 * V_148 ;
struct V_47 * V_149 ;
struct V_11 * V_11 ;
bool V_150 = false ;
unsigned long V_151 , V_152 = 0 ;
int V_153 , V_70 ;
V_144 = F_88 ( V_143 , struct V_144 , V_143 ) ;
V_13 = F_88 ( V_144 , struct V_12 ,
V_154 ) ;
V_11 = & V_13 -> V_11 ;
F_89 () ;
for ( V_153 = 0 ; V_153 < V_155 ; V_153 ++ ) {
V_148 = V_11 -> V_156 [ V_153 ] ;
if ( ! V_148 )
continue;
for ( V_70 = 0 ; V_70 < V_148 -> V_157 ; V_70 ++ ) {
V_149 = & V_148 -> V_158 [ V_70 ] ;
if ( V_149 -> V_159 != V_160 )
continue;
V_151 = V_149 -> V_161 + F_90 (
V_162 ) ;
if ( F_91 ( V_163 , V_151 ) ) {
V_149 -> V_159 = V_164 ;
V_149 -> V_161 = V_163 ;
F_92 ( & V_146 , V_149 ,
V_165 ) ;
F_93 ( V_13 , & V_146 ,
V_166 ,
NULL , V_141 ) ;
continue;
}
if ( ! V_150 )
V_152 = V_151 - V_163 ;
else
V_152 = F_65 ( V_152 , V_151 - V_163 ) ;
V_150 = true ;
}
}
F_94 () ;
if ( V_150 )
F_95 ( V_167 , & V_13 -> V_154 ,
V_152 ) ;
}
void F_96 ( struct V_11 * V_11 ,
struct V_145 * V_146 ,
T_4 V_40 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned long V_151 ;
F_97 ( V_11 , V_146 ) ;
F_98 ( V_11 , V_146 , V_160 ) ;
V_151 = F_90 ( V_162 ) ;
F_95 ( V_167 , & V_13 -> V_154 ,
V_151 ) ;
F_93 ( V_13 , V_146 , V_168 , NULL , V_40 ) ;
}
void F_99 ( struct V_1 * V_25 ,
const struct V_145 * V_146 ,
enum V_169 V_170 , T_4 V_40 )
{
struct V_8 * V_9 = V_25 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned long V_151 ;
F_100 ( V_25 , V_170 ) ;
if ( F_22 ( ! V_9 -> V_171 ) )
return;
if ( F_22 ( ! V_9 -> V_146 . V_48 ) )
return;
switch ( V_170 ) {
case V_172 :
V_151 = V_9 -> V_173 +
F_90 ( V_9 -> V_174 ) ;
F_22 ( ! F_91 ( V_163 , V_151 ) ) ;
F_98 ( V_11 , V_146 , V_175 ) ;
break;
case V_176 :
break;
default:
F_22 ( 1 ) ;
return;
}
V_9 -> V_171 = false ;
F_93 ( V_13 , V_146 , V_170 , V_25 , V_40 ) ;
}
