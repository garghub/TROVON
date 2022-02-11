void F_1 ( struct V_1 * V_2 )
{
if ( V_2 )
F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 . V_4 ) ;
F_5 ( V_2 -> V_5 ) ;
F_6 ( V_2 , V_3 . V_6 ) ;
}
struct V_1 *
F_7 ( struct V_7 * V_8 , struct V_9 * V_10 ,
T_1 V_11 )
{
struct V_12 V_13 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
struct V_20 * V_21 ;
struct V_1 * V_22 = NULL ;
struct V_23 * V_24 = NULL ;
T_2 V_25 ;
T_2 V_26 ;
T_3 * V_27 ;
int V_28 , V_29 = - V_30 ;
V_17 = F_8 ( V_11 ) ;
if ( ! V_17 )
goto V_31;
V_22 = F_9 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_22 )
goto V_32;
F_10 ( & V_22 -> V_3 ,
V_8 ,
& V_10 -> V_33 ) ;
F_11 ( & V_19 ) ;
F_12 ( & V_13 , & V_15 , V_10 -> V_34 , V_10 -> V_35 ) ;
F_13 ( & V_13 , F_14 ( V_17 ) , V_36 ) ;
V_27 = F_15 ( & V_13 , 4 ) ;
if ( F_16 ( ! V_27 ) )
goto V_37;
V_25 = F_17 ( V_27 ) ;
F_18 ( L_1 , V_38 , V_25 ) ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
V_21 = F_19 ( V_8 -> V_39 -> V_40 ,
& V_13 , V_11 ) ;
if ( V_21 )
F_20 ( & V_21 -> V_41 , & V_19 ) ;
}
if ( F_21 ( & V_19 ) ) {
F_18 ( L_2 ,
V_38 ) ;
V_29 = - V_42 ;
goto V_37;
}
V_27 = F_15 ( & V_13 , 4 ) ;
if ( F_16 ( ! V_27 ) )
goto V_37;
V_26 = F_17 ( V_27 ) ;
F_18 ( L_3 , V_38 , V_26 ) ;
V_24 = F_9 ( V_26 * sizeof( struct V_23 ) ,
V_11 ) ;
if ( ! V_24 )
goto V_32;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_27 = F_15 ( & V_13 , 20 ) ;
if ( F_16 ( ! V_27 ) )
goto V_37;
V_24 [ V_28 ] . V_43 = F_17 ( V_27 ++ ) ;
V_24 [ V_28 ] . V_44 = F_17 ( V_27 ++ ) ;
V_24 [ V_28 ] . V_45 = F_22 ( F_17 ( V_27 ++ ) , NULL ) ;
V_24 [ V_28 ] . V_46 = F_22 ( F_17 ( V_27 ++ ) , NULL ) ;
V_24 [ V_28 ] . V_47 = F_17 ( V_27 ) ;
if ( V_24 [ V_28 ] . V_45 > V_48 )
V_24 [ V_28 ] . V_45 = V_48 ;
if ( V_24 [ V_28 ] . V_46 > V_48 )
V_24 [ V_28 ] . V_46 = V_48 ;
if ( V_24 [ V_28 ] . V_43 != 3 || V_24 [ V_28 ] . V_44 != 0 ) {
F_18 ( L_4 , V_38 ,
V_28 , V_24 [ V_28 ] . V_43 ,
V_24 [ V_28 ] . V_44 ) ;
V_29 = - V_49 ;
goto V_37;
}
F_18 ( L_5 ,
V_38 , V_28 , V_24 [ V_28 ] . V_43 ,
V_24 [ V_28 ] . V_44 ,
V_24 [ V_28 ] . V_45 ,
V_24 [ V_28 ] . V_46 ,
V_24 [ V_28 ] . V_47 ) ;
}
V_22 -> V_24 = V_24 ;
V_22 -> V_50 = V_26 ;
V_22 -> V_5 = F_23 ( & V_19 , V_11 ) ;
if ( ! V_22 -> V_5 )
goto V_37;
while ( ! F_21 ( & V_19 ) ) {
V_21 = F_24 ( & V_19 ,
struct V_20 ,
V_41 ) ;
F_25 ( & V_21 -> V_41 ) ;
F_26 ( V_21 -> V_51 ) ;
F_26 ( V_21 ) ;
}
F_27 ( V_17 ) ;
return V_22 ;
V_37:
while ( ! F_21 ( & V_19 ) ) {
V_21 = F_24 ( & V_19 , struct V_20 ,
V_41 ) ;
F_25 ( & V_21 -> V_41 ) ;
F_26 ( V_21 -> V_51 ) ;
F_26 ( V_21 ) ;
}
F_26 ( V_24 ) ;
V_32:
F_27 ( V_17 ) ;
V_31:
F_26 ( V_22 ) ;
F_18 ( L_6 , V_38 , V_29 ) ;
return NULL ;
}
static T_4
F_28 ( T_4 V_52 , T_4 V_53 )
{
T_4 V_54 ;
V_54 = V_52 + V_53 ;
return V_54 >= V_52 ? V_54 : V_55 ;
}
static void F_29 ( struct V_56 * V_57 ,
T_4 V_58 , T_4 V_59 )
{
T_4 V_54 ;
V_54 = F_30 ( T_4 , F_28 ( V_57 -> V_58 , V_57 -> V_59 ) ,
F_28 ( V_58 , V_59 ) ) ;
V_57 -> V_58 = F_31 ( T_4 , V_57 -> V_58 , V_58 ) ;
V_57 -> V_59 = V_54 - V_57 -> V_58 ;
}
static bool F_32 ( struct V_56 * V_57 , T_4 V_58 ,
T_4 V_59 , int V_60 , enum V_61 V_62 ,
T_5 * V_63 ,
struct V_64 * V_4 )
{
return V_57 -> V_60 == V_60 && V_57 -> V_62 == V_62 &&
F_33 ( & V_57 -> V_63 , V_63 ) &&
! memcmp ( & V_57 -> V_4 , V_4 , sizeof( * V_4 ) ) &&
F_28 ( V_57 -> V_58 , V_57 -> V_59 ) >= V_58 &&
V_57 -> V_58 <= F_28 ( V_58 , V_59 ) ;
}
static bool F_34 ( struct V_56 * V_65 ,
struct V_56 * V_66 )
{
if ( ! F_32 ( V_65 , V_66 -> V_58 , V_66 -> V_59 , V_66 -> V_60 ,
V_66 -> V_62 , & V_66 -> V_63 , & V_66 -> V_4 ) )
return false ;
F_29 ( V_65 , V_66 -> V_58 , V_66 -> V_59 ) ;
return true ;
}
static bool
F_35 ( struct V_67 * V_68 ,
struct V_56 * V_69 )
{
struct V_56 * V_57 ;
F_36 (err, &flo->error_list, list) {
if ( F_34 ( V_57 , V_69 ) ) {
return true ;
}
}
F_37 ( & V_69 -> V_70 , & V_68 -> V_71 ) ;
return false ;
}
static bool
F_38 ( struct V_67 * V_68 , T_4 V_58 ,
T_4 V_59 , int V_60 , enum V_61 V_62 ,
T_5 * V_63 , struct V_64 * V_4 )
{
bool V_72 = false ;
struct V_56 * V_57 ;
F_36 (err, &flo->error_list, list) {
if ( F_32 ( V_57 , V_58 , V_59 , V_60 , V_62 ,
V_63 , V_4 ) ) {
V_72 = true ;
F_29 ( V_57 , V_58 , V_59 ) ;
break;
}
}
return V_72 ;
}
int F_39 ( struct V_67 * V_68 ,
struct V_73 * V_74 , T_4 V_58 ,
T_4 V_59 , int V_60 , enum V_61 V_62 ,
T_1 V_11 )
{
struct V_56 * V_69 ;
bool V_75 ;
if ( V_60 == 0 )
return 0 ;
if ( V_74 -> V_2 == NULL )
return - V_76 ;
F_40 ( & V_68 -> V_77 . V_78 -> V_79 ) ;
if ( F_38 ( V_68 , V_58 , V_59 , V_60 , V_62 ,
& V_74 -> V_63 ,
& V_74 -> V_2 -> V_3 . V_4 ) ) {
F_41 ( & V_68 -> V_77 . V_78 -> V_79 ) ;
return 0 ;
}
F_41 ( & V_68 -> V_77 . V_78 -> V_79 ) ;
V_69 = F_42 ( sizeof( * V_69 ) , V_11 ) ;
if ( ! V_69 )
return - V_30 ;
F_11 ( & V_69 -> V_70 ) ;
V_69 -> V_58 = V_58 ;
V_69 -> V_59 = V_59 ;
V_69 -> V_60 = V_60 ;
V_69 -> V_62 = V_62 ;
F_43 ( & V_69 -> V_63 , & V_74 -> V_63 ) ;
memcpy ( & V_69 -> V_4 , & V_74 -> V_2 -> V_3 . V_4 ,
V_80 ) ;
F_40 ( & V_68 -> V_77 . V_78 -> V_79 ) ;
V_75 = F_35 ( V_68 , V_69 ) ;
F_41 ( & V_68 -> V_77 . V_78 -> V_79 ) ;
if ( V_75 )
F_26 ( V_69 ) ;
return 0 ;
}
static T_6
F_44 ( struct V_73 * V_74 )
{
if ( V_74 -> V_81 == ( T_2 ) - 1 )
return V_82 ;
return V_83 ;
}
static int F_45 ( struct V_73 * V_74 ,
struct V_84 * V_5 )
{
if ( V_5 -> V_85 && ! V_74 -> V_86 &&
V_74 -> V_2 -> V_24 [ 0 ] . V_43 == 3 ) {
struct V_87 * V_88 = V_5 -> V_85 -> V_89 -> V_90 ;
struct V_91 * V_86 ;
struct V_92 V_93 = {
. V_81 = F_46 ( & V_94 , V_74 -> V_81 ) ,
. V_95 = F_47 ( & V_94 , V_74 -> V_95 ) ,
} ;
V_86 = V_88 -> V_96 -> V_97 ( V_88 , & V_93 , 0 ) ;
if ( F_48 ( V_86 ) ) {
F_18 ( L_7 ,
V_38 , F_49 ( V_86 ) ) ;
return F_49 ( V_86 ) ;
} else {
if ( F_50 ( & V_74 -> V_86 , NULL , V_86 ) )
F_51 ( V_86 ) ;
}
}
return 0 ;
}
struct V_98 *
F_52 ( struct V_99 * V_100 , T_2 V_101 )
{
struct V_73 * V_74 = F_53 ( V_100 , V_101 ) ;
struct V_98 * V_102 = NULL ;
struct V_103 * V_104 ;
if ( V_74 == NULL || V_74 -> V_2 == NULL ||
V_74 -> V_2 -> V_5 == NULL ) {
F_54 ( V_105 L_8 ,
V_38 , V_101 ) ;
if ( V_74 && V_74 -> V_2 ) {
V_104 = & V_74 -> V_2 -> V_3 ;
F_55 ( V_104 ) ;
}
goto V_106;
}
V_102 = & V_74 -> V_107 [ 0 ] ;
V_106:
return V_102 ;
}
struct V_84 *
F_56 ( struct V_99 * V_100 , T_2 V_108 ,
bool V_109 )
{
struct V_73 * V_74 = F_53 ( V_100 , V_108 ) ;
struct V_84 * V_5 = NULL ;
struct V_103 * V_104 ;
struct V_110 * V_111 = V_100 -> V_112 -> V_78 ;
struct V_7 * V_113 = F_57 ( V_111 ) ;
unsigned int V_114 ;
T_6 V_115 ;
if ( V_74 == NULL || V_74 -> V_2 == NULL ||
V_74 -> V_2 -> V_5 == NULL ) {
F_54 ( V_105 L_9 ,
V_38 , V_108 ) ;
if ( V_74 && V_74 -> V_2 ) {
V_104 = & V_74 -> V_2 -> V_3 ;
F_55 ( V_104 ) ;
}
goto V_106;
}
V_104 = & V_74 -> V_2 -> V_3 ;
if ( F_58 ( V_104 ) )
goto V_106;
V_5 = V_74 -> V_2 -> V_5 ;
F_59 () ;
if ( V_5 -> V_85 )
goto V_116;
V_115 = F_44 ( V_74 ) ;
F_60 ( V_113 , V_5 , V_104 , V_117 ,
V_118 ,
V_74 -> V_2 -> V_24 [ 0 ] . V_43 ,
V_74 -> V_2 -> V_24 [ 0 ] . V_44 ,
V_115 ) ;
if ( V_5 -> V_85 ) {
V_114 =
F_22 ( F_61 ( V_5 -> V_85 -> V_89 ) ,
NULL ) ;
if ( V_74 -> V_2 -> V_24 [ 0 ] . V_45 > V_114 )
V_74 -> V_2 -> V_24 [ 0 ] . V_45 = V_114 ;
if ( V_74 -> V_2 -> V_24 [ 0 ] . V_46 > V_114 )
V_74 -> V_2 -> V_24 [ 0 ] . V_46 = V_114 ;
} else {
F_39 ( F_62 ( V_100 -> V_112 ) ,
V_74 , V_100 -> V_119 . V_58 ,
V_100 -> V_119 . V_59 , V_120 ,
V_121 , V_122 ) ;
if ( V_109 ) {
F_63 ( V_111 , V_100 ) ;
if ( F_64 ( V_100 ) )
F_65 ( V_100 -> V_112 ) ;
else
F_66 ( V_100 -> V_112 ) ;
} else {
if ( F_64 ( V_100 ) )
F_67 ( V_123 ,
& V_100 -> V_112 -> V_124 ) ;
else {
F_63 ( V_111 , V_100 ) ;
F_66 ( V_100 -> V_112 ) ;
}
}
}
V_116:
if ( F_45 ( V_74 , V_5 ) )
V_5 = NULL ;
V_106:
return V_5 ;
}
struct V_91 *
F_68 ( struct V_99 * V_100 , T_2 V_108 ,
struct V_91 * V_125 )
{
struct V_73 * V_74 = F_53 ( V_100 , V_108 ) ;
struct V_91 * V_86 = F_69 ( - V_76 ) ;
if ( ! F_56 ( V_100 , V_108 , true ) )
goto V_106;
if ( V_74 && V_74 -> V_86 )
V_86 = V_74 -> V_86 ;
else
V_86 = V_125 ;
V_106:
return V_86 ;
}
struct V_126 *
F_70 ( struct V_99 * V_100 , T_2 V_108 ,
struct V_39 * V_85 , struct V_110 * V_110 )
{
struct V_73 * V_74 = F_53 ( V_100 , V_108 ) ;
switch ( V_74 -> V_2 -> V_24 [ 0 ] . V_43 ) {
case 3 :
return V_85 -> V_89 ;
case 4 :
return F_71 ( V_85 , V_110 ) ;
default:
F_72 () ;
}
}
static bool F_73 ( T_4 V_127 , T_4 V_128 ,
T_4 V_129 , T_4 V_130 )
{
T_4 V_131 = F_28 ( V_127 , V_128 ) ;
T_4 V_132 = F_28 ( V_129 , V_130 ) ;
return ( V_131 == V_55 || V_131 > V_129 ) &&
( V_132 == V_55 || V_132 > V_127 ) ;
}
int F_74 ( struct V_67 * V_68 ,
struct V_12 * V_133 , int * V_134 ,
const struct V_135 * V_136 )
{
struct V_56 * V_57 , * V_137 ;
T_3 * V_27 ;
F_75 (err, n, &flo->error_list, list) {
if ( ! F_73 ( V_57 -> V_58 , V_57 -> V_59 ,
V_136 -> V_58 , V_136 -> V_59 ) )
continue;
V_27 = F_76 ( V_133 ,
24 + V_138 + V_80 ) ;
if ( F_16 ( ! V_27 ) )
return - V_139 ;
V_27 = F_77 ( V_27 , V_57 -> V_58 ) ;
V_27 = F_77 ( V_27 , V_57 -> V_59 ) ;
V_27 = F_78 ( V_27 , & V_57 -> V_63 ,
V_138 ) ;
V_27 = F_78 ( V_27 , & V_57 -> V_4 ,
V_80 ) ;
* V_27 ++ = F_79 ( V_57 -> V_60 ) ;
* V_27 ++ = F_79 ( V_57 -> V_62 ) ;
* V_134 += 1 ;
F_80 ( & V_57 -> V_70 ) ;
F_18 ( L_10 ,
V_38 , V_57 -> V_58 , V_57 -> V_59 , V_57 -> V_60 ,
V_57 -> V_62 , * V_134 ) ;
F_26 ( V_57 ) ;
}
return 0 ;
}
bool F_64 ( struct V_99 * V_100 )
{
struct V_73 * V_74 ;
struct V_103 * V_104 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < F_81 ( V_100 ) ; V_140 ++ ) {
V_74 = F_53 ( V_100 , V_140 ) ;
if ( V_74 && V_74 -> V_2 ) {
V_104 = & V_74 -> V_2 -> V_3 ;
if ( ! F_58 ( V_104 ) )
return true ;
}
}
return false ;
}
