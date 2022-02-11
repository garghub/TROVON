void F_1 ( struct V_1 * V_2 )
{
if ( V_2 )
F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 . V_4 ) ;
F_5 ( V_2 -> V_5 ) ;
F_6 ( V_2 ) ;
}
struct V_1 *
F_7 ( struct V_6 * V_7 , struct V_8 * V_9 ,
T_1 V_10 )
{
struct V_11 V_12 ;
struct V_13 V_14 ;
struct V_15 * V_16 ;
struct V_17 V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_21 = NULL ;
struct V_22 * V_23 = NULL ;
T_2 V_24 ;
T_2 V_25 ;
T_3 * V_26 ;
int V_27 , V_28 = - V_29 ;
V_16 = F_8 ( V_10 ) ;
if ( ! V_16 )
goto V_30;
V_21 = F_9 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_21 )
goto V_31;
F_10 ( & V_21 -> V_3 ,
V_7 ,
& V_9 -> V_32 ) ;
F_11 ( & V_18 ) ;
F_12 ( & V_12 , & V_14 , V_9 -> V_33 , V_9 -> V_34 ) ;
F_13 ( & V_12 , F_14 ( V_16 ) , V_35 ) ;
V_26 = F_15 ( & V_12 , 4 ) ;
if ( F_16 ( ! V_26 ) )
goto V_36;
V_24 = F_17 ( V_26 ) ;
F_18 ( L_1 , V_37 , V_24 ) ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ ) {
V_20 = F_19 ( V_7 -> V_38 -> V_39 ,
& V_12 , V_10 ) ;
if ( V_20 )
F_20 ( & V_20 -> V_40 , & V_18 ) ;
}
if ( F_21 ( & V_18 ) ) {
F_18 ( L_2 ,
V_37 ) ;
V_28 = - V_41 ;
goto V_36;
}
V_26 = F_15 ( & V_12 , 4 ) ;
if ( F_16 ( ! V_26 ) )
goto V_36;
V_25 = F_17 ( V_26 ) ;
F_18 ( L_3 , V_37 , V_25 ) ;
V_23 = F_9 ( V_25 * sizeof( struct V_22 ) ,
V_10 ) ;
if ( ! V_23 )
goto V_31;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ ) {
V_26 = F_15 ( & V_12 , 20 ) ;
if ( F_16 ( ! V_26 ) )
goto V_36;
V_23 [ V_27 ] . V_42 = F_17 ( V_26 ++ ) ;
V_23 [ V_27 ] . V_43 = F_17 ( V_26 ++ ) ;
V_23 [ V_27 ] . V_44 = F_22 ( F_17 ( V_26 ++ ) , NULL ) ;
V_23 [ V_27 ] . V_45 = F_22 ( F_17 ( V_26 ++ ) , NULL ) ;
V_23 [ V_27 ] . V_46 = F_17 ( V_26 ) ;
if ( V_23 [ V_27 ] . V_44 > V_47 )
V_23 [ V_27 ] . V_44 = V_47 ;
if ( V_23 [ V_27 ] . V_45 > V_47 )
V_23 [ V_27 ] . V_45 = V_47 ;
if ( V_23 [ V_27 ] . V_42 != 3 || V_23 [ V_27 ] . V_43 != 0 ) {
F_18 ( L_4 , V_37 ,
V_27 , V_23 [ V_27 ] . V_42 ,
V_23 [ V_27 ] . V_43 ) ;
V_28 = - V_48 ;
goto V_36;
}
F_18 ( L_5 ,
V_37 , V_27 , V_23 [ V_27 ] . V_42 ,
V_23 [ V_27 ] . V_43 ,
V_23 [ V_27 ] . V_44 ,
V_23 [ V_27 ] . V_45 ,
V_23 [ V_27 ] . V_46 ) ;
}
V_21 -> V_23 = V_23 ;
V_21 -> V_49 = V_25 ;
V_21 -> V_5 = F_23 ( & V_18 , V_10 ) ;
if ( ! V_21 -> V_5 )
goto V_36;
while ( ! F_21 ( & V_18 ) ) {
V_20 = F_24 ( & V_18 ,
struct V_19 ,
V_40 ) ;
F_25 ( & V_20 -> V_40 ) ;
F_6 ( V_20 -> V_50 ) ;
F_6 ( V_20 ) ;
}
F_26 ( V_16 ) ;
return V_21 ;
V_36:
while ( ! F_21 ( & V_18 ) ) {
V_20 = F_24 ( & V_18 , struct V_19 ,
V_40 ) ;
F_25 ( & V_20 -> V_40 ) ;
F_6 ( V_20 -> V_50 ) ;
F_6 ( V_20 ) ;
}
F_6 ( V_23 ) ;
V_31:
F_26 ( V_16 ) ;
V_30:
F_6 ( V_21 ) ;
F_18 ( L_6 , V_37 , V_28 ) ;
return NULL ;
}
static T_4
F_27 ( T_4 V_51 , T_4 V_52 )
{
T_4 V_53 ;
V_53 = V_51 + V_52 ;
return V_53 >= V_51 ? V_53 : V_54 ;
}
static void F_28 ( struct V_55 * V_56 ,
T_4 V_57 , T_4 V_58 )
{
T_4 V_53 ;
V_53 = F_29 ( T_4 , F_27 ( V_56 -> V_57 , V_56 -> V_58 ) ,
F_27 ( V_57 , V_58 ) ) ;
V_56 -> V_57 = F_30 ( T_4 , V_56 -> V_57 , V_57 ) ;
V_56 -> V_58 = V_53 - V_56 -> V_57 ;
}
static bool F_31 ( struct V_55 * V_56 , T_4 V_57 ,
T_4 V_58 , int V_59 , enum V_60 V_61 ,
T_5 * V_62 ,
struct V_63 * V_4 )
{
return V_56 -> V_59 == V_59 && V_56 -> V_61 == V_61 &&
F_32 ( & V_56 -> V_62 , V_62 ) &&
! memcmp ( & V_56 -> V_4 , V_4 , sizeof( * V_4 ) ) &&
F_27 ( V_56 -> V_57 , V_56 -> V_58 ) >= V_57 &&
V_56 -> V_57 <= F_27 ( V_57 , V_58 ) ;
}
static bool F_33 ( struct V_55 * V_64 ,
struct V_55 * V_65 )
{
if ( ! F_31 ( V_64 , V_65 -> V_57 , V_65 -> V_58 , V_65 -> V_59 ,
V_65 -> V_61 , & V_65 -> V_62 , & V_65 -> V_4 ) )
return false ;
F_28 ( V_64 , V_65 -> V_57 , V_65 -> V_58 ) ;
return true ;
}
static bool
F_34 ( struct V_66 * V_67 ,
struct V_55 * V_68 )
{
struct V_55 * V_56 ;
F_35 (err, &flo->error_list, list) {
if ( F_33 ( V_56 , V_68 ) ) {
return true ;
}
}
F_36 ( & V_68 -> V_69 , & V_67 -> V_70 ) ;
return false ;
}
static bool
F_37 ( struct V_66 * V_67 , T_4 V_57 ,
T_4 V_58 , int V_59 , enum V_60 V_61 ,
T_5 * V_62 , struct V_63 * V_4 )
{
bool V_71 = false ;
struct V_55 * V_56 ;
F_35 (err, &flo->error_list, list) {
if ( F_31 ( V_56 , V_57 , V_58 , V_59 , V_61 ,
V_62 , V_4 ) ) {
V_71 = true ;
F_28 ( V_56 , V_57 , V_58 ) ;
break;
}
}
return V_71 ;
}
int F_38 ( struct V_66 * V_67 ,
struct V_72 * V_73 , T_4 V_57 ,
T_4 V_58 , int V_59 , enum V_60 V_61 ,
T_1 V_10 )
{
struct V_55 * V_68 ;
bool V_74 ;
if ( V_59 == 0 )
return 0 ;
if ( V_73 -> V_2 == NULL )
return - V_75 ;
F_39 ( & V_67 -> V_76 . V_77 -> V_78 ) ;
if ( F_37 ( V_67 , V_57 , V_58 , V_59 , V_61 ,
& V_73 -> V_62 ,
& V_73 -> V_2 -> V_3 . V_4 ) ) {
F_40 ( & V_67 -> V_76 . V_77 -> V_78 ) ;
return 0 ;
}
F_40 ( & V_67 -> V_76 . V_77 -> V_78 ) ;
V_68 = F_41 ( sizeof( * V_68 ) , V_10 ) ;
if ( ! V_68 )
return - V_29 ;
F_11 ( & V_68 -> V_69 ) ;
V_68 -> V_57 = V_57 ;
V_68 -> V_58 = V_58 ;
V_68 -> V_59 = V_59 ;
V_68 -> V_61 = V_61 ;
F_42 ( & V_68 -> V_62 , & V_73 -> V_62 ) ;
memcpy ( & V_68 -> V_4 , & V_73 -> V_2 -> V_3 . V_4 ,
V_79 ) ;
F_39 ( & V_67 -> V_76 . V_77 -> V_78 ) ;
V_74 = F_34 ( V_67 , V_68 ) ;
F_40 ( & V_67 -> V_76 . V_77 -> V_78 ) ;
if ( V_74 )
F_6 ( V_68 ) ;
return 0 ;
}
static T_6
F_43 ( struct V_72 * V_73 )
{
if ( V_73 -> V_80 == ( T_2 ) - 1 )
return V_81 ;
return V_82 ;
}
static int F_44 ( struct V_72 * V_73 ,
struct V_83 * V_5 )
{
if ( V_5 -> V_84 && ! V_73 -> V_85 &&
V_73 -> V_2 -> V_23 [ 0 ] . V_42 == 3 ) {
struct V_86 * V_87 = V_5 -> V_84 -> V_88 -> V_89 ;
struct V_90 * V_85 ;
struct V_91 V_92 = {
. V_80 = F_45 ( & V_93 , V_73 -> V_80 ) ,
. V_94 = F_46 ( & V_93 , V_73 -> V_94 ) ,
} ;
V_85 = V_87 -> V_95 -> V_96 ( V_87 , & V_92 , 0 ) ;
if ( F_47 ( V_85 ) ) {
F_18 ( L_7 ,
V_37 , F_48 ( V_85 ) ) ;
return F_48 ( V_85 ) ;
} else {
V_73 -> V_85 = V_85 ;
}
}
return 0 ;
}
struct V_97 *
F_49 ( struct V_98 * V_99 , T_2 V_100 )
{
struct V_72 * V_73 = F_50 ( V_99 , V_100 ) ;
struct V_97 * V_101 = NULL ;
struct V_102 * V_103 ;
if ( V_73 == NULL || V_73 -> V_2 == NULL ||
V_73 -> V_2 -> V_5 == NULL ) {
F_51 ( V_104 L_8 ,
V_37 , V_100 ) ;
if ( V_73 && V_73 -> V_2 ) {
V_103 = & V_73 -> V_2 -> V_3 ;
F_52 ( V_103 ) ;
}
goto V_105;
}
V_101 = & V_73 -> V_106 [ 0 ] ;
V_105:
return V_101 ;
}
struct V_83 *
F_53 ( struct V_98 * V_99 , T_2 V_107 ,
bool V_108 )
{
struct V_72 * V_73 = F_50 ( V_99 , V_107 ) ;
struct V_83 * V_5 = NULL ;
struct V_102 * V_103 ;
struct V_109 * V_110 = V_99 -> V_111 -> V_77 ;
struct V_6 * V_112 = F_54 ( V_110 ) ;
unsigned int V_113 ;
T_6 V_114 ;
if ( V_73 == NULL || V_73 -> V_2 == NULL ||
V_73 -> V_2 -> V_5 == NULL ) {
F_51 ( V_104 L_9 ,
V_37 , V_107 ) ;
if ( V_73 && V_73 -> V_2 ) {
V_103 = & V_73 -> V_2 -> V_3 ;
F_52 ( V_103 ) ;
}
goto V_105;
}
V_103 = & V_73 -> V_2 -> V_3 ;
if ( F_55 ( V_103 ) )
goto V_105;
V_5 = V_73 -> V_2 -> V_5 ;
F_56 () ;
if ( V_5 -> V_84 )
goto V_105;
V_114 = F_43 ( V_73 ) ;
F_57 ( V_112 , V_5 , V_103 , V_115 ,
V_116 ,
V_73 -> V_2 -> V_23 [ 0 ] . V_42 ,
V_73 -> V_2 -> V_23 [ 0 ] . V_43 ,
V_114 ) ;
if ( V_5 -> V_84 ) {
V_113 =
F_22 ( F_58 ( V_5 -> V_84 -> V_88 ) ,
NULL ) ;
if ( V_73 -> V_2 -> V_23 [ 0 ] . V_44 > V_113 )
V_73 -> V_2 -> V_23 [ 0 ] . V_44 = V_113 ;
if ( V_73 -> V_2 -> V_23 [ 0 ] . V_45 > V_113 )
V_73 -> V_2 -> V_23 [ 0 ] . V_45 = V_113 ;
} else {
F_38 ( F_59 ( V_99 -> V_111 ) ,
V_73 , V_99 -> V_117 . V_57 ,
V_99 -> V_117 . V_58 , V_118 ,
V_119 , V_120 ) ;
if ( V_108 ) {
F_60 ( V_110 , V_99 ) ;
if ( F_61 ( V_99 ) )
F_62 ( V_99 -> V_111 ) ;
else
F_63 ( V_99 -> V_111 ) ;
} else {
if ( F_61 ( V_99 ) )
F_64 ( V_121 ,
& V_99 -> V_111 -> V_122 ) ;
else {
F_60 ( V_110 , V_99 ) ;
F_63 ( V_99 -> V_111 ) ;
}
}
}
if ( F_44 ( V_73 , V_5 ) )
V_5 = NULL ;
V_105:
return V_5 ;
}
struct V_90 *
F_65 ( struct V_98 * V_99 , T_2 V_107 ,
struct V_90 * V_123 )
{
struct V_72 * V_73 = F_50 ( V_99 , V_107 ) ;
struct V_90 * V_85 = F_66 ( - V_75 ) ;
if ( ! F_53 ( V_99 , V_107 , true ) )
goto V_105;
if ( V_73 && V_73 -> V_85 )
V_85 = V_73 -> V_85 ;
else
V_85 = V_123 ;
V_105:
return V_85 ;
}
struct V_124 *
F_67 ( struct V_98 * V_99 , T_2 V_107 ,
struct V_38 * V_84 , struct V_109 * V_109 )
{
struct V_72 * V_73 = F_50 ( V_99 , V_107 ) ;
switch ( V_73 -> V_2 -> V_23 [ 0 ] . V_42 ) {
case 3 :
return V_84 -> V_88 ;
case 4 :
return F_68 ( V_84 , V_109 ) ;
default:
F_69 () ;
}
}
static bool F_70 ( T_4 V_125 , T_4 V_126 ,
T_4 V_127 , T_4 V_128 )
{
T_4 V_129 = F_27 ( V_125 , V_126 ) ;
T_4 V_130 = F_27 ( V_127 , V_128 ) ;
return ( V_129 == V_54 || V_129 > V_127 ) &&
( V_130 == V_54 || V_130 > V_125 ) ;
}
int F_71 ( struct V_66 * V_67 ,
struct V_11 * V_131 , int * V_132 ,
const struct V_133 * V_134 )
{
struct V_55 * V_56 , * V_135 ;
T_3 * V_26 ;
F_72 (err, n, &flo->error_list, list) {
if ( ! F_70 ( V_56 -> V_57 , V_56 -> V_58 ,
V_134 -> V_57 , V_134 -> V_58 ) )
continue;
V_26 = F_73 ( V_131 ,
24 + V_136 + V_79 ) ;
if ( F_16 ( ! V_26 ) )
return - V_137 ;
V_26 = F_74 ( V_26 , V_56 -> V_57 ) ;
V_26 = F_74 ( V_26 , V_56 -> V_58 ) ;
V_26 = F_75 ( V_26 , & V_56 -> V_62 ,
V_136 ) ;
V_26 = F_75 ( V_26 , & V_56 -> V_4 ,
V_79 ) ;
* V_26 ++ = F_76 ( V_56 -> V_59 ) ;
* V_26 ++ = F_76 ( V_56 -> V_61 ) ;
* V_132 += 1 ;
F_77 ( & V_56 -> V_69 ) ;
F_18 ( L_10 ,
V_37 , V_56 -> V_57 , V_56 -> V_58 , V_56 -> V_59 ,
V_56 -> V_61 , * V_132 ) ;
F_6 ( V_56 ) ;
}
return 0 ;
}
bool F_61 ( struct V_98 * V_99 )
{
struct V_72 * V_73 ;
struct V_102 * V_103 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < F_78 ( V_99 ) ; V_138 ++ ) {
V_73 = F_50 ( V_99 , V_138 ) ;
if ( V_73 && V_73 -> V_2 ) {
V_103 = & V_73 -> V_2 -> V_3 ;
if ( ! F_55 ( V_103 ) )
return true ;
}
}
return false ;
}
