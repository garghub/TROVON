void F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_2 ) ;
F_4 ( V_6 ) ;
F_5 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
F_6 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_6 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_3 , T_2 V_4 )
{
T_3 V_14 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
T_1 * V_17 = V_16 -> V_18 . V_19 . V_20 ;
int V_21 = F_9 ( struct V_15 , V_18 . V_19 . V_20 ) ;
F_10 ( V_2 , V_13 ) ;
F_4 ( V_6 ) ;
V_14 = F_11 ( V_16 -> V_18 . V_19 . V_14 ) ;
if ( V_14 != V_22 && V_6 -> V_23 &&
F_12 ( V_6 ) ) {
F_13 ( V_8 , V_13 ) ;
goto V_24;
}
F_14 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_14 != V_22 && V_6 -> V_23 ) {
F_15 ( V_6 ) ;
F_13 ( V_8 , V_13 ) ;
goto V_24;
}
if ( ! V_6 -> V_23 && V_6 -> V_25 == V_26 ) {
V_6 -> V_25 = V_27 ;
}
F_16 ( V_2 , V_16 -> V_28 , NULL , 0 , V_17 , V_4 - V_21 ,
V_14 ,
V_14 == V_22 , V_13 ) ;
V_24:
F_7 ( V_6 ) ;
}
void F_17 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
bool V_29 = false ;
F_18 ( V_2 ) ;
F_19 ( V_6 ) ;
if ( V_6 -> V_30 &&
F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_21 ( V_6 -> V_30 ) ;
F_13 ( V_8 , & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
V_29 = true ;
}
F_22 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 == V_32 && V_29 ) {
T_3 V_33 ;
bool V_34 ;
V_33 = F_11 ( V_16 -> V_18 . V_35 . V_33 ) ;
V_34 = ! F_20 ( V_16 -> V_36 , V_2 -> V_37 ) ;
F_23 ( V_2 , NULL , 0 , V_33 , V_34 ) ;
} else if ( V_6 -> V_25 == V_27 ) {
F_16 ( V_2 , V_16 -> V_28 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
}
}
void F_24 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 ) ;
F_17 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_6 ) ;
}
void F_25 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
T_3 V_33 ;
bool V_34 ;
F_26 ( V_2 ) ;
F_19 ( V_6 ) ;
F_27 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 != V_32 )
return;
if ( V_6 -> V_30 &&
F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_28 ( V_2 , V_6 -> V_30 ) ;
F_21 ( V_6 -> V_30 ) ;
F_13 ( V_8 , & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
} else
F_29 ( 1 ) ;
V_33 = F_11 ( V_16 -> V_18 . V_39 . V_33 ) ;
V_34 = ! F_20 ( V_16 -> V_36 , V_2 -> V_37 ) ;
F_23 ( V_2 , NULL , 0 , V_33 , V_34 ) ;
}
void F_30 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 ) ;
F_25 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_6 ) ;
}
void F_31 ( struct V_1 * V_2 , const T_1 * V_40 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_32 ( V_2 , V_40 ) ;
F_4 ( V_6 ) ;
F_33 ( V_10 , V_2 , V_40 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_16 ( V_2 , V_40 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
F_7 ( V_6 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_40 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_35 ( V_2 , V_40 ) ;
F_4 ( V_6 ) ;
F_36 ( V_10 , V_2 , V_40 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_16 ( V_2 , V_40 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
F_7 ( V_6 ) ;
}
void F_37 ( struct V_1 * V_2 , const T_1 * V_40 ,
enum V_41 V_42 , int V_43 ,
const T_1 * V_44 , T_4 V_45 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
#ifdef F_38
union V_46 V_47 ;
char * V_3 = F_39 ( 128 , V_45 ) ;
if ( V_3 ) {
sprintf ( V_3 , L_1
L_2 , V_43 ,
V_42 == V_48 ? L_3 : L_4 ,
V_40 ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_49 . V_50 = strlen ( V_3 ) ;
F_40 ( V_2 , V_51 , & V_47 , V_3 ) ;
F_41 ( V_3 ) ;
}
#endif
F_42 ( V_2 , V_40 , V_42 , V_43 , V_44 ) ;
F_43 ( V_10 , V_2 , V_40 , V_42 , V_43 , V_44 , V_45 ) ;
}
int F_44 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_52 * V_53 ,
enum V_54 V_55 ,
const T_1 * V_28 ,
const T_1 * V_56 , int V_57 ,
const T_1 * V_17 , int V_58 ,
const T_1 * V_59 , int V_60 , int V_61 ,
const T_1 * V_62 , int V_63 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_64 V_65 ;
int V_66 ;
F_19 ( V_6 ) ;
if ( V_55 == V_67 )
if ( ! V_59 || ! V_60 || V_61 < 0 || V_61 > 4 )
return - V_68 ;
if ( V_6 -> V_30 &&
F_20 ( V_28 , V_6 -> V_30 -> V_31 . V_28 ) )
return - V_69 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_17 = V_17 ;
V_65 . V_58 = V_58 ;
V_65 . V_62 = V_62 ;
V_65 . V_63 = V_63 ;
V_65 . V_55 = V_55 ;
V_65 . V_13 = F_45 ( & V_10 -> V_8 , V_53 , V_28 , V_56 , V_57 ,
V_70 , V_70 ) ;
V_65 . V_59 = V_59 ;
V_65 . V_60 = V_60 ;
V_65 . V_61 = V_61 ;
if ( ! V_65 . V_13 )
return - V_71 ;
V_66 = F_46 ( V_10 , V_6 , V_65 . V_13 -> V_72 ,
V_73 ) ;
if ( V_66 )
goto V_24;
V_66 = F_47 ( V_10 , V_2 , & V_65 ) ;
V_24:
F_13 ( & V_10 -> V_8 , V_65 . V_13 ) ;
return V_66 ;
}
int F_48 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_52 * V_53 ,
enum V_54 V_55 , const T_1 * V_28 ,
const T_1 * V_56 , int V_57 ,
const T_1 * V_17 , int V_58 ,
const T_1 * V_59 , int V_60 , int V_61 ,
const T_1 * V_62 , int V_63 )
{
int V_66 ;
F_49 ( & V_10 -> V_74 ) ;
F_4 ( V_2 -> V_7 ) ;
V_66 = F_44 ( V_10 , V_2 , V_53 , V_55 , V_28 ,
V_56 , V_57 , V_17 , V_58 ,
V_59 , V_60 , V_61 ,
V_62 , V_63 ) ;
F_7 ( V_2 -> V_7 ) ;
F_50 ( & V_10 -> V_74 ) ;
return V_66 ;
}
void F_51 ( struct V_75 * V_76 ,
const struct V_75 * V_77 )
{
int V_78 ;
T_1 * V_79 , * V_80 ;
if ( ! V_77 ) {
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
return;
}
V_79 = ( T_1 * ) ( V_76 ) ;
V_80 = ( T_1 * ) ( V_77 ) ;
for ( V_78 = 0 ; V_78 < sizeof( * V_76 ) ; V_78 ++ )
V_79 [ V_78 ] &= V_80 [ V_78 ] ;
}
void F_52 ( struct V_81 * V_82 ,
const struct V_81 * V_83 )
{
int V_78 ;
T_1 * V_79 , * V_80 ;
if ( ! V_83 ) {
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
return;
}
V_79 = ( T_1 * ) ( V_82 ) ;
V_80 = ( T_1 * ) ( V_83 ) ;
for ( V_78 = 0 ; V_78 < sizeof( * V_82 ) ; V_78 ++ )
V_79 [ V_78 ] &= V_80 [ V_78 ] ;
}
int F_53 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_52 * V_53 ,
const T_1 * V_28 ,
const T_1 * V_56 , int V_57 ,
struct V_84 * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
bool V_85 = false ;
F_19 ( V_6 ) ;
if ( V_6 -> V_30 && V_65 -> V_86 &&
F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_65 -> V_86 ) ) {
if ( V_6 -> V_25 == V_32 ) {
V_85 = true ;
V_6 -> V_25 = V_27 ;
}
} else if ( V_6 -> V_30 )
return - V_69 ;
F_51 ( & V_65 -> V_77 ,
V_10 -> V_8 . V_87 ) ;
F_52 ( & V_65 -> V_83 ,
V_10 -> V_8 . V_88 ) ;
V_65 -> V_13 = F_45 ( & V_10 -> V_8 , V_53 , V_28 , V_56 , V_57 ,
V_70 , V_70 ) ;
if ( ! V_65 -> V_13 ) {
if ( V_85 )
V_6 -> V_25 = V_32 ;
return - V_71 ;
}
V_66 = F_46 ( V_10 , V_6 , V_53 , V_73 ) ;
if ( V_66 )
goto V_24;
V_66 = F_54 ( V_10 , V_2 , V_65 ) ;
V_24:
if ( V_66 ) {
if ( V_85 )
V_6 -> V_25 = V_32 ;
F_13 ( & V_10 -> V_8 , V_65 -> V_13 ) ;
}
return V_66 ;
}
int F_55 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_52 * V_53 ,
const T_1 * V_28 ,
const T_1 * V_56 , int V_57 ,
struct V_84 * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
F_49 ( & V_10 -> V_74 ) ;
F_4 ( V_6 ) ;
V_66 = F_53 ( V_10 , V_2 , V_53 , V_28 ,
V_56 , V_57 , V_65 ) ;
F_7 ( V_6 ) ;
F_50 ( & V_10 -> V_74 ) ;
return V_66 ;
}
int F_56 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_58 , T_3 V_89 ,
bool V_90 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_91 V_65 = {
. V_28 = V_28 ,
. V_33 = V_89 ,
. V_17 = V_17 ,
. V_58 = V_58 ,
. V_90 = V_90 ,
} ;
F_19 ( V_6 ) ;
if ( V_90 && ( ! V_6 -> V_30 ||
! F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) )
return 0 ;
return F_57 ( V_10 , V_2 , & V_65 ) ;
}
int F_58 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_58 , T_3 V_89 ,
bool V_90 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
F_4 ( V_6 ) ;
V_66 = F_56 ( V_10 , V_2 , V_28 , V_17 , V_58 , V_89 ,
V_90 ) ;
F_7 ( V_6 ) ;
return V_66 ;
}
static int F_59 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_58 , T_3 V_89 ,
bool V_90 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_92 V_65 ;
F_19 ( V_6 ) ;
if ( V_6 -> V_25 != V_32 )
return - V_93 ;
if ( F_60 ( ! V_6 -> V_30 , L_5 , V_6 -> V_25 ) )
return - V_93 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_33 = V_89 ;
V_65 . V_90 = V_90 ;
V_65 . V_17 = V_17 ;
V_65 . V_58 = V_58 ;
if ( F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) )
V_65 . V_13 = & V_6 -> V_30 -> V_31 ;
else
return - V_93 ;
return F_61 ( V_10 , V_2 , & V_65 ) ;
}
int F_62 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_58 , T_3 V_89 ,
bool V_90 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
F_4 ( V_6 ) ;
V_66 = F_59 ( V_10 , V_2 , V_28 , V_17 , V_58 , V_89 ,
V_90 ) ;
F_7 ( V_6 ) ;
return V_66 ;
}
void F_63 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_91 V_65 ;
T_1 V_28 [ V_94 ] ;
F_19 ( V_6 ) ;
if ( ! V_10 -> V_95 -> V_35 )
return;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_33 = V_96 ;
V_65 . V_17 = NULL ;
V_65 . V_58 = 0 ;
if ( ! V_6 -> V_30 )
return;
memcpy ( V_28 , V_6 -> V_30 -> V_31 . V_28 , V_94 ) ;
V_65 . V_28 = V_28 ;
F_57 ( V_10 , V_2 , & V_65 ) ;
if ( V_6 -> V_30 ) {
F_21 ( V_6 -> V_30 ) ;
F_13 ( & V_10 -> V_8 , & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
}
int F_64 ( struct V_5 * V_6 , T_5 V_97 ,
T_3 V_98 , const T_1 * V_99 ,
int V_100 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_101 * V_102 , * V_103 ;
int V_66 = 0 ;
T_3 V_104 ;
if ( ! V_6 -> V_8 -> V_105 )
return - V_106 ;
if ( ( V_98 & V_107 ) != V_108 )
return - V_68 ;
if ( V_98 & ~ ( V_107 | V_109 ) )
return - V_68 ;
V_104 = ( V_98 & V_109 ) >> 4 ;
if ( ! ( V_6 -> V_8 -> V_105 [ V_6 -> V_110 ] . V_111 & F_65 ( V_104 ) ) )
return - V_68 ;
V_103 = F_66 ( sizeof( * V_102 ) + V_100 , V_11 ) ;
if ( ! V_103 )
return - V_112 ;
F_67 ( & V_6 -> V_113 ) ;
F_68 (reg, &wdev->mgmt_registrations, list) {
int V_114 = F_69 ( V_100 , V_102 -> V_100 ) ;
if ( V_98 != F_11 ( V_102 -> V_98 ) )
continue;
if ( memcmp ( V_102 -> V_115 , V_99 , V_114 ) == 0 ) {
V_66 = - V_69 ;
break;
}
}
if ( V_66 ) {
F_41 ( V_103 ) ;
goto V_24;
}
memcpy ( V_103 -> V_115 , V_99 , V_100 ) ;
V_103 -> V_100 = V_100 ;
V_103 -> V_116 = V_97 ;
V_103 -> V_98 = F_70 ( V_98 ) ;
F_71 ( & V_103 -> V_117 , & V_6 -> V_118 ) ;
if ( V_10 -> V_95 -> V_119 )
F_72 ( V_10 , V_6 , V_98 , true ) ;
V_24:
F_73 ( & V_6 -> V_113 ) ;
return V_66 ;
}
void F_74 ( struct V_5 * V_6 , T_5 V_116 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_101 * V_102 , * V_120 ;
F_67 ( & V_6 -> V_113 ) ;
F_75 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_102 -> V_116 != V_116 )
continue;
if ( V_10 -> V_95 -> V_119 ) {
T_3 V_98 = F_11 ( V_102 -> V_98 ) ;
F_72 ( V_10 , V_6 ,
V_98 , false ) ;
}
F_76 ( & V_102 -> V_117 ) ;
F_41 ( V_102 ) ;
}
F_73 ( & V_6 -> V_113 ) ;
if ( V_116 && V_10 -> V_121 == V_116 ) {
V_10 -> V_121 = 0 ;
F_77 ( V_10 , V_6 ) ;
}
if ( V_116 == V_6 -> V_122 )
V_6 -> V_122 = 0 ;
}
void F_78 ( struct V_5 * V_6 )
{
struct V_101 * V_102 , * V_120 ;
F_67 ( & V_6 -> V_113 ) ;
F_75 (reg, tmp, &wdev->mgmt_registrations, list) {
F_76 ( & V_102 -> V_117 ) ;
F_41 ( V_102 ) ;
}
F_73 ( & V_6 -> V_113 ) ;
}
int F_79 ( struct V_9 * V_10 ,
struct V_5 * V_6 ,
struct V_52 * V_53 , bool V_123 ,
unsigned int V_124 , const T_1 * V_3 , T_2 V_4 ,
bool V_125 , bool V_126 , T_6 * V_127 )
{
const struct V_15 * V_16 ;
T_3 V_128 ;
if ( ! V_6 -> V_8 -> V_105 )
return - V_106 ;
if ( ! V_10 -> V_95 -> V_129 )
return - V_106 ;
if ( V_4 < 24 + 1 )
return - V_68 ;
V_16 = ( const struct V_15 * ) V_3 ;
if ( ! F_80 ( V_16 -> V_130 ) )
return - V_68 ;
V_128 = F_11 ( V_16 -> V_130 ) & V_109 ;
if ( ! ( V_6 -> V_8 -> V_105 [ V_6 -> V_110 ] . V_131 & F_65 ( V_128 >> 4 ) ) )
return - V_68 ;
if ( F_81 ( V_16 -> V_130 ) &&
V_16 -> V_18 . V_132 . V_133 != V_134 ) {
int V_66 = 0 ;
F_4 ( V_6 ) ;
switch ( V_6 -> V_110 ) {
case V_135 :
case V_136 :
case V_137 :
if ( ! V_6 -> V_30 ) {
V_66 = - V_93 ;
break;
}
if ( ! F_20 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_28 ) ) {
V_66 = - V_93 ;
break;
}
if ( V_6 -> V_110 == V_135 )
break;
if ( ! F_20 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_138 ) ) {
V_66 = - V_93 ;
break;
}
break;
case V_139 :
case V_140 :
case V_141 :
if ( ! F_20 ( V_16 -> V_28 , F_82 ( V_6 ) ) )
V_66 = - V_68 ;
break;
case V_142 :
if ( ! F_20 ( V_16 -> V_36 , V_16 -> V_28 ) ) {
V_66 = - V_68 ;
break;
}
break;
case V_143 :
default:
V_66 = - V_106 ;
break;
}
F_7 ( V_6 ) ;
if ( V_66 )
return V_66 ;
}
if ( ! F_20 ( V_16 -> V_36 , F_82 ( V_6 ) ) )
return - V_68 ;
return F_83 ( V_10 , V_6 , V_53 , V_123 ,
V_124 , V_3 , V_4 , V_125 , V_126 ,
V_127 ) ;
}
bool F_84 ( struct V_5 * V_6 , int V_144 , int V_145 ,
const T_1 * V_3 , T_2 V_4 , T_4 V_45 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_101 * V_102 ;
const struct V_146 * V_147 =
& V_8 -> V_105 [ V_6 -> V_110 ] ;
struct V_15 * V_16 = ( void * ) V_3 ;
const T_1 * V_49 ;
int V_148 ;
bool V_149 = false ;
T_7 V_150 = V_16 -> V_130 &
F_70 ( V_107 | V_109 ) ;
T_3 V_128 ;
F_85 ( V_6 , V_144 , V_145 ) ;
V_128 = ( F_11 ( V_16 -> V_130 ) & V_109 ) >> 4 ;
if ( ! ( V_147 -> V_111 & F_65 ( V_128 ) ) ) {
F_86 ( false ) ;
return false ;
}
V_49 = V_3 + F_87 ( V_16 -> V_130 ) ;
V_148 = V_4 - F_87 ( V_16 -> V_130 ) ;
F_67 ( & V_6 -> V_113 ) ;
F_68 (reg, &wdev->mgmt_registrations, list) {
if ( V_102 -> V_98 != V_150 )
continue;
if ( V_102 -> V_100 > V_148 )
continue;
if ( memcmp ( V_102 -> V_115 , V_49 , V_102 -> V_100 ) )
continue;
if ( F_88 ( V_10 , V_6 , V_102 -> V_116 ,
V_144 , V_145 ,
V_3 , V_4 , V_45 ) )
continue;
V_149 = true ;
break;
}
F_73 ( & V_6 -> V_113 ) ;
F_86 ( V_149 ) ;
return V_149 ;
}
void F_89 ( struct V_151 * V_152 )
{
struct V_153 * V_153 ;
struct V_9 * V_10 ;
struct V_154 V_155 ;
struct V_156 * V_157 ;
struct V_52 * V_158 ;
struct V_8 * V_8 ;
bool V_159 = false ;
unsigned long V_160 , V_161 = 0 ;
int V_162 , V_78 ;
V_153 = F_90 ( V_152 , struct V_153 , V_152 ) ;
V_10 = F_90 ( V_153 , struct V_9 ,
V_163 ) ;
V_8 = & V_10 -> V_8 ;
F_49 ( & V_164 ) ;
for ( V_162 = 0 ; V_162 < V_165 ; V_162 ++ ) {
V_157 = V_8 -> V_166 [ V_162 ] ;
if ( ! V_157 )
continue;
for ( V_78 = 0 ; V_78 < V_157 -> V_167 ; V_78 ++ ) {
V_158 = & V_157 -> V_168 [ V_78 ] ;
if ( V_158 -> V_169 != V_170 )
continue;
V_160 = V_158 -> V_171 +
V_172 ;
if ( F_91 ( V_173 , V_160 ) ) {
V_158 -> V_169 = V_174 ;
F_92 ( & V_155 , V_158 ,
V_175 ) ;
F_93 ( V_10 , & V_155 ,
V_176 ,
NULL , V_177 ) ;
continue;
}
if ( ! V_159 )
V_161 = V_160 - V_173 ;
else
V_161 = F_69 ( V_161 , V_160 - V_173 ) ;
V_159 = true ;
}
}
F_50 ( & V_164 ) ;
if ( V_159 )
F_94 ( V_178 , & V_10 -> V_163 ,
V_161 ) ;
}
void F_95 ( struct V_8 * V_8 ,
struct V_154 * V_155 ,
T_4 V_45 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
unsigned long V_160 ;
F_96 ( V_8 , V_155 ) ;
F_97 ( V_8 , V_155 , V_170 ) ;
V_160 = F_98 ( V_172 ) ;
F_94 ( V_178 , & V_10 -> V_163 ,
V_160 ) ;
F_93 ( V_10 , V_155 , V_179 , NULL , V_45 ) ;
}
void F_99 ( struct V_1 * V_180 ,
enum V_181 V_182 , T_4 V_45 )
{
struct V_5 * V_6 = V_180 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_154 V_155 ;
unsigned long V_160 ;
F_100 ( V_180 , V_182 ) ;
if ( F_29 ( ! V_6 -> V_183 ) )
return;
if ( F_29 ( ! V_6 -> V_72 ) )
return;
F_92 ( & V_155 , V_6 -> V_72 , V_175 ) ;
switch ( V_182 ) {
case V_184 :
V_160 = V_6 -> V_185 +
F_98 ( V_186 ) ;
F_29 ( ! F_91 ( V_173 , V_160 ) ) ;
F_97 ( V_8 , & V_155 , V_187 ) ;
break;
case V_188 :
break;
default:
F_29 ( 1 ) ;
return;
}
V_6 -> V_183 = false ;
F_93 ( V_10 , & V_155 , V_182 , V_180 , V_45 ) ;
}
