void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const T_1 * V_5 , T_2 V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_5 ;
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_18 = ( int ) F_3 ( V_15 -> V_19 . V_20 . V_21 ) ;
V_17 . V_22 = V_15 -> V_22 ;
V_17 . V_4 = V_4 ;
V_17 . V_23 = V_15 -> V_19 . V_20 . V_24 ;
V_17 . V_25 =
V_6 - F_4 ( struct V_14 , V_19 . V_20 . V_24 ) ;
V_17 . V_26 = V_27 ;
F_5 ( V_2 , V_4 ) ;
if ( F_6 ( V_9 , V_17 . V_18 ) ) {
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_11 , V_4 ) ;
return;
}
F_10 ( V_13 , V_2 , V_5 , V_6 , V_28 , V_7 ) ;
F_11 ( V_2 , & V_17 , V_17 . V_18 == V_29 ) ;
}
static void F_12 ( struct V_8 * V_9 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
F_13 ( V_13 , V_9 -> V_30 , V_5 , V_6 , V_28 ) ;
F_14 ( V_9 , V_5 , V_6 ) ;
}
static void F_15 ( struct V_8 * V_9 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_5 ;
const T_1 * V_22 = V_15 -> V_22 ;
T_3 V_31 = F_3 ( V_15 -> V_19 . V_32 . V_31 ) ;
bool V_33 = ! F_16 ( V_15 -> V_34 , V_9 -> V_30 -> V_35 ) ;
F_17 ( V_13 , V_9 -> V_30 , V_5 , V_6 , V_28 ) ;
if ( ! V_9 -> V_36 ||
! F_16 ( V_9 -> V_36 -> V_37 . V_22 , V_22 ) )
return;
F_18 ( V_9 -> V_30 , NULL , 0 , V_31 , V_33 ) ;
F_19 ( V_9 ) ;
}
static void F_20 ( struct V_8 * V_9 ,
const T_1 * V_5 , T_2 V_6 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_5 ;
const T_1 * V_22 = V_15 -> V_22 ;
T_3 V_31 = F_3 ( V_15 -> V_19 . V_38 . V_31 ) ;
bool V_33 = ! F_16 ( V_15 -> V_34 , V_9 -> V_30 -> V_35 ) ;
F_21 ( V_13 , V_9 -> V_30 , V_5 , V_6 , V_28 ) ;
if ( F_22 ( ! V_9 -> V_36 ||
! F_16 ( V_9 -> V_36 -> V_37 . V_22 , V_22 ) ) )
return;
F_18 ( V_9 -> V_30 , NULL , 0 , V_31 , V_33 ) ;
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
if ( F_27 ( V_15 -> V_39 ) )
F_12 ( V_9 , V_5 , V_6 ) ;
else if ( F_28 ( V_15 -> V_39 ) )
F_15 ( V_9 , V_5 , V_6 ) ;
else if ( F_29 ( V_15 -> V_39 ) )
F_20 ( V_9 , V_5 , V_6 ) ;
}
void F_30 ( struct V_1 * V_2 , const T_1 * V_40 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_31 ( V_2 , V_40 ) ;
F_32 ( V_13 , V_2 , V_40 , V_28 ) ;
F_33 ( V_9 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_35 ( V_2 , V_4 -> V_22 ) ;
F_36 ( V_13 , V_2 , V_4 -> V_22 , V_28 ) ;
F_37 ( V_9 ) ;
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_11 , V_4 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
F_39 ( V_9 ) ;
F_7 ( F_8 ( V_4 ) ) ;
F_9 ( V_11 , V_4 ) ;
}
void F_40 ( struct V_1 * V_2 , const T_1 * V_5 , T_2 V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_14 * V_15 = ( void * ) V_5 ;
F_25 ( V_9 ) ;
F_41 ( V_2 , V_5 , V_6 ) ;
if ( F_22 ( V_6 < 2 ) )
return;
if ( F_28 ( V_15 -> V_39 ) )
F_15 ( V_9 , V_5 , V_6 ) ;
else
F_20 ( V_9 , V_5 , V_6 ) ;
}
void F_42 ( struct V_1 * V_2 , const T_1 * V_40 ,
enum V_41 V_42 , int V_43 ,
const T_1 * V_44 , T_4 V_45 )
{
struct V_11 * V_11 = V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
#ifdef F_43
union V_46 V_47 ;
char * V_5 = F_44 ( 128 , V_45 ) ;
if ( V_5 ) {
sprintf ( V_5 , L_1
L_2 , V_43 ,
V_42 == V_48 ? L_3 : L_4 ,
V_40 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_49 . V_50 = strlen ( V_5 ) ;
F_45 ( V_2 , V_51 , & V_47 , V_5 ) ;
F_46 ( V_5 ) ;
}
#endif
F_47 ( V_2 , V_40 , V_42 , V_43 , V_44 ) ;
F_48 ( V_13 , V_2 , V_40 , V_42 , V_43 , V_44 , V_45 ) ;
}
int F_49 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_52 * V_53 ,
enum V_54 V_55 ,
const T_1 * V_22 ,
const T_1 * V_56 , int V_57 ,
const T_1 * V_58 , int V_59 ,
const T_1 * V_60 , int V_61 , int V_62 ,
const T_1 * V_63 , int V_64 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_65 V_66 = {
. V_58 = V_58 ,
. V_59 = V_59 ,
. V_63 = V_63 ,
. V_64 = V_64 ,
. V_55 = V_55 ,
. V_60 = V_60 ,
. V_61 = V_61 ,
. V_62 = V_62 ,
} ;
int V_67 ;
F_25 ( V_9 ) ;
if ( V_55 == V_68 )
if ( ! V_60 || ! V_61 || V_62 < 0 || V_62 > 3 )
return - V_69 ;
if ( V_9 -> V_36 &&
F_16 ( V_22 , V_9 -> V_36 -> V_37 . V_22 ) )
return - V_70 ;
V_66 . V_4 = F_50 ( & V_13 -> V_11 , V_53 , V_22 , V_56 , V_57 ,
V_71 ,
V_72 ) ;
if ( ! V_66 . V_4 )
return - V_73 ;
V_67 = F_51 ( V_13 , V_2 , & V_66 ) ;
F_9 ( & V_13 -> V_11 , V_66 . V_4 ) ;
return V_67 ;
}
void F_52 ( struct V_74 * V_75 ,
const struct V_74 * V_76 )
{
int V_77 ;
T_1 * V_78 , * V_79 ;
if ( ! V_76 ) {
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
return;
}
V_78 = ( T_1 * ) ( V_75 ) ;
V_79 = ( T_1 * ) ( V_76 ) ;
for ( V_77 = 0 ; V_77 < sizeof( * V_75 ) ; V_77 ++ )
V_78 [ V_77 ] &= V_79 [ V_77 ] ;
}
void F_53 ( struct V_80 * V_81 ,
const struct V_80 * V_82 )
{
int V_77 ;
T_1 * V_78 , * V_79 ;
if ( ! V_82 ) {
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
return;
}
V_78 = ( T_1 * ) ( V_81 ) ;
V_79 = ( T_1 * ) ( V_82 ) ;
for ( V_77 = 0 ; V_77 < sizeof( * V_81 ) ; V_77 ++ )
V_78 [ V_77 ] &= V_79 [ V_77 ] ;
}
int F_54 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_52 * V_53 ,
const T_1 * V_22 ,
const T_1 * V_56 , int V_57 ,
struct V_83 * V_66 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_67 ;
F_25 ( V_9 ) ;
if ( V_9 -> V_36 &&
( ! V_66 -> V_84 || ! F_16 ( V_9 -> V_36 -> V_37 . V_22 ,
V_66 -> V_84 ) ) )
return - V_70 ;
F_52 ( & V_66 -> V_76 ,
V_13 -> V_11 . V_85 ) ;
F_53 ( & V_66 -> V_82 ,
V_13 -> V_11 . V_86 ) ;
V_66 -> V_4 = F_50 ( & V_13 -> V_11 , V_53 , V_22 , V_56 , V_57 ,
V_71 ,
V_72 ) ;
if ( ! V_66 -> V_4 )
return - V_73 ;
V_67 = F_55 ( V_13 , V_2 , V_66 ) ;
if ( ! V_67 )
F_56 ( F_8 ( V_66 -> V_4 ) ) ;
else
F_9 ( & V_13 -> V_11 , V_66 -> V_4 ) ;
return V_67 ;
}
int F_57 ( struct V_12 * V_13 ,
struct V_1 * V_2 , const T_1 * V_22 ,
const T_1 * V_58 , int V_59 , T_3 V_87 ,
bool V_88 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_89 V_66 = {
. V_22 = V_22 ,
. V_31 = V_87 ,
. V_58 = V_58 ,
. V_59 = V_59 ,
. V_88 = V_88 ,
} ;
F_25 ( V_9 ) ;
if ( V_88 &&
( ! V_9 -> V_36 ||
! F_16 ( V_9 -> V_36 -> V_37 . V_22 , V_22 ) ) )
return 0 ;
if ( F_16 ( V_9 -> V_90 , V_22 ) ||
( V_9 -> V_36 &&
F_16 ( V_9 -> V_36 -> V_37 . V_22 , V_22 ) ) )
V_9 -> V_91 = 0 ;
return F_58 ( V_13 , V_2 , & V_66 ) ;
}
int F_59 ( struct V_12 * V_13 ,
struct V_1 * V_2 , const T_1 * V_22 ,
const T_1 * V_58 , int V_59 , T_3 V_87 ,
bool V_88 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_92 V_66 = {
. V_31 = V_87 ,
. V_88 = V_88 ,
. V_58 = V_58 ,
. V_59 = V_59 ,
} ;
int V_67 ;
F_25 ( V_9 ) ;
if ( ! V_9 -> V_36 )
return - V_93 ;
if ( F_16 ( V_9 -> V_36 -> V_37 . V_22 , V_22 ) )
V_66 . V_4 = & V_9 -> V_36 -> V_37 ;
else
return - V_93 ;
V_67 = F_60 ( V_13 , V_2 , & V_66 ) ;
if ( V_67 )
return V_67 ;
F_22 ( V_9 -> V_36 ) ;
return 0 ;
}
void F_61 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_22 [ V_94 ] ;
F_25 ( V_9 ) ;
if ( ! V_13 -> V_95 -> V_32 )
return;
if ( ! V_9 -> V_36 )
return;
memcpy ( V_22 , V_9 -> V_36 -> V_37 . V_22 , V_94 ) ;
F_57 ( V_13 , V_2 , V_22 , NULL , 0 ,
V_96 , false ) ;
}
static void
F_62 ( struct V_12 * V_13 )
{
struct V_97 * V_98 ;
F_63 () ;
F_64 ( & V_13 -> V_99 ) ;
while ( ( V_98 = F_65 ( & V_13 -> V_100 ,
struct V_97 ,
V_101 ) ) ) {
F_66 ( & V_98 -> V_101 ) ;
F_67 ( & V_13 -> V_99 ) ;
if ( V_13 -> V_95 -> V_102 ) {
T_3 V_103 = F_3 ( V_98 -> V_103 ) ;
F_68 ( V_13 , V_98 -> V_9 ,
V_103 , false ) ;
}
F_46 ( V_98 ) ;
F_64 ( & V_13 -> V_99 ) ;
}
F_67 ( & V_13 -> V_99 ) ;
}
void F_69 ( struct V_104 * V_105 )
{
struct V_12 * V_13 ;
V_13 = F_70 ( V_105 , struct V_12 ,
V_106 ) ;
F_71 () ;
F_62 ( V_13 ) ;
F_72 () ;
}
int F_73 ( struct V_8 * V_9 , T_5 V_107 ,
T_3 V_103 , const T_1 * V_108 ,
int V_109 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_97 * V_98 , * V_110 ;
int V_67 = 0 ;
T_3 V_111 ;
if ( ! V_9 -> V_11 -> V_112 )
return - V_113 ;
if ( ( V_103 & V_114 ) != V_115 )
return - V_69 ;
if ( V_103 & ~ ( V_114 | V_116 ) )
return - V_69 ;
V_111 = ( V_103 & V_116 ) >> 4 ;
if ( ! ( V_9 -> V_11 -> V_112 [ V_9 -> V_117 ] . V_118 & F_74 ( V_111 ) ) )
return - V_69 ;
V_110 = F_75 ( sizeof( * V_98 ) + V_109 , V_28 ) ;
if ( ! V_110 )
return - V_119 ;
F_64 ( & V_9 -> V_120 ) ;
F_76 (reg, &wdev->mgmt_registrations, list) {
int V_121 = F_77 ( V_109 , V_98 -> V_109 ) ;
if ( V_103 != F_3 ( V_98 -> V_103 ) )
continue;
if ( memcmp ( V_98 -> V_122 , V_108 , V_121 ) == 0 ) {
V_67 = - V_70 ;
break;
}
}
if ( V_67 ) {
F_46 ( V_110 ) ;
goto V_123;
}
memcpy ( V_110 -> V_122 , V_108 , V_109 ) ;
V_110 -> V_109 = V_109 ;
V_110 -> V_124 = V_107 ;
V_110 -> V_103 = F_78 ( V_103 ) ;
V_110 -> V_9 = V_9 ;
F_79 ( & V_110 -> V_101 , & V_9 -> V_125 ) ;
F_67 ( & V_9 -> V_120 ) ;
F_62 ( V_13 ) ;
if ( V_13 -> V_95 -> V_102 )
F_68 ( V_13 , V_9 , V_103 , true ) ;
return 0 ;
V_123:
F_67 ( & V_9 -> V_120 ) ;
return V_67 ;
}
void F_80 ( struct V_8 * V_9 , T_5 V_124 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_97 * V_98 , * V_126 ;
F_64 ( & V_9 -> V_120 ) ;
F_81 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_98 -> V_124 != V_124 )
continue;
F_66 ( & V_98 -> V_101 ) ;
F_82 ( & V_13 -> V_99 ) ;
F_83 ( & V_98 -> V_101 , & V_13 -> V_100 ) ;
F_84 ( & V_13 -> V_99 ) ;
F_85 ( & V_13 -> V_106 ) ;
}
F_67 ( & V_9 -> V_120 ) ;
if ( V_124 && V_13 -> V_127 == V_124 ) {
V_13 -> V_127 = 0 ;
F_86 ( V_13 , V_9 ) ;
}
if ( V_124 == V_9 -> V_128 )
V_9 -> V_128 = 0 ;
}
void F_87 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_2 ( V_9 -> V_11 ) ;
F_64 ( & V_9 -> V_120 ) ;
F_82 ( & V_13 -> V_99 ) ;
F_88 ( & V_9 -> V_125 , & V_13 -> V_100 ) ;
F_84 ( & V_13 -> V_99 ) ;
F_67 ( & V_9 -> V_120 ) ;
F_62 ( V_13 ) ;
}
int F_89 ( struct V_12 * V_13 ,
struct V_8 * V_9 ,
struct V_129 * V_130 , T_6 * V_131 )
{
const struct V_14 * V_15 ;
T_3 V_132 ;
if ( ! V_9 -> V_11 -> V_112 )
return - V_113 ;
if ( ! V_13 -> V_95 -> V_133 )
return - V_113 ;
if ( V_130 -> V_6 < 24 + 1 )
return - V_69 ;
V_15 = ( const struct V_14 * ) V_130 -> V_5 ;
if ( ! F_90 ( V_15 -> V_39 ) )
return - V_69 ;
V_132 = F_3 ( V_15 -> V_39 ) & V_116 ;
if ( ! ( V_9 -> V_11 -> V_112 [ V_9 -> V_117 ] . V_134 & F_74 ( V_132 >> 4 ) ) )
return - V_69 ;
if ( F_91 ( V_15 -> V_39 ) &&
V_15 -> V_19 . V_135 . V_136 != V_137 ) {
int V_67 = 0 ;
F_92 ( V_9 ) ;
switch ( V_9 -> V_117 ) {
case V_138 :
case V_139 :
case V_140 :
if ( ! V_9 -> V_36 ) {
V_67 = - V_93 ;
break;
}
if ( ! F_16 ( V_9 -> V_36 -> V_37 . V_22 ,
V_15 -> V_22 ) ) {
V_67 = - V_93 ;
break;
}
if ( V_9 -> V_117 == V_138 )
break;
if ( ! F_16 ( V_9 -> V_36 -> V_37 . V_22 ,
V_15 -> V_141 ) ) {
V_67 = - V_93 ;
break;
}
break;
case V_142 :
case V_143 :
case V_144 :
if ( ! F_16 ( V_15 -> V_22 , F_93 ( V_9 ) ) )
V_67 = - V_69 ;
break;
case V_145 :
if ( ! F_16 ( V_15 -> V_34 , V_15 -> V_22 ) ) {
V_67 = - V_69 ;
break;
}
break;
case V_146 :
case V_147 :
default:
V_67 = - V_113 ;
break;
}
F_94 ( V_9 ) ;
if ( V_67 )
return V_67 ;
}
if ( ! F_16 ( V_15 -> V_34 , F_93 ( V_9 ) ) ) {
if ( ! F_91 ( V_15 -> V_39 ) ||
V_15 -> V_19 . V_135 . V_136 != V_137 )
return - V_69 ;
if ( ! V_9 -> V_36 &&
! F_95 (
& V_13 -> V_11 ,
V_148 ) )
return - V_69 ;
if ( V_9 -> V_36 &&
! F_95 (
& V_13 -> V_11 ,
V_149 ) )
return - V_69 ;
}
return F_96 ( V_13 , V_9 , V_130 , V_131 ) ;
}
bool F_97 ( struct V_8 * V_9 , int V_150 , int V_151 ,
const T_1 * V_5 , T_2 V_6 , T_5 V_152 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_97 * V_98 ;
const struct V_153 * V_154 =
& V_11 -> V_112 [ V_9 -> V_117 ] ;
struct V_14 * V_15 = ( void * ) V_5 ;
const T_1 * V_49 ;
int V_155 ;
bool V_156 = false ;
T_7 V_157 = V_15 -> V_39 &
F_78 ( V_114 | V_116 ) ;
T_3 V_132 ;
F_98 ( V_9 , V_150 , V_151 ) ;
V_132 = ( F_3 ( V_15 -> V_39 ) & V_116 ) >> 4 ;
if ( ! ( V_154 -> V_118 & F_74 ( V_132 ) ) ) {
F_99 ( false ) ;
return false ;
}
V_49 = V_5 + F_100 ( V_15 -> V_39 ) ;
V_155 = V_6 - F_100 ( V_15 -> V_39 ) ;
F_64 ( & V_9 -> V_120 ) ;
F_76 (reg, &wdev->mgmt_registrations, list) {
if ( V_98 -> V_103 != V_157 )
continue;
if ( V_98 -> V_109 > V_155 )
continue;
if ( memcmp ( V_98 -> V_122 , V_49 , V_98 -> V_109 ) )
continue;
if ( F_101 ( V_13 , V_9 , V_98 -> V_124 ,
V_150 , V_151 ,
V_5 , V_6 , V_152 , V_158 ) )
continue;
V_156 = true ;
break;
}
F_67 ( & V_9 -> V_120 ) ;
F_99 ( V_156 ) ;
return V_156 ;
}
void F_102 ( struct V_12 * V_13 )
{
F_103 ( & V_13 -> V_159 ) ;
F_104 ( V_160 , & V_13 -> V_159 , 0 ) ;
}
void F_105 ( struct V_104 * V_161 )
{
struct V_162 * V_162 = F_106 ( V_161 ) ;
struct V_12 * V_13 ;
struct V_163 V_164 ;
struct V_165 * V_166 ;
struct V_52 * V_167 ;
struct V_11 * V_11 ;
bool V_168 = false ;
unsigned long V_169 , V_170 = 0 ;
unsigned long V_171 ;
enum V_172 V_173 ;
int V_174 , V_77 ;
V_13 = F_70 ( V_162 , struct V_12 ,
V_159 ) ;
V_11 = & V_13 -> V_11 ;
F_71 () ;
for ( V_174 = 0 ; V_174 < V_175 ; V_174 ++ ) {
V_166 = V_11 -> V_176 [ V_174 ] ;
if ( ! V_166 )
continue;
for ( V_77 = 0 ; V_77 < V_166 -> V_177 ; V_77 ++ ) {
V_167 = & V_166 -> V_178 [ V_77 ] ;
if ( ! ( V_167 -> V_152 & V_179 ) )
continue;
if ( V_167 -> V_180 != V_181 &&
V_167 -> V_180 != V_182 )
continue;
if ( V_167 -> V_180 == V_181 ) {
V_171 = V_183 ;
V_173 = V_184 ;
} else {
if ( F_107 ( V_11 ) ||
F_108 ( V_11 , V_167 ) )
continue;
V_171 = V_185 ;
V_173 = V_186 ;
}
V_169 = V_167 -> V_187 +
F_109 ( V_171 ) ;
if ( F_110 ( V_188 , V_169 ) ) {
V_167 -> V_180 = V_189 ;
V_167 -> V_187 = V_188 ;
F_111 ( & V_164 , V_167 ,
V_190 ) ;
F_112 ( V_13 , & V_164 ,
V_173 , NULL ,
V_158 ) ;
F_113 ( V_11 , & V_164 ,
V_167 -> V_180 ,
V_173 ) ;
continue;
}
if ( ! V_168 )
V_170 = V_169 - V_188 ;
else
V_170 = F_77 ( V_170 , V_169 - V_188 ) ;
V_168 = true ;
}
}
F_72 () ;
if ( V_168 )
F_104 ( V_160 , & V_13 -> V_159 ,
V_170 ) ;
}
void F_114 ( struct V_11 * V_11 ,
struct V_163 * V_164 ,
T_4 V_45 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_115 ( V_11 , V_164 ) ;
F_116 ( V_11 , V_164 , V_181 ) ;
F_102 ( V_13 ) ;
F_112 ( V_13 , V_164 , V_191 , NULL , V_45 ) ;
memcpy ( & V_13 -> V_192 , V_164 , sizeof( struct V_163 ) ) ;
F_117 ( V_160 , & V_13 -> V_193 ) ;
}
void F_118 ( struct V_1 * V_30 ,
const struct V_163 * V_164 ,
enum V_172 V_194 , T_4 V_45 )
{
struct V_8 * V_9 = V_30 -> V_10 ;
struct V_11 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned long V_169 ;
F_119 ( V_30 , V_194 ) ;
if ( F_22 ( ! V_9 -> V_195 ) )
return;
if ( F_22 ( ! V_9 -> V_164 . V_53 ) )
return;
switch ( V_194 ) {
case V_196 :
V_169 = V_9 -> V_197 +
F_109 ( V_9 -> V_198 ) ;
F_22 ( ! F_110 ( V_188 , V_169 ) ) ;
F_116 ( V_11 , V_164 , V_182 ) ;
memcpy ( & V_13 -> V_199 , V_164 ,
sizeof( struct V_163 ) ) ;
F_117 ( V_160 , & V_13 -> V_200 ) ;
F_102 ( V_13 ) ;
break;
case V_201 :
break;
default:
F_22 ( 1 ) ;
return;
}
V_9 -> V_195 = false ;
F_112 ( V_13 , V_164 , V_194 , V_30 , V_45 ) ;
}
