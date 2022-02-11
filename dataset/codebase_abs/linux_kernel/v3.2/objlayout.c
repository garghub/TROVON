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
void F_25 ( struct V_11 * V_28 ,
struct V_26 * * * V_36 , unsigned * V_37 ,
T_2 V_38 , unsigned long V_39 )
{
T_2 V_40 ;
F_24 ( V_38 < V_28 -> V_41 . V_38 ) ;
V_40 = F_22 ( V_28 -> V_41 . V_38 ,
V_28 -> V_41 . V_42 ) ;
F_24 ( V_38 >= V_40 ) ;
F_8 ( V_38 + V_39 > V_40 ) ;
if ( * V_37 > V_30 ) {
F_5 ( L_7 , V_8 , * V_37 ) ;
* V_36 += * V_37 >> V_43 ;
* V_37 &= ~ V_44 ;
}
}
static void
F_26 ( struct V_45 * V_46 )
{
if ( F_27 ( V_46 -> V_15 >= 0 ) ) {
F_28 ( V_46 ) ;
} else {
struct V_4 * V_5 = V_46 -> V_5 ;
F_29 ( & V_5 -> V_6 ) ;
V_5 -> V_47 = V_48 ;
F_30 ( & V_5 -> V_7 , & V_46 -> V_7 ) ;
F_31 ( & V_5 -> V_6 ) ;
}
}
void
F_32 ( struct V_45 * V_46 , unsigned V_49 ,
struct V_50 * V_51 , int V_52 ,
T_2 V_38 , T_2 V_42 , bool V_53 )
{
struct V_54 * V_55 = & V_46 -> V_56 [ V_49 ] ;
F_24 ( V_49 >= V_46 -> V_57 ) ;
if ( V_52 ) {
V_55 -> V_58 = * V_51 ;
V_55 -> V_59 = V_38 ;
V_55 -> V_60 = V_42 ;
V_55 -> V_61 = V_53 ;
V_55 -> V_62 = V_52 ;
F_5 ( L_8
L_9 ,
V_8 , V_49 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
F_34 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
} else {
V_55 -> V_62 = 0 ;
}
}
static void F_35 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
F_5 ( L_10 , V_8 ) ;
V_69 = F_36 ( V_67 , struct V_68 , V_72 . V_73 ) ;
V_71 = F_36 ( V_69 , struct V_70 , V_69 ) ;
F_37 ( V_71 ) ;
}
void
F_38 ( struct V_45 * V_46 , T_3 V_15 , bool V_74 )
{
struct V_70 * V_71 = V_46 -> V_75 ;
V_46 -> V_15 = V_71 -> V_69 . V_76 = V_15 ;
if ( V_15 >= 0 )
V_71 -> V_77 . V_39 = V_15 ;
F_26 ( V_46 ) ;
F_5 ( L_11 , V_8 ,
V_15 , V_71 -> V_77 . V_78 , V_74 ) ;
if ( V_74 )
F_37 ( V_71 ) ;
else {
F_39 ( & V_71 -> V_69 . V_72 . V_73 , F_35 ) ;
F_40 ( & V_71 -> V_69 . V_72 . V_73 ) ;
}
}
enum V_79
F_41 ( struct V_70 * V_71 )
{
T_4 V_38 = V_71 -> args . V_38 ;
T_5 V_39 = V_71 -> args . V_39 ;
int V_32 ;
T_4 V_78 ;
V_78 = F_42 ( V_71 -> V_2 ) ;
if ( F_17 ( V_38 + V_39 > V_78 ) ) {
if ( V_38 >= V_78 ) {
V_32 = 0 ;
V_71 -> V_77 . V_39 = 0 ;
V_71 -> V_77 . V_78 = 1 ;
goto V_80;
}
V_39 = V_78 - V_38 ;
}
V_71 -> V_77 . V_78 = ( V_38 + V_39 ) >= V_78 ;
F_25 ( V_71 -> V_28 , & V_71 -> args . V_21 ,
& V_71 -> args . V_81 ,
V_71 -> args . V_38 , V_71 -> args . V_39 ) ;
F_5 ( L_12 ,
V_8 , V_71 -> V_2 -> V_82 , V_38 , V_39 , V_71 -> V_77 . V_78 ) ;
V_32 = F_43 ( V_71 ) ;
V_80:
if ( F_17 ( V_32 ) ) {
V_71 -> V_83 = V_32 ;
F_5 ( L_13 , V_8 , V_32 ) ;
return V_84 ;
}
return V_85 ;
}
static void F_44 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_86 * V_87 ;
F_5 ( L_10 , V_8 ) ;
V_69 = F_36 ( V_67 , struct V_68 , V_72 . V_73 ) ;
V_87 = F_36 ( V_69 , struct V_86 , V_69 ) ;
F_45 ( V_87 ) ;
}
void
F_46 ( struct V_45 * V_46 , T_3 V_15 , bool V_74 )
{
struct V_86 * V_87 = V_46 -> V_75 ;
V_46 -> V_15 = V_87 -> V_69 . V_76 = V_15 ;
if ( V_15 >= 0 ) {
V_87 -> V_77 . V_39 = V_15 ;
V_87 -> V_88 . V_89 = V_46 -> V_89 ;
}
F_26 ( V_46 ) ;
F_5 ( L_14 , V_8 ,
V_15 , V_87 -> V_88 . V_89 , V_74 ) ;
if ( V_74 )
F_45 ( V_87 ) ;
else {
F_39 ( & V_87 -> V_69 . V_72 . V_73 , F_44 ) ;
F_40 ( & V_87 -> V_69 . V_72 . V_73 ) ;
}
}
enum V_79
F_47 ( struct V_86 * V_87 ,
int V_90 )
{
int V_32 ;
F_25 ( V_87 -> V_28 , & V_87 -> args . V_21 ,
& V_87 -> args . V_81 ,
V_87 -> args . V_38 , V_87 -> args . V_39 ) ;
V_32 = F_48 ( V_87 , V_90 ) ;
if ( F_17 ( V_32 ) ) {
V_87 -> V_83 = V_32 ;
F_5 ( L_13 , V_8 , V_32 ) ;
return V_84 ;
}
return V_85 ;
}
void
F_49 ( struct V_1 * V_12 ,
struct V_17 * V_91 ,
const struct V_92 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_93 V_94 ;
T_6 * V_33 ;
F_5 ( L_15 , V_8 ) ;
F_29 ( & V_5 -> V_6 ) ;
V_94 . V_95 = ( V_5 -> V_47 == V_96 ) ;
V_94 . V_97 = V_5 -> V_98 ;
V_5 -> V_98 = 0 ;
V_5 -> V_47 = V_99 ;
V_94 . V_100 = ! F_9 ( & V_5 -> V_7 ) ;
F_31 ( & V_5 -> V_6 ) ;
V_33 = F_50 ( V_91 , 4 ) ;
F_24 ( F_51 ( V_91 , & V_94 ) ) ;
* V_33 = F_52 ( ( V_91 -> V_101 - V_33 - 1 ) * 4 ) ;
F_5 ( L_16 , V_8 ,
V_94 . V_97 , V_94 . V_100 ) ;
}
static int
F_53 ( T_7 V_62 )
{
switch ( V_62 ) {
case 0 :
return 0 ;
case V_102 :
return V_103 ;
case V_104 :
return V_105 ;
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
default:
F_8 ( 1 ) ;
case V_114 :
return V_115 ;
}
}
static void
F_54 ( struct V_54 * V_116 ,
const struct V_54 * V_117 )
{
T_2 V_118 , V_119 ;
if ( ! V_116 -> V_62 ) {
* V_116 = * V_117 ;
memset ( & V_116 -> V_58 . V_63 , 0 ,
sizeof( V_116 -> V_58 . V_63 ) ) ;
return;
}
if ( V_116 -> V_58 . V_64 !=
V_117 -> V_58 . V_64 )
V_116 -> V_58 . V_64 = 0 ;
if ( V_116 -> V_58 . V_65 !=
V_117 -> V_58 . V_65 )
V_116 -> V_58 . V_65 = 0 ;
if ( V_116 -> V_59 > V_117 -> V_59 )
V_116 -> V_59 = V_117 -> V_59 ;
V_118 = F_22 ( V_116 -> V_59 ,
V_116 -> V_60 ) ;
V_119 = F_22 ( V_117 -> V_59 ,
V_117 -> V_60 ) ;
if ( V_118 < V_119 )
V_118 = V_119 ;
V_116 -> V_60 = V_118 - V_116 -> V_59 ;
if ( ( V_117 -> V_61 == V_116 -> V_61 ) &&
( F_53 ( V_117 -> V_62 ) > F_53 ( V_116 -> V_62 ) ) ) {
V_116 -> V_62 = V_117 -> V_62 ;
} else if ( V_117 -> V_61 ) {
V_116 -> V_61 = true ;
V_116 -> V_62 = V_117 -> V_62 ;
}
}
static void
F_55 ( struct V_4 * V_5 , T_6 * V_101 )
{
struct V_45 * V_46 , * V_120 ;
struct V_54 V_121 = { . V_62 = 0 } ;
F_56 (oir, tmp, &objlay->err_list, err_list) {
unsigned V_122 ;
for ( V_122 = 0 ; V_122 < V_46 -> V_57 ; V_122 ++ ) {
struct V_54 * V_55 = & V_46 -> V_56 [ V_122 ] ;
if ( ! V_55 -> V_62 )
continue;
F_57 ( V_123 L_17
L_18
L_19 ,
V_8 , V_122 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
F_34 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
F_54 ( & V_121 , V_55 ) ;
}
F_58 ( & V_46 -> V_7 ) ;
F_28 ( V_46 ) ;
}
F_59 ( V_101 , & V_121 ) ;
}
void
F_60 ( struct V_1 * V_12 ,
struct V_17 * V_91 ,
const struct V_124 * args )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_45 * V_46 , * V_120 ;
T_6 * V_33 ;
F_5 ( L_15 , V_8 ) ;
V_33 = F_50 ( V_91 , 4 ) ;
F_24 ( ! V_33 ) ;
F_29 ( & V_5 -> V_6 ) ;
F_56 (oir, tmp, &objlay->err_list, err_list) {
T_6 * V_125 = NULL , * V_101 ;
unsigned V_122 ;
int V_77 = 0 ;
for ( V_122 = 0 ; V_122 < V_46 -> V_57 ; V_122 ++ ) {
struct V_54 * V_55 = & V_46 -> V_56 [ V_122 ] ;
if ( ! V_55 -> V_62 )
continue;
F_5 ( L_17
L_18
L_19 ,
V_8 , V_122 , V_55 -> V_62 ,
V_55 -> V_61 ,
F_33 ( & V_55 -> V_58 . V_63 ) ,
F_34 ( & V_55 -> V_58 . V_63 ) ,
V_55 -> V_58 . V_64 ,
V_55 -> V_58 . V_65 ,
V_55 -> V_59 ,
V_55 -> V_60 ) ;
V_101 = F_61 ( V_91 ) ;
if ( F_17 ( ! V_101 ) ) {
V_77 = - V_126 ;
break;
}
V_125 = V_101 ;
F_59 ( V_101 , & V_46 -> V_56 [ V_122 ] ) ;
}
if ( F_17 ( V_77 ) ) {
F_24 ( ! V_125 ) ;
F_55 ( V_5 , V_125 ) ;
goto V_127;
}
F_58 ( & V_46 -> V_7 ) ;
F_28 ( V_46 ) ;
}
V_127:
F_31 ( & V_5 -> V_6 ) ;
* V_33 = F_52 ( ( V_91 -> V_101 - V_33 - 1 ) * 4 ) ;
F_5 ( L_20 , V_8 ) ;
}
int F_62 ( struct V_1 * V_12 ,
struct V_128 * V_129 , struct V_130 * * V_131 ,
T_1 V_3 )
{
struct V_132 * V_133 ;
struct V_134 V_135 ;
struct V_136 * V_137 ;
struct V_26 * V_26 , * * V_21 ;
T_7 * V_101 ;
int V_32 ;
V_26 = F_12 ( V_3 ) ;
if ( ! V_26 )
return - V_16 ;
V_21 = & V_26 ;
V_135 . V_21 = V_21 ;
memcpy ( & V_135 . V_138 , V_129 , sizeof( * V_129 ) ) ;
V_135 . V_139 = V_140 ;
V_135 . V_21 = & V_26 ;
V_135 . V_81 = 0 ;
V_135 . V_141 = V_30 ;
V_135 . V_142 = 0 ;
V_137 = V_12 -> V_143 -> V_144 ;
V_32 = F_63 ( F_64 ( V_12 -> V_143 ) , & V_135 ) ;
F_5 ( L_21 , V_8 , V_32 ) ;
if ( V_32 )
goto V_145;
V_101 = F_15 ( V_26 ) ;
V_133 = F_2 ( sizeof( * V_133 ) , V_3 ) ;
if ( ! V_133 ) {
V_32 = - V_16 ;
goto V_145;
}
F_65 ( & V_133 -> V_146 , V_101 ) ;
V_133 -> V_26 = V_26 ;
* V_131 = & V_133 -> V_146 ;
return 0 ;
V_145:
F_18 ( V_26 ) ;
return V_32 ;
}
void F_66 ( struct V_130 * V_131 )
{
struct V_132 * V_133 = F_36 ( V_131 ,
struct V_132 ,
V_146 ) ;
F_18 ( V_133 -> V_26 ) ;
F_10 ( V_133 ) ;
}
