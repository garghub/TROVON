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
V_60 = F_49 ( V_12 , V_2 , & V_59 ) ;
F_9 ( & V_12 -> V_10 , V_59 . V_4 ) ;
return V_60 ;
}
void F_50 ( struct V_66 * V_67 ,
const struct V_66 * V_68 )
{
int V_69 ;
T_1 * V_70 , * V_71 ;
if ( ! V_68 ) {
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
return;
}
V_70 = ( T_1 * ) ( V_67 ) ;
V_71 = ( T_1 * ) ( V_68 ) ;
for ( V_69 = 0 ; V_69 < sizeof( * V_67 ) ; V_69 ++ )
V_70 [ V_69 ] &= V_71 [ V_69 ] ;
}
void F_51 ( struct V_72 * V_73 ,
const struct V_72 * V_74 )
{
int V_69 ;
T_1 * V_70 , * V_71 ;
if ( ! V_74 ) {
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
return;
}
V_70 = ( T_1 * ) ( V_73 ) ;
V_71 = ( T_1 * ) ( V_74 ) ;
for ( V_69 = 0 ; V_69 < sizeof( * V_73 ) ; V_69 ++ )
V_70 [ V_69 ] &= V_71 [ V_69 ] ;
}
int F_52 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_46 * V_47 ,
const T_1 * V_22 ,
const T_1 * V_50 , int V_51 ,
struct V_75 * V_59 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_60 ;
F_25 ( V_8 ) ;
if ( V_8 -> V_30 &&
( ! V_59 -> V_76 || ! F_16 ( V_8 -> V_30 -> V_31 . V_22 ,
V_59 -> V_76 ) ) )
return - V_63 ;
F_50 ( & V_59 -> V_68 ,
V_12 -> V_10 . V_77 ) ;
F_51 ( & V_59 -> V_74 ,
V_12 -> V_10 . V_78 ) ;
V_59 -> V_4 = F_48 ( & V_12 -> V_10 , V_47 , V_22 , V_50 , V_51 ,
V_64 , V_64 ) ;
if ( ! V_59 -> V_4 )
return - V_65 ;
V_60 = F_53 ( V_12 , V_2 , V_59 ) ;
if ( ! V_60 )
F_54 ( F_8 ( V_59 -> V_4 ) ) ;
else
F_9 ( & V_12 -> V_10 , V_59 -> V_4 ) ;
return V_60 ;
}
int F_55 ( struct V_11 * V_12 ,
struct V_1 * V_2 , const T_1 * V_22 ,
const T_1 * V_15 , int V_52 , T_3 V_79 ,
bool V_80 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_81 V_59 = {
. V_22 = V_22 ,
. V_25 = V_79 ,
. V_15 = V_15 ,
. V_52 = V_52 ,
. V_80 = V_80 ,
} ;
F_25 ( V_8 ) ;
if ( V_80 &&
( ! V_8 -> V_30 ||
! F_16 ( V_8 -> V_30 -> V_31 . V_22 , V_22 ) ) )
return 0 ;
return F_56 ( V_12 , V_2 , & V_59 ) ;
}
int F_57 ( struct V_11 * V_12 ,
struct V_1 * V_2 , const T_1 * V_22 ,
const T_1 * V_15 , int V_52 , T_3 V_79 ,
bool V_80 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_82 V_59 = {
. V_25 = V_79 ,
. V_80 = V_80 ,
. V_15 = V_15 ,
. V_52 = V_52 ,
} ;
int V_60 ;
F_25 ( V_8 ) ;
if ( ! V_8 -> V_30 )
return - V_83 ;
if ( F_16 ( V_8 -> V_30 -> V_31 . V_22 , V_22 ) )
V_59 . V_4 = & V_8 -> V_30 -> V_31 ;
else
return - V_83 ;
V_60 = F_58 ( V_12 , V_2 , & V_59 ) ;
if ( V_60 )
return V_60 ;
F_22 ( V_8 -> V_30 ) ;
return 0 ;
}
void F_59 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_22 [ V_84 ] ;
F_25 ( V_8 ) ;
if ( ! V_12 -> V_85 -> V_26 )
return;
if ( ! V_8 -> V_30 )
return;
memcpy ( V_22 , V_8 -> V_30 -> V_31 . V_22 , V_84 ) ;
F_55 ( V_12 , V_2 , V_22 , NULL , 0 ,
V_86 , false ) ;
}
int F_60 ( struct V_7 * V_8 , T_5 V_87 ,
T_3 V_88 , const T_1 * V_89 ,
int V_90 )
{
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_91 * V_92 , * V_93 ;
int V_60 = 0 ;
T_3 V_94 ;
if ( ! V_8 -> V_10 -> V_95 )
return - V_96 ;
if ( ( V_88 & V_97 ) != V_98 )
return - V_62 ;
if ( V_88 & ~ ( V_97 | V_99 ) )
return - V_62 ;
V_94 = ( V_88 & V_99 ) >> 4 ;
if ( ! ( V_8 -> V_10 -> V_95 [ V_8 -> V_100 ] . V_101 & F_61 ( V_94 ) ) )
return - V_62 ;
V_93 = F_62 ( sizeof( * V_92 ) + V_90 , V_21 ) ;
if ( ! V_93 )
return - V_102 ;
F_63 ( & V_8 -> V_103 ) ;
F_64 (reg, &wdev->mgmt_registrations, list) {
int V_104 = F_65 ( V_90 , V_92 -> V_90 ) ;
if ( V_88 != F_4 ( V_92 -> V_88 ) )
continue;
if ( memcmp ( V_92 -> V_105 , V_89 , V_104 ) == 0 ) {
V_60 = - V_63 ;
break;
}
}
if ( V_60 ) {
F_44 ( V_93 ) ;
goto V_106;
}
memcpy ( V_93 -> V_105 , V_89 , V_90 ) ;
V_93 -> V_90 = V_90 ;
V_93 -> V_107 = V_87 ;
V_93 -> V_88 = F_66 ( V_88 ) ;
F_67 ( & V_93 -> V_108 , & V_8 -> V_109 ) ;
if ( V_12 -> V_85 -> V_110 )
F_68 ( V_12 , V_8 , V_88 , true ) ;
V_106:
F_69 ( & V_8 -> V_103 ) ;
return V_60 ;
}
void F_70 ( struct V_7 * V_8 , T_5 V_107 )
{
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_91 * V_92 , * V_111 ;
F_63 ( & V_8 -> V_103 ) ;
F_71 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_92 -> V_107 != V_107 )
continue;
if ( V_12 -> V_85 -> V_110 ) {
T_3 V_88 = F_4 ( V_92 -> V_88 ) ;
F_68 ( V_12 , V_8 ,
V_88 , false ) ;
}
F_72 ( & V_92 -> V_108 ) ;
F_44 ( V_92 ) ;
}
F_69 ( & V_8 -> V_103 ) ;
if ( V_107 && V_12 -> V_112 == V_107 ) {
V_12 -> V_112 = 0 ;
F_73 ( V_12 , V_8 ) ;
}
if ( V_107 == V_8 -> V_113 )
V_8 -> V_113 = 0 ;
}
void F_74 ( struct V_7 * V_8 )
{
struct V_91 * V_92 , * V_111 ;
F_63 ( & V_8 -> V_103 ) ;
F_71 (reg, tmp, &wdev->mgmt_registrations, list) {
F_72 ( & V_92 -> V_108 ) ;
F_44 ( V_92 ) ;
}
F_69 ( & V_8 -> V_103 ) ;
}
int F_75 ( struct V_11 * V_12 ,
struct V_7 * V_8 ,
struct V_114 * V_115 , T_6 * V_116 )
{
const struct V_13 * V_14 ;
T_3 V_117 ;
if ( ! V_8 -> V_10 -> V_95 )
return - V_96 ;
if ( ! V_12 -> V_85 -> V_118 )
return - V_96 ;
if ( V_115 -> V_6 < 24 + 1 )
return - V_62 ;
V_14 = ( const struct V_13 * ) V_115 -> V_5 ;
if ( ! F_76 ( V_14 -> V_33 ) )
return - V_62 ;
V_117 = F_4 ( V_14 -> V_33 ) & V_99 ;
if ( ! ( V_8 -> V_10 -> V_95 [ V_8 -> V_100 ] . V_119 & F_61 ( V_117 >> 4 ) ) )
return - V_62 ;
if ( F_77 ( V_14 -> V_33 ) &&
V_14 -> V_16 . V_120 . V_121 != V_122 ) {
int V_60 = 0 ;
F_78 ( V_8 ) ;
switch ( V_8 -> V_100 ) {
case V_123 :
case V_124 :
case V_125 :
if ( ! V_8 -> V_30 ) {
V_60 = - V_83 ;
break;
}
if ( ! F_16 ( V_8 -> V_30 -> V_31 . V_22 ,
V_14 -> V_22 ) ) {
V_60 = - V_83 ;
break;
}
if ( V_8 -> V_100 == V_123 )
break;
if ( ! F_16 ( V_8 -> V_30 -> V_31 . V_22 ,
V_14 -> V_126 ) ) {
V_60 = - V_83 ;
break;
}
break;
case V_127 :
case V_128 :
case V_129 :
if ( ! F_16 ( V_14 -> V_22 , F_79 ( V_8 ) ) )
V_60 = - V_62 ;
break;
case V_130 :
if ( ! F_16 ( V_14 -> V_28 , V_14 -> V_22 ) ) {
V_60 = - V_62 ;
break;
}
break;
case V_131 :
default:
V_60 = - V_96 ;
break;
}
F_80 ( V_8 ) ;
if ( V_60 )
return V_60 ;
}
if ( ! F_16 ( V_14 -> V_28 , F_79 ( V_8 ) ) )
return - V_62 ;
return F_81 ( V_12 , V_8 , V_115 , V_116 ) ;
}
bool F_82 ( struct V_7 * V_8 , int V_132 , int V_133 ,
const T_1 * V_5 , T_2 V_6 , T_5 V_134 , T_4 V_39 )
{
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_91 * V_92 ;
const struct V_135 * V_136 =
& V_10 -> V_95 [ V_8 -> V_100 ] ;
struct V_13 * V_14 = ( void * ) V_5 ;
const T_1 * V_43 ;
int V_137 ;
bool V_138 = false ;
T_7 V_139 = V_14 -> V_33 &
F_66 ( V_97 | V_99 ) ;
T_3 V_117 ;
F_83 ( V_8 , V_132 , V_133 ) ;
V_117 = ( F_4 ( V_14 -> V_33 ) & V_99 ) >> 4 ;
if ( ! ( V_136 -> V_101 & F_61 ( V_117 ) ) ) {
F_84 ( false ) ;
return false ;
}
V_43 = V_5 + F_85 ( V_14 -> V_33 ) ;
V_137 = V_6 - F_85 ( V_14 -> V_33 ) ;
F_63 ( & V_8 -> V_103 ) ;
F_64 (reg, &wdev->mgmt_registrations, list) {
if ( V_92 -> V_88 != V_139 )
continue;
if ( V_92 -> V_90 > V_137 )
continue;
if ( memcmp ( V_92 -> V_105 , V_43 , V_92 -> V_90 ) )
continue;
if ( F_86 ( V_12 , V_8 , V_92 -> V_107 ,
V_132 , V_133 ,
V_5 , V_6 , V_134 , V_39 ) )
continue;
V_138 = true ;
break;
}
F_69 ( & V_8 -> V_103 ) ;
F_84 ( V_138 ) ;
return V_138 ;
}
void F_87 ( struct V_140 * V_141 )
{
struct V_142 * V_142 ;
struct V_11 * V_12 ;
struct V_143 V_144 ;
struct V_145 * V_146 ;
struct V_46 * V_147 ;
struct V_10 * V_10 ;
bool V_148 = false ;
unsigned long V_149 , V_150 = 0 ;
int V_151 , V_69 ;
V_142 = F_88 ( V_141 , struct V_142 , V_141 ) ;
V_12 = F_88 ( V_142 , struct V_11 ,
V_152 ) ;
V_10 = & V_12 -> V_10 ;
F_89 () ;
for ( V_151 = 0 ; V_151 < V_153 ; V_151 ++ ) {
V_146 = V_10 -> V_154 [ V_151 ] ;
if ( ! V_146 )
continue;
for ( V_69 = 0 ; V_69 < V_146 -> V_155 ; V_69 ++ ) {
V_147 = & V_146 -> V_156 [ V_69 ] ;
if ( V_147 -> V_157 != V_158 )
continue;
V_149 = V_147 -> V_159 + F_90 (
V_160 ) ;
if ( F_91 ( V_161 , V_149 ) ) {
V_147 -> V_157 = V_162 ;
V_147 -> V_159 = V_161 ;
F_92 ( & V_144 , V_147 ,
V_163 ) ;
F_93 ( V_12 , & V_144 ,
V_164 ,
NULL , V_165 ) ;
continue;
}
if ( ! V_148 )
V_150 = V_149 - V_161 ;
else
V_150 = F_65 ( V_150 , V_149 - V_161 ) ;
V_148 = true ;
}
}
F_94 () ;
if ( V_148 )
F_95 ( V_166 , & V_12 -> V_152 ,
V_150 ) ;
}
void F_96 ( struct V_10 * V_10 ,
struct V_143 * V_144 ,
T_4 V_39 )
{
struct V_11 * V_12 = F_2 ( V_10 ) ;
unsigned long V_149 ;
F_97 ( V_10 , V_144 ) ;
F_98 ( V_10 , V_144 , V_158 ) ;
V_149 = F_90 ( V_160 ) ;
F_95 ( V_166 , & V_12 -> V_152 ,
V_149 ) ;
F_93 ( V_12 , V_144 , V_167 , NULL , V_39 ) ;
}
void F_99 ( struct V_1 * V_24 ,
const struct V_143 * V_144 ,
enum V_168 V_169 , T_4 V_39 )
{
struct V_7 * V_8 = V_24 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
unsigned long V_149 ;
F_100 ( V_24 , V_169 ) ;
if ( F_22 ( ! V_8 -> V_170 ) )
return;
if ( F_22 ( ! V_8 -> V_144 . V_47 ) )
return;
switch ( V_169 ) {
case V_171 :
V_149 = V_8 -> V_172 +
F_90 ( V_8 -> V_173 ) ;
F_22 ( ! F_91 ( V_161 , V_149 ) ) ;
F_98 ( V_10 , V_144 , V_174 ) ;
break;
case V_175 :
break;
default:
F_22 ( 1 ) ;
return;
}
V_8 -> V_170 = false ;
F_93 ( V_12 , V_144 , V_169 , V_24 , V_39 ) ;
}
