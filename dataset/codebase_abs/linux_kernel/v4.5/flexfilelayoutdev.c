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
static void F_28 ( struct V_52 * V_53 ,
struct V_54 * V_55 )
{
F_29 ( V_55 ) ;
if ( ! F_30 ( V_53 ) )
F_31 ( V_53 -> V_56 -> V_57 ,
V_53 ) ;
}
static bool F_32 ( struct V_52 * V_53 ,
struct V_58 * V_59 )
{
if ( V_59 == NULL || V_59 -> V_2 == NULL ) {
F_31 ( V_53 -> V_56 -> V_57 ,
V_53 ) ;
return false ;
}
if ( V_59 -> V_2 -> V_5 == NULL ) {
struct V_54 * V_55 ;
V_55 = & V_59 -> V_2 -> V_3 ;
F_28 ( V_53 , V_55 ) ;
return false ;
}
return true ;
}
static T_4
F_33 ( T_4 V_60 , T_4 V_61 )
{
T_4 V_62 ;
V_62 = V_60 + V_61 ;
return V_62 >= V_60 ? V_62 : V_63 ;
}
static void F_34 ( struct V_64 * V_65 ,
T_4 V_66 , T_4 V_67 )
{
T_4 V_62 ;
V_62 = F_35 ( T_4 , F_33 ( V_65 -> V_66 , V_65 -> V_67 ) ,
F_33 ( V_66 , V_67 ) ) ;
V_65 -> V_66 = F_36 ( T_4 , V_65 -> V_66 , V_66 ) ;
V_65 -> V_67 = V_62 - V_65 -> V_66 ;
}
static int
F_37 ( const struct V_64 * V_68 ,
const struct V_64 * V_69 )
{
int V_29 ;
if ( V_68 -> V_70 != V_69 -> V_70 )
return V_68 -> V_70 < V_69 -> V_70 ? - 1 : 1 ;
if ( V_68 -> V_71 != V_69 -> V_71 )
return V_68 -> V_71 < V_69 -> V_71 ? - 1 : 1 ;
V_29 = memcmp ( & V_68 -> V_72 , & V_69 -> V_72 , sizeof( V_68 -> V_72 ) ) ;
if ( V_29 != 0 )
return V_29 ;
V_29 = memcmp ( & V_68 -> V_4 , & V_69 -> V_4 , sizeof( V_68 -> V_4 ) ) ;
if ( V_29 != 0 )
return V_29 ;
if ( F_33 ( V_68 -> V_66 , V_68 -> V_67 ) < V_69 -> V_66 )
return - 1 ;
if ( V_68 -> V_66 > F_33 ( V_69 -> V_66 , V_69 -> V_67 ) )
return 1 ;
return 0 ;
}
static void
F_38 ( struct V_73 * V_74 ,
struct V_64 * V_75 )
{
struct V_64 * V_65 , * V_76 ;
struct V_18 * V_77 = & V_74 -> V_78 ;
int V_79 ;
F_39 (err, tmp, &flo->error_list, list) {
V_79 = F_37 ( V_65 , V_75 ) ;
if ( V_79 < 0 )
continue;
if ( V_79 > 0 ) {
V_77 = & V_65 -> V_80 ;
break;
}
F_34 ( V_75 , V_65 -> V_66 , V_65 -> V_67 ) ;
F_40 ( & V_65 -> V_80 ) ;
F_26 ( V_65 ) ;
}
F_20 ( & V_75 -> V_80 , V_77 ) ;
}
int F_41 ( struct V_73 * V_74 ,
struct V_58 * V_59 , T_4 V_66 ,
T_4 V_67 , int V_71 , enum V_81 V_70 ,
T_1 V_11 )
{
struct V_64 * V_75 ;
if ( V_71 == 0 )
return 0 ;
if ( V_59 -> V_2 == NULL )
return - V_82 ;
V_75 = F_42 ( sizeof( * V_75 ) , V_11 ) ;
if ( ! V_75 )
return - V_30 ;
F_11 ( & V_75 -> V_80 ) ;
V_75 -> V_66 = V_66 ;
V_75 -> V_67 = V_67 ;
V_75 -> V_71 = V_71 ;
V_75 -> V_70 = V_70 ;
F_43 ( & V_75 -> V_72 , & V_59 -> V_72 ) ;
memcpy ( & V_75 -> V_4 , & V_59 -> V_2 -> V_3 . V_4 ,
V_83 ) ;
F_44 ( & V_74 -> V_84 . V_57 -> V_85 ) ;
F_38 ( V_74 , V_75 ) ;
F_45 ( & V_74 -> V_84 . V_57 -> V_85 ) ;
return 0 ;
}
static T_5
F_46 ( struct V_58 * V_59 )
{
if ( V_59 -> V_86 == ( T_2 ) - 1 )
return V_87 ;
return V_88 ;
}
static int F_47 ( struct V_58 * V_59 ,
struct V_89 * V_5 )
{
if ( V_5 -> V_90 && ! V_59 -> V_91 &&
V_59 -> V_2 -> V_24 [ 0 ] . V_43 == 3 ) {
struct V_92 * V_93 = V_5 -> V_90 -> V_94 -> V_95 ;
struct V_96 * V_91 ;
struct V_97 V_98 = {
. V_86 = F_48 ( & V_99 , V_59 -> V_86 ) ,
. V_100 = F_49 ( & V_99 , V_59 -> V_100 ) ,
} ;
V_91 = V_93 -> V_101 -> V_102 ( V_93 , & V_98 , 0 ) ;
if ( F_50 ( V_91 ) ) {
F_18 ( L_7 ,
V_38 , F_51 ( V_91 ) ) ;
return F_51 ( V_91 ) ;
} else {
if ( F_52 ( & V_59 -> V_91 , NULL , V_91 ) )
F_53 ( V_91 ) ;
}
}
return 0 ;
}
struct V_103 *
F_54 ( struct V_52 * V_53 , T_2 V_104 )
{
struct V_58 * V_59 = F_55 ( V_53 , V_104 ) ;
struct V_103 * V_105 = NULL ;
if ( ! F_32 ( V_53 , V_59 ) ) {
F_56 ( L_8 ,
V_38 , V_104 ) ;
goto V_106;
}
V_105 = & V_59 -> V_107 [ 0 ] ;
V_106:
return V_105 ;
}
struct V_89 *
F_57 ( struct V_52 * V_53 , T_2 V_108 ,
bool V_109 )
{
struct V_58 * V_59 = F_55 ( V_53 , V_108 ) ;
struct V_89 * V_5 = NULL ;
struct V_54 * V_55 ;
struct V_110 * V_111 = V_53 -> V_56 -> V_57 ;
struct V_7 * V_112 = F_58 ( V_111 ) ;
unsigned int V_113 ;
T_5 V_114 ;
if ( ! F_32 ( V_53 , V_59 ) ) {
F_56 ( L_9 ,
V_38 , V_108 ) ;
goto V_106;
}
V_55 = & V_59 -> V_2 -> V_3 ;
if ( F_59 ( V_55 ) )
goto V_106;
V_5 = V_59 -> V_2 -> V_5 ;
F_60 () ;
if ( V_5 -> V_90 )
goto V_115;
V_114 = F_46 ( V_59 ) ;
F_61 ( V_112 , V_5 , V_55 , V_116 ,
V_117 ,
V_59 -> V_2 -> V_24 [ 0 ] . V_43 ,
V_59 -> V_2 -> V_24 [ 0 ] . V_44 ,
V_114 ) ;
if ( V_5 -> V_90 ) {
V_113 =
F_22 ( F_62 ( V_5 -> V_90 -> V_94 ) ,
NULL ) ;
if ( V_59 -> V_2 -> V_24 [ 0 ] . V_45 > V_113 )
V_59 -> V_2 -> V_24 [ 0 ] . V_45 = V_113 ;
if ( V_59 -> V_2 -> V_24 [ 0 ] . V_46 > V_113 )
V_59 -> V_2 -> V_24 [ 0 ] . V_46 = V_113 ;
} else {
F_41 ( F_63 ( V_53 -> V_56 ) ,
V_59 , V_53 -> V_118 . V_66 ,
V_53 -> V_118 . V_67 , V_119 ,
V_120 , V_121 ) ;
if ( ! V_109 ) {
if ( F_30 ( V_53 ) )
F_64 ( V_122 ,
& V_53 -> V_56 -> V_123 ) ;
else
F_31 ( V_111 , V_53 ) ;
} else
F_31 ( V_111 , V_53 ) ;
}
V_115:
if ( F_47 ( V_59 , V_5 ) )
V_5 = NULL ;
V_106:
return V_5 ;
}
struct V_96 *
F_65 ( struct V_52 * V_53 , T_2 V_108 ,
struct V_96 * V_124 )
{
struct V_58 * V_59 = F_55 ( V_53 , V_108 ) ;
struct V_96 * V_91 = F_66 ( - V_82 ) ;
if ( ! F_57 ( V_53 , V_108 , true ) )
goto V_106;
if ( V_59 && V_59 -> V_91 )
V_91 = V_59 -> V_91 ;
else
V_91 = V_124 ;
V_106:
return V_91 ;
}
struct V_125 *
F_67 ( struct V_52 * V_53 , T_2 V_108 ,
struct V_39 * V_90 , struct V_110 * V_110 )
{
struct V_58 * V_59 = F_55 ( V_53 , V_108 ) ;
switch ( V_59 -> V_2 -> V_24 [ 0 ] . V_43 ) {
case 3 :
return V_90 -> V_94 ;
case 4 :
return F_68 ( V_90 , V_110 ) ;
default:
F_69 () ;
}
}
static bool F_70 ( T_4 V_126 , T_4 V_127 ,
T_4 V_128 , T_4 V_129 )
{
T_4 V_130 = F_33 ( V_126 , V_127 ) ;
T_4 V_131 = F_33 ( V_128 , V_129 ) ;
return ( V_130 == V_63 || V_130 > V_128 ) &&
( V_131 == V_63 || V_131 > V_126 ) ;
}
int F_71 ( struct V_73 * V_74 ,
struct V_12 * V_132 , int * V_133 ,
const struct V_134 * V_135 )
{
struct V_64 * V_65 , * V_136 ;
T_3 * V_27 ;
F_39 (err, n, &flo->error_list, list) {
if ( ! F_70 ( V_65 -> V_66 , V_65 -> V_67 ,
V_135 -> V_66 , V_135 -> V_67 ) )
continue;
V_27 = F_72 ( V_132 ,
28 + V_137 + V_83 ) ;
if ( F_16 ( ! V_27 ) )
return - V_138 ;
V_27 = F_73 ( V_27 , V_65 -> V_66 ) ;
V_27 = F_73 ( V_27 , V_65 -> V_67 ) ;
V_27 = F_74 ( V_27 , & V_65 -> V_72 ,
V_137 ) ;
* V_27 ++ = F_75 ( 1 ) ;
V_27 = F_74 ( V_27 , & V_65 -> V_4 ,
V_83 ) ;
* V_27 ++ = F_75 ( V_65 -> V_71 ) ;
* V_27 ++ = F_75 ( V_65 -> V_70 ) ;
* V_133 += 1 ;
F_40 ( & V_65 -> V_80 ) ;
F_18 ( L_10 ,
V_38 , V_65 -> V_66 , V_65 -> V_67 , V_65 -> V_71 ,
V_65 -> V_70 , * V_133 ) ;
F_26 ( V_65 ) ;
}
return 0 ;
}
static bool F_76 ( struct V_52 * V_53 )
{
struct V_58 * V_59 ;
struct V_54 * V_55 ;
T_2 V_139 ;
for ( V_139 = 0 ; V_139 < F_77 ( V_53 ) ; V_139 ++ ) {
V_59 = F_55 ( V_53 , V_139 ) ;
if ( V_59 && V_59 -> V_2 ) {
V_55 = & V_59 -> V_2 -> V_3 ;
if ( ! F_59 ( V_55 ) )
return true ;
}
}
return false ;
}
static bool F_78 ( struct V_52 * V_53 )
{
struct V_58 * V_59 ;
struct V_54 * V_55 ;
T_2 V_139 ;
for ( V_139 = 0 ; V_139 < F_77 ( V_53 ) ; V_139 ++ ) {
V_59 = F_55 ( V_53 , V_139 ) ;
if ( ! V_59 || ! V_59 -> V_2 )
return false ;
V_55 = & V_59 -> V_2 -> V_3 ;
if ( F_59 ( V_55 ) )
return false ;
}
return F_77 ( V_53 ) != 0 ;
}
bool F_30 ( struct V_52 * V_53 )
{
if ( V_53 -> V_118 . V_140 == V_141 )
return F_76 ( V_53 ) ;
return F_78 ( V_53 ) ;
}
