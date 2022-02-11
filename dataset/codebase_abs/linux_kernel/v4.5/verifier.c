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
if ( ( V_47 == V_145 || V_47 == V_146 ||
V_47 == V_147 ) && F_5 ( V_26 -> V_28 ) == V_144 ) {
int V_82 = F_4 ( V_26 -> V_28 ) == V_30 ? 64 : 32 ;
if ( V_26 -> V_13 < 0 || V_26 -> V_13 >= V_82 ) {
F_2 ( L_64 , V_26 -> V_13 ) ;
return - V_72 ;
}
}
if ( V_47 == V_148 && F_4 ( V_26 -> V_28 ) == V_30 &&
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
struct V_61 * V_149 ;
T_1 V_47 = F_6 ( V_26 -> V_28 ) ;
int V_63 ;
if ( V_47 > V_50 ) {
F_2 ( L_65 , V_47 ) ;
return - V_72 ;
}
if ( F_5 ( V_26 -> V_28 ) == V_31 ) {
if ( V_26 -> V_13 != 0 ) {
F_2 ( L_66 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_23 ( V_2 , V_26 -> V_34 ) ) {
F_2 ( L_67 ,
V_26 -> V_34 ) ;
return - V_74 ;
}
} else {
if ( V_26 -> V_34 != V_135 ) {
F_2 ( L_66 ) ;
return - V_72 ;
}
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_5 ( V_26 -> V_28 ) == V_144 &&
( V_47 == V_150 || V_47 == V_151 ) &&
V_8 [ V_26 -> V_32 ] . type == V_11 &&
V_8 [ V_26 -> V_32 ] . V_13 == V_26 -> V_13 ) {
if ( V_47 == V_150 ) {
* V_56 += V_26 -> V_38 ;
return 0 ;
} else {
return 0 ;
}
}
V_149 = F_11 ( V_2 , * V_56 + V_26 -> V_38 + 1 , * V_56 ) ;
if ( ! V_149 )
return - V_110 ;
if ( F_5 ( V_26 -> V_28 ) == V_144 &&
V_26 -> V_13 == 0 && ( V_47 == V_150 ||
V_47 == V_151 ) &&
V_8 [ V_26 -> V_32 ] . type == V_16 ) {
if ( V_47 == V_150 ) {
V_8 [ V_26 -> V_32 ] . type = V_15 ;
V_149 -> V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_149 -> V_8 [ V_26 -> V_32 ] . V_13 = 0 ;
} else {
V_149 -> V_8 [ V_26 -> V_32 ] . type = V_15 ;
V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_8 [ V_26 -> V_32 ] . V_13 = 0 ;
}
} else if ( F_23 ( V_2 , V_26 -> V_32 ) ) {
F_2 ( L_67 , V_26 -> V_32 ) ;
return - V_74 ;
} else if ( F_5 ( V_26 -> V_28 ) == V_144 &&
( V_47 == V_150 || V_47 == V_151 ) ) {
if ( V_47 == V_150 ) {
V_149 -> V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_149 -> V_8 [ V_26 -> V_32 ] . V_13 = V_26 -> V_13 ;
} else {
V_8 [ V_26 -> V_32 ] . type = V_11 ;
V_8 [ V_26 -> V_32 ] . V_13 = V_26 -> V_13 ;
}
}
if ( V_152 )
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_86 * F_33 ( struct V_25 * V_26 )
{
T_3 V_153 = ( ( T_3 ) ( T_2 ) V_26 [ 0 ] . V_13 ) | ( ( T_3 ) ( T_2 ) V_26 [ 1 ] . V_13 ) << 32 ;
return (struct V_86 * ) ( unsigned long ) V_153 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
int V_63 ;
if ( F_8 ( V_26 -> V_28 ) != V_80 ) {
F_2 ( L_68 ) ;
return - V_72 ;
}
if ( V_26 -> V_38 != 0 ) {
F_2 ( L_69 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_75 ) ;
if ( V_63 )
return V_63 ;
if ( V_26 -> V_34 == 0 )
return 0 ;
F_15 ( V_26 -> V_34 != V_154 ) ;
V_8 [ V_26 -> V_32 ] . type = V_14 ;
V_8 [ V_26 -> V_32 ] . V_17 = F_33 ( V_26 ) ;
return 0 ;
}
static bool F_35 ( enum V_155 type )
{
switch ( type ) {
case V_156 :
case V_157 :
case V_158 :
return true ;
default:
return false ;
}
}
static int F_36 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_64 * V_8 = V_2 -> V_7 . V_8 ;
T_1 V_159 = F_7 ( V_26 -> V_28 ) ;
struct V_64 * V_100 ;
int V_5 , V_63 ;
if ( ! F_35 ( V_2 -> V_89 -> type ) ) {
F_2 ( L_70 ) ;
return - V_72 ;
}
if ( V_26 -> V_32 != V_135 || V_26 -> V_38 != 0 ||
( V_159 == V_43 && V_26 -> V_34 != V_135 ) ) {
F_2 ( L_71 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_160 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( V_8 [ V_160 ] . type != V_68 ) {
F_2 ( L_72 ) ;
return - V_72 ;
}
if ( V_159 == V_44 ) {
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
static int F_37 ( int V_4 , int V_161 , int V_162 , struct V_1 * V_2 )
{
if ( V_162 == V_163 && V_164 [ V_4 ] >= ( V_165 | V_163 ) )
return 0 ;
if ( V_162 == V_166 && V_164 [ V_4 ] >= ( V_165 | V_166 ) )
return 0 ;
if ( V_161 < 0 || V_161 >= V_2 -> V_89 -> V_167 ) {
F_2 ( L_73 , V_4 , V_161 ) ;
return - V_72 ;
}
if ( V_162 == V_166 )
V_2 -> V_168 [ V_161 ] = V_169 ;
if ( V_164 [ V_161 ] == 0 ) {
V_164 [ V_4 ] = V_165 | V_162 ;
V_164 [ V_161 ] = V_165 ;
if ( V_170 >= V_2 -> V_89 -> V_167 )
return - V_171 ;
V_172 [ V_170 ++ ] = V_161 ;
return 1 ;
} else if ( ( V_164 [ V_161 ] & 0xF0 ) == V_165 ) {
F_2 ( L_74 , V_4 , V_161 ) ;
return - V_72 ;
} else if ( V_164 [ V_161 ] == V_173 ) {
V_164 [ V_4 ] = V_165 | V_162 ;
} else {
F_2 ( L_75 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_25 * V_174 = V_2 -> V_89 -> V_175 ;
int V_176 = V_2 -> V_89 -> V_167 ;
int V_177 = 0 ;
int V_5 , V_4 ;
V_164 = F_39 ( V_176 , sizeof( int ) , V_62 ) ;
if ( ! V_164 )
return - V_178 ;
V_172 = F_39 ( V_176 , sizeof( int ) , V_62 ) ;
if ( ! V_172 ) {
F_10 ( V_164 ) ;
return - V_178 ;
}
V_164 [ 0 ] = V_165 ;
V_172 [ 0 ] = 0 ;
V_170 = 1 ;
V_179:
if ( V_170 == 0 )
goto V_180;
V_4 = V_172 [ V_170 - 1 ] ;
if ( F_4 ( V_174 [ V_4 ] . V_28 ) == V_46 ) {
T_1 V_47 = F_6 ( V_174 [ V_4 ] . V_28 ) ;
if ( V_47 == V_50 ) {
goto V_181;
} else if ( V_47 == V_48 ) {
V_177 = F_37 ( V_4 , V_4 + 1 , V_163 , V_2 ) ;
if ( V_177 == 1 )
goto V_179;
else if ( V_177 < 0 )
goto V_182;
} else if ( V_47 == V_49 ) {
if ( F_5 ( V_174 [ V_4 ] . V_28 ) != V_144 ) {
V_177 = - V_72 ;
goto V_182;
}
V_177 = F_37 ( V_4 , V_4 + V_174 [ V_4 ] . V_38 + 1 ,
V_163 , V_2 ) ;
if ( V_177 == 1 )
goto V_179;
else if ( V_177 < 0 )
goto V_182;
if ( V_4 + 1 < V_176 )
V_2 -> V_168 [ V_4 + 1 ] = V_169 ;
} else {
V_177 = F_37 ( V_4 , V_4 + 1 , V_163 , V_2 ) ;
if ( V_177 == 1 )
goto V_179;
else if ( V_177 < 0 )
goto V_182;
V_177 = F_37 ( V_4 , V_4 + V_174 [ V_4 ] . V_38 + 1 , V_166 , V_2 ) ;
if ( V_177 == 1 )
goto V_179;
else if ( V_177 < 0 )
goto V_182;
}
} else {
V_177 = F_37 ( V_4 , V_4 + 1 , V_163 , V_2 ) ;
if ( V_177 == 1 )
goto V_179;
else if ( V_177 < 0 )
goto V_182;
}
V_181:
V_164 [ V_4 ] = V_173 ;
if ( V_170 -- <= 0 ) {
F_2 ( L_76 ) ;
V_177 = - V_110 ;
goto V_182;
}
goto V_179;
V_180:
for ( V_5 = 0 ; V_5 < V_176 ; V_5 ++ ) {
if ( V_164 [ V_5 ] != V_173 ) {
F_2 ( L_77 , V_5 ) ;
V_177 = - V_72 ;
goto V_182;
}
}
V_177 = 0 ;
V_182:
F_10 ( V_164 ) ;
F_10 ( V_172 ) ;
return V_177 ;
}
static bool F_40 ( struct V_61 * V_183 , struct V_61 * V_184 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( memcmp ( & V_183 -> V_8 [ V_5 ] , & V_184 -> V_8 [ V_5 ] ,
sizeof( V_183 -> V_8 [ 0 ] ) ) != 0 ) {
if ( V_183 -> V_8 [ V_5 ] . type == V_9 ||
( V_183 -> V_8 [ V_5 ] . type == V_70 &&
V_184 -> V_8 [ V_5 ] . type != V_9 ) )
continue;
return false ;
}
}
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
if ( V_183 -> V_22 [ V_5 ] == V_185 )
continue;
if ( V_183 -> V_22 [ V_5 ] != V_184 -> V_22 [ V_5 ] )
return false ;
if ( V_5 % V_21 )
continue;
if ( memcmp ( & V_183 -> V_24 [ V_5 / V_21 ] ,
& V_184 -> V_24 [ V_5 / V_21 ] ,
sizeof( V_183 -> V_24 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_41 ( struct V_1 * V_2 , int V_56 )
{
struct V_186 * V_187 ;
struct V_186 * V_188 ;
V_188 = V_2 -> V_168 [ V_56 ] ;
if ( ! V_188 )
return 0 ;
while ( V_188 != V_169 ) {
if ( F_40 ( & V_188 -> V_81 , & V_2 -> V_7 ) )
return 1 ;
V_188 = V_188 -> V_59 ;
}
V_187 = F_12 ( sizeof( struct V_186 ) , V_189 ) ;
if ( ! V_187 )
return - V_178 ;
memcpy ( & V_187 -> V_81 , & V_2 -> V_7 , sizeof( V_2 -> V_7 ) ) ;
V_187 -> V_59 = V_2 -> V_168 [ V_56 ] ;
V_2 -> V_168 [ V_56 ] = V_187 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_61 * V_81 = & V_2 -> V_7 ;
struct V_25 * V_174 = V_2 -> V_89 -> V_175 ;
struct V_64 * V_8 = V_81 -> V_8 ;
int V_176 = V_2 -> V_89 -> V_167 ;
int V_56 , V_53 = 0 ;
int V_190 = 0 ;
bool V_191 = false ;
F_13 ( V_8 ) ;
V_56 = 0 ;
for (; ; ) {
struct V_25 * V_26 ;
T_1 V_27 ;
int V_63 ;
if ( V_56 >= V_176 ) {
F_2 ( L_78 ,
V_56 , V_176 ) ;
return - V_110 ;
}
V_26 = & V_174 [ V_56 ] ;
V_27 = F_4 ( V_26 -> V_28 ) ;
if ( ++ V_190 > 32768 ) {
F_2 ( L_79 ,
V_190 ) ;
return - V_171 ;
}
V_63 = F_41 ( V_2 , V_56 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_63 == 1 ) {
if ( V_152 ) {
if ( V_191 )
F_2 ( L_80 ,
V_53 , V_56 ) ;
else
F_2 ( L_81 , V_56 ) ;
}
goto V_192;
}
if ( V_152 && V_191 ) {
F_2 ( L_82 , V_53 , V_56 ) ;
F_1 ( V_2 ) ;
V_191 = false ;
}
if ( V_152 ) {
F_2 ( L_83 , V_56 ) ;
F_3 ( V_26 ) ;
}
if ( V_27 == V_29 || V_27 == V_30 ) {
V_63 = F_31 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_27 == V_41 ) {
enum V_3 V_193 ;
V_63 = F_16 ( V_8 , V_26 -> V_34 , V_73 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_16 ( V_8 , V_26 -> V_32 , V_194 ) ;
if ( V_63 )
return V_63 ;
V_193 = V_8 [ V_26 -> V_34 ] . type ;
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
V_26 -> V_13 = V_193 ;
} else if ( V_193 != V_26 -> V_13 &&
( V_193 == V_68 ||
V_26 -> V_13 == V_68 ) ) {
F_2 ( L_84 ) ;
return - V_72 ;
}
} else if ( V_27 == V_35 ) {
enum V_3 V_195 ;
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
V_195 = V_8 [ V_26 -> V_32 ] . type ;
V_63 = F_24 ( V_2 , V_26 -> V_32 , V_26 -> V_38 ,
F_8 ( V_26 -> V_28 ) , V_94 ,
V_26 -> V_34 ) ;
if ( V_63 )
return V_63 ;
if ( V_26 -> V_13 == 0 ) {
V_26 -> V_13 = V_195 ;
} else if ( V_195 != V_26 -> V_13 &&
( V_195 == V_68 ||
V_26 -> V_13 == V_68 ) ) {
F_2 ( L_84 ) ;
return - V_72 ;
}
} else if ( V_27 == V_40 ) {
if ( F_7 ( V_26 -> V_28 ) != V_36 ||
V_26 -> V_34 != V_135 ) {
F_2 ( L_85 ) ;
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
F_2 ( L_86 ) ;
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
F_2 ( L_87 ) ;
return - V_72 ;
}
V_56 += V_26 -> V_38 + 1 ;
continue;
} else if ( V_47 == V_50 ) {
if ( F_5 ( V_26 -> V_28 ) != V_144 ||
V_26 -> V_13 != 0 ||
V_26 -> V_34 != V_135 ||
V_26 -> V_32 != V_135 ) {
F_2 ( L_88 ) ;
return - V_72 ;
}
V_63 = F_16 ( V_8 , V_135 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( F_23 ( V_2 , V_135 ) ) {
F_2 ( L_89 ) ;
return - V_74 ;
}
V_192:
V_56 = F_9 ( V_2 , & V_53 ) ;
if ( V_56 < 0 ) {
break;
} else {
V_191 = true ;
continue;
}
} else {
V_63 = F_32 ( V_2 , V_26 , & V_56 ) ;
if ( V_63 )
return V_63 ;
}
} else if ( V_27 == V_42 ) {
T_1 V_159 = F_7 ( V_26 -> V_28 ) ;
if ( V_159 == V_43 || V_159 == V_44 ) {
V_63 = F_36 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
} else if ( V_159 == V_45 ) {
V_63 = F_34 ( V_2 , V_26 ) ;
if ( V_63 )
return V_63 ;
V_56 ++ ;
} else {
F_2 ( L_90 ) ;
return - V_72 ;
}
} else {
F_2 ( L_91 , V_27 ) ;
return - V_72 ;
}
V_56 ++ ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_89 -> V_175 ;
int V_176 = V_2 -> V_89 -> V_167 ;
int V_5 , V_196 ;
for ( V_5 = 0 ; V_5 < V_176 ; V_5 ++ , V_26 ++ ) {
if ( F_4 ( V_26 -> V_28 ) == V_41 &&
( F_7 ( V_26 -> V_28 ) != V_36 || V_26 -> V_13 != 0 ) ) {
F_2 ( L_92 ) ;
return - V_72 ;
}
if ( F_4 ( V_26 -> V_28 ) == V_35 &&
( ( F_7 ( V_26 -> V_28 ) != V_36 &&
F_7 ( V_26 -> V_28 ) != V_39 ) || V_26 -> V_13 != 0 ) ) {
F_2 ( L_93 ) ;
return - V_72 ;
}
if ( V_26 [ 0 ] . V_28 == ( V_42 | V_45 | V_80 ) ) {
struct V_86 * V_87 ;
struct V_197 V_198 ;
if ( V_5 == V_176 - 1 || V_26 [ 1 ] . V_28 != 0 ||
V_26 [ 1 ] . V_32 != 0 || V_26 [ 1 ] . V_34 != 0 ||
V_26 [ 1 ] . V_38 != 0 ) {
F_2 ( L_94 ) ;
return - V_72 ;
}
if ( V_26 -> V_34 == 0 )
goto V_199;
if ( V_26 -> V_34 != V_154 ) {
F_2 ( L_95 ) ;
return - V_72 ;
}
V_198 = F_44 ( V_26 -> V_13 ) ;
V_87 = F_45 ( V_198 ) ;
if ( F_46 ( V_87 ) ) {
F_2 ( L_96 ,
V_26 -> V_13 ) ;
F_47 ( V_198 ) ;
return F_48 ( V_87 ) ;
}
V_26 [ 0 ] . V_13 = ( T_2 ) ( unsigned long ) V_87 ;
V_26 [ 1 ] . V_13 = ( ( T_3 ) ( unsigned long ) V_87 ) >> 32 ;
for ( V_196 = 0 ; V_196 < V_2 -> V_200 ; V_196 ++ )
if ( V_2 -> V_201 [ V_196 ] == V_87 ) {
F_47 ( V_198 ) ;
goto V_199;
}
if ( V_2 -> V_200 >= V_202 ) {
F_47 ( V_198 ) ;
return - V_171 ;
}
V_2 -> V_201 [ V_2 -> V_200 ++ ] = V_87 ;
F_49 ( V_87 , false ) ;
F_47 ( V_198 ) ;
V_199:
V_26 ++ ;
V_5 ++ ;
}
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_200 ; V_5 ++ )
F_51 ( V_2 -> V_201 [ V_5 ] ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_89 -> V_175 ;
int V_176 = V_2 -> V_89 -> V_167 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_176 ; V_5 ++ , V_26 ++ )
if ( V_26 -> V_28 == ( V_42 | V_45 | V_80 ) )
V_26 -> V_34 = 0 ;
}
static void F_53 ( struct V_203 * V_89 , int V_204 , int V_205 )
{
struct V_25 * V_26 = V_89 -> V_175 ;
int V_176 = V_89 -> V_167 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_176 ; V_5 ++ , V_26 ++ ) {
if ( F_4 ( V_26 -> V_28 ) != V_46 ||
F_6 ( V_26 -> V_28 ) == V_48 ||
F_6 ( V_26 -> V_28 ) == V_50 )
continue;
if ( V_5 < V_204 && V_5 + V_26 -> V_38 + 1 > V_204 )
V_26 -> V_38 += V_205 ;
else if ( V_5 > V_204 + V_205 && V_5 + V_26 -> V_38 + 1 <= V_204 + V_205 )
V_26 -> V_38 -= V_205 ;
}
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_89 -> V_175 ;
int V_176 = V_2 -> V_89 -> V_167 ;
struct V_25 V_206 [ 16 ] ;
struct V_203 * V_207 ;
T_2 V_208 ;
int V_5 ;
enum V_88 type ;
if ( ! V_2 -> V_89 -> V_90 -> V_91 -> V_209 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_176 ; V_5 ++ , V_26 ++ ) {
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
V_208 = V_2 -> V_89 -> V_90 -> V_91 ->
V_209 ( type , V_26 -> V_32 , V_26 -> V_34 ,
V_26 -> V_38 , V_206 , V_2 -> V_89 ) ;
if ( V_208 == 0 || V_208 >= F_29 ( V_206 ) ) {
F_2 ( L_97 ) ;
return - V_72 ;
}
if ( V_208 == 1 ) {
memcpy ( V_26 , V_206 , sizeof( * V_26 ) ) ;
continue;
}
V_176 += V_208 - 1 ;
V_207 = F_55 ( V_2 -> V_89 ,
F_56 ( V_176 ) ,
V_189 ) ;
if ( ! V_207 )
return - V_178 ;
V_207 -> V_167 = V_176 ;
memmove ( V_207 -> V_175 + V_5 + V_208 , V_207 -> V_174 + V_5 + 1 ,
sizeof( * V_26 ) * ( V_176 - V_5 - V_208 ) ) ;
memcpy ( V_207 -> V_175 + V_5 , V_206 , sizeof( * V_26 ) * V_208 ) ;
F_53 ( V_207 , V_5 , V_208 - 1 ) ;
V_2 -> V_89 = V_207 ;
V_26 = V_207 -> V_175 + V_5 + V_208 - 1 ;
V_5 += V_208 - 1 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_186 * V_188 , * V_210 ;
int V_5 ;
if ( ! V_2 -> V_168 )
return;
for ( V_5 = 0 ; V_5 < V_2 -> V_89 -> V_167 ; V_5 ++ ) {
V_188 = V_2 -> V_168 [ V_5 ] ;
if ( V_188 )
while ( V_188 != V_169 ) {
V_210 = V_188 -> V_59 ;
F_10 ( V_188 ) ;
V_188 = V_210 ;
}
}
F_10 ( V_2 -> V_168 ) ;
}
int F_58 ( struct V_203 * * V_89 , union V_211 * V_212 )
{
char T_4 * V_213 = NULL ;
struct V_1 * V_2 ;
int V_177 = - V_72 ;
if ( ( * V_89 ) -> V_167 <= 0 || ( * V_89 ) -> V_167 > V_214 )
return - V_171 ;
V_2 = F_59 ( sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_2 )
return - V_178 ;
V_2 -> V_89 = * V_89 ;
F_60 ( & V_215 ) ;
if ( V_212 -> V_152 || V_212 -> V_216 || V_212 -> V_217 ) {
V_152 = V_212 -> V_152 ;
V_213 = ( char T_4 * ) ( unsigned long ) V_212 -> V_216 ;
V_217 = V_212 -> V_217 ;
V_218 = 0 ;
V_177 = - V_72 ;
if ( V_217 < 128 || V_217 > V_219 >> 8 ||
V_152 == 0 || V_213 == NULL )
goto V_220;
V_177 = - V_178 ;
V_216 = F_61 ( V_217 ) ;
if ( ! V_216 )
goto V_220;
} else {
V_152 = 0 ;
}
V_177 = F_43 ( V_2 ) ;
if ( V_177 < 0 )
goto V_221;
V_2 -> V_168 = F_39 ( V_2 -> V_89 -> V_167 ,
sizeof( struct V_186 * ) ,
V_189 ) ;
V_177 = - V_178 ;
if ( ! V_2 -> V_168 )
goto V_221;
V_177 = F_38 ( V_2 ) ;
if ( V_177 < 0 )
goto V_221;
V_2 -> V_93 = F_62 ( V_222 ) ;
V_177 = F_42 ( V_2 ) ;
V_221:
while ( F_9 ( V_2 , NULL ) >= 0 ) ;
F_57 ( V_2 ) ;
if ( V_177 == 0 )
V_177 = F_54 ( V_2 ) ;
if ( V_152 && V_218 >= V_217 - 1 ) {
F_15 ( V_218 >= V_217 ) ;
V_177 = - V_223 ;
}
if ( V_152 && F_63 ( V_213 , V_216 , V_218 + 1 ) != 0 ) {
V_177 = - V_110 ;
goto V_224;
}
if ( V_177 == 0 && V_2 -> V_200 ) {
V_2 -> V_89 -> V_90 -> V_201 = F_64 ( V_2 -> V_200 ,
sizeof( V_2 -> V_201 [ 0 ] ) ,
V_62 ) ;
if ( ! V_2 -> V_89 -> V_90 -> V_201 ) {
V_177 = - V_178 ;
goto V_224;
}
memcpy ( V_2 -> V_89 -> V_90 -> V_201 , V_2 -> V_201 ,
sizeof( V_2 -> V_201 [ 0 ] ) * V_2 -> V_200 ) ;
V_2 -> V_89 -> V_90 -> V_200 = V_2 -> V_200 ;
F_52 ( V_2 ) ;
}
V_224:
if ( V_152 )
F_65 ( V_216 ) ;
V_220:
if ( ! V_2 -> V_89 -> V_90 -> V_201 )
F_50 ( V_2 ) ;
* V_89 = V_2 -> V_89 ;
F_10 ( V_2 ) ;
F_66 ( & V_215 ) ;
return V_177 ;
}
