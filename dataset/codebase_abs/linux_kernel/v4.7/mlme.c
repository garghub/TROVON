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
V_65 ,
V_66 ) ;
if ( ! V_60 . V_4 )
return - V_67 ;
V_61 = F_49 ( V_13 , V_2 , & V_60 ) ;
F_9 ( & V_13 -> V_11 , V_60 . V_4 ) ;
return V_61 ;
}
void F_50 ( struct V_68 * V_69 ,
const struct V_68 * V_70 )
{
int V_71 ;
T_1 * V_72 , * V_73 ;
if ( ! V_70 ) {
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
return;
}
V_72 = ( T_1 * ) ( V_69 ) ;
V_73 = ( T_1 * ) ( V_70 ) ;
for ( V_71 = 0 ; V_71 < sizeof( * V_69 ) ; V_71 ++ )
V_72 [ V_71 ] &= V_73 [ V_71 ] ;
}
void F_51 ( struct V_74 * V_75 ,
const struct V_74 * V_76 )
{
int V_71 ;
T_1 * V_72 , * V_73 ;
if ( ! V_76 ) {
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
return;
}
V_72 = ( T_1 * ) ( V_75 ) ;
V_73 = ( T_1 * ) ( V_76 ) ;
for ( V_71 = 0 ; V_71 < sizeof( * V_75 ) ; V_71 ++ )
V_72 [ V_71 ] &= V_73 [ V_71 ] ;
}
int F_52 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_47 * V_48 ,
const T_1 * V_23 ,
const T_1 * V_51 , int V_52 ,
struct V_77 * V_60 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_61 ;
F_25 ( V_9 ) ;
if ( V_9 -> V_31 &&
( ! V_60 -> V_78 || ! F_16 ( V_9 -> V_31 -> V_32 . V_23 ,
V_60 -> V_78 ) ) )
return - V_64 ;
F_50 ( & V_60 -> V_70 ,
V_13 -> V_11 . V_79 ) ;
F_51 ( & V_60 -> V_76 ,
V_13 -> V_11 . V_80 ) ;
V_60 -> V_4 = F_48 ( & V_13 -> V_11 , V_48 , V_23 , V_51 , V_52 ,
V_65 ,
V_66 ) ;
if ( ! V_60 -> V_4 )
return - V_67 ;
V_61 = F_53 ( V_13 , V_2 , V_60 ) ;
if ( ! V_61 )
F_54 ( F_8 ( V_60 -> V_4 ) ) ;
else
F_9 ( & V_13 -> V_11 , V_60 -> V_4 ) ;
return V_61 ;
}
int F_55 ( struct V_12 * V_13 ,
struct V_1 * V_2 , const T_1 * V_23 ,
const T_1 * V_16 , int V_53 , T_3 V_81 ,
bool V_82 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_83 V_60 = {
. V_23 = V_23 ,
. V_26 = V_81 ,
. V_16 = V_16 ,
. V_53 = V_53 ,
. V_82 = V_82 ,
} ;
F_25 ( V_9 ) ;
if ( V_82 &&
( ! V_9 -> V_31 ||
! F_16 ( V_9 -> V_31 -> V_32 . V_23 , V_23 ) ) )
return 0 ;
return F_56 ( V_13 , V_2 , & V_60 ) ;
}
int F_57 ( struct V_12 * V_13 ,
struct V_1 * V_2 , const T_1 * V_23 ,
const T_1 * V_16 , int V_53 , T_3 V_81 ,
bool V_82 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_84 V_60 = {
. V_26 = V_81 ,
. V_82 = V_82 ,
. V_16 = V_16 ,
. V_53 = V_53 ,
} ;
int V_61 ;
F_25 ( V_9 ) ;
if ( ! V_9 -> V_31 )
return - V_85 ;
if ( F_16 ( V_9 -> V_31 -> V_32 . V_23 , V_23 ) )
V_60 . V_4 = & V_9 -> V_31 -> V_32 ;
else
return - V_85 ;
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
T_1 V_23 [ V_86 ] ;
F_25 ( V_9 ) ;
if ( ! V_13 -> V_87 -> V_27 )
return;
if ( ! V_9 -> V_31 )
return;
memcpy ( V_23 , V_9 -> V_31 -> V_32 . V_23 , V_86 ) ;
F_55 ( V_13 , V_2 , V_23 , NULL , 0 ,
V_88 , false ) ;
}
static void
F_60 ( struct V_12 * V_13 )
{
struct V_89 * V_90 ;
F_61 () ;
F_62 ( & V_13 -> V_91 ) ;
while ( ( V_90 = F_63 ( & V_13 -> V_92 ,
struct V_89 ,
V_93 ) ) ) {
F_64 ( & V_90 -> V_93 ) ;
F_65 ( & V_13 -> V_91 ) ;
if ( V_13 -> V_87 -> V_94 ) {
T_3 V_95 = F_4 ( V_90 -> V_95 ) ;
F_66 ( V_13 , V_90 -> V_9 ,
V_95 , false ) ;
}
F_44 ( V_90 ) ;
F_62 ( & V_13 -> V_91 ) ;
}
F_65 ( & V_13 -> V_91 ) ;
}
void F_67 ( struct V_96 * V_97 )
{
struct V_12 * V_13 ;
V_13 = F_68 ( V_97 , struct V_12 ,
V_98 ) ;
F_69 () ;
F_60 ( V_13 ) ;
F_70 () ;
}
int F_71 ( struct V_8 * V_9 , T_5 V_99 ,
T_3 V_95 , const T_1 * V_100 ,
int V_101 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_89 * V_90 , * V_102 ;
int V_61 = 0 ;
T_3 V_103 ;
if ( ! V_9 -> V_11 -> V_104 )
return - V_105 ;
if ( ( V_95 & V_106 ) != V_107 )
return - V_63 ;
if ( V_95 & ~ ( V_106 | V_108 ) )
return - V_63 ;
V_103 = ( V_95 & V_108 ) >> 4 ;
if ( ! ( V_9 -> V_11 -> V_104 [ V_9 -> V_109 ] . V_110 & F_72 ( V_103 ) ) )
return - V_63 ;
V_102 = F_73 ( sizeof( * V_90 ) + V_101 , V_22 ) ;
if ( ! V_102 )
return - V_111 ;
F_62 ( & V_9 -> V_112 ) ;
F_74 (reg, &wdev->mgmt_registrations, list) {
int V_113 = F_75 ( V_101 , V_90 -> V_101 ) ;
if ( V_95 != F_4 ( V_90 -> V_95 ) )
continue;
if ( memcmp ( V_90 -> V_114 , V_100 , V_113 ) == 0 ) {
V_61 = - V_64 ;
break;
}
}
if ( V_61 ) {
F_44 ( V_102 ) ;
goto V_115;
}
memcpy ( V_102 -> V_114 , V_100 , V_101 ) ;
V_102 -> V_101 = V_101 ;
V_102 -> V_116 = V_99 ;
V_102 -> V_95 = F_76 ( V_95 ) ;
V_102 -> V_9 = V_9 ;
F_77 ( & V_102 -> V_93 , & V_9 -> V_117 ) ;
F_65 ( & V_9 -> V_112 ) ;
F_60 ( V_13 ) ;
if ( V_13 -> V_87 -> V_94 )
F_66 ( V_13 , V_9 , V_95 , true ) ;
return 0 ;
V_115:
F_65 ( & V_9 -> V_112 ) ;
return V_61 ;
}
void F_78 ( struct V_8 * V_9 , T_5 V_116 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_89 * V_90 , * V_118 ;
F_62 ( & V_9 -> V_112 ) ;
F_79 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_90 -> V_116 != V_116 )
continue;
F_64 ( & V_90 -> V_93 ) ;
F_80 ( & V_13 -> V_91 ) ;
F_81 ( & V_90 -> V_93 , & V_13 -> V_92 ) ;
F_82 ( & V_13 -> V_91 ) ;
F_83 ( & V_13 -> V_98 ) ;
}
F_65 ( & V_9 -> V_112 ) ;
if ( V_116 && V_13 -> V_119 == V_116 ) {
V_13 -> V_119 = 0 ;
F_84 ( V_13 , V_9 ) ;
}
if ( V_116 == V_9 -> V_120 )
V_9 -> V_120 = 0 ;
}
void F_85 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
F_62 ( & V_9 -> V_112 ) ;
F_80 ( & V_13 -> V_91 ) ;
F_86 ( & V_9 -> V_117 , & V_13 -> V_92 ) ;
F_82 ( & V_13 -> V_91 ) ;
F_65 ( & V_9 -> V_112 ) ;
F_60 ( V_13 ) ;
}
int F_87 ( struct V_12 * V_13 ,
struct V_8 * V_9 ,
struct V_121 * V_122 , T_6 * V_123 )
{
const struct V_14 * V_15 ;
T_3 V_124 ;
if ( ! V_9 -> V_11 -> V_104 )
return - V_105 ;
if ( ! V_13 -> V_87 -> V_125 )
return - V_105 ;
if ( V_122 -> V_6 < 24 + 1 )
return - V_63 ;
V_15 = ( const struct V_14 * ) V_122 -> V_5 ;
if ( ! F_88 ( V_15 -> V_34 ) )
return - V_63 ;
V_124 = F_4 ( V_15 -> V_34 ) & V_108 ;
if ( ! ( V_9 -> V_11 -> V_104 [ V_9 -> V_109 ] . V_126 & F_72 ( V_124 >> 4 ) ) )
return - V_63 ;
if ( F_89 ( V_15 -> V_34 ) &&
V_15 -> V_17 . V_127 . V_128 != V_129 ) {
int V_61 = 0 ;
F_90 ( V_9 ) ;
switch ( V_9 -> V_109 ) {
case V_130 :
case V_131 :
case V_132 :
if ( ! V_9 -> V_31 ) {
V_61 = - V_85 ;
break;
}
if ( ! F_16 ( V_9 -> V_31 -> V_32 . V_23 ,
V_15 -> V_23 ) ) {
V_61 = - V_85 ;
break;
}
if ( V_9 -> V_109 == V_130 )
break;
if ( ! F_16 ( V_9 -> V_31 -> V_32 . V_23 ,
V_15 -> V_133 ) ) {
V_61 = - V_85 ;
break;
}
break;
case V_134 :
case V_135 :
case V_136 :
if ( ! F_16 ( V_15 -> V_23 , F_91 ( V_9 ) ) )
V_61 = - V_63 ;
break;
case V_137 :
if ( ! F_16 ( V_15 -> V_29 , V_15 -> V_23 ) ) {
V_61 = - V_63 ;
break;
}
break;
case V_138 :
default:
V_61 = - V_105 ;
break;
}
F_92 ( V_9 ) ;
if ( V_61 )
return V_61 ;
}
if ( ! F_16 ( V_15 -> V_29 , F_91 ( V_9 ) ) )
return - V_63 ;
return F_93 ( V_13 , V_9 , V_122 , V_123 ) ;
}
bool F_94 ( struct V_8 * V_9 , int V_139 , int V_140 ,
const T_1 * V_5 , T_2 V_6 , T_5 V_141 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_89 * V_90 ;
const struct V_142 * V_143 =
& V_11 -> V_104 [ V_9 -> V_109 ] ;
struct V_14 * V_15 = ( void * ) V_5 ;
const T_1 * V_44 ;
int V_144 ;
bool V_145 = false ;
T_7 V_146 = V_15 -> V_34 &
F_76 ( V_106 | V_108 ) ;
T_3 V_124 ;
F_95 ( V_9 , V_139 , V_140 ) ;
V_124 = ( F_4 ( V_15 -> V_34 ) & V_108 ) >> 4 ;
if ( ! ( V_143 -> V_110 & F_72 ( V_124 ) ) ) {
F_96 ( false ) ;
return false ;
}
V_44 = V_5 + F_97 ( V_15 -> V_34 ) ;
V_144 = V_6 - F_97 ( V_15 -> V_34 ) ;
F_62 ( & V_9 -> V_112 ) ;
F_74 (reg, &wdev->mgmt_registrations, list) {
if ( V_90 -> V_95 != V_146 )
continue;
if ( V_90 -> V_101 > V_144 )
continue;
if ( memcmp ( V_90 -> V_114 , V_44 , V_90 -> V_101 ) )
continue;
if ( F_98 ( V_13 , V_9 , V_90 -> V_116 ,
V_139 , V_140 ,
V_5 , V_6 , V_141 , V_147 ) )
continue;
V_145 = true ;
break;
}
F_65 ( & V_9 -> V_112 ) ;
F_96 ( V_145 ) ;
return V_145 ;
}
void F_99 ( struct V_96 * V_148 )
{
struct V_149 * V_149 = F_100 ( V_148 ) ;
struct V_12 * V_13 ;
struct V_150 V_151 ;
struct V_152 * V_153 ;
struct V_47 * V_154 ;
struct V_11 * V_11 ;
bool V_155 = false ;
unsigned long V_156 , V_157 = 0 ;
int V_158 , V_71 ;
V_13 = F_68 ( V_149 , struct V_12 ,
V_159 ) ;
V_11 = & V_13 -> V_11 ;
F_69 () ;
for ( V_158 = 0 ; V_158 < V_160 ; V_158 ++ ) {
V_153 = V_11 -> V_161 [ V_158 ] ;
if ( ! V_153 )
continue;
for ( V_71 = 0 ; V_71 < V_153 -> V_162 ; V_71 ++ ) {
V_154 = & V_153 -> V_163 [ V_71 ] ;
if ( V_154 -> V_164 != V_165 )
continue;
V_156 = V_154 -> V_166 + F_101 (
V_167 ) ;
if ( F_102 ( V_168 , V_156 ) ) {
V_154 -> V_164 = V_169 ;
V_154 -> V_166 = V_168 ;
F_103 ( & V_151 , V_154 ,
V_170 ) ;
F_104 ( V_13 , & V_151 ,
V_171 ,
NULL , V_147 ) ;
continue;
}
if ( ! V_155 )
V_157 = V_156 - V_168 ;
else
V_157 = F_75 ( V_157 , V_156 - V_168 ) ;
V_155 = true ;
}
}
F_70 () ;
if ( V_155 )
F_105 ( V_172 , & V_13 -> V_159 ,
V_157 ) ;
}
void F_106 ( struct V_11 * V_11 ,
struct V_150 * V_151 ,
T_4 V_40 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned long V_156 ;
F_107 ( V_11 , V_151 ) ;
F_108 ( V_11 , V_151 , V_165 ) ;
V_156 = F_101 ( V_167 ) ;
F_105 ( V_172 , & V_13 -> V_159 ,
V_156 ) ;
F_104 ( V_13 , V_151 , V_173 , NULL , V_40 ) ;
}
void F_109 ( struct V_1 * V_25 ,
const struct V_150 * V_151 ,
enum V_174 V_175 , T_4 V_40 )
{
struct V_8 * V_9 = V_25 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned long V_156 ;
F_110 ( V_25 , V_175 ) ;
if ( F_22 ( ! V_9 -> V_176 ) )
return;
if ( F_22 ( ! V_9 -> V_151 . V_48 ) )
return;
switch ( V_175 ) {
case V_177 :
V_156 = V_9 -> V_178 +
F_101 ( V_9 -> V_179 ) ;
F_22 ( ! F_102 ( V_168 , V_156 ) ) ;
F_108 ( V_11 , V_151 , V_180 ) ;
break;
case V_181 :
break;
default:
F_22 ( 1 ) ;
return;
}
V_9 -> V_176 = false ;
F_104 ( V_13 , V_151 , V_175 , V_25 , V_40 ) ;
}
