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
V_29 = memcmp ( V_68 -> V_72 . V_73 , V_69 -> V_72 . V_73 ,
sizeof( V_68 -> V_72 . V_73 ) ) ;
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
F_38 ( struct V_74 * V_75 ,
struct V_64 * V_76 )
{
struct V_64 * V_65 , * V_77 ;
struct V_18 * V_78 = & V_75 -> V_79 ;
int V_80 ;
F_39 (err, tmp, &flo->error_list, list) {
V_80 = F_37 ( V_65 , V_76 ) ;
if ( V_80 < 0 )
continue;
if ( V_80 > 0 ) {
V_78 = & V_65 -> V_81 ;
break;
}
F_34 ( V_76 , V_65 -> V_66 , V_65 -> V_67 ) ;
F_40 ( & V_65 -> V_81 ) ;
F_26 ( V_65 ) ;
}
F_20 ( & V_76 -> V_81 , V_78 ) ;
}
int F_41 ( struct V_74 * V_75 ,
struct V_58 * V_59 , T_4 V_66 ,
T_4 V_67 , int V_71 , enum V_82 V_70 ,
T_1 V_11 )
{
struct V_64 * V_76 ;
if ( V_71 == 0 )
return 0 ;
if ( V_59 -> V_2 == NULL )
return - V_83 ;
V_76 = F_42 ( sizeof( * V_76 ) , V_11 ) ;
if ( ! V_76 )
return - V_30 ;
F_11 ( & V_76 -> V_81 ) ;
V_76 -> V_66 = V_66 ;
V_76 -> V_67 = V_67 ;
V_76 -> V_71 = V_71 ;
V_76 -> V_70 = V_70 ;
F_43 ( & V_76 -> V_72 , & V_59 -> V_72 ) ;
memcpy ( & V_76 -> V_4 , & V_59 -> V_2 -> V_3 . V_4 ,
V_84 ) ;
F_44 ( & V_75 -> V_85 . V_57 -> V_86 ) ;
F_38 ( V_75 , V_76 ) ;
F_45 ( & V_75 -> V_85 . V_57 -> V_86 ) ;
return 0 ;
}
static struct V_87 *
F_46 ( struct V_58 * V_59 , T_2 V_88 )
{
struct V_87 * V_89 , V_90 * * V_91 ;
if ( V_88 == V_92 )
V_91 = & V_59 -> V_93 ;
else
V_91 = & V_59 -> V_94 ;
F_47 () ;
do {
V_89 = F_48 ( * V_91 ) ;
if ( ! V_89 )
break;
V_89 = F_49 ( V_89 ) ;
} while( ! V_89 );
F_50 () ;
return V_89 ;
}
struct V_95 *
F_51 ( struct V_52 * V_53 , T_2 V_96 )
{
struct V_58 * V_59 = F_52 ( V_53 , V_96 ) ;
struct V_95 * V_97 = NULL ;
if ( ! F_32 ( V_53 , V_59 ) ) {
F_53 ( L_7 ,
V_38 , V_96 ) ;
goto V_98;
}
V_97 = & V_59 -> V_99 [ 0 ] ;
V_98:
return V_97 ;
}
struct V_100 *
F_54 ( struct V_52 * V_53 , T_2 V_101 ,
bool V_102 )
{
struct V_58 * V_59 = F_52 ( V_53 , V_101 ) ;
struct V_100 * V_5 = NULL ;
struct V_54 * V_55 ;
struct V_103 * V_104 = V_53 -> V_56 -> V_57 ;
struct V_7 * V_105 = F_55 ( V_104 ) ;
unsigned int V_106 ;
if ( ! F_32 ( V_53 , V_59 ) ) {
F_53 ( L_8 ,
V_38 , V_101 ) ;
goto V_98;
}
V_55 = & V_59 -> V_2 -> V_3 ;
if ( F_56 ( V_55 ) )
goto V_107;
V_5 = V_59 -> V_2 -> V_5 ;
F_57 () ;
if ( V_5 -> V_108 )
goto V_98;
F_58 ( V_105 , V_5 , V_55 , V_109 ,
V_110 ,
V_59 -> V_2 -> V_24 [ 0 ] . V_43 ,
V_59 -> V_2 -> V_24 [ 0 ] . V_44 ,
V_111 ) ;
if ( V_5 -> V_108 ) {
V_106 =
F_22 ( F_59 ( V_5 -> V_108 -> V_112 ) ,
NULL ) ;
if ( V_59 -> V_2 -> V_24 [ 0 ] . V_45 > V_106 )
V_59 -> V_2 -> V_24 [ 0 ] . V_45 = V_106 ;
if ( V_59 -> V_2 -> V_24 [ 0 ] . V_46 > V_106 )
V_59 -> V_2 -> V_24 [ 0 ] . V_46 = V_106 ;
goto V_98;
}
F_41 ( F_60 ( V_53 -> V_56 ) ,
V_59 , V_53 -> V_113 . V_66 ,
V_53 -> V_113 . V_67 , V_114 ,
V_115 , V_116 ) ;
V_107:
if ( V_102 || ! F_30 ( V_53 ) )
F_31 ( V_104 , V_53 ) ;
V_5 = NULL ;
V_98:
return V_5 ;
}
struct V_87 *
F_61 ( struct V_52 * V_53 , T_2 V_101 ,
struct V_87 * V_117 )
{
struct V_58 * V_59 = F_52 ( V_53 , V_101 ) ;
struct V_87 * V_89 ;
if ( V_59 ) {
V_89 = F_46 ( V_59 , V_53 -> V_113 . V_88 ) ;
if ( ! V_89 )
V_89 = F_62 ( V_117 ) ;
} else {
V_89 = F_62 ( V_117 ) ;
}
return V_89 ;
}
struct V_118 *
F_63 ( struct V_52 * V_53 , T_2 V_101 ,
struct V_39 * V_108 , struct V_103 * V_103 )
{
struct V_58 * V_59 = F_52 ( V_53 , V_101 ) ;
switch ( V_59 -> V_2 -> V_24 [ 0 ] . V_43 ) {
case 3 :
return V_108 -> V_112 ;
case 4 :
return F_64 ( V_108 , V_103 ) ;
default:
F_65 () ;
}
}
static bool F_66 ( T_4 V_119 , T_4 V_120 ,
T_4 V_121 , T_4 V_122 )
{
T_4 V_123 = F_33 ( V_119 , V_120 ) ;
T_4 V_124 = F_33 ( V_121 , V_122 ) ;
return ( V_123 == V_63 || V_123 > V_121 ) &&
( V_124 == V_63 || V_124 > V_119 ) ;
}
int F_67 ( struct V_74 * V_75 ,
struct V_12 * V_125 , int * V_126 ,
const struct V_127 * V_128 )
{
struct V_64 * V_65 , * V_129 ;
T_3 * V_27 ;
F_39 (err, n, &flo->error_list, list) {
if ( ! F_66 ( V_65 -> V_66 , V_65 -> V_67 ,
V_128 -> V_66 , V_128 -> V_67 ) )
continue;
V_27 = F_68 ( V_125 ,
28 + V_130 + V_84 ) ;
if ( F_16 ( ! V_27 ) )
return - V_131 ;
V_27 = F_69 ( V_27 , V_65 -> V_66 ) ;
V_27 = F_69 ( V_27 , V_65 -> V_67 ) ;
V_27 = F_70 ( V_27 , & V_65 -> V_72 ,
V_130 ) ;
* V_27 ++ = F_71 ( 1 ) ;
V_27 = F_70 ( V_27 , & V_65 -> V_4 ,
V_84 ) ;
* V_27 ++ = F_71 ( V_65 -> V_71 ) ;
* V_27 ++ = F_71 ( V_65 -> V_70 ) ;
* V_126 += 1 ;
F_40 ( & V_65 -> V_81 ) ;
F_18 ( L_9 ,
V_38 , V_65 -> V_66 , V_65 -> V_67 , V_65 -> V_71 ,
V_65 -> V_70 , * V_126 ) ;
F_26 ( V_65 ) ;
}
return 0 ;
}
static bool F_72 ( struct V_52 * V_53 )
{
struct V_58 * V_59 ;
struct V_54 * V_55 ;
T_2 V_132 ;
for ( V_132 = 0 ; V_132 < F_73 ( V_53 ) ; V_132 ++ ) {
V_59 = F_52 ( V_53 , V_132 ) ;
if ( V_59 && V_59 -> V_2 ) {
V_55 = & V_59 -> V_2 -> V_3 ;
if ( ! F_56 ( V_55 ) )
return true ;
}
}
return false ;
}
static bool F_74 ( struct V_52 * V_53 )
{
struct V_58 * V_59 ;
struct V_54 * V_55 ;
T_2 V_132 ;
for ( V_132 = 0 ; V_132 < F_73 ( V_53 ) ; V_132 ++ ) {
V_59 = F_52 ( V_53 , V_132 ) ;
if ( ! V_59 || ! V_59 -> V_2 )
return false ;
V_55 = & V_59 -> V_2 -> V_3 ;
if ( F_56 ( V_55 ) )
return false ;
}
return F_73 ( V_53 ) != 0 ;
}
bool F_30 ( struct V_52 * V_53 )
{
if ( V_53 -> V_113 . V_88 == V_92 )
return F_72 ( V_53 ) ;
return F_74 ( V_53 ) ;
}
bool F_75 ( struct V_52 * V_53 )
{
return F_76 ( V_53 ) ||
F_30 ( V_53 ) ;
}
bool F_77 ( struct V_52 * V_53 )
{
return V_53 -> V_113 . V_88 == V_133 &&
F_78 ( V_53 ) ;
}
