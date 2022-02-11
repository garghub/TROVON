struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_3 ) ;
if ( V_5 ) {
F_3 ( & V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
}
F_5 ( L_1 , V_8 , V_5 ) ;
return & V_5 -> V_9 ;
}
void
F_6 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = F_7 ( V_10 ) ;
F_5 ( L_2 , V_8 , V_5 ) ;
F_8 ( ! F_9 ( & V_5 -> V_7 ) ) ;
F_10 ( V_5 ) ;
}
struct V_11 *
F_11 ( struct V_1 * V_12 ,
struct V_13 * V_14 ,
T_1 V_3 )
{
int V_15 = - V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 = {
. V_21 = V_14 -> V_22 -> V_21 ,
. V_23 = V_14 -> V_22 -> V_24 ,
. V_25 = V_14 -> V_22 -> V_24 ,
. V_24 = V_14 -> V_22 -> V_24 ,
} ;
struct V_26 * V_27 ;
struct V_11 * V_28 ;
F_5 ( L_3 , V_8 , V_12 ) ;
V_27 = F_12 ( V_3 ) ;
if ( ! V_27 )
goto V_29;
F_13 ( & V_18 , & V_20 , NULL ) ;
F_14 ( & V_18 , F_15 ( V_27 ) , V_30 ) ;
V_15 = F_16 ( & V_28 , V_12 , & V_14 -> V_31 , & V_18 , V_3 ) ;
if ( F_17 ( V_15 ) ) {
F_5 ( L_4 , V_8 ,
V_15 ) ;
goto V_32;
}
F_18 ( V_27 ) ;
F_5 ( L_1 , V_8 , V_28 ) ;
return V_28 ;
V_32:
F_18 ( V_27 ) ;
V_29:
F_5 ( L_5 , V_8 , V_15 ) ;
return F_19 ( V_15 ) ;
}
void
F_20 ( struct V_11 * V_28 )
{
F_5 ( L_6 , V_8 , V_28 ) ;
if ( F_17 ( ! V_28 ) )
return;
F_21 ( V_28 ) ;
}
static inline T_2
F_22 ( T_2 V_33 , T_2 V_24 )
{
T_2 V_34 ;
V_34 = V_33 + V_24 ;
return V_34 >= V_33 ? V_34 : V_35 ;
}
static inline T_2
F_23 ( T_2 V_33 , T_2 V_24 )
{
T_2 V_34 ;
F_24 ( ! V_24 ) ;
V_34 = V_33 + V_24 ;
return V_34 > V_33 ? V_34 - 1 : V_35 ;
}
static struct V_36 *
F_25 ( struct V_1 * V_37 ,
struct V_26 * * V_21 ,
unsigned V_38 ,
T_3 V_39 ,
T_4 V_40 ,
struct V_11 * V_28 ,
void * V_41 ,
T_1 V_3 )
{
struct V_36 * V_42 ;
T_2 V_43 ;
F_5 ( L_7 , V_8 ) ;
if ( F_26 ( V_28 , & V_42 , V_3 ) )
return NULL ;
F_24 ( V_39 < V_28 -> V_44 . V_39 ) ;
V_43 = F_22 ( V_28 -> V_44 . V_39 ,
V_28 -> V_44 . V_45 ) ;
F_24 ( V_39 >= V_43 ) ;
if ( V_39 + V_40 > V_43 ) {
V_40 = V_28 -> V_44 . V_45 -
( V_39 - V_28 -> V_44 . V_39 ) ;
F_5 ( L_8 , V_8 , V_40 ) ;
}
if ( V_38 > V_30 ) {
V_21 += V_38 >> V_46 ;
V_38 &= ~ V_47 ;
}
F_4 ( & V_42 -> V_7 ) ;
V_42 -> V_28 = V_28 ;
V_42 -> V_41 = V_41 ;
V_42 -> V_21 = V_21 ;
V_42 -> V_38 = V_38 ;
V_42 -> V_48 = ( V_38 + V_40 + V_30 - 1 ) >> V_46 ;
V_42 -> V_39 = V_39 ;
V_42 -> V_40 = V_40 ;
V_42 -> V_49 = 0 ;
return V_42 ;
}
static void
F_27 ( struct V_36 * V_42 )
{
F_5 ( L_9 , V_8 ) ;
if ( F_17 ( ! V_42 ) )
return;
F_28 ( V_42 ) ;
}
static void
F_29 ( struct V_36 * V_42 )
{
F_5 ( L_10 , V_8 , V_42 ) ;
if ( F_30 ( V_42 -> V_15 >= 0 ) ) {
F_27 ( V_42 ) ;
} else {
struct V_4 * V_5 = F_7 ( V_42 -> V_28 -> V_50 ) ;
F_31 ( & V_5 -> V_6 ) ;
V_5 -> V_51 = V_52 ;
F_32 ( & V_5 -> V_7 , & V_42 -> V_7 ) ;
F_33 ( & V_5 -> V_6 ) ;
}
}
void
F_34 ( struct V_36 * V_42 , unsigned V_53 ,
struct V_54 * V_55 , int V_56 ,
T_2 V_39 , T_2 V_45 , bool V_57 )
{
struct V_58 * V_59 = & V_42 -> V_60 [ V_53 ] ;
F_24 ( V_53 >= V_42 -> V_61 ) ;
if ( V_56 ) {
V_59 -> V_62 = * V_55 ;
V_59 -> V_63 = V_39 ;
V_59 -> V_64 = V_45 ;
V_59 -> V_65 = V_57 ;
V_59 -> V_66 = V_56 ;
F_5 ( L_11
L_12 ,
V_8 , V_53 , V_59 -> V_66 ,
V_59 -> V_65 ,
F_35 ( & V_59 -> V_62 . V_67 ) ,
F_36 ( & V_59 -> V_62 . V_67 ) ,
V_59 -> V_62 . V_68 ,
V_59 -> V_62 . V_69 ,
V_59 -> V_63 ,
V_59 -> V_64 ) ;
} else {
V_59 -> V_66 = 0 ;
}
}
static void F_37 ( struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
F_5 ( L_13 , V_8 ) ;
V_73 = F_38 ( V_71 , struct V_72 , V_76 . V_77 ) ;
V_75 = F_38 ( V_73 , struct V_74 , V_73 ) ;
F_39 ( V_75 ) ;
}
void
F_40 ( struct V_36 * V_42 , T_5 V_15 , bool V_49 )
{
int V_78 = V_42 -> V_78 ;
struct V_74 * V_75 ;
V_42 -> V_15 = V_15 ;
F_5 ( L_14 , V_8 , V_15 , V_78 ) ;
V_75 = V_42 -> V_41 ;
V_75 -> V_73 . V_79 = V_15 ;
if ( V_15 >= 0 ) {
V_75 -> V_80 . V_40 = V_15 ;
V_75 -> V_80 . V_78 = V_78 ;
}
F_29 ( V_42 ) ;
if ( V_49 )
F_39 ( V_75 ) ;
else {
F_41 ( & V_75 -> V_73 . V_76 . V_77 , F_37 ) ;
F_42 ( & V_75 -> V_73 . V_76 . V_77 ) ;
}
}
enum V_81
F_43 ( struct V_74 * V_75 )
{
T_3 V_39 = V_75 -> args . V_39 ;
T_4 V_40 = V_75 -> args . V_40 ;
struct V_36 * V_42 ;
T_5 V_15 = 0 ;
T_3 V_78 ;
F_5 ( L_15 ,
V_8 , V_75 -> V_2 , V_39 , ( int ) V_40 ) ;
V_78 = F_44 ( V_75 -> V_2 ) ;
if ( F_17 ( V_39 + V_40 > V_78 ) ) {
if ( V_39 >= V_78 ) {
V_15 = 0 ;
V_75 -> V_80 . V_40 = 0 ;
V_75 -> V_80 . V_78 = 1 ;
goto V_82;
}
V_40 = V_78 - V_39 ;
}
V_42 = F_25 ( F_45 ( V_75 -> V_2 ) -> V_83 ,
V_75 -> args . V_21 , V_75 -> args . V_38 ,
V_39 , V_40 ,
V_75 -> V_28 , V_75 ,
V_84 ) ;
if ( F_17 ( ! V_42 ) ) {
V_15 = - V_16 ;
goto V_82;
}
V_42 -> V_78 = V_42 -> V_39 + V_42 -> V_40 >= V_78 ;
V_15 = F_46 ( V_42 ) ;
V_82:
F_5 ( L_16 , V_8 , V_15 ) ;
V_75 -> V_85 = V_15 ;
return V_86 ;
}
static void F_47 ( struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_87 * V_88 ;
F_5 ( L_13 , V_8 ) ;
V_73 = F_38 ( V_71 , struct V_72 , V_76 . V_77 ) ;
V_88 = F_38 ( V_73 , struct V_87 , V_73 ) ;
F_48 ( V_88 ) ;
}
void
F_49 ( struct V_36 * V_42 , T_5 V_15 ,
bool V_49 )
{
struct V_87 * V_88 ;
F_5 ( L_17 , V_8 ) ;
V_88 = V_42 -> V_41 ;
V_42 -> V_15 = V_15 ;
V_88 -> V_73 . V_79 = V_15 ;
if ( V_15 >= 0 ) {
V_88 -> V_80 . V_40 = V_15 ;
V_88 -> V_89 . V_90 = V_42 -> V_90 ;
F_5 ( L_18 ,
V_8 , V_88 -> V_73 . V_79 ,
V_88 -> V_89 . V_90 ) ;
} else
F_5 ( L_19 ,
V_8 , V_88 -> V_73 . V_79 ) ;
F_29 ( V_42 ) ;
if ( V_49 )
F_48 ( V_88 ) ;
else {
F_41 ( & V_88 -> V_73 . V_76 . V_77 , F_47 ) ;
F_42 ( & V_88 -> V_73 . V_76 . V_77 ) ;
}
}
enum V_81
F_50 ( struct V_87 * V_88 ,
int V_91 )
{
struct V_36 * V_42 ;
T_5 V_15 ;
F_5 ( L_20 ,
V_8 , V_88 -> V_2 , V_88 -> args . V_39 , V_88 -> args . V_40 ) ;
V_42 = F_25 ( F_45 ( V_88 -> V_2 ) -> V_83 ,
V_88 -> args . V_21 ,
V_88 -> args . V_38 ,
V_88 -> args . V_39 ,
V_88 -> args . V_40 ,
V_88 -> V_28 , V_88 ,
V_92 ) ;
if ( F_17 ( ! V_42 ) ) {
V_15 = - V_16 ;
goto V_82;
}
V_42 -> V_49 = V_91 & V_93 ;
V_15 = F_51 ( V_42 , V_91 & V_94 ) ;
V_82:
F_5 ( L_16 , V_8 , V_15 ) ;
V_88 -> V_85 = V_15 ;
return V_86 ;
}
void
F_52 ( struct V_1 * V_12 ,
struct V_17 * V_95 ,
const struct V_96 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_97 V_98 ;
T_6 * V_33 ;
F_5 ( L_17 , V_8 ) ;
F_31 ( & V_5 -> V_6 ) ;
V_98 . V_99 = ( V_5 -> V_51 == V_100 ) ;
V_98 . V_101 = V_5 -> V_102 ;
V_5 -> V_102 = 0 ;
V_5 -> V_51 = V_103 ;
V_98 . V_104 = ! F_9 ( & V_5 -> V_7 ) ;
F_33 ( & V_5 -> V_6 ) ;
V_33 = F_53 ( V_95 , 4 ) ;
F_24 ( F_54 ( V_95 , & V_98 ) ) ;
* V_33 = F_55 ( ( V_95 -> V_105 - V_33 - 1 ) * 4 ) ;
F_5 ( L_21 , V_8 ,
V_98 . V_101 , V_98 . V_104 ) ;
}
static int
F_56 ( T_7 V_66 )
{
switch ( V_66 ) {
case 0 :
return 0 ;
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
default:
F_8 ( 1 ) ;
case V_118 :
return V_119 ;
}
}
static void
F_57 ( struct V_58 * V_120 ,
const struct V_58 * V_121 )
{
T_2 V_122 , V_123 ;
if ( ! V_120 -> V_66 ) {
* V_120 = * V_121 ;
memset ( & V_120 -> V_62 . V_67 , 0 ,
sizeof( V_120 -> V_62 . V_67 ) ) ;
return;
}
if ( V_120 -> V_62 . V_68 !=
V_121 -> V_62 . V_68 )
V_120 -> V_62 . V_68 = 0 ;
if ( V_120 -> V_62 . V_69 !=
V_121 -> V_62 . V_69 )
V_120 -> V_62 . V_69 = 0 ;
if ( V_120 -> V_63 > V_121 -> V_63 )
V_120 -> V_63 = V_121 -> V_63 ;
V_122 = F_22 ( V_120 -> V_63 ,
V_120 -> V_64 ) ;
V_123 = F_22 ( V_121 -> V_63 ,
V_121 -> V_64 ) ;
if ( V_122 < V_123 )
V_122 = V_123 ;
V_120 -> V_64 = V_122 - V_120 -> V_63 ;
if ( ( V_121 -> V_65 == V_120 -> V_65 ) &&
( F_56 ( V_121 -> V_66 ) > F_56 ( V_120 -> V_66 ) ) ) {
V_120 -> V_66 = V_121 -> V_66 ;
} else if ( V_121 -> V_65 ) {
V_120 -> V_65 = true ;
V_120 -> V_66 = V_121 -> V_66 ;
}
}
static void
F_58 ( struct V_4 * V_5 , T_6 * V_105 )
{
struct V_36 * V_42 , * V_124 ;
struct V_58 V_125 = { . V_66 = 0 } ;
F_59 (state, tmp, &objlay->err_list, err_list) {
unsigned V_126 ;
for ( V_126 = 0 ; V_126 < V_42 -> V_61 ; V_126 ++ ) {
struct V_58 * V_59 = & V_42 -> V_60 [ V_126 ] ;
if ( ! V_59 -> V_66 )
continue;
F_60 ( V_127 L_22
L_23
L_24 ,
V_8 , V_126 , V_59 -> V_66 ,
V_59 -> V_65 ,
F_35 ( & V_59 -> V_62 . V_67 ) ,
F_36 ( & V_59 -> V_62 . V_67 ) ,
V_59 -> V_62 . V_68 ,
V_59 -> V_62 . V_69 ,
V_59 -> V_63 ,
V_59 -> V_64 ) ;
F_57 ( & V_125 , V_59 ) ;
}
F_61 ( & V_42 -> V_7 ) ;
F_27 ( V_42 ) ;
}
F_62 ( V_105 , & V_125 ) ;
}
void
F_63 ( struct V_1 * V_12 ,
struct V_17 * V_95 ,
const struct V_128 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_36 * V_42 , * V_124 ;
T_6 * V_33 ;
F_5 ( L_17 , V_8 ) ;
V_33 = F_53 ( V_95 , 4 ) ;
F_24 ( ! V_33 ) ;
F_31 ( & V_5 -> V_6 ) ;
F_59 (state, tmp, &objlay->err_list, err_list) {
T_6 * V_129 = NULL , * V_105 ;
unsigned V_126 ;
int V_80 = 0 ;
for ( V_126 = 0 ; V_126 < V_42 -> V_61 ; V_126 ++ ) {
struct V_58 * V_59 = & V_42 -> V_60 [ V_126 ] ;
if ( ! V_59 -> V_66 )
continue;
F_5 ( L_22
L_23
L_24 ,
V_8 , V_126 , V_59 -> V_66 ,
V_59 -> V_65 ,
F_35 ( & V_59 -> V_62 . V_67 ) ,
F_36 ( & V_59 -> V_62 . V_67 ) ,
V_59 -> V_62 . V_68 ,
V_59 -> V_62 . V_69 ,
V_59 -> V_63 ,
V_59 -> V_64 ) ;
V_105 = F_64 ( V_95 ) ;
if ( F_17 ( ! V_105 ) ) {
V_80 = - V_130 ;
break;
}
V_129 = V_105 ;
F_62 ( V_105 , & V_42 -> V_60 [ V_126 ] ) ;
}
if ( F_17 ( V_80 ) ) {
F_24 ( ! V_129 ) ;
F_58 ( V_5 , V_129 ) ;
goto V_131;
}
F_61 ( & V_42 -> V_7 ) ;
F_27 ( V_42 ) ;
}
V_131:
F_33 ( & V_5 -> V_6 ) ;
* V_33 = F_55 ( ( V_95 -> V_105 - V_33 - 1 ) * 4 ) ;
F_5 ( L_25 , V_8 ) ;
}
int F_65 ( struct V_1 * V_12 ,
struct V_132 * V_133 , struct V_134 * * V_135 ,
T_1 V_3 )
{
struct V_136 * V_137 ;
struct V_138 V_139 ;
struct V_140 * V_141 ;
struct V_26 * V_26 , * * V_21 ;
T_7 * V_105 ;
int V_32 ;
V_26 = F_12 ( V_3 ) ;
if ( ! V_26 )
return - V_16 ;
V_21 = & V_26 ;
V_139 . V_21 = V_21 ;
memcpy ( & V_139 . V_142 , V_133 , sizeof( * V_133 ) ) ;
V_139 . V_143 = V_144 ;
V_139 . V_21 = & V_26 ;
V_139 . V_38 = 0 ;
V_139 . V_145 = V_30 ;
V_139 . V_146 = 0 ;
V_141 = V_12 -> V_147 -> V_148 ;
V_32 = F_66 ( F_67 ( V_12 -> V_147 ) , & V_139 ) ;
F_5 ( L_26 , V_8 , V_32 ) ;
if ( V_32 )
goto V_149;
V_105 = F_15 ( V_26 ) ;
V_137 = F_2 ( sizeof( * V_137 ) , V_3 ) ;
if ( ! V_137 ) {
V_32 = - V_16 ;
goto V_149;
}
F_68 ( & V_137 -> V_150 , V_105 ) ;
V_137 -> V_26 = V_26 ;
* V_135 = & V_137 -> V_150 ;
return 0 ;
V_149:
F_18 ( V_26 ) ;
return V_32 ;
}
void F_69 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = F_38 ( V_135 ,
struct V_136 ,
V_150 ) ;
F_18 ( V_137 -> V_26 ) ;
F_10 ( V_137 ) ;
}
