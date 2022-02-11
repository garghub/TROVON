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
static bool F_22 ( enum V_94 type )
{
switch ( type ) {
case V_95 :
return true ;
default:
return false ;
}
}
static int F_23 ( struct V_58 * V_59 , T_2 V_76 , int V_17 ,
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
static int F_24 ( struct V_58 * V_59 , int V_17 , int V_88 ,
enum V_96 V_6 , enum V_5 * V_97 )
{
if ( V_59 -> V_98 -> V_99 -> V_100 -> V_101 &&
V_59 -> V_98 -> V_99 -> V_100 -> V_101 ( V_17 , V_88 , V_6 , V_97 ) ) {
if ( V_59 -> V_98 -> V_99 -> V_102 < V_17 + V_88 )
V_59 -> V_98 -> V_99 -> V_102 = V_17 + V_88 ;
return 0 ;
}
F_2 ( L_37 , V_17 , V_88 ) ;
return - V_80 ;
}
static bool F_25 ( struct V_58 * V_59 , int V_76 )
{
if ( V_59 -> V_103 )
return false ;
switch ( V_59 -> V_65 . V_9 [ V_76 ] . type ) {
case V_19 :
case V_12 :
return false ;
default:
return true ;
}
}
static int F_26 ( struct V_58 * V_59 , struct V_3 * V_4 ,
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
switch ( V_59 -> V_98 -> type ) {
case V_104 :
case V_105 :
case V_95 :
break;
default:
F_2 ( L_39 ) ;
return - V_80 ;
}
if ( F_27 ( V_106 ) )
return 0 ;
if ( V_4 -> V_16 && V_88 != 1 ) {
F_2 ( L_40 ) ;
return - V_80 ;
}
if ( ( V_107 + V_4 -> V_17 + V_17 ) % V_88 != 0 ) {
F_2 ( L_41 ,
V_107 , V_4 -> V_17 , V_17 , V_88 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_28 ( struct V_58 * V_59 , T_2 V_76 , int V_17 ,
int V_82 , enum V_96 V_6 ,
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
V_70 = F_26 ( V_59 , V_4 , V_17 , V_88 ) ;
if ( V_70 )
return V_70 ;
if ( V_4 -> type == V_21 ) {
if ( V_6 == V_108 && V_89 >= 0 &&
F_25 ( V_59 , V_89 ) ) {
F_2 ( L_42 , V_89 ) ;
return - V_80 ;
}
V_70 = F_21 ( V_59 , V_76 , V_17 , V_88 ) ;
if ( ! V_70 && V_6 == V_109 && V_89 >= 0 )
F_14 ( V_2 -> V_9 , V_89 ) ;
} else if ( V_4 -> type == V_75 ) {
enum V_5 V_97 = V_19 ;
if ( V_6 == V_108 && V_89 >= 0 &&
F_25 ( V_59 , V_89 ) ) {
F_2 ( L_43 , V_89 ) ;
return - V_80 ;
}
V_70 = F_24 ( V_59 , V_17 , V_88 , V_6 , & V_97 ) ;
if ( ! V_70 && V_6 == V_109 && V_89 >= 0 ) {
F_14 ( V_2 -> V_9 , V_89 ) ;
if ( V_59 -> V_103 )
V_2 -> V_9 [ V_89 ] . type = V_97 ;
}
} else if ( V_4 -> type == V_73 || V_4 -> type == V_13 ) {
if ( V_17 >= 0 || V_17 < - V_26 ) {
F_2 ( L_44 , V_17 , V_88 ) ;
return - V_80 ;
}
if ( V_6 == V_108 ) {
if ( ! V_59 -> V_103 &&
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
if ( V_6 == V_108 && ! F_22 ( V_59 -> V_98 -> type ) ) {
F_2 ( L_46 ) ;
return - V_80 ;
}
if ( V_6 == V_108 && V_89 >= 0 &&
F_25 ( V_59 , V_89 ) ) {
F_2 ( L_47 , V_89 ) ;
return - V_80 ;
}
V_70 = F_23 ( V_59 , V_76 , V_17 , V_88 ) ;
if ( ! V_70 && V_6 == V_109 && V_89 >= 0 )
F_14 ( V_2 -> V_9 , V_89 ) ;
} else {
F_2 ( L_48 ,
V_76 , V_11 [ V_4 -> type ] ) ;
return - V_80 ;
}
if ( ! V_70 && V_88 <= 2 && V_89 >= 0 && V_59 -> V_103 &&
V_2 -> V_9 [ V_89 ] . type == V_19 ) {
V_2 -> V_9 [ V_89 ] . V_14 = 64 - V_88 * 8 ;
}
return V_70 ;
}
static int F_29 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
int V_70 ;
if ( ( F_8 ( V_32 -> V_34 ) != V_83 && F_8 ( V_32 -> V_34 ) != V_86 ) ||
V_32 -> V_14 != 0 ) {
F_2 ( L_49 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_28 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_109 , - 1 ) ;
if ( V_70 )
return V_70 ;
return F_28 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_108 , - 1 ) ;
}
static int F_30 ( struct V_58 * V_59 , int V_76 ,
int V_110 , bool V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_3 * V_9 = V_2 -> V_9 ;
int V_17 , V_7 ;
if ( V_9 [ V_76 ] . type != V_13 ) {
if ( V_111 && V_110 == 0 &&
V_9 [ V_76 ] . type == V_12 &&
V_9 [ V_76 ] . V_14 == 0 )
return 0 ;
F_2 ( L_50 , V_76 ,
V_11 [ V_9 [ V_76 ] . type ] ,
V_11 [ V_13 ] ) ;
return - V_80 ;
}
V_17 = V_9 [ V_76 ] . V_14 ;
if ( V_17 >= 0 || V_17 < - V_26 || V_17 + V_110 > 0 ||
V_110 <= 0 ) {
F_2 ( L_51 ,
V_76 , V_17 , V_110 ) ;
return - V_80 ;
}
if ( V_113 && V_113 -> V_114 ) {
V_113 -> V_110 = V_110 ;
V_113 -> V_76 = V_76 ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ ) {
if ( V_2 -> V_28 [ V_26 + V_17 + V_7 ] != V_90 ) {
F_2 ( L_52 ,
V_17 , V_7 , V_110 ) ;
return - V_80 ;
}
}
return 0 ;
}
static int F_31 ( struct V_58 * V_59 , T_2 V_76 ,
enum V_115 V_116 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = V_59 -> V_65 . V_9 + V_76 ;
enum V_5 V_117 ;
int V_70 = 0 ;
if ( V_116 == V_118 )
return 0 ;
if ( V_4 -> type == V_10 ) {
F_2 ( L_30 , V_76 ) ;
return - V_80 ;
}
if ( V_116 == V_119 ) {
if ( F_25 ( V_59 , V_76 ) ) {
F_2 ( L_53 , V_76 ) ;
return - V_80 ;
}
return 0 ;
}
if ( V_116 == V_120 ||
V_116 == V_121 ) {
V_117 = V_13 ;
} else if ( V_116 == V_122 ||
V_116 == V_123 ) {
V_117 = V_12 ;
} else if ( V_116 == V_124 ) {
V_117 = V_20 ;
} else if ( V_116 == V_125 ) {
V_117 = V_75 ;
} else if ( V_116 == V_126 ||
V_116 == V_127 ) {
V_117 = V_13 ;
if ( V_4 -> type == V_12 && V_4 -> V_14 == 0 )
V_117 = V_12 ;
V_113 -> V_114 = V_116 == V_127 ;
} else {
F_2 ( L_54 , V_116 ) ;
return - V_128 ;
}
if ( V_4 -> type != V_117 ) {
F_2 ( L_50 , V_76 ,
V_11 [ V_4 -> type ] , V_11 [ V_117 ] ) ;
return - V_80 ;
}
if ( V_116 == V_124 ) {
V_113 -> V_23 = V_4 -> V_23 ;
} else if ( V_116 == V_120 ) {
if ( ! V_113 -> V_23 ) {
F_2 ( L_55 ) ;
return - V_80 ;
}
V_70 = F_30 ( V_59 , V_76 , V_113 -> V_23 -> V_24 ,
false , NULL ) ;
} else if ( V_116 == V_121 ) {
if ( ! V_113 -> V_23 ) {
F_2 ( L_56 ) ;
return - V_80 ;
}
V_70 = F_30 ( V_59 , V_76 ,
V_113 -> V_23 -> V_25 ,
false , NULL ) ;
} else if ( V_116 == V_122 ||
V_116 == V_123 ) {
bool V_111 = ( V_116 == V_123 ) ;
if ( V_76 == 0 ) {
F_2 ( L_57 ) ;
return - V_80 ;
}
V_70 = F_30 ( V_59 , V_76 - 1 , V_4 -> V_14 ,
V_111 , V_113 ) ;
}
return V_70 ;
}
static int F_32 ( struct V_92 * V_93 , int V_129 )
{
if ( ! V_93 )
return 0 ;
switch ( V_93 -> V_130 ) {
case V_131 :
if ( V_129 != V_132 )
goto error;
break;
case V_133 :
if ( V_129 != V_134 &&
V_129 != V_135 )
goto error;
break;
case V_136 :
if ( V_129 != V_137 )
goto error;
break;
case V_138 :
if ( V_129 != V_139 )
goto error;
break;
default:
break;
}
switch ( V_129 ) {
case V_132 :
if ( V_93 -> V_130 != V_131 )
goto error;
break;
case V_134 :
case V_135 :
if ( V_93 -> V_130 != V_133 )
goto error;
break;
case V_137 :
if ( V_93 -> V_130 != V_136 )
goto error;
break;
case V_139 :
if ( V_93 -> V_130 != V_138 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_2 ( L_58 ,
V_93 -> V_130 , V_129 ) ;
return - V_78 ;
}
static int F_33 ( const struct V_140 * V_141 )
{
int V_142 = 0 ;
if ( V_141 -> V_143 == V_127 )
V_142 ++ ;
if ( V_141 -> V_144 == V_127 )
V_142 ++ ;
if ( V_141 -> V_145 == V_127 )
V_142 ++ ;
if ( V_141 -> V_146 == V_127 )
V_142 ++ ;
if ( V_141 -> V_147 == V_127 )
V_142 ++ ;
return V_142 > 1 ? - V_78 : 0 ;
}
static void F_34 ( struct V_58 * V_59 )
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
static int F_35 ( struct V_58 * V_59 , int V_129 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
const struct V_140 * V_141 = NULL ;
struct V_3 * V_9 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_112 V_113 ;
bool V_148 ;
int V_7 , V_70 ;
if ( V_129 < 0 || V_129 >= V_149 ) {
F_2 ( L_59 , V_129 ) ;
return - V_78 ;
}
if ( V_59 -> V_98 -> V_99 -> V_100 -> V_150 )
V_141 = V_59 -> V_98 -> V_99 -> V_100 -> V_150 ( V_129 ) ;
if ( ! V_141 ) {
F_2 ( L_60 , V_129 ) ;
return - V_78 ;
}
if ( ! V_59 -> V_98 -> V_151 && V_141 -> V_152 ) {
F_2 ( L_61 ) ;
return - V_78 ;
}
V_148 = F_36 ( V_141 -> V_153 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_70 = F_33 ( V_141 ) ;
if ( V_70 ) {
F_2 ( L_62 , V_129 ) ;
return V_70 ;
}
V_70 = F_31 ( V_59 , V_74 , V_141 -> V_143 , & V_113 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_31 ( V_59 , V_154 , V_141 -> V_144 , & V_113 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_31 ( V_59 , V_155 , V_141 -> V_145 , & V_113 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_31 ( V_59 , V_156 , V_141 -> V_146 , & V_113 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_31 ( V_59 , V_157 , V_141 -> V_147 , & V_113 ) ;
if ( V_70 )
return V_70 ;
for ( V_7 = 0 ; V_7 < V_113 . V_110 ; V_7 ++ ) {
V_70 = F_28 ( V_59 , V_113 . V_76 , V_7 , V_85 , V_108 , - 1 ) ;
if ( V_70 )
return V_70 ;
}
for ( V_7 = 0 ; V_7 < V_158 ; V_7 ++ ) {
V_4 = V_9 + V_159 [ V_7 ] ;
V_4 -> type = V_10 ;
V_4 -> V_14 = 0 ;
}
if ( V_141 -> V_160 == V_161 ) {
V_9 [ V_162 ] . type = V_19 ;
} else if ( V_141 -> V_160 == V_163 ) {
V_9 [ V_162 ] . type = V_10 ;
} else if ( V_141 -> V_160 == V_164 ) {
V_9 [ V_162 ] . type = V_22 ;
if ( V_113 . V_23 == NULL ) {
F_2 ( L_63 ) ;
return - V_78 ;
}
V_9 [ V_162 ] . V_23 = V_113 . V_23 ;
} else {
F_2 ( L_64 ,
V_141 -> V_160 , V_129 ) ;
return - V_78 ;
}
V_70 = F_32 ( V_113 . V_23 , V_129 ) ;
if ( V_70 )
return V_70 ;
if ( V_148 )
F_34 ( V_59 ) ;
return 0 ;
}
static int F_37 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_38 = & V_9 [ V_32 -> V_38 ] ;
struct V_3 * V_40 = & V_9 [ V_32 -> V_40 ] ;
struct V_3 V_165 ;
T_3 V_14 ;
if ( F_5 ( V_32 -> V_34 ) == V_166 ) {
V_14 = V_32 -> V_14 ;
V_167:
if ( V_14 <= 0 ) {
F_2 ( L_65 ) ;
return - V_80 ;
}
if ( V_14 >= V_168 ||
V_14 + V_38 -> V_17 >= V_168 ) {
F_2 ( L_66 ,
V_14 ) ;
return - V_80 ;
}
V_38 -> V_17 += V_14 ;
} else {
if ( V_40 -> type == V_15 ) {
V_165 = * V_38 ;
* V_38 = * V_40 ;
V_40 = & V_165 ;
}
if ( V_40 -> type == V_12 ) {
V_14 = V_40 -> V_14 ;
goto V_167;
}
if ( V_40 -> type != V_19 ) {
F_2 ( L_67 ,
V_11 [ V_40 -> type ] ) ;
return - V_80 ;
}
if ( V_40 -> V_14 < 48 ) {
F_2 ( L_68 ,
V_40 -> V_14 ) ;
return - V_80 ;
}
V_38 -> V_16 = ++ V_59 -> V_169 ;
V_38 -> V_17 = 0 ;
V_38 -> V_18 = 0 ;
}
return 0 ;
}
static int F_38 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_38 = & V_9 [ V_32 -> V_38 ] ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
T_4 V_170 ;
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
struct V_3 * V_40 = & V_9 [ V_32 -> V_40 ] ;
if ( V_40 -> type == V_19 && V_40 -> V_14 > 0 &&
V_38 -> V_14 && V_52 == V_171 ) {
V_38 -> V_14 = F_39 ( V_38 -> V_14 , V_40 -> V_14 ) ;
V_38 -> V_14 -- ;
return 0 ;
}
if ( V_40 -> type == V_12 && V_40 -> V_14 > 0 &&
V_38 -> V_14 && V_52 == V_171 ) {
V_170 = F_40 ( ( long long ) V_40 -> V_14 ) ;
V_38 -> V_14 = F_39 ( V_38 -> V_14 , 63 - V_170 ) ;
V_38 -> V_14 -- ;
return 0 ;
}
V_38 -> V_14 = 0 ;
return 0 ;
}
V_170 = F_40 ( ( long long ) V_32 -> V_14 ) ;
if ( V_38 -> V_14 && V_52 == V_172 ) {
V_38 -> V_14 -= V_32 -> V_14 ;
} else if ( V_38 -> V_14 && V_52 == V_173 ) {
V_38 -> V_14 -= V_170 + 1 ;
} else if ( V_52 == V_174 ) {
V_38 -> V_14 = 63 - V_170 ;
} else if ( V_38 -> V_14 && V_52 == V_171 ) {
V_38 -> V_14 = F_39 ( V_38 -> V_14 , 63 - V_170 ) ;
V_38 -> V_14 -- ;
} else if ( V_52 == V_175 ) {
V_38 -> V_14 += V_32 -> V_14 ;
if ( F_41 ( V_38 -> V_14 > 64 ) )
V_38 -> V_14 = 64 ;
} else {
V_38 -> V_14 = 0 ;
}
if ( V_38 -> V_14 < 0 ) {
V_38 -> V_14 = 0 ;
}
return 0 ;
}
static int F_42 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
struct V_3 * V_38 = & V_9 [ V_32 -> V_38 ] ;
struct V_3 * V_40 = & V_9 [ V_32 -> V_40 ] ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
if ( V_52 == V_171 && F_5 ( V_32 -> V_34 ) == V_166 )
V_38 -> V_14 += V_32 -> V_14 ;
else if ( V_52 == V_171 && F_5 ( V_32 -> V_34 ) == V_37 &&
V_40 -> type == V_12 )
V_38 -> V_14 += V_40 -> V_14 ;
else
F_14 ( V_9 , V_32 -> V_38 ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 , * V_38 ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
int V_70 ;
if ( V_52 == V_176 || V_52 == V_177 ) {
if ( V_52 == V_177 ) {
if ( F_5 ( V_32 -> V_34 ) != 0 ||
V_32 -> V_40 != V_162 ||
V_32 -> V_17 != 0 || V_32 -> V_14 != 0 ) {
F_2 ( L_69 ) ;
return - V_78 ;
}
} else {
if ( V_32 -> V_40 != V_162 || V_32 -> V_17 != 0 ||
( V_32 -> V_14 != 16 && V_32 -> V_14 != 32 && V_32 -> V_14 != 64 ) ) {
F_2 ( L_70 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( F_25 ( V_59 , V_32 -> V_38 ) ) {
F_2 ( L_71 ,
V_32 -> V_38 ) ;
return - V_80 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_81 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_52 == V_178 ) {
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( V_32 -> V_14 != 0 || V_32 -> V_17 != 0 ) {
F_2 ( L_72 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
} else {
if ( V_32 -> V_40 != V_162 || V_32 -> V_17 != 0 ) {
F_2 ( L_72 ) ;
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
if ( F_25 ( V_59 , V_32 -> V_40 ) ) {
F_2 ( L_73 ,
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
} else if ( V_52 > V_176 ) {
F_2 ( L_74 , V_52 ) ;
return - V_78 ;
} else {
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( V_32 -> V_14 != 0 || V_32 -> V_17 != 0 ) {
F_2 ( L_75 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
} else {
if ( V_32 -> V_40 != V_162 || V_32 -> V_17 != 0 ) {
F_2 ( L_75 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( ( V_52 == V_179 || V_52 == V_180 ) &&
F_5 ( V_32 -> V_34 ) == V_166 && V_32 -> V_14 == 0 ) {
F_2 ( L_76 ) ;
return - V_78 ;
}
if ( ( V_52 == V_172 || V_52 == V_175 ||
V_52 == V_181 ) && F_5 ( V_32 -> V_34 ) == V_166 ) {
int V_88 = F_4 ( V_32 -> V_34 ) == V_36 ? 64 : 32 ;
if ( V_32 -> V_14 < 0 || V_32 -> V_14 >= V_88 ) {
F_2 ( L_77 , V_32 -> V_14 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_182 ) ;
if ( V_70 )
return V_70 ;
V_38 = & V_9 [ V_32 -> V_38 ] ;
if ( V_52 == V_171 && F_4 ( V_32 -> V_34 ) == V_36 &&
V_38 -> type == V_73 && F_5 ( V_32 -> V_34 ) == V_166 ) {
V_38 -> type = V_13 ;
V_38 -> V_14 = V_32 -> V_14 ;
return 0 ;
} else if ( V_52 == V_171 &&
F_4 ( V_32 -> V_34 ) == V_36 &&
( V_38 -> type == V_15 ||
( F_5 ( V_32 -> V_34 ) == V_37 &&
V_9 [ V_32 -> V_40 ] . type == V_15 ) ) ) {
return F_37 ( V_59 , V_32 ) ;
} else if ( F_4 ( V_32 -> V_34 ) == V_36 &&
V_38 -> type == V_19 &&
V_59 -> V_103 ) {
return F_38 ( V_59 , V_32 ) ;
} else if ( F_4 ( V_32 -> V_34 ) == V_36 &&
V_38 -> type == V_12 &&
V_59 -> V_103 ) {
return F_42 ( V_59 , V_32 ) ;
} else if ( F_25 ( V_59 , V_32 -> V_38 ) ) {
F_2 ( L_71 ,
V_32 -> V_38 ) ;
return - V_80 ;
} else if ( F_5 ( V_32 -> V_34 ) == V_37 &&
F_25 ( V_59 , V_32 -> V_40 ) ) {
F_2 ( L_71 ,
V_32 -> V_40 ) ;
return - V_80 ;
}
F_14 ( V_9 , V_32 -> V_38 ) ;
}
return 0 ;
}
static void F_44 ( struct V_58 * V_59 ,
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
static int F_45 ( struct V_58 * V_59 ,
struct V_31 * V_32 , int * V_63 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 , * V_38 ;
struct V_1 * V_183 ;
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
int V_70 ;
if ( V_52 > V_55 ) {
F_2 ( L_78 , V_52 ) ;
return - V_78 ;
}
if ( F_5 ( V_32 -> V_34 ) == V_37 ) {
if ( V_32 -> V_14 != 0 ) {
F_2 ( L_79 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( F_25 ( V_59 , V_32 -> V_40 ) ) {
F_2 ( L_80 ,
V_32 -> V_40 ) ;
return - V_80 ;
}
} else {
if ( V_32 -> V_40 != V_162 ) {
F_2 ( L_79 ) ;
return - V_78 ;
}
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_38 = & V_9 [ V_32 -> V_38 ] ;
if ( F_5 ( V_32 -> V_34 ) == V_166 &&
( V_52 == V_184 || V_52 == V_185 ) &&
V_38 -> type == V_12 && V_38 -> V_14 == V_32 -> V_14 ) {
if ( V_52 == V_184 ) {
* V_63 += V_32 -> V_17 ;
return 0 ;
} else {
return 0 ;
}
}
V_183 = F_11 ( V_59 , * V_63 + V_32 -> V_17 + 1 , * V_63 ) ;
if ( ! V_183 )
return - V_128 ;
if ( F_5 ( V_32 -> V_34 ) == V_166 &&
V_32 -> V_14 == 0 && ( V_52 == V_184 || V_52 == V_185 ) &&
V_38 -> type == V_22 ) {
if ( V_52 == V_184 ) {
V_9 [ V_32 -> V_38 ] . type = V_21 ;
F_14 ( V_183 -> V_9 ,
V_32 -> V_38 ) ;
} else {
V_183 -> V_9 [ V_32 -> V_38 ] . type = V_21 ;
F_14 ( V_9 , V_32 -> V_38 ) ;
}
} else if ( F_5 ( V_32 -> V_34 ) == V_37 && V_52 == V_186 &&
V_38 -> type == V_15 &&
V_9 [ V_32 -> V_40 ] . type == V_87 ) {
F_44 ( V_59 , V_38 ) ;
} else if ( F_25 ( V_59 , V_32 -> V_38 ) ) {
F_2 ( L_80 , V_32 -> V_38 ) ;
return - V_80 ;
}
if ( V_187 )
F_1 ( & V_59 -> V_65 ) ;
return 0 ;
}
static struct V_92 * F_46 ( struct V_31 * V_32 )
{
T_5 V_188 = ( ( T_5 ) ( T_2 ) V_32 [ 0 ] . V_14 ) | ( ( T_5 ) ( T_2 ) V_32 [ 1 ] . V_14 ) << 32 ;
return (struct V_92 * ) ( unsigned long ) V_188 ;
}
static int F_47 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
int V_70 ;
if ( F_8 ( V_32 -> V_34 ) != V_86 ) {
F_2 ( L_81 ) ;
return - V_78 ;
}
if ( V_32 -> V_17 != 0 ) {
F_2 ( L_82 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_81 ) ;
if ( V_70 )
return V_70 ;
if ( V_32 -> V_40 == 0 )
return 0 ;
F_15 ( V_32 -> V_40 != V_189 ) ;
V_9 [ V_32 -> V_38 ] . type = V_20 ;
V_9 [ V_32 -> V_38 ] . V_23 = F_46 ( V_32 ) ;
return 0 ;
}
static bool F_48 ( enum V_94 type )
{
switch ( type ) {
case V_190 :
case V_104 :
case V_105 :
return true ;
default:
return false ;
}
}
static int F_49 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_3 * V_9 = V_59 -> V_65 . V_9 ;
T_1 V_191 = F_7 ( V_32 -> V_34 ) ;
struct V_3 * V_4 ;
int V_7 , V_70 ;
if ( ! F_48 ( V_59 -> V_98 -> type ) ) {
F_2 ( L_83 ) ;
return - V_78 ;
}
if ( V_32 -> V_38 != V_162 || V_32 -> V_17 != 0 ||
F_8 ( V_32 -> V_34 ) == V_86 ||
( V_191 == V_48 && V_32 -> V_40 != V_162 ) ) {
F_2 ( L_84 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_192 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( V_9 [ V_192 ] . type != V_75 ) {
F_2 ( L_85 ) ;
return - V_78 ;
}
if ( V_191 == V_49 ) {
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
}
for ( V_7 = 0 ; V_7 < V_158 ; V_7 ++ ) {
V_4 = V_9 + V_159 [ V_7 ] ;
V_4 -> type = V_10 ;
V_4 -> V_14 = 0 ;
}
V_9 [ V_162 ] . type = V_19 ;
return 0 ;
}
static int F_50 ( int V_6 , int V_193 , int V_194 , struct V_58 * V_59 )
{
if ( V_194 == V_195 && V_196 [ V_6 ] >= ( V_197 | V_195 ) )
return 0 ;
if ( V_194 == V_198 && V_196 [ V_6 ] >= ( V_197 | V_198 ) )
return 0 ;
if ( V_193 < 0 || V_193 >= V_59 -> V_98 -> V_199 ) {
F_2 ( L_86 , V_6 , V_193 ) ;
return - V_78 ;
}
if ( V_194 == V_198 )
V_59 -> V_200 [ V_193 ] = V_201 ;
if ( V_196 [ V_193 ] == 0 ) {
V_196 [ V_6 ] = V_197 | V_194 ;
V_196 [ V_193 ] = V_197 ;
if ( V_202 >= V_59 -> V_98 -> V_199 )
return - V_203 ;
V_204 [ V_202 ++ ] = V_193 ;
return 1 ;
} else if ( ( V_196 [ V_193 ] & 0xF0 ) == V_197 ) {
F_2 ( L_87 , V_6 , V_193 ) ;
return - V_78 ;
} else if ( V_196 [ V_193 ] == V_205 ) {
V_196 [ V_6 ] = V_197 | V_194 ;
} else {
F_2 ( L_88 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_51 ( struct V_58 * V_59 )
{
struct V_31 * V_206 = V_59 -> V_98 -> V_207 ;
int V_208 = V_59 -> V_98 -> V_199 ;
int V_209 = 0 ;
int V_7 , V_6 ;
V_196 = F_52 ( V_208 , sizeof( int ) , V_69 ) ;
if ( ! V_196 )
return - V_210 ;
V_204 = F_52 ( V_208 , sizeof( int ) , V_69 ) ;
if ( ! V_204 ) {
F_10 ( V_196 ) ;
return - V_210 ;
}
V_196 [ 0 ] = V_197 ;
V_204 [ 0 ] = 0 ;
V_202 = 1 ;
V_211:
if ( V_202 == 0 )
goto V_212;
V_6 = V_204 [ V_202 - 1 ] ;
if ( F_4 ( V_206 [ V_6 ] . V_34 ) == V_51 ) {
T_1 V_52 = F_6 ( V_206 [ V_6 ] . V_34 ) ;
if ( V_52 == V_55 ) {
goto V_213;
} else if ( V_52 == V_53 ) {
V_209 = F_50 ( V_6 , V_6 + 1 , V_195 , V_59 ) ;
if ( V_209 == 1 )
goto V_211;
else if ( V_209 < 0 )
goto V_214;
if ( V_6 + 1 < V_208 )
V_59 -> V_200 [ V_6 + 1 ] = V_201 ;
} else if ( V_52 == V_54 ) {
if ( F_5 ( V_206 [ V_6 ] . V_34 ) != V_166 ) {
V_209 = - V_78 ;
goto V_214;
}
V_209 = F_50 ( V_6 , V_6 + V_206 [ V_6 ] . V_17 + 1 ,
V_195 , V_59 ) ;
if ( V_209 == 1 )
goto V_211;
else if ( V_209 < 0 )
goto V_214;
if ( V_6 + 1 < V_208 )
V_59 -> V_200 [ V_6 + 1 ] = V_201 ;
} else {
V_209 = F_50 ( V_6 , V_6 + 1 , V_195 , V_59 ) ;
if ( V_209 == 1 )
goto V_211;
else if ( V_209 < 0 )
goto V_214;
V_209 = F_50 ( V_6 , V_6 + V_206 [ V_6 ] . V_17 + 1 , V_198 , V_59 ) ;
if ( V_209 == 1 )
goto V_211;
else if ( V_209 < 0 )
goto V_214;
}
} else {
V_209 = F_50 ( V_6 , V_6 + 1 , V_195 , V_59 ) ;
if ( V_209 == 1 )
goto V_211;
else if ( V_209 < 0 )
goto V_214;
}
V_213:
V_196 [ V_6 ] = V_205 ;
if ( V_202 -- <= 0 ) {
F_2 ( L_89 ) ;
V_209 = - V_128 ;
goto V_214;
}
goto V_211;
V_212:
for ( V_7 = 0 ; V_7 < V_208 ; V_7 ++ ) {
if ( V_196 [ V_7 ] != V_205 ) {
F_2 ( L_90 , V_7 ) ;
V_209 = - V_78 ;
goto V_214;
}
}
V_209 = 0 ;
V_214:
F_10 ( V_196 ) ;
F_10 ( V_204 ) ;
return V_209 ;
}
static bool F_53 ( struct V_3 * V_215 , struct V_3 * V_216 )
{
if ( V_215 -> V_16 != V_216 -> V_16 )
return false ;
if ( V_215 -> V_17 == V_216 -> V_17 && V_215 -> V_18 < V_216 -> V_18 )
return true ;
if ( V_215 -> V_17 <= V_216 -> V_17 &&
V_215 -> V_17 >= V_215 -> V_18 && V_216 -> V_17 >= V_216 -> V_18 )
return true ;
return false ;
}
static bool F_54 ( struct V_1 * V_215 , struct V_1 * V_216 )
{
struct V_3 * V_217 , * V_218 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_217 = & V_215 -> V_9 [ V_7 ] ;
V_218 = & V_216 -> V_9 [ V_7 ] ;
if ( memcmp ( V_217 , V_218 , sizeof( * V_217 ) ) == 0 )
continue;
if ( V_217 -> type == V_10 ||
( V_217 -> type == V_19 && V_218 -> type != V_10 ) )
continue;
if ( V_217 -> type == V_15 && V_218 -> type == V_15 &&
F_53 ( V_217 , V_218 ) )
continue;
return false ;
}
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
if ( V_215 -> V_28 [ V_7 ] == V_219 )
continue;
if ( V_215 -> V_28 [ V_7 ] != V_216 -> V_28 [ V_7 ] )
return false ;
if ( V_7 % V_27 )
continue;
if ( memcmp ( & V_215 -> V_30 [ V_7 / V_27 ] ,
& V_216 -> V_30 [ V_7 / V_27 ] ,
sizeof( V_215 -> V_30 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_55 ( struct V_58 * V_59 , int V_63 )
{
struct V_220 * V_221 ;
struct V_220 * V_222 ;
V_222 = V_59 -> V_200 [ V_63 ] ;
if ( ! V_222 )
return 0 ;
while ( V_222 != V_201 ) {
if ( F_54 ( & V_222 -> V_2 , & V_59 -> V_65 ) )
return 1 ;
V_222 = V_222 -> V_67 ;
}
V_221 = F_12 ( sizeof( struct V_220 ) , V_223 ) ;
if ( ! V_221 )
return - V_210 ;
memcpy ( & V_221 -> V_2 , & V_59 -> V_65 , sizeof( V_59 -> V_65 ) ) ;
V_221 -> V_67 = V_59 -> V_200 [ V_63 ] ;
V_59 -> V_200 [ V_63 ] = V_221 ;
return 0 ;
}
static int F_56 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_59 -> V_65 ;
struct V_31 * V_206 = V_59 -> V_98 -> V_207 ;
struct V_3 * V_9 = V_2 -> V_9 ;
int V_208 = V_59 -> V_98 -> V_199 ;
int V_63 , V_60 = 0 ;
int V_224 = 0 ;
bool V_225 = false ;
F_13 ( V_9 ) ;
V_63 = 0 ;
for (; ; ) {
struct V_31 * V_32 ;
T_1 V_33 ;
int V_70 ;
if ( V_63 >= V_208 ) {
F_2 ( L_91 ,
V_63 , V_208 ) ;
return - V_128 ;
}
V_32 = & V_206 [ V_63 ] ;
V_33 = F_4 ( V_32 -> V_34 ) ;
if ( ++ V_224 > V_226 ) {
F_2 ( L_92 ,
V_224 ) ;
return - V_203 ;
}
V_70 = F_55 ( V_59 , V_63 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_70 == 1 ) {
if ( V_187 ) {
if ( V_225 )
F_2 ( L_93 ,
V_60 , V_63 ) ;
else
F_2 ( L_94 , V_63 ) ;
}
goto V_227;
}
if ( V_187 && V_225 ) {
F_2 ( L_95 , V_60 , V_63 ) ;
F_1 ( & V_59 -> V_65 ) ;
V_225 = false ;
}
if ( V_187 ) {
F_2 ( L_96 , V_63 ) ;
F_3 ( V_32 ) ;
}
if ( V_33 == V_35 || V_33 == V_36 ) {
V_70 = F_43 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_33 == V_46 ) {
enum V_5 V_228 ;
V_70 = F_16 ( V_9 , V_32 -> V_40 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_182 ) ;
if ( V_70 )
return V_70 ;
V_228 = V_9 [ V_32 -> V_40 ] . type ;
V_70 = F_28 ( V_59 , V_32 -> V_40 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_109 ,
V_32 -> V_38 ) ;
if ( V_70 )
return V_70 ;
if ( F_8 ( V_32 -> V_34 ) != V_83 ) {
V_63 ++ ;
continue;
}
if ( V_32 -> V_14 == 0 ) {
V_32 -> V_14 = V_228 ;
} else if ( V_228 != V_32 -> V_14 &&
( V_228 == V_75 ||
V_32 -> V_14 == V_75 ) ) {
F_2 ( L_97 ) ;
return - V_78 ;
}
} else if ( V_33 == V_41 ) {
enum V_5 V_229 ;
if ( F_7 ( V_32 -> V_34 ) == V_44 ) {
V_70 = F_29 ( V_59 , V_32 ) ;
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
V_229 = V_9 [ V_32 -> V_38 ] . type ;
V_70 = F_28 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_108 ,
V_32 -> V_40 ) ;
if ( V_70 )
return V_70 ;
if ( V_32 -> V_14 == 0 ) {
V_32 -> V_14 = V_229 ;
} else if ( V_229 != V_32 -> V_14 &&
( V_229 == V_75 ||
V_32 -> V_14 == V_75 ) ) {
F_2 ( L_97 ) ;
return - V_78 ;
}
} else if ( V_33 == V_45 ) {
if ( F_7 ( V_32 -> V_34 ) != V_42 ||
V_32 -> V_40 != V_162 ) {
F_2 ( L_98 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_32 -> V_38 , V_79 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_28 ( V_59 , V_32 -> V_38 , V_32 -> V_17 ,
F_8 ( V_32 -> V_34 ) , V_108 ,
- 1 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_33 == V_51 ) {
T_1 V_52 = F_6 ( V_32 -> V_34 ) ;
if ( V_52 == V_53 ) {
if ( F_5 ( V_32 -> V_34 ) != V_166 ||
V_32 -> V_17 != 0 ||
V_32 -> V_40 != V_162 ||
V_32 -> V_38 != V_162 ) {
F_2 ( L_99 ) ;
return - V_78 ;
}
V_70 = F_35 ( V_59 , V_32 -> V_14 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_52 == V_54 ) {
if ( F_5 ( V_32 -> V_34 ) != V_166 ||
V_32 -> V_14 != 0 ||
V_32 -> V_40 != V_162 ||
V_32 -> V_38 != V_162 ) {
F_2 ( L_100 ) ;
return - V_78 ;
}
V_63 += V_32 -> V_17 + 1 ;
continue;
} else if ( V_52 == V_55 ) {
if ( F_5 ( V_32 -> V_34 ) != V_166 ||
V_32 -> V_14 != 0 ||
V_32 -> V_40 != V_162 ||
V_32 -> V_38 != V_162 ) {
F_2 ( L_101 ) ;
return - V_78 ;
}
V_70 = F_16 ( V_9 , V_162 , V_79 ) ;
if ( V_70 )
return V_70 ;
if ( F_25 ( V_59 , V_162 ) ) {
F_2 ( L_102 ) ;
return - V_80 ;
}
V_227:
V_63 = F_9 ( V_59 , & V_60 ) ;
if ( V_63 < 0 ) {
break;
} else {
V_225 = true ;
continue;
}
} else {
V_70 = F_45 ( V_59 , V_32 , & V_63 ) ;
if ( V_70 )
return V_70 ;
}
} else if ( V_33 == V_47 ) {
T_1 V_191 = F_7 ( V_32 -> V_34 ) ;
if ( V_191 == V_48 || V_191 == V_49 ) {
V_70 = F_49 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_191 == V_50 ) {
V_70 = F_47 ( V_59 , V_32 ) ;
if ( V_70 )
return V_70 ;
V_63 ++ ;
} else {
F_2 ( L_103 ) ;
return - V_78 ;
}
} else {
F_2 ( L_104 , V_33 ) ;
return - V_78 ;
}
V_63 ++ ;
}
F_2 ( L_105 , V_224 ) ;
return 0 ;
}
static int F_57 ( struct V_58 * V_59 )
{
struct V_31 * V_32 = V_59 -> V_98 -> V_207 ;
int V_208 = V_59 -> V_98 -> V_199 ;
int V_7 , V_230 ;
for ( V_7 = 0 ; V_7 < V_208 ; V_7 ++ , V_32 ++ ) {
if ( F_4 ( V_32 -> V_34 ) == V_46 &&
( F_7 ( V_32 -> V_34 ) != V_42 || V_32 -> V_14 != 0 ) ) {
F_2 ( L_106 ) ;
return - V_78 ;
}
if ( F_4 ( V_32 -> V_34 ) == V_41 &&
( ( F_7 ( V_32 -> V_34 ) != V_42 &&
F_7 ( V_32 -> V_34 ) != V_44 ) || V_32 -> V_14 != 0 ) ) {
F_2 ( L_107 ) ;
return - V_78 ;
}
if ( V_32 [ 0 ] . V_34 == ( V_47 | V_50 | V_86 ) ) {
struct V_92 * V_93 ;
struct V_231 V_232 ;
if ( V_7 == V_208 - 1 || V_32 [ 1 ] . V_34 != 0 ||
V_32 [ 1 ] . V_38 != 0 || V_32 [ 1 ] . V_40 != 0 ||
V_32 [ 1 ] . V_17 != 0 ) {
F_2 ( L_108 ) ;
return - V_78 ;
}
if ( V_32 -> V_40 == 0 )
goto V_233;
if ( V_32 -> V_40 != V_189 ) {
F_2 ( L_109 ) ;
return - V_78 ;
}
V_232 = F_58 ( V_32 -> V_14 ) ;
V_93 = F_59 ( V_232 ) ;
if ( F_60 ( V_93 ) ) {
F_2 ( L_110 ,
V_32 -> V_14 ) ;
return F_61 ( V_93 ) ;
}
V_32 [ 0 ] . V_14 = ( T_2 ) ( unsigned long ) V_93 ;
V_32 [ 1 ] . V_14 = ( ( T_5 ) ( unsigned long ) V_93 ) >> 32 ;
for ( V_230 = 0 ; V_230 < V_59 -> V_234 ; V_230 ++ )
if ( V_59 -> V_235 [ V_230 ] == V_93 ) {
F_62 ( V_232 ) ;
goto V_233;
}
if ( V_59 -> V_234 >= V_236 ) {
F_62 ( V_232 ) ;
return - V_203 ;
}
V_93 = F_63 ( V_93 , false ) ;
if ( F_60 ( V_93 ) ) {
F_62 ( V_232 ) ;
return F_61 ( V_93 ) ;
}
V_59 -> V_235 [ V_59 -> V_234 ++ ] = V_93 ;
F_62 ( V_232 ) ;
V_233:
V_32 ++ ;
V_7 ++ ;
}
}
return 0 ;
}
static void F_64 ( struct V_58 * V_59 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_59 -> V_234 ; V_7 ++ )
F_65 ( V_59 -> V_235 [ V_7 ] ) ;
}
static void F_66 ( struct V_58 * V_59 )
{
struct V_31 * V_32 = V_59 -> V_98 -> V_207 ;
int V_208 = V_59 -> V_98 -> V_199 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_208 ; V_7 ++ , V_32 ++ )
if ( V_32 -> V_34 == ( V_47 | V_50 | V_86 ) )
V_32 -> V_40 = 0 ;
}
static int F_67 ( struct V_58 * V_59 )
{
struct V_31 * V_32 = V_59 -> V_98 -> V_207 ;
int V_208 = V_59 -> V_98 -> V_199 ;
struct V_31 V_237 [ 16 ] ;
struct V_238 * V_239 ;
enum V_96 type ;
int V_7 ;
if ( ! V_59 -> V_98 -> V_99 -> V_100 -> V_240 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_208 ; V_7 ++ , V_32 ++ ) {
T_2 V_241 , V_242 ;
if ( V_32 -> V_34 == ( V_46 | V_42 | V_83 ) )
type = V_109 ;
else if ( V_32 -> V_34 == ( V_41 | V_42 | V_83 ) )
type = V_108 ;
else
continue;
if ( V_32 -> V_14 != V_75 ) {
V_32 -> V_14 = 0 ;
continue;
}
V_242 = V_59 -> V_98 -> V_99 -> V_100 ->
V_240 ( type , V_32 -> V_38 , V_32 -> V_40 ,
V_32 -> V_17 , V_237 , V_59 -> V_98 ) ;
if ( V_242 == 0 || V_242 >= F_68 ( V_237 ) ) {
F_2 ( L_111 ) ;
return - V_78 ;
}
V_239 = F_69 ( V_59 -> V_98 , V_7 , V_237 , V_242 ) ;
if ( ! V_239 )
return - V_210 ;
V_241 = V_242 - 1 ;
V_59 -> V_98 = V_239 ;
V_32 = V_239 -> V_207 + V_7 + V_241 ;
V_208 += V_241 ;
V_7 += V_241 ;
}
return 0 ;
}
static void F_70 ( struct V_58 * V_59 )
{
struct V_220 * V_222 , * V_243 ;
int V_7 ;
if ( ! V_59 -> V_200 )
return;
for ( V_7 = 0 ; V_7 < V_59 -> V_98 -> V_199 ; V_7 ++ ) {
V_222 = V_59 -> V_200 [ V_7 ] ;
if ( V_222 )
while ( V_222 != V_201 ) {
V_243 = V_222 -> V_67 ;
F_10 ( V_222 ) ;
V_222 = V_243 ;
}
}
F_10 ( V_59 -> V_200 ) ;
}
int F_71 ( struct V_238 * * V_98 , union V_244 * V_245 )
{
char T_6 * V_246 = NULL ;
struct V_58 * V_59 ;
int V_209 = - V_78 ;
if ( ( * V_98 ) -> V_199 <= 0 || ( * V_98 ) -> V_199 > V_247 )
return - V_203 ;
V_59 = F_72 ( sizeof( struct V_58 ) , V_69 ) ;
if ( ! V_59 )
return - V_210 ;
V_59 -> V_98 = * V_98 ;
F_73 ( & V_248 ) ;
if ( V_245 -> V_187 || V_245 -> V_249 || V_245 -> V_250 ) {
V_187 = V_245 -> V_187 ;
V_246 = ( char T_6 * ) ( unsigned long ) V_245 -> V_249 ;
V_250 = V_245 -> V_250 ;
V_251 = 0 ;
V_209 = - V_78 ;
if ( V_250 < 128 || V_250 > V_252 >> 8 ||
V_187 == 0 || V_246 == NULL )
goto V_253;
V_209 = - V_210 ;
V_249 = F_74 ( V_250 ) ;
if ( ! V_249 )
goto V_253;
} else {
V_187 = 0 ;
}
V_209 = F_57 ( V_59 ) ;
if ( V_209 < 0 )
goto V_254;
V_59 -> V_200 = F_52 ( V_59 -> V_98 -> V_199 ,
sizeof( struct V_220 * ) ,
V_223 ) ;
V_209 = - V_210 ;
if ( ! V_59 -> V_200 )
goto V_254;
V_209 = F_51 ( V_59 ) ;
if ( V_209 < 0 )
goto V_254;
V_59 -> V_103 = F_75 ( V_255 ) ;
V_209 = F_56 ( V_59 ) ;
V_254:
while ( F_9 ( V_59 , NULL ) >= 0 ) ;
F_70 ( V_59 ) ;
if ( V_209 == 0 )
V_209 = F_67 ( V_59 ) ;
if ( V_187 && V_251 >= V_250 - 1 ) {
F_15 ( V_251 >= V_250 ) ;
V_209 = - V_256 ;
}
if ( V_187 && F_76 ( V_246 , V_249 , V_251 + 1 ) != 0 ) {
V_209 = - V_128 ;
goto V_257;
}
if ( V_209 == 0 && V_59 -> V_234 ) {
V_59 -> V_98 -> V_99 -> V_235 = F_77 ( V_59 -> V_234 ,
sizeof( V_59 -> V_235 [ 0 ] ) ,
V_69 ) ;
if ( ! V_59 -> V_98 -> V_99 -> V_235 ) {
V_209 = - V_210 ;
goto V_257;
}
memcpy ( V_59 -> V_98 -> V_99 -> V_235 , V_59 -> V_235 ,
sizeof( V_59 -> V_235 [ 0 ] ) * V_59 -> V_234 ) ;
V_59 -> V_98 -> V_99 -> V_234 = V_59 -> V_234 ;
F_66 ( V_59 ) ;
}
V_257:
if ( V_187 )
F_78 ( V_249 ) ;
V_253:
if ( ! V_59 -> V_98 -> V_99 -> V_235 )
F_64 ( V_59 ) ;
* V_98 = V_59 -> V_98 ;
F_10 ( V_59 ) ;
F_79 ( & V_248 ) ;
return V_209 ;
}
