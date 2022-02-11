static void F_1 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_4 = V_2 -> V_7 . V_8 [ V_5 ] . type ;
if ( V_4 == V_9 )
continue;
F_2 ( L_1 , V_5 , V_10 [ V_4 ] ) ;
if ( V_4 == V_11 || V_4 == V_12 )
F_2 ( L_2 , V_2 -> V_7 . V_8 [ V_5 ] . V_13 ) ;
else if ( V_4 == V_14 || V_4 == V_15 ||
V_4 == V_16 )
F_2 ( L_3 ,
V_2 -> V_7 . V_8 [ V_5 ] . V_17 -> V_18 ,
V_2 -> V_7 . V_8 [ V_5 ] . V_17 -> V_19 ) ;
}
for ( V_5 = 0 ; V_5 < V_20 ; V_5 += V_21 ) {
if ( V_2 -> V_7 . V_22 [ V_5 ] == V_23 )
F_2 ( L_4 , - V_20 + V_5 ,
V_10 [ V_2 -> V_7 . V_24 [ V_5 / V_21 ] . type ] ) ;
}
F_2 ( L_5 ) ;
}
static void F_3 ( struct V_25 * V_26 )
{
T_1 V_27 = F_4 ( V_26 -> V_28 ) ;
if ( V_27 == V_29 || V_27 == V_30 ) {
if ( F_5 ( V_26 -> V_28 ) == V_31 )
F_2 ( L_6 ,
V_26 -> V_28 , V_27 == V_29 ? L_7 : L_8 ,
V_26 -> V_32 ,
V_33 [ F_6 ( V_26 -> V_28 ) >> 4 ] ,
V_27 == V_29 ? L_7 : L_8 ,
V_26 -> V_34 ) ;
else
F_2 ( L_9 ,
V_26 -> V_28 , V_27 == V_29 ? L_7 : L_8 ,
V_26 -> V_32 ,
V_33 [ F_6 ( V_26 -> V_28 ) >> 4 ] ,
V_27 == V_29 ? L_7 : L_8 ,
V_26 -> V_13 ) ;
} else if ( V_27 == V_35 ) {
if ( F_7 ( V_26 -> V_28 ) == V_36 )
F_2 ( L_10 ,
V_26 -> V_28 ,
V_37 [ F_8 ( V_26 -> V_28 ) >> 3 ] ,
V_26 -> V_32 ,
V_26 -> V_38 , V_26 -> V_34 ) ;
else if ( F_7 ( V_26 -> V_28 ) == V_39 )
F_2 ( L_11 ,
V_26 -> V_28 ,
V_37 [ F_8 ( V_26 -> V_28 ) >> 3 ] ,
V_26 -> V_32 , V_26 -> V_38 ,
V_26 -> V_34 ) ;
else
F_2 ( L_12 , V_26 -> V_28 ) ;
} else if ( V_27 == V_40 ) {
if ( F_7 ( V_26 -> V_28 ) != V_36 ) {
F_2 ( L_13 , V_26 -> V_28 ) ;
return;
}
F_2 ( L_14 ,
V_26 -> V_28 ,
V_37 [ F_8 ( V_26 -> V_28 ) >> 3 ] ,
V_26 -> V_32 ,
V_26 -> V_38 , V_26 -> V_13 ) ;
} else if ( V_27 == V_41 ) {
if ( F_7 ( V_26 -> V_28 ) != V_36 ) {
F_2 ( L_15 , V_26 -> V_28 ) ;
return;
}
F_2 ( L_16 ,
V_26 -> V_28 , V_26 -> V_32 ,
V_37 [ F_8 ( V_26 -> V_28 ) >> 3 ] ,
V_26 -> V_34 , V_26 -> V_38 ) ;
} else if ( V_27 == V_42 ) {
if ( F_7 ( V_26 -> V_28 ) == V_43 ) {
F_2 ( L_17 ,
V_26 -> V_28 ,
V_37 [ F_8 ( V_26 -> V_28 ) >> 3 ] ,
V_26 -> V_13 ) ;
} else if ( F_7 ( V_26 -> V_28 ) == V_44 ) {
F_2 ( L_18 ,
V_26 -> V_28 ,
V_37 [ F_8 ( V_26 -> V_28 ) >> 3 ] ,
V_26 -> V_34 , V_26 -> V_13 ) ;
} else if ( F_7 ( V_26 -> V_28 ) == V_45 ) {
F_2 ( L_19 ,
V_26 -> V_28 , V_26 -> V_32 , V_26 -> V_13 ) ;
} else {
F_2 ( L_20 , V_26 -> V_28 ) ;
return;
}
} else if ( V_27 == V_46 ) {
T_1 V_47 = F_6 ( V_26 -> V_28 ) ;
if ( V_47 == V_48 ) {
F_2 ( L_21 , V_26 -> V_28 , V_26 -> V_13 ) ;
} else if ( V_26 -> V_28 == ( V_46 | V_49 ) ) {
F_2 ( L_22 ,
V_26 -> V_28 , V_26 -> V_38 ) ;
} else if ( V_26 -> V_28 == ( V_46 | V_50 ) ) {
F_2 ( L_23 , V_26 -> V_28 ) ;
} else if ( F_5 ( V_26 -> V_28 ) == V_31 ) {
F_2 ( L_24 ,
V_26 -> V_28 , V_26 -> V_32 ,
V_51 [ F_6 ( V_26 -> V_28 ) >> 4 ] ,
V_26 -> V_34 , V_26 -> V_38 ) ;
} else {
F_2 ( L_25 ,
V_26 -> V_28 , V_26 -> V_32 ,
V_51 [ F_6 ( V_26 -> V_28 ) >> 4 ] ,
V_26 -> V_13 , V_26 -> V_38 ) ;
}
} else {
F_2 ( L_26 , V_26 -> V_28 , V_52 [ V_27 ] ) ;
}
}
static int F_9 ( struct V_1 * V_2 , int * V_53 )
{
struct V_54 * V_55 ;
int V_56 ;
if ( V_2 -> V_57 == NULL )
return - 1 ;
memcpy ( & V_2 -> V_7 , & V_2 -> V_57 -> V_58 , sizeof( V_2 -> V_7 ) ) ;
V_56 = V_2 -> V_57 -> V_56 ;
if ( V_53 )
* V_53 = V_2 -> V_57 -> V_53 ;
V_55 = V_2 -> V_57 -> V_59 ;
F_10 ( V_2 -> V_57 ) ;
V_2 -> V_57 = V_55 ;
V_2 -> V_60 -- ;
return V_56 ;
}
static struct V_61 * F_11 ( struct V_1 * V_2 , int V_56 ,
int V_53 )
{
struct V_54 * V_55 ;
V_55 = F_12 ( sizeof( struct V_54 ) , V_62 ) ;
if ( ! V_55 )
goto V_63;
memcpy ( & V_55 -> V_58 , & V_2 -> V_7 , sizeof( V_2 -> V_7 ) ) ;
V_55 -> V_56 = V_56 ;
V_55 -> V_53 = V_53 ;
V_55 -> V_59 = V_2 -> V_57 ;
V_2 -> V_57 = V_55 ;
V_2 -> V_60 ++ ;
if ( V_2 -> V_60 > 1024 ) {
F_2 ( L_27 ) ;
goto V_63;
}
return & V_55 -> V_58 ;
V_63:
while ( F_9 ( V_2 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_13 ( struct V_64 * V_8 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_8 [ V_5 ] . type = V_9 ;
V_8 [ V_5 ] . V_13 = 0 ;
V_8 [ V_5 ] . V_17 = NULL ;
}
V_8 [ V_65 ] . type = V_66 ;
V_8 [ V_67 ] . type = V_68 ;
}
static void F_14 ( struct V_64 * V_8 , T_2 V_69 )
{
F_15 ( V_69 >= V_6 ) ;
V_8 [ V_69 ] . type = V_70 ;
V_8 [ V_69 ] . V_13 = 0 ;
V_8 [ V_69 ] . V_17 = NULL ;
}
static int F_16 ( struct V_64 * V_8 , T_2 V_69 ,
enum V_71 V_4 )
{
if ( V_69 >= V_6 ) {
F_2 ( L_28 , V_69 ) ;
return - V_72 ;
}
if ( V_4 == V_73 ) {
if ( V_8 [ V_69 ] . type == V_9 ) {
F_2 ( L_29 , V_69 ) ;
return - V_74 ;
}
} else {
if ( V_69 == V_65 ) {
F_2 ( L_30 ) ;
return - V_74 ;
}
if ( V_4 == V_75 )
F_14 ( V_8 , V_69 ) ;
}
return 0 ;
}
static int F_17 ( int V_76 )
{
if ( V_76 == V_77 )
return 4 ;
else if ( V_76 == V_78 )
return 2 ;
else if ( V_76 == V_79 )
return 1 ;
else if ( V_76 == V_80 )
return 8 ;
else
return - V_72 ;
}
static bool F_18 ( enum V_3 type )
{
switch ( type ) {
case V_15 :
case V_16 :
case V_12 :
case V_68 :
case V_66 :
case V_14 :
return true ;
default:
return false ;
}
}
static int F_19 ( struct V_61 * V_81 , int V_38 , int V_82 ,
int V_83 )
{
int V_5 ;
if ( V_83 >= 0 &&
F_18 ( V_81 -> V_8 [ V_83 ] . type ) ) {
if ( V_82 != V_21 ) {
F_2 ( L_31 ) ;
return - V_74 ;
}
V_81 -> V_24 [ ( V_20 + V_38 ) / V_21 ] =
V_81 -> V_8 [ V_83 ] ;
for ( V_5 = 0 ; V_5 < V_21 ; V_5 ++ )
V_81 -> V_22 [ V_20 + V_38 + V_5 ] = V_23 ;
} else {
V_81 -> V_24 [ ( V_20 + V_38 ) / V_21 ] =
(struct V_64 ) {} ;
for ( V_5 = 0 ; V_5 < V_82 ; V_5 ++ )
V_81 -> V_22 [ V_20 + V_38 + V_5 ] = V_84 ;
}
return 0 ;
}
static int F_20 ( struct V_61 * V_81 , int V_38 , int V_82 ,
int V_83 )
{
T_1 * V_85 ;
int V_5 ;
V_85 = & V_81 -> V_22 [ V_20 + V_38 ] ;
if ( V_85 [ 0 ] == V_23 ) {
if ( V_82 != V_21 ) {
F_2 ( L_31 ) ;
return - V_74 ;
}
for ( V_5 = 1 ; V_5 < V_21 ; V_5 ++ ) {
if ( V_85 [ V_5 ] != V_23 ) {
F_2 ( L_32 ) ;
return - V_74 ;
}
}
if ( V_83 >= 0 )
V_81 -> V_8 [ V_83 ] =
V_81 -> V_24 [ ( V_20 + V_38 ) / V_21 ] ;
return 0 ;
} else {
for ( V_5 = 0 ; V_5 < V_82 ; V_5 ++ ) {
if ( V_85 [ V_5 ] != V_84 ) {
F_2 ( L_33 ,
V_38 , V_5 , V_82 ) ;
return - V_74 ;
}
}
if ( V_83 >= 0 )
F_14 ( V_81 -> V_8 , V_83 ) ;
return 0 ;
}
}
static int F_21 ( struct V_1 * V_2 , T_2 V_69 , int V_38 ,
int V_82 )
{
struct V_86 * V_87 = V_2 -> V_7 . V_8 [ V_69 ] . V_17 ;
if ( V_38 < 0 || V_38 + V_82 > V_87 -> V_19 ) {
F_2 ( L_34 ,
V_87 -> V_19 , V_38 , V_82 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_38 , int V_82 ,
enum V_88 V_4 )
{
if ( V_2 -> V_89 -> V_90 -> V_91 -> V_92 &&
V_2 -> V_89 -> V_90 -> V_91 -> V_92 ( V_38 , V_82 , V_4 ) )
return 0 ;
F_2 ( L_35 , V_38 , V_82 ) ;
return - V_74 ;
}
static bool F_23 ( struct V_1 * V_2 , int V_69 )
{
if ( V_2 -> V_93 )
return false ;
switch ( V_2 -> V_7 . V_8 [ V_69 ] . type ) {
case V_70 :
case V_11 :
return false ;
default:
return true ;
}
}
static int F_24 ( struct V_1 * V_2 , T_2 V_69 , int V_38 ,
int V_76 , enum V_88 V_4 ,
int V_83 )
{
struct V_61 * V_81 = & V_2 -> V_7 ;
int V_82 , V_63 = 0 ;
if ( V_81 -> V_8 [ V_69 ] . type == V_12 )
V_38 += V_81 -> V_8 [ V_69 ] . V_13 ;
V_82 = F_17 ( V_76 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_38 % V_82 != 0 ) {
F_2 ( L_36 , V_38 , V_82 ) ;
return - V_74 ;
}
if ( V_81 -> V_8 [ V_69 ] . type == V_15 ) {
if ( V_4 == V_94 && V_83 >= 0 &&
F_23 ( V_2 , V_83 ) ) {
F_2 ( L_37 , V_83 ) ;
return - V_74 ;
}
V_63 = F_21 ( V_2 , V_69 , V_38 , V_82 ) ;
if ( ! V_63 && V_4 == V_95 && V_83 >= 0 )
F_14 ( V_81 -> V_8 , V_83 ) ;
} else if ( V_81 -> V_8 [ V_69 ] . type == V_68 ) {
if ( V_4 == V_94 && V_83 >= 0 &&
F_23 ( V_2 , V_83 ) ) {
F_2 ( L_38 , V_83 ) ;
return - V_74 ;
}
V_63 = F_22 ( V_2 , V_38 , V_82 , V_4 ) ;
if ( ! V_63 && V_4 == V_95 && V_83 >= 0 )
F_14 ( V_81 -> V_8 , V_83 ) ;
} else if ( V_81 -> V_8 [ V_69 ] . type == V_66 ||
V_81 -> V_8 [ V_69 ] . type == V_12 ) {
if ( V_38 >= 0 || V_38 < - V_20 ) {
F_2 ( L_39 , V_38 , V_82 ) ;
return - V_74 ;
}
if ( V_4 == V_94 ) {
if ( ! V_2 -> V_93 &&
V_81 -> V_22 [ V_20 + V_38 ] == V_23 &&
V_82 != V_21 ) {
F_2 ( L_40 ) ;
return - V_74 ;
}
V_63 = F_19 ( V_81 , V_38 , V_82 , V_83 ) ;
} else {
V_63 = F_20 ( V_81 , V_38 , V_82 , V_83 ) ;
}
} else {
F_2 ( L_41 ,
V_69 , V_10 [ V_81 -> V_8 [ V_69 ] . type ] ) ;
return - V_74 ;
}
return V_63 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
int V_63 ;
if ( ( F_8 ( V_26 -> V_28 ) != V_77 && F_8 ( V_26 -> V_28 ) != V_80 ) ||
V_26 -> V_13 != 0 ) {
F_2 ( L_42 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_24 ( V_2 , V_26 -> V_32 , V_26 -> V_38 ,
F_8 ( V_26 -> V_28 ) , V_95 , - 1 ) ;
if ( V_63 )
return V_63 ;
return F_24 ( V_2 , V_26 -> V_32 , V_26 -> V_38 ,
F_8 ( V_26 -> V_28 ) , V_94 , - 1 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_69 , int V_96 )
{
struct V_61 * V_81 = & V_2 -> V_7 ;
struct V_64 * V_8 = V_81 -> V_8 ;
int V_38 , V_5 ;
if ( V_8 [ V_69 ] . type != V_12 )
return - V_74 ;
V_38 = V_8 [ V_69 ] . V_13 ;
if ( V_38 >= 0 || V_38 < - V_20 || V_38 + V_96 > 0 ||
V_96 <= 0 ) {
F_2 ( L_43 ,
V_69 , V_38 , V_96 ) ;
return - V_74 ;
}
for ( V_5 = 0 ; V_5 < V_96 ; V_5 ++ ) {
if ( V_81 -> V_22 [ V_20 + V_38 + V_5 ] != V_84 ) {
F_2 ( L_44 ,
V_38 , V_5 , V_96 ) ;
return - V_74 ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_69 ,
enum V_97 V_98 , struct V_86 * * V_99 )
{
struct V_64 * V_100 = V_2 -> V_7 . V_8 + V_69 ;
enum V_3 V_101 ;
int V_63 = 0 ;
if ( V_98 == V_102 )
return 0 ;
if ( V_100 -> type == V_9 ) {
F_2 ( L_29 , V_69 ) ;
return - V_74 ;
}
if ( V_98 == V_103 ) {
if ( F_23 ( V_2 , V_69 ) ) {
F_2 ( L_45 , V_69 ) ;
return - V_74 ;
}
return 0 ;
}
if ( V_98 == V_104 || V_98 == V_105 ||
V_98 == V_106 ) {
V_101 = V_12 ;
} else if ( V_98 == V_107 ) {
V_101 = V_11 ;
} else if ( V_98 == V_108 ) {
V_101 = V_14 ;
} else if ( V_98 == V_109 ) {
V_101 = V_68 ;
} else {
F_2 ( L_46 , V_98 ) ;
return - V_110 ;
}
if ( V_100 -> type != V_101 ) {
F_2 ( L_47 , V_69 ,
V_10 [ V_100 -> type ] , V_10 [ V_101 ] ) ;
return - V_74 ;
}
if ( V_98 == V_108 ) {
* V_99 = V_100 -> V_17 ;
} else if ( V_98 == V_105 ) {
if ( ! * V_99 ) {
F_2 ( L_48 ) ;
return - V_74 ;
}
V_63 = F_26 ( V_2 , V_69 , ( * V_99 ) -> V_18 ) ;
} else if ( V_98 == V_106 ) {
if ( ! * V_99 ) {
F_2 ( L_49 ) ;
return - V_74 ;
}
V_63 = F_26 ( V_2 , V_69 , ( * V_99 ) -> V_19 ) ;
} else if ( V_98 == V_107 ) {
if ( V_69 == 0 ) {
F_2 ( L_50 ) ;
return - V_74 ;
}
V_63 = F_26 ( V_2 , V_69 - 1 , V_100 -> V_13 ) ;
}
return V_63 ;
}
static int F_28 ( struct V_86 * V_87 , int V_111 )
{
bool V_112 , V_113 ;
int V_5 ;
if ( ! V_87 )
return 0 ;
for ( V_5 = 0 ; V_5 < F_29 ( V_114 ) ; V_5 ++ ) {
V_112 = ( V_87 -> V_115 == V_114 [ V_5 ] . V_115 ) ;
V_113 = ( V_111 == V_114 [ V_5 ] . V_111 ) ;
if ( V_113 && V_112 != V_113 )
return - V_72 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_111 )
{
struct V_61 * V_81 = & V_2 -> V_7 ;
const struct V_116 * V_117 = NULL ;
struct V_64 * V_8 = V_81 -> V_8 ;
struct V_86 * V_87 = NULL ;
struct V_64 * V_100 ;
int V_5 , V_63 ;
if ( V_111 < 0 || V_111 >= V_118 ) {
F_2 ( L_51 , V_111 ) ;
return - V_72 ;
}
if ( V_2 -> V_89 -> V_90 -> V_91 -> V_119 )
V_117 = V_2 -> V_89 -> V_90 -> V_91 -> V_119 ( V_111 ) ;
if ( ! V_117 ) {
F_2 ( L_52 , V_111 ) ;
return - V_72 ;
}
if ( ! V_2 -> V_89 -> V_120 && V_117 -> V_121 ) {
F_2 ( L_53 ) ;
return - V_72 ;
}
V_63 = F_27 ( V_2 , V_67 , V_117 -> V_122 , & V_87 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_27 ( V_2 , V_123 , V_117 -> V_124 , & V_87 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_27 ( V_2 , V_125 , V_117 -> V_126 , & V_87 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_27 ( V_2 , V_127 , V_117 -> V_128 , & V_87 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_27 ( V_2 , V_129 , V_117 -> V_130 , & V_87 ) ;
if ( V_63 )
return V_63 ;
for ( V_5 = 0 ; V_5 < V_131 ; V_5 ++ ) {
V_100 = V_8 + V_132 [ V_5 ] ;
V_100 -> type = V_9 ;
V_100 -> V_13 = 0 ;
}
if ( V_117 -> V_133 == V_134 ) {
V_8 [ V_135 ] . type = V_70 ;
} else if ( V_117 -> V_133 == V_136 ) {
V_8 [ V_135 ] . type = V_9 ;
} else if ( V_117 -> V_133 == V_137 ) {
V_8 [ V_135 ] . type = V_16 ;
if ( V_87 == NULL ) {
F_2 ( L_54 ) ;
return - V_72 ;
}
V_8 [ V_135 ] . V_17 = V_87 ;
} else {
F_2 ( L_55 ,
V_117 -> V_133 , V_111 ) ;
return - V_72 ;
}
V_63 = F_28 ( V_87 , V_111 ) ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
T_1 V_47 = F_6 ( V_26 -> V_28 ) ;
int V_63 ;
if ( V_47 == V_138 || V_47 == V_139 ) {
if ( V_47 == V_139 ) {
if ( F_5 ( V_26 -> V_28 ) != 0 ||
V_26 -> V_34 != V_135 ||
V_26 -> V_38 != 0 || V_26 -> V_13 != 0 ) {
F_2 ( L_56 ) ;
return - V_72 ;
}
} else {
if ( V_26 -> V_34 != V_135 || V_26 -> V_38 != 0 ||
( V_26 -> V_13 != 16 && V_26 -> V_13 != 32 && V_26 -> V_13 != 64 ) ) {
F_2 ( L_57 ) ;
return - V_72 ;
}
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_23 ( V_2 , V_26 -> V_32 ) ) {
F_2 ( L_58 ,
V_26 -> V_32 ) ;
return - V_74 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_75 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_47 == V_140 ) {
if ( F_5 ( V_26 -> V_28 ) == V_31 ) {
if ( V_26 -> V_13 != 0 || V_26 -> V_38 != 0 ) {
F_2 ( L_59 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
} else {
if ( V_26 -> V_34 != V_135 || V_26 -> V_38 != 0 ) {
F_2 ( L_59 ) ;
return - V_72 ;
}
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_75 ) ;
if ( V_63 )
return V_63 ;
if ( F_5 ( V_26 -> V_28 ) == V_31 ) {
if ( F_4 ( V_26 -> V_28 ) == V_30 ) {
V_8 [ V_26 -> V_32 ] = V_8 [ V_26 -> V_34 ] ;
} else {
if ( F_23 ( V_2 , V_26 -> V_34 ) ) {
F_2 ( L_60 ,
V_26 -> V_34 ) ;
return - V_74 ;
}
V_8 [ V_26 -> V_32 ] . type = V_70 ;
V_8 [ V_26 -> V_32 ] . V_17 = NULL ;
}
} else {
V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_8 [ V_26 -> V_32 ] . V_13 = V_26 -> V_13 ;
}
} else if ( V_47 > V_138 ) {
F_2 ( L_61 , V_47 ) ;
return - V_72 ;
} else {
bool V_141 = false ;
if ( F_5 ( V_26 -> V_28 ) == V_31 ) {
if ( V_26 -> V_13 != 0 || V_26 -> V_38 != 0 ) {
F_2 ( L_62 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
} else {
if ( V_26 -> V_34 != V_135 || V_26 -> V_38 != 0 ) {
F_2 ( L_62 ) ;
return - V_72 ;
}
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( ( V_47 == V_142 || V_47 == V_143 ) &&
F_5 ( V_26 -> V_28 ) == V_144 && V_26 -> V_13 == 0 ) {
F_2 ( L_63 ) ;
return - V_72 ;
}
if ( V_47 == V_145 && F_4 ( V_26 -> V_28 ) == V_30 &&
V_8 [ V_26 -> V_32 ] . type == V_66 &&
F_5 ( V_26 -> V_28 ) == V_144 ) {
V_141 = true ;
} else if ( F_23 ( V_2 , V_26 -> V_32 ) ) {
F_2 ( L_58 ,
V_26 -> V_32 ) ;
return - V_74 ;
} else if ( F_5 ( V_26 -> V_28 ) == V_31 &&
F_23 ( V_2 , V_26 -> V_34 ) ) {
F_2 ( L_58 ,
V_26 -> V_34 ) ;
return - V_74 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_75 ) ;
if ( V_63 )
return V_63 ;
if ( V_141 ) {
V_8 [ V_26 -> V_32 ] . type = V_12 ;
V_8 [ V_26 -> V_32 ] . V_13 = V_26 -> V_13 ;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int * V_56 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
struct V_61 * V_146 ;
T_1 V_47 = F_6 ( V_26 -> V_28 ) ;
int V_63 ;
if ( V_47 > V_50 ) {
F_2 ( L_64 , V_47 ) ;
return - V_72 ;
}
if ( F_5 ( V_26 -> V_28 ) == V_31 ) {
if ( V_26 -> V_13 != 0 ) {
F_2 ( L_65 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_23 ( V_2 , V_26 -> V_34 ) ) {
F_2 ( L_66 ,
V_26 -> V_34 ) ;
return - V_74 ;
}
} else {
if ( V_26 -> V_34 != V_135 ) {
F_2 ( L_65 ) ;
return - V_72 ;
}
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_5 ( V_26 -> V_28 ) == V_144 &&
( V_47 == V_147 || V_47 == V_148 ) &&
V_8 [ V_26 -> V_32 ] . type == V_11 &&
V_8 [ V_26 -> V_32 ] . V_13 == V_26 -> V_13 ) {
if ( V_47 == V_147 ) {
* V_56 += V_26 -> V_38 ;
return 0 ;
} else {
return 0 ;
}
}
V_146 = F_11 ( V_2 , * V_56 + V_26 -> V_38 + 1 , * V_56 ) ;
if ( ! V_146 )
return - V_110 ;
if ( F_5 ( V_26 -> V_28 ) == V_144 &&
V_26 -> V_13 == 0 && ( V_47 == V_147 ||
V_47 == V_148 ) &&
V_8 [ V_26 -> V_32 ] . type == V_16 ) {
if ( V_47 == V_147 ) {
V_8 [ V_26 -> V_32 ] . type = V_15 ;
V_146 -> V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_146 -> V_8 [ V_26 -> V_32 ] . V_13 = 0 ;
} else {
V_146 -> V_8 [ V_26 -> V_32 ] . type = V_15 ;
V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_8 [ V_26 -> V_32 ] . V_13 = 0 ;
}
} else if ( F_23 ( V_2 , V_26 -> V_32 ) ) {
F_2 ( L_66 , V_26 -> V_32 ) ;
return - V_74 ;
} else if ( F_5 ( V_26 -> V_28 ) == V_144 &&
( V_47 == V_147 || V_47 == V_148 ) ) {
if ( V_47 == V_147 ) {
V_146 -> V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_146 -> V_8 [ V_26 -> V_32 ] . V_13 = V_26 -> V_13 ;
} else {
V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_8 [ V_26 -> V_32 ] . V_13 = V_26 -> V_13 ;
}
}
if ( V_149 )
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_86 * F_33 ( struct V_25 * V_26 )
{
T_3 V_150 = ( ( T_3 ) ( T_2 ) V_26 [ 0 ] . V_13 ) | ( ( T_3 ) ( T_2 ) V_26 [ 1 ] . V_13 ) << 32 ;
return (struct V_86 * ) ( unsigned long ) V_150 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
int V_63 ;
if ( F_8 ( V_26 -> V_28 ) != V_80 ) {
F_2 ( L_67 ) ;
return - V_72 ;
}
if ( V_26 -> V_38 != 0 ) {
F_2 ( L_68 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_75 ) ;
if ( V_63 )
return V_63 ;
if ( V_26 -> V_34 == 0 )
return 0 ;
F_15 ( V_26 -> V_34 != V_151 ) ;
V_8 [ V_26 -> V_32 ] . type = V_14 ;
V_8 [ V_26 -> V_32 ] . V_17 = F_33 ( V_26 ) ;
return 0 ;
}
static bool F_35 ( enum V_152 type )
{
switch ( type ) {
case V_153 :
case V_154 :
case V_155 :
return true ;
default:
return false ;
}
}
static int F_36 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
T_1 V_156 = F_7 ( V_26 -> V_28 ) ;
struct V_64 * V_100 ;
int V_5 , V_63 ;
if ( ! F_35 ( V_2 -> V_89 -> type ) ) {
F_2 ( L_69 ) ;
return - V_72 ;
}
if ( V_26 -> V_32 != V_135 || V_26 -> V_38 != 0 ||
( V_156 == V_43 && V_26 -> V_34 != V_135 ) ) {
F_2 ( L_70 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_157 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( V_8 [ V_157 ] . type != V_68 ) {
F_2 ( L_71 ) ;
return - V_72 ;
}
if ( V_156 == V_44 ) {
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
}
for ( V_5 = 0 ; V_5 < V_131 ; V_5 ++ ) {
V_100 = V_8 + V_132 [ V_5 ] ;
V_100 -> type = V_9 ;
V_100 -> V_13 = 0 ;
}
V_8 [ V_135 ] . type = V_70 ;
return 0 ;
}
static int F_37 ( int V_4 , int V_158 , int V_159 , struct V_1 * V_2 )
{
if ( V_159 == V_160 && V_161 [ V_4 ] >= ( V_162 | V_160 ) )
return 0 ;
if ( V_159 == V_163 && V_161 [ V_4 ] >= ( V_162 | V_163 ) )
return 0 ;
if ( V_158 < 0 || V_158 >= V_2 -> V_89 -> V_164 ) {
F_2 ( L_72 , V_4 , V_158 ) ;
return - V_72 ;
}
if ( V_159 == V_163 )
V_2 -> V_165 [ V_158 ] = V_166 ;
if ( V_161 [ V_158 ] == 0 ) {
V_161 [ V_4 ] = V_162 | V_159 ;
V_161 [ V_158 ] = V_162 ;
if ( V_167 >= V_2 -> V_89 -> V_164 )
return - V_168 ;
V_169 [ V_167 ++ ] = V_158 ;
return 1 ;
} else if ( ( V_161 [ V_158 ] & 0xF0 ) == V_162 ) {
F_2 ( L_73 , V_4 , V_158 ) ;
return - V_72 ;
} else if ( V_161 [ V_158 ] == V_170 ) {
V_161 [ V_4 ] = V_162 | V_159 ;
} else {
F_2 ( L_74 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_25 * V_171 = V_2 -> V_89 -> V_172 ;
int V_173 = V_2 -> V_89 -> V_164 ;
int V_174 = 0 ;
int V_5 , V_4 ;
V_161 = F_39 ( V_173 , sizeof( int ) , V_62 ) ;
if ( ! V_161 )
return - V_175 ;
V_169 = F_39 ( V_173 , sizeof( int ) , V_62 ) ;
if ( ! V_169 ) {
F_10 ( V_161 ) ;
return - V_175 ;
}
V_161 [ 0 ] = V_162 ;
V_169 [ 0 ] = 0 ;
V_167 = 1 ;
V_176:
if ( V_167 == 0 )
goto V_177;
V_4 = V_169 [ V_167 - 1 ] ;
if ( F_4 ( V_171 [ V_4 ] . V_28 ) == V_46 ) {
T_1 V_47 = F_6 ( V_171 [ V_4 ] . V_28 ) ;
if ( V_47 == V_50 ) {
goto V_178;
} else if ( V_47 == V_48 ) {
V_174 = F_37 ( V_4 , V_4 + 1 , V_160 , V_2 ) ;
if ( V_174 == 1 )
goto V_176;
else if ( V_174 < 0 )
goto V_179;
} else if ( V_47 == V_49 ) {
if ( F_5 ( V_171 [ V_4 ] . V_28 ) != V_144 ) {
V_174 = - V_72 ;
goto V_179;
}
V_174 = F_37 ( V_4 , V_4 + V_171 [ V_4 ] . V_38 + 1 ,
V_160 , V_2 ) ;
if ( V_174 == 1 )
goto V_176;
else if ( V_174 < 0 )
goto V_179;
if ( V_4 + 1 < V_173 )
V_2 -> V_165 [ V_4 + 1 ] = V_166 ;
} else {
V_174 = F_37 ( V_4 , V_4 + 1 , V_160 , V_2 ) ;
if ( V_174 == 1 )
goto V_176;
else if ( V_174 < 0 )
goto V_179;
V_174 = F_37 ( V_4 , V_4 + V_171 [ V_4 ] . V_38 + 1 , V_163 , V_2 ) ;
if ( V_174 == 1 )
goto V_176;
else if ( V_174 < 0 )
goto V_179;
}
} else {
V_174 = F_37 ( V_4 , V_4 + 1 , V_160 , V_2 ) ;
if ( V_174 == 1 )
goto V_176;
else if ( V_174 < 0 )
goto V_179;
}
V_178:
V_161 [ V_4 ] = V_170 ;
if ( V_167 -- <= 0 ) {
F_2 ( L_75 ) ;
V_174 = - V_110 ;
goto V_179;
}
goto V_176;
V_177:
for ( V_5 = 0 ; V_5 < V_173 ; V_5 ++ ) {
if ( V_161 [ V_5 ] != V_170 ) {
F_2 ( L_76 , V_5 ) ;
V_174 = - V_72 ;
goto V_179;
}
}
V_174 = 0 ;
V_179:
F_10 ( V_161 ) ;
F_10 ( V_169 ) ;
return V_174 ;
}
static bool F_40 ( struct V_61 * V_180 , struct V_61 * V_181 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( memcmp ( & V_180 -> V_8 [ V_5 ] , & V_181 -> V_8 [ V_5 ] ,
sizeof( V_180 -> V_8 [ 0 ] ) ) != 0 ) {
if ( V_180 -> V_8 [ V_5 ] . type == V_9 ||
( V_180 -> V_8 [ V_5 ] . type == V_70 &&
V_181 -> V_8 [ V_5 ] . type != V_9 ) )
continue;
return false ;
}
}
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
if ( V_180 -> V_22 [ V_5 ] == V_182 )
continue;
if ( V_180 -> V_22 [ V_5 ] != V_181 -> V_22 [ V_5 ] )
return false ;
if ( V_5 % V_21 )
continue;
if ( memcmp ( & V_180 -> V_24 [ V_5 / V_21 ] ,
& V_181 -> V_24 [ V_5 / V_21 ] ,
sizeof( V_180 -> V_24 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_41 ( struct V_1 * V_2 , int V_56 )
{
struct V_183 * V_184 ;
struct V_183 * V_185 ;
V_185 = V_2 -> V_165 [ V_56 ] ;
if ( ! V_185 )
return 0 ;
while ( V_185 != V_166 ) {
if ( F_40 ( & V_185 -> V_81 , & V_2 -> V_7 ) )
return 1 ;
V_185 = V_185 -> V_59 ;
}
V_184 = F_12 ( sizeof( struct V_183 ) , V_186 ) ;
if ( ! V_184 )
return - V_175 ;
memcpy ( & V_184 -> V_81 , & V_2 -> V_7 , sizeof( V_2 -> V_7 ) ) ;
V_184 -> V_59 = V_2 -> V_165 [ V_56 ] ;
V_2 -> V_165 [ V_56 ] = V_184 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_61 * V_81 = & V_2 -> V_7 ;
struct V_25 * V_171 = V_2 -> V_89 -> V_172 ;
struct V_64 * V_8 = V_81 -> V_8 ;
int V_173 = V_2 -> V_89 -> V_164 ;
int V_56 , V_53 = 0 ;
int V_187 = 0 ;
bool V_188 = false ;
F_13 ( V_8 ) ;
V_56 = 0 ;
for (; ; ) {
struct V_25 * V_26 ;
T_1 V_27 ;
int V_63 ;
if ( V_56 >= V_173 ) {
F_2 ( L_77 ,
V_56 , V_173 ) ;
return - V_110 ;
}
V_26 = & V_171 [ V_56 ] ;
V_27 = F_4 ( V_26 -> V_28 ) ;
if ( ++ V_187 > 32768 ) {
F_2 ( L_78 ,
V_187 ) ;
return - V_168 ;
}
V_63 = F_41 ( V_2 , V_56 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_63 == 1 ) {
if ( V_149 ) {
if ( V_188 )
F_2 ( L_79 ,
V_53 , V_56 ) ;
else
F_2 ( L_80 , V_56 ) ;
}
goto V_189;
}
if ( V_149 && V_188 ) {
F_2 ( L_81 , V_53 , V_56 ) ;
F_1 ( V_2 ) ;
V_188 = false ;
}
if ( V_149 ) {
F_2 ( L_82 , V_56 ) ;
F_3 ( V_26 ) ;
}
if ( V_27 == V_29 || V_27 == V_30 ) {
V_63 = F_31 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_27 == V_41 ) {
enum V_3 V_190 ;
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_191 ) ;
if ( V_63 )
return V_63 ;
V_190 = V_8 [ V_26 -> V_34 ] . type ;
V_63 = F_24 ( V_2 , V_26 -> V_34 , V_26 -> V_38 ,
F_8 ( V_26 -> V_28 ) , V_95 ,
V_26 -> V_32 ) ;
if ( V_63 )
return V_63 ;
if ( F_8 ( V_26 -> V_28 ) != V_77 ) {
V_56 ++ ;
continue;
}
if ( V_26 -> V_13 == 0 ) {
V_26 -> V_13 = V_190 ;
} else if ( V_190 != V_26 -> V_13 &&
( V_190 == V_68 ||
V_26 -> V_13 == V_68 ) ) {
F_2 ( L_83 ) ;
return - V_72 ;
}
} else if ( V_27 == V_35 ) {
enum V_3 V_192 ;
if ( F_7 ( V_26 -> V_28 ) == V_39 ) {
V_63 = F_25 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
V_56 ++ ;
continue;
}
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_192 = V_8 [ V_26 -> V_32 ] . type ;
V_63 = F_24 ( V_2 , V_26 -> V_32 , V_26 -> V_38 ,
F_8 ( V_26 -> V_28 ) , V_94 ,
V_26 -> V_34 ) ;
if ( V_63 )
return V_63 ;
if ( V_26 -> V_13 == 0 ) {
V_26 -> V_13 = V_192 ;
} else if ( V_192 != V_26 -> V_13 &&
( V_192 == V_68 ||
V_26 -> V_13 == V_68 ) ) {
F_2 ( L_83 ) ;
return - V_72 ;
}
} else if ( V_27 == V_40 ) {
if ( F_7 ( V_26 -> V_28 ) != V_36 ||
V_26 -> V_34 != V_135 ) {
F_2 ( L_84 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_24 ( V_2 , V_26 -> V_32 , V_26 -> V_38 ,
F_8 ( V_26 -> V_28 ) , V_94 ,
- 1 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_27 == V_46 ) {
T_1 V_47 = F_6 ( V_26 -> V_28 ) ;
if ( V_47 == V_48 ) {
if ( F_5 ( V_26 -> V_28 ) != V_144 ||
V_26 -> V_38 != 0 ||
V_26 -> V_34 != V_135 ||
V_26 -> V_32 != V_135 ) {
F_2 ( L_85 ) ;
return - V_72 ;
}
V_63 = F_30 ( V_2 , V_26 -> V_13 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_47 == V_49 ) {
if ( F_5 ( V_26 -> V_28 ) != V_144 ||
V_26 -> V_13 != 0 ||
V_26 -> V_34 != V_135 ||
V_26 -> V_32 != V_135 ) {
F_2 ( L_86 ) ;
return - V_72 ;
}
V_56 += V_26 -> V_38 + 1 ;
continue;
} else if ( V_47 == V_50 ) {
if ( F_5 ( V_26 -> V_28 ) != V_144 ||
V_26 -> V_13 != 0 ||
V_26 -> V_34 != V_135 ||
V_26 -> V_32 != V_135 ) {
F_2 ( L_87 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_135 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_23 ( V_2 , V_135 ) ) {
F_2 ( L_88 ) ;
return - V_74 ;
}
V_189:
V_56 = F_9 ( V_2 , & V_53 ) ;
if ( V_56 < 0 ) {
break;
} else {
V_188 = true ;
continue;
}
} else {
V_63 = F_32 ( V_2 , V_26 , & V_56 ) ;
if ( V_63 )
return V_63 ;
}
} else if ( V_27 == V_42 ) {
T_1 V_156 = F_7 ( V_26 -> V_28 ) ;
if ( V_156 == V_43 || V_156 == V_44 ) {
V_63 = F_36 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_156 == V_45 ) {
V_63 = F_34 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
V_56 ++ ;
} else {
F_2 ( L_89 ) ;
return - V_72 ;
}
} else {
F_2 ( L_90 , V_27 ) ;
return - V_72 ;
}
V_56 ++ ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_89 -> V_172 ;
int V_173 = V_2 -> V_89 -> V_164 ;
int V_5 , V_193 ;
for ( V_5 = 0 ; V_5 < V_173 ; V_5 ++ , V_26 ++ ) {
if ( F_4 ( V_26 -> V_28 ) == V_41 &&
( F_7 ( V_26 -> V_28 ) != V_36 || V_26 -> V_13 != 0 ) ) {
F_2 ( L_91 ) ;
return - V_72 ;
}
if ( F_4 ( V_26 -> V_28 ) == V_35 &&
( ( F_7 ( V_26 -> V_28 ) != V_36 &&
F_7 ( V_26 -> V_28 ) != V_39 ) || V_26 -> V_13 != 0 ) ) {
F_2 ( L_92 ) ;
return - V_72 ;
}
if ( V_26 [ 0 ] . V_28 == ( V_42 | V_45 | V_80 ) ) {
struct V_86 * V_87 ;
struct V_194 V_195 ;
if ( V_5 == V_173 - 1 || V_26 [ 1 ] . V_28 != 0 ||
V_26 [ 1 ] . V_32 != 0 || V_26 [ 1 ] . V_34 != 0 ||
V_26 [ 1 ] . V_38 != 0 ) {
F_2 ( L_93 ) ;
return - V_72 ;
}
if ( V_26 -> V_34 == 0 )
goto V_196;
if ( V_26 -> V_34 != V_151 ) {
F_2 ( L_94 ) ;
return - V_72 ;
}
V_195 = F_44 ( V_26 -> V_13 ) ;
V_87 = F_45 ( V_195 ) ;
if ( F_46 ( V_87 ) ) {
F_2 ( L_95 ,
V_26 -> V_13 ) ;
F_47 ( V_195 ) ;
return F_48 ( V_87 ) ;
}
V_26 [ 0 ] . V_13 = ( T_2 ) ( unsigned long ) V_87 ;
V_26 [ 1 ] . V_13 = ( ( T_3 ) ( unsigned long ) V_87 ) >> 32 ;
for ( V_193 = 0 ; V_193 < V_2 -> V_197 ; V_193 ++ )
if ( V_2 -> V_198 [ V_193 ] == V_87 ) {
F_47 ( V_195 ) ;
goto V_196;
}
if ( V_2 -> V_197 >= V_199 ) {
F_47 ( V_195 ) ;
return - V_168 ;
}
V_2 -> V_198 [ V_2 -> V_197 ++ ] = V_87 ;
F_49 ( V_87 , false ) ;
F_47 ( V_195 ) ;
V_196:
V_26 ++ ;
V_5 ++ ;
}
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_197 ; V_5 ++ )
F_51 ( V_2 -> V_198 [ V_5 ] ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_89 -> V_172 ;
int V_173 = V_2 -> V_89 -> V_164 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_173 ; V_5 ++ , V_26 ++ )
if ( V_26 -> V_28 == ( V_42 | V_45 | V_80 ) )
V_26 -> V_34 = 0 ;
}
static void F_53 ( struct V_200 * V_89 , int V_201 , int V_202 )
{
struct V_25 * V_26 = V_89 -> V_172 ;
int V_173 = V_89 -> V_164 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_173 ; V_5 ++ , V_26 ++ ) {
if ( F_4 ( V_26 -> V_28 ) != V_46 ||
F_6 ( V_26 -> V_28 ) == V_48 ||
F_6 ( V_26 -> V_28 ) == V_50 )
continue;
if ( V_5 < V_201 && V_5 + V_26 -> V_38 + 1 > V_201 )
V_26 -> V_38 += V_202 ;
else if ( V_5 > V_201 && V_5 + V_26 -> V_38 + 1 < V_201 )
V_26 -> V_38 -= V_202 ;
}
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_89 -> V_172 ;
int V_173 = V_2 -> V_89 -> V_164 ;
struct V_25 V_203 [ 16 ] ;
struct V_200 * V_204 ;
T_2 V_205 ;
int V_5 ;
enum V_88 type ;
if ( ! V_2 -> V_89 -> V_90 -> V_91 -> V_206 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_173 ; V_5 ++ , V_26 ++ ) {
if ( V_26 -> V_28 == ( V_41 | V_36 | V_77 ) )
type = V_95 ;
else if ( V_26 -> V_28 == ( V_35 | V_36 | V_77 ) )
type = V_94 ;
else
continue;
if ( V_26 -> V_13 != V_68 ) {
V_26 -> V_13 = 0 ;
continue;
}
V_205 = V_2 -> V_89 -> V_90 -> V_91 ->
V_206 ( type , V_26 -> V_32 , V_26 -> V_34 ,
V_26 -> V_38 , V_203 , V_2 -> V_89 ) ;
if ( V_205 == 0 || V_205 >= F_29 ( V_203 ) ) {
F_2 ( L_96 ) ;
return - V_72 ;
}
if ( V_205 == 1 ) {
memcpy ( V_26 , V_203 , sizeof( * V_26 ) ) ;
continue;
}
V_173 += V_205 - 1 ;
V_204 = F_55 ( V_2 -> V_89 ,
F_56 ( V_173 ) ,
V_186 ) ;
if ( ! V_204 )
return - V_175 ;
V_204 -> V_164 = V_173 ;
memmove ( V_204 -> V_172 + V_5 + V_205 , V_204 -> V_171 + V_5 + 1 ,
sizeof( * V_26 ) * ( V_173 - V_5 - V_205 ) ) ;
memcpy ( V_204 -> V_172 + V_5 , V_203 , sizeof( * V_26 ) * V_205 ) ;
F_53 ( V_204 , V_5 , V_205 - 1 ) ;
V_2 -> V_89 = V_204 ;
V_26 = V_204 -> V_172 + V_5 + V_205 - 1 ;
V_5 += V_205 - 1 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_183 * V_185 , * V_207 ;
int V_5 ;
if ( ! V_2 -> V_165 )
return;
for ( V_5 = 0 ; V_5 < V_2 -> V_89 -> V_164 ; V_5 ++ ) {
V_185 = V_2 -> V_165 [ V_5 ] ;
if ( V_185 )
while ( V_185 != V_166 ) {
V_207 = V_185 -> V_59 ;
F_10 ( V_185 ) ;
V_185 = V_207 ;
}
}
F_10 ( V_2 -> V_165 ) ;
}
int F_58 ( struct V_200 * * V_89 , union V_208 * V_209 )
{
char T_4 * V_210 = NULL ;
struct V_1 * V_2 ;
int V_174 = - V_72 ;
if ( ( * V_89 ) -> V_164 <= 0 || ( * V_89 ) -> V_164 > V_211 )
return - V_168 ;
V_2 = F_59 ( sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_2 )
return - V_175 ;
V_2 -> V_89 = * V_89 ;
F_60 ( & V_212 ) ;
if ( V_209 -> V_149 || V_209 -> V_213 || V_209 -> V_214 ) {
V_149 = V_209 -> V_149 ;
V_210 = ( char T_4 * ) ( unsigned long ) V_209 -> V_213 ;
V_214 = V_209 -> V_214 ;
V_215 = 0 ;
V_174 = - V_72 ;
if ( V_214 < 128 || V_214 > V_216 >> 8 ||
V_149 == 0 || V_210 == NULL )
goto V_217;
V_174 = - V_175 ;
V_213 = F_61 ( V_214 ) ;
if ( ! V_213 )
goto V_217;
} else {
V_149 = 0 ;
}
V_174 = F_43 ( V_2 ) ;
if ( V_174 < 0 )
goto V_218;
V_2 -> V_165 = F_39 ( V_2 -> V_89 -> V_164 ,
sizeof( struct V_183 * ) ,
V_186 ) ;
V_174 = - V_175 ;
if ( ! V_2 -> V_165 )
goto V_218;
V_174 = F_38 ( V_2 ) ;
if ( V_174 < 0 )
goto V_218;
V_2 -> V_93 = F_62 ( V_219 ) ;
V_174 = F_42 ( V_2 ) ;
V_218:
while ( F_9 ( V_2 , NULL ) >= 0 ) ;
F_57 ( V_2 ) ;
if ( V_174 == 0 )
V_174 = F_54 ( V_2 ) ;
if ( V_149 && V_215 >= V_214 - 1 ) {
F_15 ( V_215 >= V_214 ) ;
V_174 = - V_220 ;
}
if ( V_149 && F_63 ( V_210 , V_213 , V_215 + 1 ) != 0 ) {
V_174 = - V_110 ;
goto V_221;
}
if ( V_174 == 0 && V_2 -> V_197 ) {
V_2 -> V_89 -> V_90 -> V_198 = F_64 ( V_2 -> V_197 ,
sizeof( V_2 -> V_198 [ 0 ] ) ,
V_62 ) ;
if ( ! V_2 -> V_89 -> V_90 -> V_198 ) {
V_174 = - V_175 ;
goto V_221;
}
memcpy ( V_2 -> V_89 -> V_90 -> V_198 , V_2 -> V_198 ,
sizeof( V_2 -> V_198 [ 0 ] ) * V_2 -> V_197 ) ;
V_2 -> V_89 -> V_90 -> V_197 = V_2 -> V_197 ;
F_52 ( V_2 ) ;
}
V_221:
if ( V_149 )
F_65 ( V_213 ) ;
V_217:
if ( ! V_2 -> V_89 -> V_90 -> V_198 )
F_50 ( V_2 ) ;
* V_89 = V_2 -> V_89 ;
F_10 ( V_2 ) ;
F_66 ( & V_212 ) ;
return V_174 ;
}
