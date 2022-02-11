void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( & V_2 -> V_3 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 . V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
F_7 ( V_2 , V_3 . V_6 ) ;
}
struct V_1 *
F_8 ( struct V_7 * V_8 , struct V_9 * V_10 ,
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
V_17 = F_9 ( V_11 ) ;
if ( ! V_17 )
goto V_31;
V_22 = F_10 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_22 )
goto V_32;
F_11 ( & V_22 -> V_3 ,
V_8 ,
& V_10 -> V_33 ) ;
F_12 ( & V_19 ) ;
F_13 ( & V_13 , & V_15 , V_10 -> V_34 , V_10 -> V_35 ) ;
F_14 ( & V_13 , F_15 ( V_17 ) , V_36 ) ;
V_27 = F_16 ( & V_13 , 4 ) ;
if ( F_17 ( ! V_27 ) )
goto V_37;
V_25 = F_18 ( V_27 ) ;
F_19 ( L_1 , V_38 , V_25 ) ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
V_21 = F_20 ( V_8 -> V_39 -> V_40 ,
& V_13 , V_11 ) ;
if ( V_21 )
F_21 ( & V_21 -> V_41 , & V_19 ) ;
}
if ( F_22 ( & V_19 ) ) {
F_19 ( L_2 ,
V_38 ) ;
V_29 = - V_42 ;
goto V_37;
}
V_27 = F_16 ( & V_13 , 4 ) ;
if ( F_17 ( ! V_27 ) )
goto V_37;
V_26 = F_18 ( V_27 ) ;
F_19 ( L_3 , V_38 , V_26 ) ;
V_24 = F_10 ( V_26 * sizeof( struct V_23 ) ,
V_11 ) ;
if ( ! V_24 )
goto V_32;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_27 = F_16 ( & V_13 , 20 ) ;
if ( F_17 ( ! V_27 ) )
goto V_37;
V_24 [ V_28 ] . V_43 = F_18 ( V_27 ++ ) ;
V_24 [ V_28 ] . V_44 = F_18 ( V_27 ++ ) ;
V_24 [ V_28 ] . V_45 = F_23 ( F_18 ( V_27 ++ ) , NULL ) ;
V_24 [ V_28 ] . V_46 = F_23 ( F_18 ( V_27 ++ ) , NULL ) ;
V_24 [ V_28 ] . V_47 = F_18 ( V_27 ) ;
if ( V_24 [ V_28 ] . V_45 > V_48 )
V_24 [ V_28 ] . V_45 = V_48 ;
if ( V_24 [ V_28 ] . V_46 > V_48 )
V_24 [ V_28 ] . V_46 = V_48 ;
if ( V_24 [ V_28 ] . V_43 != 3 || V_24 [ V_28 ] . V_44 != 0 ) {
F_19 ( L_4 , V_38 ,
V_28 , V_24 [ V_28 ] . V_43 ,
V_24 [ V_28 ] . V_44 ) ;
V_29 = - V_49 ;
goto V_37;
}
F_19 ( L_5 ,
V_38 , V_28 , V_24 [ V_28 ] . V_43 ,
V_24 [ V_28 ] . V_44 ,
V_24 [ V_28 ] . V_45 ,
V_24 [ V_28 ] . V_46 ,
V_24 [ V_28 ] . V_47 ) ;
}
V_22 -> V_24 = V_24 ;
V_22 -> V_50 = V_26 ;
V_22 -> V_5 = F_24 ( & V_19 , V_11 ) ;
if ( ! V_22 -> V_5 )
goto V_37;
while ( ! F_22 ( & V_19 ) ) {
V_21 = F_25 ( & V_19 ,
struct V_20 ,
V_41 ) ;
F_26 ( & V_21 -> V_41 ) ;
F_27 ( V_21 -> V_51 ) ;
F_27 ( V_21 ) ;
}
F_28 ( V_17 ) ;
return V_22 ;
V_37:
while ( ! F_22 ( & V_19 ) ) {
V_21 = F_25 ( & V_19 , struct V_20 ,
V_41 ) ;
F_26 ( & V_21 -> V_41 ) ;
F_27 ( V_21 -> V_51 ) ;
F_27 ( V_21 ) ;
}
F_27 ( V_24 ) ;
V_32:
F_28 ( V_17 ) ;
V_31:
F_27 ( V_22 ) ;
F_19 ( L_6 , V_38 , V_29 ) ;
return NULL ;
}
static void F_29 ( struct V_52 * V_53 ,
struct V_54 * V_55 )
{
F_30 ( V_55 -> V_56 , V_55 -> V_39 , & V_55 -> V_4 ) ;
if ( ! F_31 ( V_53 ) )
F_32 ( V_53 -> V_57 -> V_58 ,
V_53 ) ;
}
static bool F_33 ( struct V_52 * V_53 ,
struct V_59 * V_60 ,
bool V_61 )
{
if ( V_60 == NULL || F_34 ( V_60 -> V_2 ) )
goto V_62;
if ( V_60 -> V_2 == NULL ) {
if ( V_61 ) {
struct V_54 * V_63 ;
struct V_64 * V_65 = V_53 -> V_57 ;
struct V_1 * V_2 = F_35 ( - V_66 ) ;
V_63 = F_36 ( F_37 ( V_65 -> V_58 ) ,
& V_60 -> V_55 , V_65 -> V_67 ,
V_68 ) ;
if ( V_63 )
V_2 = F_38 ( V_63 ) ;
if ( F_39 ( & V_60 -> V_2 , NULL , V_2 ) &&
V_2 != F_35 ( - V_66 ) )
F_3 ( V_63 ) ;
} else
goto V_62;
}
if ( V_60 -> V_2 -> V_5 == NULL ) {
struct V_54 * V_55 ;
V_55 = & V_60 -> V_2 -> V_3 ;
F_29 ( V_53 , V_55 ) ;
return false ;
}
return true ;
V_62:
F_32 ( V_53 -> V_57 -> V_58 , V_53 ) ;
return false ;
}
static void F_40 ( struct V_69 * V_70 ,
T_4 V_71 , T_4 V_72 )
{
T_4 V_73 ;
V_73 = F_41 ( T_4 , F_42 ( V_70 -> V_71 , V_70 -> V_72 ) ,
F_42 ( V_71 , V_72 ) ) ;
V_70 -> V_71 = F_43 ( T_4 , V_70 -> V_71 , V_71 ) ;
V_70 -> V_72 = V_73 - V_70 -> V_71 ;
}
static int
F_44 ( const struct V_69 * V_74 ,
const struct V_69 * V_75 )
{
int V_29 ;
if ( V_74 -> V_76 != V_75 -> V_76 )
return V_74 -> V_76 < V_75 -> V_76 ? - 1 : 1 ;
if ( V_74 -> V_77 != V_75 -> V_77 )
return V_74 -> V_77 < V_75 -> V_77 ? - 1 : 1 ;
V_29 = memcmp ( V_74 -> V_78 . V_79 , V_75 -> V_78 . V_79 ,
sizeof( V_74 -> V_78 . V_79 ) ) ;
if ( V_29 != 0 )
return V_29 ;
V_29 = memcmp ( & V_74 -> V_4 , & V_75 -> V_4 , sizeof( V_74 -> V_4 ) ) ;
if ( V_29 != 0 )
return V_29 ;
if ( F_42 ( V_74 -> V_71 , V_74 -> V_72 ) < V_75 -> V_71 )
return - 1 ;
if ( V_74 -> V_71 > F_42 ( V_75 -> V_71 , V_75 -> V_72 ) )
return 1 ;
return 0 ;
}
static void
F_45 ( struct V_80 * V_81 ,
struct V_69 * V_82 )
{
struct V_69 * V_70 , * V_83 ;
struct V_18 * V_84 = & V_81 -> V_85 ;
int V_86 ;
F_46 (err, tmp, &flo->error_list, list) {
V_86 = F_44 ( V_70 , V_82 ) ;
if ( V_86 < 0 )
continue;
if ( V_86 > 0 ) {
V_84 = & V_70 -> V_87 ;
break;
}
F_40 ( V_82 , V_70 -> V_71 , V_70 -> V_72 ) ;
F_47 ( & V_70 -> V_87 , & V_82 -> V_87 ) ;
F_27 ( V_70 ) ;
return;
}
F_21 ( & V_82 -> V_87 , V_84 ) ;
}
int F_48 ( struct V_80 * V_81 ,
struct V_59 * V_60 , T_4 V_71 ,
T_4 V_72 , int V_77 , enum V_88 V_76 ,
T_1 V_11 )
{
struct V_69 * V_82 ;
if ( V_77 == 0 )
return 0 ;
if ( V_60 -> V_2 == NULL )
return - V_89 ;
V_82 = F_49 ( sizeof( * V_82 ) , V_11 ) ;
if ( ! V_82 )
return - V_30 ;
F_12 ( & V_82 -> V_87 ) ;
V_82 -> V_71 = V_71 ;
V_82 -> V_72 = V_72 ;
V_82 -> V_77 = V_77 ;
V_82 -> V_76 = V_76 ;
F_50 ( & V_82 -> V_78 , & V_60 -> V_78 ) ;
memcpy ( & V_82 -> V_4 , & V_60 -> V_2 -> V_3 . V_4 ,
V_90 ) ;
F_51 ( & V_81 -> V_91 . V_58 -> V_92 ) ;
F_45 ( V_81 , V_82 ) ;
F_52 ( & V_81 -> V_91 . V_58 -> V_92 ) ;
return 0 ;
}
static struct V_93 *
F_53 ( struct V_59 * V_60 , T_2 V_94 )
{
struct V_93 * V_95 , V_96 * * V_97 ;
if ( V_94 == V_98 )
V_97 = & V_60 -> V_99 ;
else
V_97 = & V_60 -> V_100 ;
F_54 () ;
do {
V_95 = F_55 ( * V_97 ) ;
if ( ! V_95 )
break;
V_95 = F_56 ( V_95 ) ;
} while( ! V_95 );
F_57 () ;
return V_95 ;
}
struct V_101 *
F_58 ( struct V_52 * V_53 , T_2 V_102 )
{
struct V_59 * V_60 = F_59 ( V_53 , V_102 ) ;
struct V_101 * V_103 = NULL ;
if ( ! F_33 ( V_53 , V_60 , false ) ) {
F_60 ( L_7 ,
V_38 , V_102 ) ;
goto V_104;
}
V_103 = & V_60 -> V_105 [ 0 ] ;
V_104:
return V_103 ;
}
struct V_106 *
F_61 ( struct V_52 * V_53 , T_2 V_107 ,
bool V_108 )
{
struct V_59 * V_60 = F_59 ( V_53 , V_107 ) ;
struct V_106 * V_5 = NULL ;
struct V_54 * V_55 ;
struct V_109 * V_110 = V_53 -> V_57 -> V_58 ;
struct V_7 * V_111 = F_37 ( V_110 ) ;
unsigned int V_112 ;
if ( ! F_33 ( V_53 , V_60 , true ) ) {
F_60 ( L_8 ,
V_38 , V_107 ) ;
goto V_104;
}
V_55 = & V_60 -> V_2 -> V_3 ;
if ( F_62 ( V_55 ) )
goto V_113;
V_5 = V_60 -> V_2 -> V_5 ;
F_63 () ;
if ( V_5 -> V_114 )
goto V_104;
F_64 ( V_111 , V_5 , V_55 , V_115 ,
V_116 ,
V_60 -> V_2 -> V_24 [ 0 ] . V_43 ,
V_60 -> V_2 -> V_24 [ 0 ] . V_44 ) ;
if ( V_5 -> V_114 ) {
V_112 =
F_23 ( F_65 ( V_5 -> V_114 -> V_117 ) ,
NULL ) ;
if ( V_60 -> V_2 -> V_24 [ 0 ] . V_45 > V_112 )
V_60 -> V_2 -> V_24 [ 0 ] . V_45 = V_112 ;
if ( V_60 -> V_2 -> V_24 [ 0 ] . V_46 > V_112 )
V_60 -> V_2 -> V_24 [ 0 ] . V_46 = V_112 ;
goto V_104;
}
F_48 ( F_66 ( V_53 -> V_57 ) ,
V_60 , V_53 -> V_118 . V_71 ,
V_53 -> V_118 . V_72 , V_119 ,
V_120 , V_121 ) ;
V_113:
if ( V_108 || ! F_31 ( V_53 ) )
F_32 ( V_110 , V_53 ) ;
V_5 = NULL ;
V_104:
return V_5 ;
}
struct V_93 *
F_67 ( struct V_52 * V_53 , T_2 V_107 ,
struct V_93 * V_122 )
{
struct V_59 * V_60 = F_59 ( V_53 , V_107 ) ;
struct V_93 * V_95 ;
if ( V_60 ) {
V_95 = F_53 ( V_60 , V_53 -> V_118 . V_94 ) ;
if ( ! V_95 )
V_95 = F_68 ( V_122 ) ;
} else {
V_95 = F_68 ( V_122 ) ;
}
return V_95 ;
}
struct V_123 *
F_69 ( struct V_52 * V_53 , T_2 V_107 ,
struct V_39 * V_114 , struct V_109 * V_109 )
{
struct V_59 * V_60 = F_59 ( V_53 , V_107 ) ;
switch ( V_60 -> V_2 -> V_24 [ 0 ] . V_43 ) {
case 3 :
return V_114 -> V_117 ;
case 4 :
return F_70 ( V_114 , V_109 ) ;
default:
F_71 () ;
}
}
void F_72 ( struct V_18 * V_84 )
{
struct V_69 * V_70 ;
while ( ! F_22 ( V_84 ) ) {
V_70 = F_25 ( V_84 ,
struct V_69 ,
V_87 ) ;
F_73 ( & V_70 -> V_87 ) ;
F_27 ( V_70 ) ;
}
}
int F_74 ( struct V_12 * V_124 , const struct V_18 * V_84 )
{
struct V_69 * V_70 ;
T_3 * V_27 ;
F_75 (err, head, list) {
V_27 = F_76 ( V_124 ,
28 + V_125 + V_90 ) ;
if ( F_17 ( ! V_27 ) )
return - V_126 ;
V_27 = F_77 ( V_27 , V_70 -> V_71 ) ;
V_27 = F_77 ( V_27 , V_70 -> V_72 ) ;
V_27 = F_78 ( V_27 , & V_70 -> V_78 ,
V_125 ) ;
* V_27 ++ = F_79 ( 1 ) ;
V_27 = F_78 ( V_27 , & V_70 -> V_4 ,
V_90 ) ;
* V_27 ++ = F_79 ( V_70 -> V_77 ) ;
* V_27 ++ = F_79 ( V_70 -> V_76 ) ;
F_19 ( L_9 ,
V_38 , V_70 -> V_71 , V_70 -> V_72 , V_70 -> V_77 ,
V_70 -> V_76 ) ;
}
return 0 ;
}
static
unsigned int F_80 ( struct V_64 * V_127 ,
const struct V_128 * V_129 ,
struct V_18 * V_84 ,
unsigned int V_130 )
{
struct V_80 * V_81 = F_66 ( V_127 ) ;
struct V_109 * V_109 = V_127 -> V_58 ;
struct V_69 * V_70 , * V_131 ;
unsigned int V_29 = 0 ;
F_51 ( & V_109 -> V_92 ) ;
F_46 (err, n, &flo->error_list, list) {
if ( ! F_81 ( V_70 -> V_71 ,
F_42 ( V_70 -> V_71 , V_70 -> V_72 ) ,
V_129 -> V_71 ,
F_42 ( V_129 -> V_71 , V_129 -> V_72 ) ) )
continue;
if ( ! V_130 )
break;
F_82 ( & V_70 -> V_87 , V_84 ) ;
V_130 -- ;
V_29 ++ ;
}
F_52 ( & V_109 -> V_92 ) ;
return V_29 ;
}
unsigned int F_83 ( struct V_64 * V_127 ,
const struct V_128 * V_129 ,
struct V_18 * V_84 ,
unsigned int V_130 )
{
unsigned int V_29 ;
V_29 = F_80 ( V_127 , V_129 , V_84 , V_130 ) ;
if ( V_29 == V_130 ) {
F_84 ( V_132 ) ;
F_80 ( V_127 , V_129 , & V_132 , - 1 ) ;
F_72 ( & V_132 ) ;
}
return V_29 ;
}
static bool F_85 ( struct V_52 * V_53 )
{
struct V_59 * V_60 ;
struct V_54 * V_55 ;
T_2 V_133 ;
for ( V_133 = 0 ; V_133 < F_86 ( V_53 ) ; V_133 ++ ) {
V_60 = F_59 ( V_53 , V_133 ) ;
if ( V_60 ) {
if ( ! V_60 -> V_2 )
return true ;
if ( F_34 ( V_60 -> V_2 ) )
continue;
V_55 = & V_60 -> V_2 -> V_3 ;
if ( ! F_62 ( V_55 ) )
return true ;
}
}
return false ;
}
static bool F_87 ( struct V_52 * V_53 )
{
struct V_59 * V_60 ;
struct V_54 * V_55 ;
T_2 V_133 ;
for ( V_133 = 0 ; V_133 < F_86 ( V_53 ) ; V_133 ++ ) {
V_60 = F_59 ( V_53 , V_133 ) ;
if ( ! V_60 || F_34 ( V_60 -> V_2 ) )
return false ;
if ( ! V_60 -> V_2 )
continue;
V_55 = & V_60 -> V_2 -> V_3 ;
if ( F_62 ( V_55 ) )
return false ;
}
return F_86 ( V_53 ) != 0 ;
}
static bool F_31 ( struct V_52 * V_53 )
{
if ( V_53 -> V_118 . V_94 == V_98 )
return F_85 ( V_53 ) ;
return F_87 ( V_53 ) ;
}
bool F_88 ( struct V_52 * V_53 )
{
return F_89 ( V_53 ) ||
F_31 ( V_53 ) ;
}
bool F_90 ( struct V_52 * V_53 )
{
return V_53 -> V_118 . V_94 == V_134 &&
F_91 ( V_53 ) ;
}
