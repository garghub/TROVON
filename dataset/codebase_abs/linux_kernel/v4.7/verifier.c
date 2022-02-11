static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_5 V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_4 = & V_2 -> V_9 [ V_7 ] ;
V_6 = V_4 -> type ;
if ( V_6 == V_10 )
continue;
F_2 ( L_1 , V_7 , V_11 [ V_6 ] ) ;
if ( V_6 == V_12 || V_6 == V_13 )
F_2 ( L_2 , V_4 -> V_14 ) ;
else if ( V_6 == V_15 )
F_2 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_18 ) ;
else if ( V_6 == V_19 && V_4 -> V_14 )
F_2 ( L_2 , V_4 -> V_14 ) ;
else if ( V_6 == V_20 || V_6 == V_21 ||
V_6 == V_22 )
F_2 ( L_4 ,
V_4 -> V_23 -> V_24 ,
V_4 -> V_23 -> V_25 ) ;
}
for ( V_7 = 0 ; V_7 < V_26 ; V_7 += V_27 ) {
if ( V_2 -> V_28 [ V_7 ] == V_29 )
F_2 ( L_5 , - V_26 + V_7 ,
V_11 [ V_2 -> V_30 [ V_7 / V_27 ] . type ] ) ;
}
F_2 ( L_6 ) ;
}
static void F_3 ( struct V_31 * V_32 )
{
T_1 V_33 = F_4 ( V_32 -> V_34 ) ;
if ( V_33 == V_35 || V_33 == V_36 ) {
if ( F_5 ( V_32 -> V_34 ) == V_37 )
F_2 ( L_7 ,
V_32 -> V_34 , V_33 == V_35 ? L_8 : L_9 ,
V_32 -> V_38 ,
V_39 [ F_6 ( V_32 -> V_34 ) >> 4 ] ,
V_33 == V_35 ? L_8 : L_9 ,
V_32 -> V_40 ) ;
else
F_2 ( L_10 ,
V_32 -> V_34 , V_33 == V_35 ? L_8 : L_9 ,
V_32 -> V_38 ,
V_39 [ F_6 ( V_32 -> V_34 ) >> 4 ] ,
V_33 == V_35 ? L_8 : L_9 ,
V_32 -> V_14 ) ;
} else if ( V_33 == V_41 ) {
if ( F_7 ( V_32 -> V_34 ) == V_42 )
F_2 ( L_11 ,
V_32 -> V_34 ,
V_43 [ F_8 ( V_32 -> V_34 ) >> 3 ] ,
V_32 -> V_38 ,
V_32 -> V_17 , V_32 -> V_40 ) ;
else if ( F_7 ( V_32 -> V_34 ) == V_44 )
F_2 ( L_12 ,
V_32 -> V_34 ,
V_43 [ F_8 ( V_32 -> V_34 ) >> 3 ] ,
V_32 -> V_38 , V_32 -> V_17 ,
V_32 -> V_40 ) ;
else
F_2 ( L_13 , V_32 -> V_34 ) ;
} else if ( V_33 == V_45 ) {
if ( F_7 ( V_32 -> V_34 ) != V_42 ) {
F_2 ( L_14 , V_32 -> V_34 ) ;
return;
}
F_2 ( L_15 ,
V_32 -> V_34 ,
V_43 [ F_8 ( V_32 -> V_34 ) >> 3 ] ,
V_32 -> V_38 ,
V_32 -> V_17 , V_32 -> V_14 ) ;
} else if ( V_33 == V_46 ) {
if ( F_7 ( V_32 -> V_34 ) != V_42 ) {
F_2 ( L_16 , V_32 -> V_34 ) ;
return;
}
F_2 ( L_17 ,
V_32 -> V_34 , V_32 -> V_38 ,
V_43 [ F_8 ( V_32 -> V_34 ) >> 3 ] ,
V_32 -> V_40 , V_32 -> V_17 ) ;
} else if ( V_33 == V_47 ) {
if ( F_7 ( V_32 -> V_34 ) == V_48 ) {
F_2 ( L_18 ,
V_32 -> V_34 ,
V_43 [ F_8 ( V_32 -> V_34 ) >> 3 ] ,
V_32 -> V_14 ) ;
} else if ( F_7 ( V_32 -> V_34 ) == V_49 ) {
F_2 ( L_19 ,
V_32 -> V_34 ,
V_43 [ F_8 ( V_32 -> V_34 ) >> 3 ] ,
V_32 -> V_40 , V_32 -> V_14 ) ;
} else if ( F_7 ( V_32 -> V_34 ) == V_50 ) {
F_2 ( L_20 ,
V_32 -> V_34 , V_32 -> V_38 , V_32 -> V_14 ) ;
} else {
F_2 ( L_21 , V_32 -> V_34 ) ;
return;
}
} else if ( V_33 == V_51 ) {
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
if ( V_52 == V_53 ) {
F_2 ( L_22 , V_32 -> V_34 , V_32 -> V_14 ) ;
} else if ( V_32 -> V_34 == ( V_51 | V_54 ) ) {
F_2 ( L_23 ,
V_32 -> V_34 , V_32 -> V_17 ) ;
} else if ( V_32 -> V_34 == ( V_51 | V_55 ) ) {
F_2 ( L_24 , V_32 -> V_34 ) ;
} else if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
F_2 ( L_25 ,
V_32 -> V_34 , V_32 -> V_38 ,
V_56 [ F_6 ( V_32 -> V_34 ) >> 4 ] ,
V_32 -> V_40 , V_32 -> V_17 ) ;
} else {
F_2 ( L_26 ,
V_32 -> V_34 , V_32 -> V_38 ,
V_56 [ F_6 ( V_32 -> V_34 ) >> 4 ] ,
V_32 -> V_14 , V_32 -> V_17 ) ;
}
} else {
F_2 ( L_27 , V_32 -> V_34 , V_57 [ V_33 ] ) ;
}
}
static int F_9 ( struct V_58 * V_59 , int * V_60 )
{
struct V_61 * V_62 ;
int V_63 ;
if ( V_59 -> V_64 == NULL )
return - 1 ;
memcpy ( & V_59 -> V_65 , & V_59 -> V_64 -> V_66 , sizeof( V_59 -> V_65 ) ) ;
V_63 = V_59 -> V_64 -> V_63 ;
if ( V_60 )
* V_60 = V_59 -> V_64 -> V_60 ;
V_62 = V_59 -> V_64 -> V_67 ;
F_10 ( V_59 -> V_64 ) ;
V_59 -> V_64 = V_62 ;
V_59 -> V_68 -- ;
return V_63 ;
}
static struct V_1 * F_11 ( struct V_58 * V_59 , int V_63 ,
int V_60 )
{
struct V_61 * V_62 ;
V_62 = F_12 ( sizeof( struct V_61 ) , V_69 ) ;
if ( ! V_62 )
goto V_70;
memcpy ( & V_62 -> V_66 , & V_59 -> V_65 , sizeof( V_59 -> V_65 ) ) ;
V_62 -> V_63 = V_63 ;
V_62 -> V_60 = V_60 ;
V_62 -> V_67 = V_59 -> V_64 ;
V_59 -> V_64 = V_62 ;
V_59 -> V_68 ++ ;
if ( V_59 -> V_68 > V_71 ) {
F_2 ( L_28 ) ;
goto V_70;
}
return & V_62 -> V_66 ;
V_70:
while ( F_9 ( V_59 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_13 ( struct V_3 * V_9 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_9 [ V_7 ] . type = V_10 ;
V_9 [ V_7 ] . V_14 = 0 ;
}
V_9 [ V_72 ] . type = V_73 ;
V_9 [ V_74 ] . type = V_75 ;
}
static void F_14 ( struct V_3 * V_9 , T_2 V_76 )
{
F_15 ( V_76 >= V_8 ) ;
V_9 [ V_76 ] . type = V_19 ;
V_9 [ V_76 ] . V_14 = 0 ;
}
static int F_16 ( struct V_3 * V_9 , T_2 V_76 ,
enum V_77 V_6 )
{
if ( V_76 >= V_8 ) {
F_2 ( L_29 , V_76 ) ;
return - V_78 ;
}
if ( V_6 == V_79 ) {
if ( V_9 [ V_76 ] . type == V_10 ) {
F_2 ( L_30 , V_76 ) ;
return - V_80 ;
}
} else {
if ( V_76 == V_72 ) {
F_2 ( L_31 ) ;
return - V_80 ;
}
if ( V_6 == V_81 )
F_14 ( V_9 , V_76 ) ;
}
return 0 ;
}
static int F_17 ( int V_82 )
{
if ( V_82 == V_83 )
return 4 ;
else if ( V_82 == V_84 )
return 2 ;
else if ( V_82 == V_85 )
return 1 ;
else if ( V_82 == V_86 )
return 8 ;
else
return - V_78 ;
}
static bool F_18 ( enum V_5 type )
{
switch ( type ) {
case V_21 :
case V_22 :
case V_13 :
case V_75 :
case V_15 :
case V_87 :
case V_73 :
case V_20 :
return true ;
default:
return false ;
}
}
static int F_19 ( struct V_1 * V_2 , int V_17 , int V_88 ,
int V_89 )
{
int V_7 ;
if ( V_89 >= 0 &&
F_18 ( V_2 -> V_9 [ V_89 ] . type ) ) {
if ( V_88 != V_27 ) {
F_2 ( L_32 ) ;
return - V_80 ;
}
V_2 -> V_30 [ ( V_26 + V_17 ) / V_27 ] =
V_2 -> V_9 [ V_89 ] ;
for ( V_7 = 0 ; V_7 < V_27 ; V_7 ++ )
V_2 -> V_28 [ V_26 + V_17 + V_7 ] = V_29 ;
} else {
V_2 -> V_30 [ ( V_26 + V_17 ) / V_27 ] =
(struct V_3 ) {} ;
for ( V_7 = 0 ; V_7 < V_88 ; V_7 ++ )
V_2 -> V_28 [ V_26 + V_17 + V_7 ] = V_90 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_17 , int V_88 ,
int V_89 )
{
T_1 * V_91 ;
int V_7 ;
V_91 = & V_2 -> V_28 [ V_26 + V_17 ] ;
if ( V_91 [ 0 ] == V_29 ) {
if ( V_88 != V_27 ) {
F_2 ( L_32 ) ;
return - V_80 ;
}
for ( V_7 = 1 ; V_7 < V_27 ; V_7 ++ ) {
if ( V_91 [ V_7 ] != V_29 ) {
F_2 ( L_33 ) ;
return - V_80 ;
}
}
if ( V_89 >= 0 )
V_2 -> V_9 [ V_89 ] =
V_2 -> V_30 [ ( V_26 + V_17 ) / V_27 ] ;
return 0 ;
} else {
for ( V_7 = 0 ; V_7 < V_88 ; V_7 ++ ) {
if ( V_91 [ V_7 ] != V_90 ) {
F_2 ( L_34 ,
V_17 , V_7 , V_88 ) ;
return - V_80 ;
}
}
if ( V_89 >= 0 )
F_14 ( V_2 -> V_9 , V_89 ) ;
return 0 ;
}
}
static int F_21 ( struct V_58 * V_59 , T_2 V_76 , int V_17 ,
int V_88 )
{
struct V_92 * V_93 = V_59 -> V_65 . V_9 [ V_76 ] . V_23 ;
if ( V_17 < 0 || V_17 + V_88 > V_93 -> V_25 ) {
F_2 ( L_35 ,
V_93 -> V_25 , V_17 , V_88 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_22 ( struct V_58 * V_59 , T_2 V_76 , int V_17 ,
int V_88 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_4 = & V_9 [ V_76 ] ;
V_17 += V_4 -> V_17 ;
if ( V_17 < 0 || V_17 + V_88 > V_4 -> V_18 ) {
F_2 ( L_36 ,
V_17 , V_88 , V_76 , V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_18 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_23 ( struct V_58 * V_59 , int V_17 , int V_88 ,
enum V_94 V_6 , enum V_5 * V_95 )
{
if ( V_59 -> V_96 -> V_97 -> V_98 -> V_99 &&
V_59 -> V_96 -> V_97 -> V_98 -> V_99 ( V_17 , V_88 , V_6 , V_95 ) ) {
if ( V_59 -> V_96 -> V_97 -> V_100 < V_17 + V_88 )
V_59 -> V_96 -> V_97 -> V_100 = V_17 + V_88 ;
return 0 ;
}
F_2 ( L_37 , V_17 , V_88 ) ;
return - V_80 ;
}
static bool F_24 ( struct V_58 * V_59 , int V_76 )
{
if ( V_59 -> V_101 )
return false ;
switch ( V_59 -> V_65 . V_9 [ V_76 ] . type ) {
case V_19 :
case V_12 :
return false ;
default:
return true ;
}
}
static int F_25 ( struct V_58 * V_59 , struct V_3 * V_4 ,
int V_17 , int V_88 )
{
if ( V_4 -> type != V_15 ) {
if ( V_17 % V_88 != 0 ) {
F_2 ( L_38 , V_17 , V_88 ) ;
return - V_80 ;
} else {
return 0 ;
}
}
switch ( V_59 -> V_96 -> type ) {
case V_102 :
case V_103 :
break;
default:
F_2 ( L_39 ) ;
return - V_80 ;
}
if ( F_26 ( V_104 ) )
return 0 ;
if ( V_4 -> V_16 && V_88 != 1 ) {
F_2 ( L_40 ) ;
return - V_80 ;
}
if ( ( V_105 + V_4 -> V_17 + V_17 ) % V_88 != 0 ) {
F_2 ( L_41 ,
V_105 , V_4 -> V_17 , V_17 , V_88 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_27 ( struct V_58 * V_59 , T_2 V_76 , int V_17 ,
int V_82 , enum V_94 V_6 ,
int V_89 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_3 * V_4 = & V_2 -> V_9 [ V_76 ] ;
int V_88 , V_70 = 0 ;
if ( V_4 -> type == V_13 )
V_17 += V_4 -> V_14 ;
V_88 = F_17 ( V_82 ) ;
if ( V_88 < 0 )
return V_88 ;
V_70 = F_25 ( V_59 , V_4 , V_17 , V_88 ) ;
if ( V_70 )
return V_70 ;
if ( V_4 -> type == V_21 ) {
if ( V_6 == V_106 && V_89 >= 0 &&
F_24 ( V_59 , V_89 ) ) {
F_2 ( L_42 , V_89 ) ;
return - V_80 ;
}
V_70 = F_21 ( V_59 , V_76 , V_17 , V_88 ) ;
if ( ! V_70 && V_6 == V_107 && V_89 >= 0 )
F_14 ( V_2 -> V_9 , V_89 ) ;
} else if ( V_4 -> type == V_75 ) {
enum V_5 V_95 = V_19 ;
if ( V_6 == V_106 && V_89 >= 0 &&
F_24 ( V_59 , V_89 ) ) {
F_2 ( L_43 , V_89 ) ;
return - V_80 ;
}
V_70 = F_23 ( V_59 , V_17 , V_88 , V_6 , & V_95 ) ;
if ( ! V_70 && V_6 == V_107 && V_89 >= 0 ) {
F_14 ( V_2 -> V_9 , V_89 ) ;
if ( V_59 -> V_101 )
V_2 -> V_9 [ V_89 ] . type = V_95 ;
}
} else if ( V_4 -> type == V_73 || V_4 -> type == V_13 ) {
if ( V_17 >= 0 || V_17 < - V_26 ) {
F_2 ( L_44 , V_17 , V_88 ) ;
return - V_80 ;
}
if ( V_6 == V_106 ) {
if ( ! V_59 -> V_101 &&
V_2 -> V_28 [ V_26 + V_17 ] == V_29 &&
V_88 != V_27 ) {
F_2 ( L_45 ) ;
return - V_80 ;
}
V_70 = F_19 ( V_2 , V_17 , V_88 , V_89 ) ;
} else {
V_70 = F_20 ( V_2 , V_17 , V_88 , V_89 ) ;
}
} else if ( V_2 -> V_9 [ V_76 ] . type == V_15 ) {
if ( V_6 == V_106 ) {
F_2 ( L_46 ) ;
return - V_80 ;
}
V_70 = F_22 ( V_59 , V_76 , V_17 , V_88 ) ;
if ( ! V_70 && V_6 == V_107 && V_89 >= 0 )
F_14 ( V_2 -> V_9 , V_89 ) ;
} else {
F_2 ( L_47 ,
V_76 , V_11 [ V_4 -> type ] ) ;
return - V_80 ;
}
if ( ! V_70 && V_88 <= 2 && V_89 >= 0 && V_59 -> V_101 &&
V_2 -> V_9 [ V_89 ] . type == V_19 ) {
V_2 -> V_9 [ V_89 ] . V_14 = 64 - V_88 * 8 ;
}
return V_70 ;
}
static int F_28 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
int V_70 ;
if ( ( F_8 ( V_32 -> V_34 ) != V_83 && F_8 ( V_32 -> V_34 ) != V_86 ) ||
V_32 -> V_14 != 0 ) {
F_2 ( L_48 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_27 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_107 , - 1 ) ;
if ( V_70 )
return V_70 ;
return F_27 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_106 , - 1 ) ;
}
static int F_29 ( struct V_58 * V_59 , int V_76 ,
int V_108 , bool V_109 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_3 * V_9 = V_2 -> V_9 ;
int V_17 , V_7 ;
if ( V_9 [ V_76 ] . type != V_13 ) {
if ( V_109 && V_108 == 0 &&
V_9 [ V_76 ] . type == V_12 &&
V_9 [ V_76 ] . V_14 == 0 )
return 0 ;
F_2 ( L_49 , V_76 ,
V_11 [ V_9 [ V_76 ] . type ] ,
V_11 [ V_13 ] ) ;
return - V_80 ;
}
V_17 = V_9 [ V_76 ] . V_14 ;
if ( V_17 >= 0 || V_17 < - V_26 || V_17 + V_108 > 0 ||
V_108 <= 0 ) {
F_2 ( L_50 ,
V_76 , V_17 , V_108 ) ;
return - V_80 ;
}
if ( V_111 && V_111 -> V_112 ) {
V_111 -> V_108 = V_108 ;
V_111 -> V_76 = V_76 ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ ) {
if ( V_2 -> V_28 [ V_26 + V_17 + V_7 ] != V_90 ) {
F_2 ( L_51 ,
V_17 , V_7 , V_108 ) ;
return - V_80 ;
}
}
return 0 ;
}
static int F_30 ( struct V_58 * V_59 , T_2 V_76 ,
enum V_113 V_114 ,
struct V_110 * V_111 )
{
struct V_3 * V_4 = V_59 -> V_65 . V_9 + V_76 ;
enum V_5 V_115 ;
int V_70 = 0 ;
if ( V_114 == V_116 )
return 0 ;
if ( V_4 -> type == V_10 ) {
F_2 ( L_30 , V_76 ) ;
return - V_80 ;
}
if ( V_114 == V_117 ) {
if ( F_24 ( V_59 , V_76 ) ) {
F_2 ( L_52 , V_76 ) ;
return - V_80 ;
}
return 0 ;
}
if ( V_114 == V_118 ||
V_114 == V_119 ) {
V_115 = V_13 ;
} else if ( V_114 == V_120 ||
V_114 == V_121 ) {
V_115 = V_12 ;
} else if ( V_114 == V_122 ) {
V_115 = V_20 ;
} else if ( V_114 == V_123 ) {
V_115 = V_75 ;
} else if ( V_114 == V_124 ||
V_114 == V_125 ) {
V_115 = V_13 ;
if ( V_4 -> type == V_12 && V_4 -> V_14 == 0 )
V_115 = V_12 ;
V_111 -> V_112 = V_114 == V_125 ;
} else {
F_2 ( L_53 , V_114 ) ;
return - V_126 ;
}
if ( V_4 -> type != V_115 ) {
F_2 ( L_49 , V_76 ,
V_11 [ V_4 -> type ] , V_11 [ V_115 ] ) ;
return - V_80 ;
}
if ( V_114 == V_122 ) {
V_111 -> V_23 = V_4 -> V_23 ;
} else if ( V_114 == V_118 ) {
if ( ! V_111 -> V_23 ) {
F_2 ( L_54 ) ;
return - V_80 ;
}
V_70 = F_29 ( V_59 , V_76 , V_111 -> V_23 -> V_24 ,
false , NULL ) ;
} else if ( V_114 == V_119 ) {
if ( ! V_111 -> V_23 ) {
F_2 ( L_55 ) ;
return - V_80 ;
}
V_70 = F_29 ( V_59 , V_76 ,
V_111 -> V_23 -> V_25 ,
false , NULL ) ;
} else if ( V_114 == V_120 ||
V_114 == V_121 ) {
bool V_109 = ( V_114 == V_121 ) ;
if ( V_76 == 0 ) {
F_2 ( L_56 ) ;
return - V_80 ;
}
V_70 = F_29 ( V_59 , V_76 - 1 , V_4 -> V_14 ,
V_109 , V_111 ) ;
}
return V_70 ;
}
static int F_31 ( struct V_92 * V_93 , int V_127 )
{
if ( ! V_93 )
return 0 ;
switch ( V_93 -> V_128 ) {
case V_129 :
if ( V_127 != V_130 )
goto error;
break;
case V_131 :
if ( V_127 != V_132 &&
V_127 != V_133 )
goto error;
break;
case V_134 :
if ( V_127 != V_135 )
goto error;
break;
default:
break;
}
switch ( V_127 ) {
case V_130 :
if ( V_93 -> V_128 != V_129 )
goto error;
break;
case V_132 :
case V_133 :
if ( V_93 -> V_128 != V_131 )
goto error;
break;
case V_135 :
if ( V_93 -> V_128 != V_134 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_2 ( L_57 ,
V_93 -> V_128 , V_127 ) ;
return - V_78 ;
}
static int F_32 ( const struct V_136 * V_137 )
{
int V_138 = 0 ;
if ( V_137 -> V_139 == V_125 )
V_138 ++ ;
if ( V_137 -> V_140 == V_125 )
V_138 ++ ;
if ( V_137 -> V_141 == V_125 )
V_138 ++ ;
if ( V_137 -> V_142 == V_125 )
V_138 ++ ;
if ( V_137 -> V_143 == V_125 )
V_138 ++ ;
return V_138 > 1 ? - V_78 : 0 ;
}
static void F_33 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_3 * V_9 = V_2 -> V_9 , * V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
if ( V_9 [ V_7 ] . type == V_15 ||
V_9 [ V_7 ] . type == V_87 )
F_14 ( V_9 , V_7 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 += V_27 ) {
if ( V_2 -> V_28 [ V_7 ] != V_29 )
continue;
V_4 = & V_2 -> V_30 [ V_7 / V_27 ] ;
if ( V_4 -> type != V_15 &&
V_4 -> type != V_87 )
continue;
V_4 -> type = V_19 ;
V_4 -> V_14 = 0 ;
}
}
static int F_34 ( struct V_58 * V_59 , int V_127 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
const struct V_136 * V_137 = NULL ;
struct V_3 * V_9 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_110 V_111 ;
bool V_144 ;
int V_7 , V_70 ;
if ( V_127 < 0 || V_127 >= V_145 ) {
F_2 ( L_58 , V_127 ) ;
return - V_78 ;
}
if ( V_59 -> V_96 -> V_97 -> V_98 -> V_146 )
V_137 = V_59 -> V_96 -> V_97 -> V_98 -> V_146 ( V_127 ) ;
if ( ! V_137 ) {
F_2 ( L_59 , V_127 ) ;
return - V_78 ;
}
if ( ! V_59 -> V_96 -> V_147 && V_137 -> V_148 ) {
F_2 ( L_60 ) ;
return - V_78 ;
}
V_144 = F_35 ( V_137 -> V_149 ) ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_70 = F_32 ( V_137 ) ;
if ( V_70 ) {
F_2 ( L_61 , V_127 ) ;
return V_70 ;
}
V_70 = F_30 ( V_59 , V_74 , V_137 -> V_139 , & V_111 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_30 ( V_59 , V_150 , V_137 -> V_140 , & V_111 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_30 ( V_59 , V_151 , V_137 -> V_141 , & V_111 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_30 ( V_59 , V_152 , V_137 -> V_142 , & V_111 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_30 ( V_59 , V_153 , V_137 -> V_143 , & V_111 ) ;
if ( V_70 )
return V_70 ;
for ( V_7 = 0 ; V_7 < V_111 . V_108 ; V_7 ++ ) {
V_70 = F_27 ( V_59 , V_111 . V_76 , V_7 , V_85 , V_106 , - 1 ) ;
if ( V_70 )
return V_70 ;
}
for ( V_7 = 0 ; V_7 < V_154 ; V_7 ++ ) {
V_4 = V_9 + V_155 [ V_7 ] ;
V_4 -> type = V_10 ;
V_4 -> V_14 = 0 ;
}
if ( V_137 -> V_156 == V_157 ) {
V_9 [ V_158 ] . type = V_19 ;
} else if ( V_137 -> V_156 == V_159 ) {
V_9 [ V_158 ] . type = V_10 ;
} else if ( V_137 -> V_156 == V_160 ) {
V_9 [ V_158 ] . type = V_22 ;
if ( V_111 . V_23 == NULL ) {
F_2 ( L_62 ) ;
return - V_78 ;
}
V_9 [ V_158 ] . V_23 = V_111 . V_23 ;
} else {
F_2 ( L_63 ,
V_137 -> V_156 , V_127 ) ;
return - V_78 ;
}
V_70 = F_31 ( V_111 . V_23 , V_127 ) ;
if ( V_70 )
return V_70 ;
if ( V_144 )
F_33 ( V_59 ) ;
return 0 ;
}
static int F_36 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_38 = & V_9 [ V_32 -> V_38 ] ;
struct V_3 * V_40 = & V_9 [ V_32 -> V_40 ] ;
struct V_3 V_161 ;
T_3 V_14 ;
if ( F_5 ( V_32 -> V_34 ) == V_162 ) {
V_14 = V_32 -> V_14 ;
V_163:
if ( V_14 <= 0 ) {
F_2 ( L_64 ) ;
return - V_80 ;
}
if ( V_14 >= V_164 ||
V_14 + V_38 -> V_17 >= V_164 ) {
F_2 ( L_65 ,
V_14 ) ;
return - V_80 ;
}
V_38 -> V_17 += V_14 ;
} else {
if ( V_40 -> type == V_15 ) {
V_161 = * V_38 ;
* V_38 = * V_40 ;
V_40 = & V_161 ;
}
if ( V_40 -> type == V_12 ) {
V_14 = V_40 -> V_14 ;
goto V_163;
}
if ( V_40 -> type != V_19 ) {
F_2 ( L_66 ,
V_11 [ V_40 -> type ] ) ;
return - V_80 ;
}
if ( V_40 -> V_14 < 48 ) {
F_2 ( L_67 ,
V_40 -> V_14 ) ;
return - V_80 ;
}
V_38 -> V_16 ++ ;
V_38 -> V_17 = 0 ;
V_38 -> V_18 = 0 ;
}
return 0 ;
}
static int F_37 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_38 = & V_9 [ V_32 -> V_38 ] ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
T_4 V_165 ;
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
struct V_3 * V_40 = & V_9 [ V_32 -> V_40 ] ;
if ( V_40 -> type == V_19 && V_40 -> V_14 > 0 &&
V_38 -> V_14 && V_52 == V_166 ) {
V_38 -> V_14 = F_38 ( V_38 -> V_14 , V_40 -> V_14 ) ;
V_38 -> V_14 -- ;
return 0 ;
}
if ( V_40 -> type == V_12 && V_40 -> V_14 > 0 &&
V_38 -> V_14 && V_52 == V_166 ) {
V_165 = F_39 ( ( long long ) V_40 -> V_14 ) ;
V_38 -> V_14 = F_38 ( V_38 -> V_14 , 63 - V_165 ) ;
V_38 -> V_14 -- ;
return 0 ;
}
V_38 -> V_14 = 0 ;
return 0 ;
}
V_165 = F_39 ( ( long long ) V_32 -> V_14 ) ;
if ( V_38 -> V_14 && V_52 == V_167 ) {
V_38 -> V_14 -= V_32 -> V_14 ;
} else if ( V_38 -> V_14 && V_52 == V_168 ) {
V_38 -> V_14 -= V_165 + 1 ;
} else if ( V_52 == V_169 ) {
V_38 -> V_14 = 63 - V_165 ;
} else if ( V_38 -> V_14 && V_52 == V_166 ) {
V_38 -> V_14 = F_38 ( V_38 -> V_14 , 63 - V_165 ) ;
V_38 -> V_14 -- ;
} else if ( V_52 == V_170 ) {
V_38 -> V_14 += V_32 -> V_14 ;
if ( F_40 ( V_38 -> V_14 > 64 ) )
V_38 -> V_14 = 64 ;
} else {
V_38 -> V_14 = 0 ;
}
if ( V_38 -> V_14 < 0 ) {
V_38 -> V_14 = 0 ;
}
return 0 ;
}
static int F_41 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_38 = & V_9 [ V_32 -> V_38 ] ;
struct V_3 * V_40 = & V_9 [ V_32 -> V_40 ] ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
if ( V_52 == V_166 && F_5 ( V_32 -> V_34 ) == V_162 )
V_38 -> V_14 += V_32 -> V_14 ;
else if ( V_52 == V_166 && F_5 ( V_32 -> V_34 ) == V_37 &&
V_40 -> type == V_12 )
V_38 -> V_14 += V_40 -> V_14 ;
else
F_14 ( V_9 , V_32 -> V_38 ) ;
return 0 ;
}
static int F_42 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 , * V_38 ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
int V_70 ;
if ( V_52 == V_171 || V_52 == V_172 ) {
if ( V_52 == V_172 ) {
if ( F_5 ( V_32 -> V_34 ) != 0 ||
V_32 -> V_40 != V_158 ||
V_32 -> V_17 != 0 || V_32 -> V_14 != 0 ) {
F_2 ( L_68 ) ;
return - V_78 ;
}
} else {
if ( V_32 -> V_40 != V_158 || V_32 -> V_17 != 0 ||
( V_32 -> V_14 != 16 && V_32 -> V_14 != 32 && V_32 -> V_14 != 64 ) ) {
F_2 ( L_69 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( F_24 ( V_59 , V_32 -> V_38 ) ) {
F_2 ( L_70 ,
V_32 -> V_38 ) ;
return - V_80 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_81 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_52 == V_173 ) {
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( V_32 -> V_14 != 0 || V_32 -> V_17 != 0 ) {
F_2 ( L_71 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
} else {
if ( V_32 -> V_40 != V_158 || V_32 -> V_17 != 0 ) {
F_2 ( L_71 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_81 ) ;
if ( V_70 )
return V_70 ;
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( F_4 ( V_32 -> V_34 ) == V_36 ) {
V_9 [ V_32 -> V_38 ] = V_9 [ V_32 -> V_40 ] ;
} else {
if ( F_24 ( V_59 , V_32 -> V_40 ) ) {
F_2 ( L_72 ,
V_32 -> V_40 ) ;
return - V_80 ;
}
V_9 [ V_32 -> V_38 ] . type = V_19 ;
V_9 [ V_32 -> V_38 ] . V_23 = NULL ;
}
} else {
V_9 [ V_32 -> V_38 ] . type = V_12 ;
V_9 [ V_32 -> V_38 ] . V_14 = V_32 -> V_14 ;
}
} else if ( V_52 > V_171 ) {
F_2 ( L_73 , V_52 ) ;
return - V_78 ;
} else {
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( V_32 -> V_14 != 0 || V_32 -> V_17 != 0 ) {
F_2 ( L_74 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
} else {
if ( V_32 -> V_40 != V_158 || V_32 -> V_17 != 0 ) {
F_2 ( L_74 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( ( V_52 == V_174 || V_52 == V_175 ) &&
F_5 ( V_32 -> V_34 ) == V_162 && V_32 -> V_14 == 0 ) {
F_2 ( L_75 ) ;
return - V_78 ;
}
if ( ( V_52 == V_167 || V_52 == V_170 ||
V_52 == V_176 ) && F_5 ( V_32 -> V_34 ) == V_162 ) {
int V_88 = F_4 ( V_32 -> V_34 ) == V_36 ? 64 : 32 ;
if ( V_32 -> V_14 < 0 || V_32 -> V_14 >= V_88 ) {
F_2 ( L_76 , V_32 -> V_14 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_177 ) ;
if ( V_70 )
return V_70 ;
V_38 = & V_9 [ V_32 -> V_38 ] ;
if ( V_52 == V_166 && F_4 ( V_32 -> V_34 ) == V_36 &&
V_38 -> type == V_73 && F_5 ( V_32 -> V_34 ) == V_162 ) {
V_38 -> type = V_13 ;
V_38 -> V_14 = V_32 -> V_14 ;
return 0 ;
} else if ( V_52 == V_166 &&
F_4 ( V_32 -> V_34 ) == V_36 &&
( V_38 -> type == V_15 ||
( F_5 ( V_32 -> V_34 ) == V_37 &&
V_9 [ V_32 -> V_40 ] . type == V_15 ) ) ) {
return F_36 ( V_59 , V_32 ) ;
} else if ( F_4 ( V_32 -> V_34 ) == V_36 &&
V_38 -> type == V_19 &&
V_59 -> V_101 ) {
return F_37 ( V_59 , V_32 ) ;
} else if ( F_4 ( V_32 -> V_34 ) == V_36 &&
V_38 -> type == V_12 &&
V_59 -> V_101 ) {
return F_41 ( V_59 , V_32 ) ;
} else if ( F_24 ( V_59 , V_32 -> V_38 ) ) {
F_2 ( L_70 ,
V_32 -> V_38 ) ;
return - V_80 ;
} else if ( F_5 ( V_32 -> V_34 ) == V_37 &&
F_24 ( V_59 , V_32 -> V_40 ) ) {
F_2 ( L_70 ,
V_32 -> V_40 ) ;
return - V_80 ;
}
F_14 ( V_9 , V_32 -> V_38 ) ;
}
return 0 ;
}
static void F_43 ( struct V_58 * V_59 ,
struct V_3 * V_38 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_3 * V_9 = V_2 -> V_9 , * V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
if ( V_9 [ V_7 ] . type == V_15 && V_9 [ V_7 ] . V_16 == V_38 -> V_16 )
V_9 [ V_7 ] . V_18 = V_38 -> V_17 ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 += V_27 ) {
if ( V_2 -> V_28 [ V_7 ] != V_29 )
continue;
V_4 = & V_2 -> V_30 [ V_7 / V_27 ] ;
if ( V_4 -> type == V_15 && V_4 -> V_16 == V_38 -> V_16 )
V_4 -> V_18 = V_38 -> V_17 ;
}
}
static int F_44 ( struct V_58 * V_59 ,
struct V_31 * V_32 , int * V_63 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 , * V_38 ;
struct V_1 * V_178 ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
int V_70 ;
if ( V_52 > V_55 ) {
F_2 ( L_77 , V_52 ) ;
return - V_78 ;
}
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( V_32 -> V_14 != 0 ) {
F_2 ( L_78 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( F_24 ( V_59 , V_32 -> V_40 ) ) {
F_2 ( L_79 ,
V_32 -> V_40 ) ;
return - V_80 ;
}
} else {
if ( V_32 -> V_40 != V_158 ) {
F_2 ( L_78 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_38 = & V_9 [ V_32 -> V_38 ] ;
if ( F_5 ( V_32 -> V_34 ) == V_162 &&
( V_52 == V_179 || V_52 == V_180 ) &&
V_38 -> type == V_12 && V_38 -> V_14 == V_32 -> V_14 ) {
if ( V_52 == V_179 ) {
* V_63 += V_32 -> V_17 ;
return 0 ;
} else {
return 0 ;
}
}
V_178 = F_11 ( V_59 , * V_63 + V_32 -> V_17 + 1 , * V_63 ) ;
if ( ! V_178 )
return - V_126 ;
if ( F_5 ( V_32 -> V_34 ) == V_162 &&
V_32 -> V_14 == 0 && ( V_52 == V_179 || V_52 == V_180 ) &&
V_38 -> type == V_22 ) {
if ( V_52 == V_179 ) {
V_9 [ V_32 -> V_38 ] . type = V_21 ;
F_14 ( V_178 -> V_9 ,
V_32 -> V_38 ) ;
} else {
V_178 -> V_9 [ V_32 -> V_38 ] . type = V_21 ;
F_14 ( V_9 , V_32 -> V_38 ) ;
}
} else if ( F_5 ( V_32 -> V_34 ) == V_37 && V_52 == V_181 &&
V_38 -> type == V_15 &&
V_9 [ V_32 -> V_40 ] . type == V_87 ) {
F_43 ( V_59 , V_38 ) ;
} else if ( F_24 ( V_59 , V_32 -> V_38 ) ) {
F_2 ( L_79 , V_32 -> V_38 ) ;
return - V_80 ;
}
if ( V_182 )
F_1 ( & V_59 -> V_65 ) ;
return 0 ;
}
static struct V_92 * F_45 ( struct V_31 * V_32 )
{
T_5 V_183 = ( ( T_5 ) ( T_2 ) V_32 [ 0 ] . V_14 ) | ( ( T_5 ) ( T_2 ) V_32 [ 1 ] . V_14 ) << 32 ;
return (struct V_92 * ) ( unsigned long ) V_183 ;
}
static int F_46 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
int V_70 ;
if ( F_8 ( V_32 -> V_34 ) != V_86 ) {
F_2 ( L_80 ) ;
return - V_78 ;
}
if ( V_32 -> V_17 != 0 ) {
F_2 ( L_81 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_81 ) ;
if ( V_70 )
return V_70 ;
if ( V_32 -> V_40 == 0 )
return 0 ;
F_15 ( V_32 -> V_40 != V_184 ) ;
V_9 [ V_32 -> V_38 ] . type = V_20 ;
V_9 [ V_32 -> V_38 ] . V_23 = F_45 ( V_32 ) ;
return 0 ;
}
static bool F_47 ( enum V_185 type )
{
switch ( type ) {
case V_186 :
case V_102 :
case V_103 :
return true ;
default:
return false ;
}
}
static int F_48 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
T_1 V_187 = F_7 ( V_32 -> V_34 ) ;
struct V_3 * V_4 ;
int V_7 , V_70 ;
if ( ! F_47 ( V_59 -> V_96 -> type ) ) {
F_2 ( L_82 ) ;
return - V_78 ;
}
if ( V_32 -> V_38 != V_158 || V_32 -> V_17 != 0 ||
F_8 ( V_32 -> V_34 ) == V_86 ||
( V_187 == V_48 && V_32 -> V_40 != V_158 ) ) {
F_2 ( L_83 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_188 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( V_9 [ V_188 ] . type != V_75 ) {
F_2 ( L_84 ) ;
return - V_78 ;
}
if ( V_187 == V_49 ) {
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
}
for ( V_7 = 0 ; V_7 < V_154 ; V_7 ++ ) {
V_4 = V_9 + V_155 [ V_7 ] ;
V_4 -> type = V_10 ;
V_4 -> V_14 = 0 ;
}
V_9 [ V_158 ] . type = V_19 ;
return 0 ;
}
static int F_49 ( int V_6 , int V_189 , int V_190 , struct V_58 * V_59 )
{
if ( V_190 == V_191 && V_192 [ V_6 ] >= ( V_193 | V_191 ) )
return 0 ;
if ( V_190 == V_194 && V_192 [ V_6 ] >= ( V_193 | V_194 ) )
return 0 ;
if ( V_189 < 0 || V_189 >= V_59 -> V_96 -> V_195 ) {
F_2 ( L_85 , V_6 , V_189 ) ;
return - V_78 ;
}
if ( V_190 == V_194 )
V_59 -> V_196 [ V_189 ] = V_197 ;
if ( V_192 [ V_189 ] == 0 ) {
V_192 [ V_6 ] = V_193 | V_190 ;
V_192 [ V_189 ] = V_193 ;
if ( V_198 >= V_59 -> V_96 -> V_195 )
return - V_199 ;
V_200 [ V_198 ++ ] = V_189 ;
return 1 ;
} else if ( ( V_192 [ V_189 ] & 0xF0 ) == V_193 ) {
F_2 ( L_86 , V_6 , V_189 ) ;
return - V_78 ;
} else if ( V_192 [ V_189 ] == V_201 ) {
V_192 [ V_6 ] = V_193 | V_190 ;
} else {
F_2 ( L_87 ) ;
return - V_126 ;
}
return 0 ;
}
static int F_50 ( struct V_58 * V_59 )
{
struct V_31 * V_202 = V_59 -> V_96 -> V_203 ;
int V_204 = V_59 -> V_96 -> V_195 ;
int V_205 = 0 ;
int V_7 , V_6 ;
V_192 = F_51 ( V_204 , sizeof( int ) , V_69 ) ;
if ( ! V_192 )
return - V_206 ;
V_200 = F_51 ( V_204 , sizeof( int ) , V_69 ) ;
if ( ! V_200 ) {
F_10 ( V_192 ) ;
return - V_206 ;
}
V_192 [ 0 ] = V_193 ;
V_200 [ 0 ] = 0 ;
V_198 = 1 ;
V_207:
if ( V_198 == 0 )
goto V_208;
V_6 = V_200 [ V_198 - 1 ] ;
if ( F_4 ( V_202 [ V_6 ] . V_34 ) == V_51 ) {
T_1 V_52 = F_6 ( V_202 [ V_6 ] . V_34 ) ;
if ( V_52 == V_55 ) {
goto V_209;
} else if ( V_52 == V_53 ) {
V_205 = F_49 ( V_6 , V_6 + 1 , V_191 , V_59 ) ;
if ( V_205 == 1 )
goto V_207;
else if ( V_205 < 0 )
goto V_210;
if ( V_6 + 1 < V_204 )
V_59 -> V_196 [ V_6 + 1 ] = V_197 ;
} else if ( V_52 == V_54 ) {
if ( F_5 ( V_202 [ V_6 ] . V_34 ) != V_162 ) {
V_205 = - V_78 ;
goto V_210;
}
V_205 = F_49 ( V_6 , V_6 + V_202 [ V_6 ] . V_17 + 1 ,
V_191 , V_59 ) ;
if ( V_205 == 1 )
goto V_207;
else if ( V_205 < 0 )
goto V_210;
if ( V_6 + 1 < V_204 )
V_59 -> V_196 [ V_6 + 1 ] = V_197 ;
} else {
V_205 = F_49 ( V_6 , V_6 + 1 , V_191 , V_59 ) ;
if ( V_205 == 1 )
goto V_207;
else if ( V_205 < 0 )
goto V_210;
V_205 = F_49 ( V_6 , V_6 + V_202 [ V_6 ] . V_17 + 1 , V_194 , V_59 ) ;
if ( V_205 == 1 )
goto V_207;
else if ( V_205 < 0 )
goto V_210;
}
} else {
V_205 = F_49 ( V_6 , V_6 + 1 , V_191 , V_59 ) ;
if ( V_205 == 1 )
goto V_207;
else if ( V_205 < 0 )
goto V_210;
}
V_209:
V_192 [ V_6 ] = V_201 ;
if ( V_198 -- <= 0 ) {
F_2 ( L_88 ) ;
V_205 = - V_126 ;
goto V_210;
}
goto V_207;
V_208:
for ( V_7 = 0 ; V_7 < V_204 ; V_7 ++ ) {
if ( V_192 [ V_7 ] != V_201 ) {
F_2 ( L_89 , V_7 ) ;
V_205 = - V_78 ;
goto V_210;
}
}
V_205 = 0 ;
V_210:
F_10 ( V_192 ) ;
F_10 ( V_200 ) ;
return V_205 ;
}
static bool F_52 ( struct V_3 * V_211 , struct V_3 * V_212 )
{
if ( V_211 -> V_16 != V_212 -> V_16 )
return false ;
if ( V_211 -> V_17 == V_212 -> V_17 && V_211 -> V_18 < V_212 -> V_18 )
return true ;
if ( V_211 -> V_17 <= V_212 -> V_17 &&
V_211 -> V_17 >= V_211 -> V_18 && V_212 -> V_17 >= V_212 -> V_18 )
return true ;
return false ;
}
static bool F_53 ( struct V_1 * V_211 , struct V_1 * V_212 )
{
struct V_3 * V_213 , * V_214 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_213 = & V_211 -> V_9 [ V_7 ] ;
V_214 = & V_212 -> V_9 [ V_7 ] ;
if ( memcmp ( V_213 , V_214 , sizeof( * V_213 ) ) == 0 )
continue;
if ( V_213 -> type == V_10 ||
( V_213 -> type == V_19 && V_214 -> type != V_10 ) )
continue;
if ( V_213 -> type == V_15 && V_214 -> type == V_15 &&
F_52 ( V_213 , V_214 ) )
continue;
return false ;
}
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
if ( V_211 -> V_28 [ V_7 ] == V_215 )
continue;
if ( V_211 -> V_28 [ V_7 ] != V_212 -> V_28 [ V_7 ] )
return false ;
if ( V_7 % V_27 )
continue;
if ( memcmp ( & V_211 -> V_30 [ V_7 / V_27 ] ,
& V_212 -> V_30 [ V_7 / V_27 ] ,
sizeof( V_211 -> V_30 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_54 ( struct V_58 * V_59 , int V_63 )
{
struct V_216 * V_217 ;
struct V_216 * V_218 ;
V_218 = V_59 -> V_196 [ V_63 ] ;
if ( ! V_218 )
return 0 ;
while ( V_218 != V_197 ) {
if ( F_53 ( & V_218 -> V_2 , & V_59 -> V_65 ) )
return 1 ;
V_218 = V_218 -> V_67 ;
}
V_217 = F_12 ( sizeof( struct V_216 ) , V_219 ) ;
if ( ! V_217 )
return - V_206 ;
memcpy ( & V_217 -> V_2 , & V_59 -> V_65 , sizeof( V_59 -> V_65 ) ) ;
V_217 -> V_67 = V_59 -> V_196 [ V_63 ] ;
V_59 -> V_196 [ V_63 ] = V_217 ;
return 0 ;
}
static int F_55 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_31 * V_202 = V_59 -> V_96 -> V_203 ;
struct V_3 * V_9 = V_2 -> V_9 ;
int V_204 = V_59 -> V_96 -> V_195 ;
int V_63 , V_60 = 0 ;
int V_220 = 0 ;
bool V_221 = false ;
F_13 ( V_9 ) ;
V_63 = 0 ;
for (; ; ) {
struct V_31 * V_32 ;
T_1 V_33 ;
int V_70 ;
if ( V_63 >= V_204 ) {
F_2 ( L_90 ,
V_63 , V_204 ) ;
return - V_126 ;
}
V_32 = & V_202 [ V_63 ] ;
V_33 = F_4 ( V_32 -> V_34 ) ;
if ( ++ V_220 > V_222 ) {
F_2 ( L_91 ,
V_220 ) ;
return - V_199 ;
}
V_70 = F_54 ( V_59 , V_63 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_70 == 1 ) {
if ( V_182 ) {
if ( V_221 )
F_2 ( L_92 ,
V_60 , V_63 ) ;
else
F_2 ( L_93 , V_63 ) ;
}
goto V_223;
}
if ( V_182 && V_221 ) {
F_2 ( L_94 , V_60 , V_63 ) ;
F_1 ( & V_59 -> V_65 ) ;
V_221 = false ;
}
if ( V_182 ) {
F_2 ( L_95 , V_63 ) ;
F_3 ( V_32 ) ;
}
if ( V_33 == V_35 || V_33 == V_36 ) {
V_70 = F_42 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_33 == V_46 ) {
enum V_5 V_224 ;
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_177 ) ;
if ( V_70 )
return V_70 ;
V_224 = V_9 [ V_32 -> V_40 ] . type ;
V_70 = F_27 ( V_59 , V_32 -> V_40 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_107 ,
V_32 -> V_38 ) ;
if ( V_70 )
return V_70 ;
if ( F_8 ( V_32 -> V_34 ) != V_83 ) {
V_63 ++ ;
continue;
}
if ( V_32 -> V_14 == 0 ) {
V_32 -> V_14 = V_224 ;
} else if ( V_224 != V_32 -> V_14 &&
( V_224 == V_75 ||
V_32 -> V_14 == V_75 ) ) {
F_2 ( L_96 ) ;
return - V_78 ;
}
} else if ( V_33 == V_41 ) {
enum V_5 V_225 ;
if ( F_7 ( V_32 -> V_34 ) == V_44 ) {
V_70 = F_28 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
V_63 ++ ;
continue;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_225 = V_9 [ V_32 -> V_38 ] . type ;
V_70 = F_27 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_106 ,
V_32 -> V_40 ) ;
if ( V_70 )
return V_70 ;
if ( V_32 -> V_14 == 0 ) {
V_32 -> V_14 = V_225 ;
} else if ( V_225 != V_32 -> V_14 &&
( V_225 == V_75 ||
V_32 -> V_14 == V_75 ) ) {
F_2 ( L_96 ) ;
return - V_78 ;
}
} else if ( V_33 == V_45 ) {
if ( F_7 ( V_32 -> V_34 ) != V_42 ||
V_32 -> V_40 != V_158 ) {
F_2 ( L_97 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_27 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_106 ,
- 1 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_33 == V_51 ) {
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
if ( V_52 == V_53 ) {
if ( F_5 ( V_32 -> V_34 ) != V_162 ||
V_32 -> V_17 != 0 ||
V_32 -> V_40 != V_158 ||
V_32 -> V_38 != V_158 ) {
F_2 ( L_98 ) ;
return - V_78 ;
}
V_70 = F_34 ( V_59 , V_32 -> V_14 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_52 == V_54 ) {
if ( F_5 ( V_32 -> V_34 ) != V_162 ||
V_32 -> V_14 != 0 ||
V_32 -> V_40 != V_158 ||
V_32 -> V_38 != V_158 ) {
F_2 ( L_99 ) ;
return - V_78 ;
}
V_63 += V_32 -> V_17 + 1 ;
continue;
} else if ( V_52 == V_55 ) {
if ( F_5 ( V_32 -> V_34 ) != V_162 ||
V_32 -> V_14 != 0 ||
V_32 -> V_40 != V_158 ||
V_32 -> V_38 != V_158 ) {
F_2 ( L_100 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_158 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( F_24 ( V_59 , V_158 ) ) {
F_2 ( L_101 ) ;
return - V_80 ;
}
V_223:
V_63 = F_9 ( V_59 , & V_60 ) ;
if ( V_63 < 0 ) {
break;
} else {
V_221 = true ;
continue;
}
} else {
V_70 = F_44 ( V_59 , V_32 , & V_63 ) ;
if ( V_70 )
return V_70 ;
}
} else if ( V_33 == V_47 ) {
T_1 V_187 = F_7 ( V_32 -> V_34 ) ;
if ( V_187 == V_48 || V_187 == V_49 ) {
V_70 = F_48 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_187 == V_50 ) {
V_70 = F_46 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
V_63 ++ ;
} else {
F_2 ( L_102 ) ;
return - V_78 ;
}
} else {
F_2 ( L_103 , V_33 ) ;
return - V_78 ;
}
V_63 ++ ;
}
F_2 ( L_104 , V_220 ) ;
return 0 ;
}
static int F_56 ( struct V_58 * V_59 )
{
struct V_31 * V_32 = V_59 -> V_96 -> V_203 ;
int V_204 = V_59 -> V_96 -> V_195 ;
int V_7 , V_226 ;
for ( V_7 = 0 ; V_7 < V_204 ; V_7 ++ , V_32 ++ ) {
if ( F_4 ( V_32 -> V_34 ) == V_46 &&
( F_7 ( V_32 -> V_34 ) != V_42 || V_32 -> V_14 != 0 ) ) {
F_2 ( L_105 ) ;
return - V_78 ;
}
if ( F_4 ( V_32 -> V_34 ) == V_41 &&
( ( F_7 ( V_32 -> V_34 ) != V_42 &&
F_7 ( V_32 -> V_34 ) != V_44 ) || V_32 -> V_14 != 0 ) ) {
F_2 ( L_106 ) ;
return - V_78 ;
}
if ( V_32 [ 0 ] . V_34 == ( V_47 | V_50 | V_86 ) ) {
struct V_92 * V_93 ;
struct V_227 V_228 ;
if ( V_7 == V_204 - 1 || V_32 [ 1 ] . V_34 != 0 ||
V_32 [ 1 ] . V_38 != 0 || V_32 [ 1 ] . V_40 != 0 ||
V_32 [ 1 ] . V_17 != 0 ) {
F_2 ( L_107 ) ;
return - V_78 ;
}
if ( V_32 -> V_40 == 0 )
goto V_229;
if ( V_32 -> V_40 != V_184 ) {
F_2 ( L_108 ) ;
return - V_78 ;
}
V_228 = F_57 ( V_32 -> V_14 ) ;
V_93 = F_58 ( V_228 ) ;
if ( F_59 ( V_93 ) ) {
F_2 ( L_109 ,
V_32 -> V_14 ) ;
return F_60 ( V_93 ) ;
}
V_32 [ 0 ] . V_14 = ( T_2 ) ( unsigned long ) V_93 ;
V_32 [ 1 ] . V_14 = ( ( T_5 ) ( unsigned long ) V_93 ) >> 32 ;
for ( V_226 = 0 ; V_226 < V_59 -> V_230 ; V_226 ++ )
if ( V_59 -> V_231 [ V_226 ] == V_93 ) {
F_61 ( V_228 ) ;
goto V_229;
}
if ( V_59 -> V_230 >= V_232 ) {
F_61 ( V_228 ) ;
return - V_199 ;
}
V_93 = F_62 ( V_93 , false ) ;
if ( F_59 ( V_93 ) ) {
F_61 ( V_228 ) ;
return F_60 ( V_93 ) ;
}
V_59 -> V_231 [ V_59 -> V_230 ++ ] = V_93 ;
F_61 ( V_228 ) ;
V_229:
V_32 ++ ;
V_7 ++ ;
}
}
return 0 ;
}
static void F_63 ( struct V_58 * V_59 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_59 -> V_230 ; V_7 ++ )
F_64 ( V_59 -> V_231 [ V_7 ] ) ;
}
static void F_65 ( struct V_58 * V_59 )
{
struct V_31 * V_32 = V_59 -> V_96 -> V_203 ;
int V_204 = V_59 -> V_96 -> V_195 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_204 ; V_7 ++ , V_32 ++ )
if ( V_32 -> V_34 == ( V_47 | V_50 | V_86 ) )
V_32 -> V_40 = 0 ;
}
static int F_66 ( struct V_58 * V_59 )
{
struct V_31 * V_32 = V_59 -> V_96 -> V_203 ;
int V_204 = V_59 -> V_96 -> V_195 ;
struct V_31 V_233 [ 16 ] ;
struct V_234 * V_235 ;
enum V_94 type ;
int V_7 ;
if ( ! V_59 -> V_96 -> V_97 -> V_98 -> V_236 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_204 ; V_7 ++ , V_32 ++ ) {
T_2 V_237 , V_238 ;
if ( V_32 -> V_34 == ( V_46 | V_42 | V_83 ) )
type = V_107 ;
else if ( V_32 -> V_34 == ( V_41 | V_42 | V_83 ) )
type = V_106 ;
else
continue;
if ( V_32 -> V_14 != V_75 ) {
V_32 -> V_14 = 0 ;
continue;
}
V_238 = V_59 -> V_96 -> V_97 -> V_98 ->
V_236 ( type , V_32 -> V_38 , V_32 -> V_40 ,
V_32 -> V_17 , V_233 , V_59 -> V_96 ) ;
if ( V_238 == 0 || V_238 >= F_67 ( V_233 ) ) {
F_2 ( L_110 ) ;
return - V_78 ;
}
V_235 = F_68 ( V_59 -> V_96 , V_7 , V_233 , V_238 ) ;
if ( ! V_235 )
return - V_206 ;
V_237 = V_238 - 1 ;
V_59 -> V_96 = V_235 ;
V_32 = V_235 -> V_203 + V_7 + V_237 ;
V_204 += V_237 ;
V_7 += V_237 ;
}
return 0 ;
}
static void F_69 ( struct V_58 * V_59 )
{
struct V_216 * V_218 , * V_239 ;
int V_7 ;
if ( ! V_59 -> V_196 )
return;
for ( V_7 = 0 ; V_7 < V_59 -> V_96 -> V_195 ; V_7 ++ ) {
V_218 = V_59 -> V_196 [ V_7 ] ;
if ( V_218 )
while ( V_218 != V_197 ) {
V_239 = V_218 -> V_67 ;
F_10 ( V_218 ) ;
V_218 = V_239 ;
}
}
F_10 ( V_59 -> V_196 ) ;
}
int F_70 ( struct V_234 * * V_96 , union V_240 * V_241 )
{
char T_6 * V_242 = NULL ;
struct V_58 * V_59 ;
int V_205 = - V_78 ;
if ( ( * V_96 ) -> V_195 <= 0 || ( * V_96 ) -> V_195 > V_243 )
return - V_199 ;
V_59 = F_71 ( sizeof( struct V_58 ) , V_69 ) ;
if ( ! V_59 )
return - V_206 ;
V_59 -> V_96 = * V_96 ;
F_72 ( & V_244 ) ;
if ( V_241 -> V_182 || V_241 -> V_245 || V_241 -> V_246 ) {
V_182 = V_241 -> V_182 ;
V_242 = ( char T_6 * ) ( unsigned long ) V_241 -> V_245 ;
V_246 = V_241 -> V_246 ;
V_247 = 0 ;
V_205 = - V_78 ;
if ( V_246 < 128 || V_246 > V_248 >> 8 ||
V_182 == 0 || V_242 == NULL )
goto V_249;
V_205 = - V_206 ;
V_245 = F_73 ( V_246 ) ;
if ( ! V_245 )
goto V_249;
} else {
V_182 = 0 ;
}
V_205 = F_56 ( V_59 ) ;
if ( V_205 < 0 )
goto V_250;
V_59 -> V_196 = F_51 ( V_59 -> V_96 -> V_195 ,
sizeof( struct V_216 * ) ,
V_219 ) ;
V_205 = - V_206 ;
if ( ! V_59 -> V_196 )
goto V_250;
V_205 = F_50 ( V_59 ) ;
if ( V_205 < 0 )
goto V_250;
V_59 -> V_101 = F_74 ( V_251 ) ;
V_205 = F_55 ( V_59 ) ;
V_250:
while ( F_9 ( V_59 , NULL ) >= 0 ) ;
F_69 ( V_59 ) ;
if ( V_205 == 0 )
V_205 = F_66 ( V_59 ) ;
if ( V_182 && V_247 >= V_246 - 1 ) {
F_15 ( V_247 >= V_246 ) ;
V_205 = - V_252 ;
}
if ( V_182 && F_75 ( V_242 , V_245 , V_247 + 1 ) != 0 ) {
V_205 = - V_126 ;
goto V_253;
}
if ( V_205 == 0 && V_59 -> V_230 ) {
V_59 -> V_96 -> V_97 -> V_231 = F_76 ( V_59 -> V_230 ,
sizeof( V_59 -> V_231 [ 0 ] ) ,
V_69 ) ;
if ( ! V_59 -> V_96 -> V_97 -> V_231 ) {
V_205 = - V_206 ;
goto V_253;
}
memcpy ( V_59 -> V_96 -> V_97 -> V_231 , V_59 -> V_231 ,
sizeof( V_59 -> V_231 [ 0 ] ) * V_59 -> V_230 ) ;
V_59 -> V_96 -> V_97 -> V_230 = V_59 -> V_230 ;
F_65 ( V_59 ) ;
}
V_253:
if ( V_182 )
F_77 ( V_245 ) ;
V_249:
if ( ! V_59 -> V_96 -> V_97 -> V_231 )
F_63 ( V_59 ) ;
* V_96 = V_59 -> V_96 ;
F_10 ( V_59 ) ;
F_78 ( & V_244 ) ;
return V_205 ;
}
