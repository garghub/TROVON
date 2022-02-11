void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_13 * V_14 = (struct V_13 * ) V_5 ;
T_1 * V_15 = V_14 -> V_16 . V_17 . V_18 ;
int V_19 = F_3 ( struct V_13 , V_16 . V_17 . V_18 ) ;
T_3 V_20 = F_4 ( V_14 -> V_16 . V_17 . V_20 ) ;
F_5 ( V_2 , V_4 ) ;
if ( F_6 ( V_8 , V_20 ) ) {
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_10 , V_4 ) ;
return;
}
F_10 ( V_12 , V_2 , V_5 , V_6 , V_21 ) ;
F_11 ( V_2 , V_14 -> V_22 , NULL , 0 , V_15 , V_6 - V_19 ,
V_20 ,
V_20 == V_23 , V_4 ) ;
}
static void F_12 ( struct V_7 * V_8 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_11 * V_12 = F_2 ( V_8 -> V_10 ) ;
F_13 ( V_12 , V_8 -> V_24 , V_5 , V_6 , V_21 ) ;
F_14 ( V_8 , V_5 , V_6 ) ;
}
static void F_15 ( struct V_7 * V_8 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_11 * V_12 = F_2 ( V_8 -> V_10 ) ;
struct V_13 * V_14 = (struct V_13 * ) V_5 ;
const T_1 * V_22 = V_14 -> V_22 ;
T_3 V_25 = F_4 ( V_14 -> V_16 . V_26 . V_25 ) ;
bool V_27 = ! F_16 ( V_14 -> V_28 , V_8 -> V_24 -> V_29 ) ;
F_17 ( V_12 , V_8 -> V_24 , V_5 , V_6 , V_21 ) ;
if ( ! V_8 -> V_30 ||
! F_16 ( V_8 -> V_30 -> V_31 . V_22 , V_22 ) )
return;
F_18 ( V_8 -> V_24 , NULL , 0 , V_25 , V_27 ) ;
F_19 ( V_8 ) ;
}
static void F_20 ( struct V_7 * V_8 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_11 * V_12 = F_2 ( V_8 -> V_10 ) ;
struct V_13 * V_14 = (struct V_13 * ) V_5 ;
const T_1 * V_22 = V_14 -> V_22 ;
T_3 V_25 = F_4 ( V_14 -> V_16 . V_32 . V_25 ) ;
bool V_27 = ! F_16 ( V_14 -> V_28 , V_8 -> V_24 -> V_29 ) ;
F_21 ( V_12 , V_8 -> V_24 , V_5 , V_6 , V_21 ) ;
if ( F_22 ( ! V_8 -> V_30 ||
! F_16 ( V_8 -> V_30 -> V_31 . V_22 , V_22 ) ) )
return;
F_18 ( V_8 -> V_24 , NULL , 0 , V_25 , V_27 ) ;
F_23 ( V_8 ) ;
}
void F_24 ( struct V_1 * V_2 , const T_1 * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_13 * V_14 = ( void * ) V_5 ;
F_25 ( V_8 ) ;
F_26 ( V_2 , V_5 , V_6 ) ;
if ( F_22 ( V_6 < 2 ) )
return;
if ( F_27 ( V_14 -> V_33 ) )
F_12 ( V_8 , V_5 , V_6 ) ;
else if ( F_28 ( V_14 -> V_33 ) )
F_15 ( V_8 , V_5 , V_6 ) ;
else if ( F_29 ( V_14 -> V_33 ) )
F_20 ( V_8 , V_5 , V_6 ) ;
}
void F_30 ( struct V_1 * V_2 , const T_1 * V_34 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
F_31 ( V_2 , V_34 ) ;
F_32 ( V_12 , V_2 , V_34 , V_21 ) ;
F_33 ( V_8 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
F_35 ( V_2 , V_4 -> V_22 ) ;
F_36 ( V_12 , V_2 , V_4 -> V_22 , V_21 ) ;
F_37 ( V_8 ) ;
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_10 , V_4 ) ;
}
void F_38 ( struct V_1 * V_2 , const T_1 * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_13 * V_14 = ( void * ) V_5 ;
F_25 ( V_8 ) ;
F_39 ( V_2 , V_5 , V_6 ) ;
if ( F_22 ( V_6 < 2 ) )
return;
if ( F_28 ( V_14 -> V_33 ) )
F_15 ( V_8 , V_5 , V_6 ) ;
else
F_20 ( V_8 , V_5 , V_6 ) ;
}
void F_40 ( struct V_1 * V_2 , const T_1 * V_34 ,
enum V_35 V_36 , int V_37 ,
const T_1 * V_38 , T_4 V_39 )
{
struct V_10 * V_10 = V_2 -> V_9 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
#ifdef F_41
union V_40 V_41 ;
char * V_5 = F_42 ( 128 , V_39 ) ;
if ( V_5 ) {
sprintf ( V_5 , L_1
L_2 , V_37 ,
V_36 == V_42 ? L_3 : L_4 ,
V_34 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_43 . V_44 = strlen ( V_5 ) ;
F_43 ( V_2 , V_45 , & V_41 , V_5 ) ;
F_44 ( V_5 ) ;
}
#endif
F_45 ( V_2 , V_34 , V_36 , V_37 , V_38 ) ;
F_46 ( V_12 , V_2 , V_34 , V_36 , V_37 , V_38 , V_39 ) ;
}
int F_47 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_46 * V_47 ,
enum V_48 V_49 ,
const T_1 * V_22 ,
const T_1 * V_50 , int V_51 ,
const T_1 * V_15 , int V_52 ,
const T_1 * V_53 , int V_54 , int V_55 ,
const T_1 * V_56 , int V_57 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_58 V_59 = {
. V_15 = V_15 ,
. V_52 = V_52 ,
. V_56 = V_56 ,
. V_57 = V_57 ,
. V_49 = V_49 ,
. V_53 = V_53 ,
. V_54 = V_54 ,
. V_55 = V_55 ,
} ;
int V_60 ;
F_25 ( V_8 ) ;
if ( V_49 == V_61 )
if ( ! V_53 || ! V_54 || V_55 < 0 || V_55 > 4 )
return - V_62 ;
if ( V_8 -> V_30 &&
F_16 ( V_22 , V_8 -> V_30 -> V_31 . V_22 ) )
return - V_63 ;
V_59 . V_4 = F_48 ( & V_12 -> V_10 , V_47 , V_22 , V_50 , V_51 ,
V_64 , V_64 ) ;
if ( ! V_59 . V_4 )
return - V_65 ;
V_60 = F_49 ( V_12 , V_8 , V_59 . V_4 -> V_66 ,
V_67 ) ;
if ( V_60 )
goto V_68;
V_60 = F_50 ( V_12 , V_2 , & V_59 ) ;
V_68:
F_9 ( & V_12 -> V_10 , V_59 . V_4 ) ;
return V_60 ;
}
void F_51 ( struct V_69 * V_70 ,
const struct V_69 * V_71 )
{
int V_72 ;
T_1 * V_73 , * V_74 ;
if ( ! V_71 ) {
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
return;
}
V_73 = ( T_1 * ) ( V_70 ) ;
V_74 = ( T_1 * ) ( V_71 ) ;
for ( V_72 = 0 ; V_72 < sizeof( * V_70 ) ; V_72 ++ )
V_73 [ V_72 ] &= V_74 [ V_72 ] ;
}
void F_52 ( struct V_75 * V_76 ,
const struct V_75 * V_77 )
{
int V_72 ;
T_1 * V_73 , * V_74 ;
if ( ! V_77 ) {
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
return;
}
V_73 = ( T_1 * ) ( V_76 ) ;
V_74 = ( T_1 * ) ( V_77 ) ;
for ( V_72 = 0 ; V_72 < sizeof( * V_76 ) ; V_72 ++ )
V_73 [ V_72 ] &= V_74 [ V_72 ] ;
}
int F_53 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_46 * V_47 ,
const T_1 * V_22 ,
const T_1 * V_50 , int V_51 ,
struct V_78 * V_59 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_60 ;
F_25 ( V_8 ) ;
if ( V_8 -> V_30 &&
( ! V_59 -> V_79 || ! F_16 ( V_8 -> V_30 -> V_31 . V_22 ,
V_59 -> V_79 ) ) )
return - V_63 ;
F_51 ( & V_59 -> V_71 ,
V_12 -> V_10 . V_80 ) ;
F_52 ( & V_59 -> V_77 ,
V_12 -> V_10 . V_81 ) ;
V_59 -> V_4 = F_48 ( & V_12 -> V_10 , V_47 , V_22 , V_50 , V_51 ,
V_64 , V_64 ) ;
if ( ! V_59 -> V_4 )
return - V_65 ;
V_60 = F_49 ( V_12 , V_8 , V_47 , V_67 ) ;
if ( V_60 )
goto V_68;
V_60 = F_54 ( V_12 , V_2 , V_59 ) ;
if ( ! V_60 )
F_55 ( F_8 ( V_59 -> V_4 ) ) ;
V_68:
if ( V_60 )
F_9 ( & V_12 -> V_10 , V_59 -> V_4 ) ;
return V_60 ;
}
int F_56 ( struct V_11 * V_12 ,
struct V_1 * V_2 , const T_1 * V_22 ,
const T_1 * V_15 , int V_52 , T_3 V_82 ,
bool V_83 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_84 V_59 = {
. V_22 = V_22 ,
. V_25 = V_82 ,
. V_15 = V_15 ,
. V_52 = V_52 ,
. V_83 = V_83 ,
} ;
F_25 ( V_8 ) ;
if ( V_83 &&
( ! V_8 -> V_30 ||
! F_16 ( V_8 -> V_30 -> V_31 . V_22 , V_22 ) ) )
return 0 ;
return F_57 ( V_12 , V_2 , & V_59 ) ;
}
int F_58 ( struct V_11 * V_12 ,
struct V_1 * V_2 , const T_1 * V_22 ,
const T_1 * V_15 , int V_52 , T_3 V_82 ,
bool V_83 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_85 V_59 = {
. V_25 = V_82 ,
. V_83 = V_83 ,
. V_15 = V_15 ,
. V_52 = V_52 ,
} ;
int V_60 ;
F_25 ( V_8 ) ;
if ( ! V_8 -> V_30 )
return - V_86 ;
if ( F_16 ( V_8 -> V_30 -> V_31 . V_22 , V_22 ) )
V_59 . V_4 = & V_8 -> V_30 -> V_31 ;
else
return - V_86 ;
V_60 = F_59 ( V_12 , V_2 , & V_59 ) ;
if ( V_60 )
return V_60 ;
F_22 ( V_8 -> V_30 ) ;
return 0 ;
}
void F_60 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_22 [ V_87 ] ;
F_25 ( V_8 ) ;
if ( ! V_12 -> V_88 -> V_26 )
return;
if ( ! V_8 -> V_30 )
return;
memcpy ( V_22 , V_8 -> V_30 -> V_31 . V_22 , V_87 ) ;
F_56 ( V_12 , V_2 , V_22 , NULL , 0 ,
V_89 , false ) ;
}
int F_61 ( struct V_7 * V_8 , T_5 V_90 ,
T_3 V_91 , const T_1 * V_92 ,
int V_93 )
{
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_94 * V_95 , * V_96 ;
int V_60 = 0 ;
T_3 V_97 ;
if ( ! V_8 -> V_10 -> V_98 )
return - V_99 ;
if ( ( V_91 & V_100 ) != V_101 )
return - V_62 ;
if ( V_91 & ~ ( V_100 | V_102 ) )
return - V_62 ;
V_97 = ( V_91 & V_102 ) >> 4 ;
if ( ! ( V_8 -> V_10 -> V_98 [ V_8 -> V_103 ] . V_104 & F_62 ( V_97 ) ) )
return - V_62 ;
V_96 = F_63 ( sizeof( * V_95 ) + V_93 , V_21 ) ;
if ( ! V_96 )
return - V_105 ;
F_64 ( & V_8 -> V_106 ) ;
F_65 (reg, &wdev->mgmt_registrations, list) {
int V_107 = F_66 ( V_93 , V_95 -> V_93 ) ;
if ( V_91 != F_4 ( V_95 -> V_91 ) )
continue;
if ( memcmp ( V_95 -> V_108 , V_92 , V_107 ) == 0 ) {
V_60 = - V_63 ;
break;
}
}
if ( V_60 ) {
F_44 ( V_96 ) ;
goto V_68;
}
memcpy ( V_96 -> V_108 , V_92 , V_93 ) ;
V_96 -> V_93 = V_93 ;
V_96 -> V_109 = V_90 ;
V_96 -> V_91 = F_67 ( V_91 ) ;
F_68 ( & V_96 -> V_110 , & V_8 -> V_111 ) ;
if ( V_12 -> V_88 -> V_112 )
F_69 ( V_12 , V_8 , V_91 , true ) ;
V_68:
F_70 ( & V_8 -> V_106 ) ;
return V_60 ;
}
void F_71 ( struct V_7 * V_8 , T_5 V_109 )
{
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_94 * V_95 , * V_113 ;
F_64 ( & V_8 -> V_106 ) ;
F_72 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_95 -> V_109 != V_109 )
continue;
if ( V_12 -> V_88 -> V_112 ) {
T_3 V_91 = F_4 ( V_95 -> V_91 ) ;
F_69 ( V_12 , V_8 ,
V_91 , false ) ;
}
F_73 ( & V_95 -> V_110 ) ;
F_44 ( V_95 ) ;
}
F_70 ( & V_8 -> V_106 ) ;
if ( V_109 && V_12 -> V_114 == V_109 ) {
V_12 -> V_114 = 0 ;
F_74 ( V_12 , V_8 ) ;
}
if ( V_109 == V_8 -> V_115 )
V_8 -> V_115 = 0 ;
}
void F_75 ( struct V_7 * V_8 )
{
struct V_94 * V_95 , * V_113 ;
F_64 ( & V_8 -> V_106 ) ;
F_72 (reg, tmp, &wdev->mgmt_registrations, list) {
F_73 ( & V_95 -> V_110 ) ;
F_44 ( V_95 ) ;
}
F_70 ( & V_8 -> V_106 ) ;
}
int F_76 ( struct V_11 * V_12 ,
struct V_7 * V_8 ,
struct V_116 * V_117 , T_6 * V_118 )
{
const struct V_13 * V_14 ;
T_3 V_119 ;
if ( ! V_8 -> V_10 -> V_98 )
return - V_99 ;
if ( ! V_12 -> V_88 -> V_120 )
return - V_99 ;
if ( V_117 -> V_6 < 24 + 1 )
return - V_62 ;
V_14 = ( const struct V_13 * ) V_117 -> V_5 ;
if ( ! F_77 ( V_14 -> V_33 ) )
return - V_62 ;
V_119 = F_4 ( V_14 -> V_33 ) & V_102 ;
if ( ! ( V_8 -> V_10 -> V_98 [ V_8 -> V_103 ] . V_121 & F_62 ( V_119 >> 4 ) ) )
return - V_62 ;
if ( F_78 ( V_14 -> V_33 ) &&
V_14 -> V_16 . V_122 . V_123 != V_124 ) {
int V_60 = 0 ;
F_79 ( V_8 ) ;
switch ( V_8 -> V_103 ) {
case V_125 :
case V_126 :
case V_127 :
if ( ! V_8 -> V_30 ) {
V_60 = - V_86 ;
break;
}
if ( ! F_16 ( V_8 -> V_30 -> V_31 . V_22 ,
V_14 -> V_22 ) ) {
V_60 = - V_86 ;
break;
}
if ( V_8 -> V_103 == V_125 )
break;
if ( ! F_16 ( V_8 -> V_30 -> V_31 . V_22 ,
V_14 -> V_128 ) ) {
V_60 = - V_86 ;
break;
}
break;
case V_129 :
case V_130 :
case V_131 :
if ( ! F_16 ( V_14 -> V_22 , F_80 ( V_8 ) ) )
V_60 = - V_62 ;
break;
case V_132 :
if ( ! F_16 ( V_14 -> V_28 , V_14 -> V_22 ) ) {
V_60 = - V_62 ;
break;
}
break;
case V_133 :
default:
V_60 = - V_99 ;
break;
}
F_81 ( V_8 ) ;
if ( V_60 )
return V_60 ;
}
if ( ! F_16 ( V_14 -> V_28 , F_80 ( V_8 ) ) )
return - V_62 ;
return F_82 ( V_12 , V_8 , V_117 , V_118 ) ;
}
bool F_83 ( struct V_7 * V_8 , int V_134 , int V_135 ,
const T_1 * V_5 , T_2 V_6 , T_5 V_136 , T_4 V_39 )
{
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_94 * V_95 ;
const struct V_137 * V_138 =
& V_10 -> V_98 [ V_8 -> V_103 ] ;
struct V_13 * V_14 = ( void * ) V_5 ;
const T_1 * V_43 ;
int V_139 ;
bool V_140 = false ;
T_7 V_141 = V_14 -> V_33 &
F_67 ( V_100 | V_102 ) ;
T_3 V_119 ;
F_84 ( V_8 , V_134 , V_135 ) ;
V_119 = ( F_4 ( V_14 -> V_33 ) & V_102 ) >> 4 ;
if ( ! ( V_138 -> V_104 & F_62 ( V_119 ) ) ) {
F_85 ( false ) ;
return false ;
}
V_43 = V_5 + F_86 ( V_14 -> V_33 ) ;
V_139 = V_6 - F_86 ( V_14 -> V_33 ) ;
F_64 ( & V_8 -> V_106 ) ;
F_65 (reg, &wdev->mgmt_registrations, list) {
if ( V_95 -> V_91 != V_141 )
continue;
if ( V_95 -> V_93 > V_139 )
continue;
if ( memcmp ( V_95 -> V_108 , V_43 , V_95 -> V_93 ) )
continue;
if ( F_87 ( V_12 , V_8 , V_95 -> V_109 ,
V_134 , V_135 ,
V_5 , V_6 , V_136 , V_39 ) )
continue;
V_140 = true ;
break;
}
F_70 ( & V_8 -> V_106 ) ;
F_85 ( V_140 ) ;
return V_140 ;
}
void F_88 ( struct V_142 * V_143 )
{
struct V_144 * V_144 ;
struct V_11 * V_12 ;
struct V_145 V_146 ;
struct V_147 * V_148 ;
struct V_46 * V_149 ;
struct V_10 * V_10 ;
bool V_150 = false ;
unsigned long V_151 , V_152 = 0 ;
int V_153 , V_72 ;
V_144 = F_89 ( V_143 , struct V_144 , V_143 ) ;
V_12 = F_89 ( V_144 , struct V_11 ,
V_154 ) ;
V_10 = & V_12 -> V_10 ;
F_90 () ;
for ( V_153 = 0 ; V_153 < V_155 ; V_153 ++ ) {
V_148 = V_10 -> V_156 [ V_153 ] ;
if ( ! V_148 )
continue;
for ( V_72 = 0 ; V_72 < V_148 -> V_157 ; V_72 ++ ) {
V_149 = & V_148 -> V_158 [ V_72 ] ;
if ( V_149 -> V_159 != V_160 )
continue;
V_151 = V_149 -> V_161 + F_91 (
V_162 ) ;
if ( F_92 ( V_163 , V_151 ) ) {
V_149 -> V_159 = V_164 ;
V_149 -> V_161 = V_163 ;
F_93 ( & V_146 , V_149 ,
V_165 ) ;
F_94 ( V_12 , & V_146 ,
V_166 ,
NULL , V_167 ) ;
continue;
}
if ( ! V_150 )
V_152 = V_151 - V_163 ;
else
V_152 = F_66 ( V_152 , V_151 - V_163 ) ;
V_150 = true ;
}
}
F_95 () ;
if ( V_150 )
F_96 ( V_168 , & V_12 -> V_154 ,
V_152 ) ;
}
void F_97 ( struct V_10 * V_10 ,
struct V_145 * V_146 ,
T_4 V_39 )
{
struct V_11 * V_12 = F_2 ( V_10 ) ;
unsigned long V_151 ;
F_98 ( V_10 , V_146 ) ;
F_99 ( V_10 , V_146 , V_160 ) ;
V_151 = F_91 ( V_162 ) ;
F_96 ( V_168 , & V_12 -> V_154 ,
V_151 ) ;
F_94 ( V_12 , V_146 , V_169 , NULL , V_39 ) ;
}
void F_100 ( struct V_1 * V_24 ,
const struct V_145 * V_146 ,
enum V_170 V_171 , T_4 V_39 )
{
struct V_7 * V_8 = V_24 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
unsigned long V_151 ;
F_101 ( V_24 , V_171 ) ;
if ( F_22 ( ! V_8 -> V_172 ) )
return;
if ( F_22 ( ! V_8 -> V_66 ) )
return;
switch ( V_171 ) {
case V_173 :
V_151 = V_8 -> V_174 +
F_91 ( V_175 ) ;
F_22 ( ! F_92 ( V_163 , V_151 ) ) ;
F_99 ( V_10 , V_146 , V_176 ) ;
break;
case V_177 :
break;
default:
F_22 ( 1 ) ;
return;
}
V_8 -> V_172 = false ;
F_94 ( V_12 , V_146 , V_171 , V_24 , V_39 ) ;
}
