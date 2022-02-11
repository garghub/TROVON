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
V_6 == V_22 ||
V_6 == V_23 )
F_2 ( L_4 ,
V_4 -> V_24 -> V_25 ,
V_4 -> V_24 -> V_26 ) ;
if ( V_4 -> V_27 != V_28 )
F_2 ( L_5 ,
( long long ) V_4 -> V_27 ) ;
if ( V_4 -> V_29 != V_30 )
F_2 ( L_6 ,
( unsigned long long ) V_4 -> V_29 ) ;
}
for ( V_7 = 0 ; V_7 < V_31 ; V_7 += V_32 ) {
if ( V_2 -> V_33 [ V_7 ] == V_34 )
F_2 ( L_7 , - V_31 + V_7 ,
V_11 [ V_2 -> V_35 [ V_7 / V_32 ] . type ] ) ;
}
F_2 ( L_8 ) ;
}
static void F_3 ( struct V_36 * V_37 )
{
T_1 V_38 = F_4 ( V_37 -> V_39 ) ;
if ( V_38 == V_40 || V_38 == V_41 ) {
if ( F_5 ( V_37 -> V_39 ) == V_42 )
F_2 ( L_9 ,
V_37 -> V_39 , V_38 == V_40 ? L_10 : L_11 ,
V_37 -> V_43 ,
V_44 [ F_6 ( V_37 -> V_39 ) >> 4 ] ,
V_38 == V_40 ? L_10 : L_11 ,
V_37 -> V_45 ) ;
else
F_2 ( L_12 ,
V_37 -> V_39 , V_38 == V_40 ? L_10 : L_11 ,
V_37 -> V_43 ,
V_44 [ F_6 ( V_37 -> V_39 ) >> 4 ] ,
V_38 == V_40 ? L_10 : L_11 ,
V_37 -> V_14 ) ;
} else if ( V_38 == V_46 ) {
if ( F_7 ( V_37 -> V_39 ) == V_47 )
F_2 ( L_13 ,
V_37 -> V_39 ,
V_48 [ F_8 ( V_37 -> V_39 ) >> 3 ] ,
V_37 -> V_43 ,
V_37 -> V_17 , V_37 -> V_45 ) ;
else if ( F_7 ( V_37 -> V_39 ) == V_49 )
F_2 ( L_14 ,
V_37 -> V_39 ,
V_48 [ F_8 ( V_37 -> V_39 ) >> 3 ] ,
V_37 -> V_43 , V_37 -> V_17 ,
V_37 -> V_45 ) ;
else
F_2 ( L_15 , V_37 -> V_39 ) ;
} else if ( V_38 == V_50 ) {
if ( F_7 ( V_37 -> V_39 ) != V_47 ) {
F_2 ( L_16 , V_37 -> V_39 ) ;
return;
}
F_2 ( L_17 ,
V_37 -> V_39 ,
V_48 [ F_8 ( V_37 -> V_39 ) >> 3 ] ,
V_37 -> V_43 ,
V_37 -> V_17 , V_37 -> V_14 ) ;
} else if ( V_38 == V_51 ) {
if ( F_7 ( V_37 -> V_39 ) != V_47 ) {
F_2 ( L_18 , V_37 -> V_39 ) ;
return;
}
F_2 ( L_19 ,
V_37 -> V_39 , V_37 -> V_43 ,
V_48 [ F_8 ( V_37 -> V_39 ) >> 3 ] ,
V_37 -> V_45 , V_37 -> V_17 ) ;
} else if ( V_38 == V_52 ) {
if ( F_7 ( V_37 -> V_39 ) == V_53 ) {
F_2 ( L_20 ,
V_37 -> V_39 ,
V_48 [ F_8 ( V_37 -> V_39 ) >> 3 ] ,
V_37 -> V_14 ) ;
} else if ( F_7 ( V_37 -> V_39 ) == V_54 ) {
F_2 ( L_21 ,
V_37 -> V_39 ,
V_48 [ F_8 ( V_37 -> V_39 ) >> 3 ] ,
V_37 -> V_45 , V_37 -> V_14 ) ;
} else if ( F_7 ( V_37 -> V_39 ) == V_55 ) {
F_2 ( L_22 ,
V_37 -> V_39 , V_37 -> V_43 , V_37 -> V_14 ) ;
} else {
F_2 ( L_23 , V_37 -> V_39 ) ;
return;
}
} else if ( V_38 == V_56 ) {
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
if ( V_57 == V_58 ) {
F_2 ( L_24 , V_37 -> V_39 , V_37 -> V_14 ) ;
} else if ( V_37 -> V_39 == ( V_56 | V_59 ) ) {
F_2 ( L_25 ,
V_37 -> V_39 , V_37 -> V_17 ) ;
} else if ( V_37 -> V_39 == ( V_56 | V_60 ) ) {
F_2 ( L_26 , V_37 -> V_39 ) ;
} else if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
F_2 ( L_27 ,
V_37 -> V_39 , V_37 -> V_43 ,
V_61 [ F_6 ( V_37 -> V_39 ) >> 4 ] ,
V_37 -> V_45 , V_37 -> V_17 ) ;
} else {
F_2 ( L_28 ,
V_37 -> V_39 , V_37 -> V_43 ,
V_61 [ F_6 ( V_37 -> V_39 ) >> 4 ] ,
V_37 -> V_14 , V_37 -> V_17 ) ;
}
} else {
F_2 ( L_29 , V_37 -> V_39 , V_62 [ V_38 ] ) ;
}
}
static int F_9 ( struct V_63 * V_64 , int * V_65 )
{
struct V_66 * V_67 ;
int V_68 ;
if ( V_64 -> V_69 == NULL )
return - 1 ;
memcpy ( & V_64 -> V_70 , & V_64 -> V_69 -> V_71 , sizeof( V_64 -> V_70 ) ) ;
V_68 = V_64 -> V_69 -> V_68 ;
if ( V_65 )
* V_65 = V_64 -> V_69 -> V_65 ;
V_67 = V_64 -> V_69 -> V_72 ;
F_10 ( V_64 -> V_69 ) ;
V_64 -> V_69 = V_67 ;
V_64 -> V_73 -- ;
return V_68 ;
}
static struct V_1 * F_11 ( struct V_63 * V_64 ,
int V_68 , int V_65 )
{
struct V_66 * V_67 ;
V_67 = F_12 ( sizeof( struct V_66 ) , V_74 ) ;
if ( ! V_67 )
goto V_75;
memcpy ( & V_67 -> V_71 , & V_64 -> V_70 , sizeof( V_64 -> V_70 ) ) ;
V_67 -> V_68 = V_68 ;
V_67 -> V_65 = V_65 ;
V_67 -> V_72 = V_64 -> V_69 ;
V_64 -> V_69 = V_67 ;
V_64 -> V_73 ++ ;
if ( V_64 -> V_73 > V_76 ) {
F_2 ( L_30 ) ;
goto V_75;
}
return & V_67 -> V_71 ;
V_75:
while ( F_9 ( V_64 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_13 ( struct V_3 * V_9 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_9 [ V_7 ] . type = V_10 ;
V_9 [ V_7 ] . V_14 = 0 ;
V_9 [ V_7 ] . V_27 = V_28 ;
V_9 [ V_7 ] . V_29 = V_30 ;
}
V_9 [ V_77 ] . type = V_78 ;
V_9 [ V_79 ] . type = V_80 ;
}
static void F_14 ( struct V_3 * V_9 , T_2 V_81 )
{
F_15 ( V_81 >= V_8 ) ;
V_9 [ V_81 ] . type = V_19 ;
V_9 [ V_81 ] . V_14 = 0 ;
}
static void F_16 ( struct V_3 * V_9 , T_2 V_81 )
{
V_9 [ V_81 ] . V_27 = V_28 ;
V_9 [ V_81 ] . V_29 = V_30 ;
}
static int F_17 ( struct V_3 * V_9 , T_2 V_81 ,
enum V_82 V_6 )
{
if ( V_81 >= V_8 ) {
F_2 ( L_31 , V_81 ) ;
return - V_83 ;
}
if ( V_6 == V_84 ) {
if ( V_9 [ V_81 ] . type == V_10 ) {
F_2 ( L_32 , V_81 ) ;
return - V_85 ;
}
} else {
if ( V_81 == V_77 ) {
F_2 ( L_33 ) ;
return - V_85 ;
}
if ( V_6 == V_86 )
F_14 ( V_9 , V_81 ) ;
}
return 0 ;
}
static int F_18 ( int V_87 )
{
if ( V_87 == V_88 )
return 4 ;
else if ( V_87 == V_89 )
return 2 ;
else if ( V_87 == V_90 )
return 1 ;
else if ( V_87 == V_91 )
return 8 ;
else
return - V_83 ;
}
static bool F_19 ( enum V_5 type )
{
switch ( type ) {
case V_21 :
case V_22 :
case V_13 :
case V_80 :
case V_15 :
case V_92 :
case V_78 :
case V_20 :
return true ;
default:
return false ;
}
}
static int F_20 ( struct V_1 * V_2 , int V_17 ,
int V_93 , int V_94 )
{
int V_7 ;
if ( V_94 >= 0 &&
F_19 ( V_2 -> V_9 [ V_94 ] . type ) ) {
if ( V_93 != V_32 ) {
F_2 ( L_34 ) ;
return - V_85 ;
}
V_2 -> V_35 [ ( V_31 + V_17 ) / V_32 ] =
V_2 -> V_9 [ V_94 ] ;
for ( V_7 = 0 ; V_7 < V_32 ; V_7 ++ )
V_2 -> V_33 [ V_31 + V_17 + V_7 ] = V_34 ;
} else {
V_2 -> V_35 [ ( V_31 + V_17 ) / V_32 ] =
(struct V_3 ) {} ;
for ( V_7 = 0 ; V_7 < V_93 ; V_7 ++ )
V_2 -> V_33 [ V_31 + V_17 + V_7 ] = V_95 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_17 , int V_93 ,
int V_94 )
{
T_1 * V_96 ;
int V_7 ;
V_96 = & V_2 -> V_33 [ V_31 + V_17 ] ;
if ( V_96 [ 0 ] == V_34 ) {
if ( V_93 != V_32 ) {
F_2 ( L_34 ) ;
return - V_85 ;
}
for ( V_7 = 1 ; V_7 < V_32 ; V_7 ++ ) {
if ( V_96 [ V_7 ] != V_34 ) {
F_2 ( L_35 ) ;
return - V_85 ;
}
}
if ( V_94 >= 0 )
V_2 -> V_9 [ V_94 ] =
V_2 -> V_35 [ ( V_31 + V_17 ) / V_32 ] ;
return 0 ;
} else {
for ( V_7 = 0 ; V_7 < V_93 ; V_7 ++ ) {
if ( V_96 [ V_7 ] != V_95 ) {
F_2 ( L_36 ,
V_17 , V_7 , V_93 ) ;
return - V_85 ;
}
}
if ( V_94 >= 0 )
F_14 ( V_2 -> V_9 , V_94 ) ;
return 0 ;
}
}
static int F_22 ( struct V_63 * V_64 , T_2 V_81 , int V_17 ,
int V_93 )
{
struct V_97 * V_98 = V_64 -> V_70 . V_9 [ V_81 ] . V_24 ;
if ( V_17 < 0 || V_17 + V_93 > V_98 -> V_26 ) {
F_2 ( L_37 ,
V_98 -> V_26 , V_17 , V_93 ) ;
return - V_85 ;
}
return 0 ;
}
static bool F_23 ( struct V_63 * V_64 ,
const struct V_99 * V_100 )
{
switch ( V_64 -> V_101 -> type ) {
case V_102 :
case V_103 :
case V_104 :
if ( V_100 )
return V_100 -> V_105 ;
V_64 -> V_106 = true ;
return true ;
default:
return false ;
}
}
static int F_24 ( struct V_63 * V_64 , T_2 V_81 , int V_17 ,
int V_93 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
struct V_3 * V_4 = & V_9 [ V_81 ] ;
V_17 += V_4 -> V_17 ;
if ( V_17 < 0 || V_93 <= 0 || V_17 + V_93 > V_4 -> V_18 ) {
F_2 ( L_38 ,
V_17 , V_93 , V_81 , V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_18 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_25 ( struct V_63 * V_64 , int V_17 , int V_93 ,
enum V_107 V_6 , enum V_5 * V_108 )
{
if ( V_64 -> V_109 )
return 0 ;
if ( V_64 -> V_101 -> V_110 -> V_111 -> V_112 &&
V_64 -> V_101 -> V_110 -> V_111 -> V_112 ( V_17 , V_93 , V_6 , V_108 ) ) {
if ( V_64 -> V_101 -> V_110 -> V_113 < V_17 + V_93 )
V_64 -> V_101 -> V_110 -> V_113 = V_17 + V_93 ;
return 0 ;
}
F_2 ( L_39 , V_17 , V_93 ) ;
return - V_85 ;
}
static bool F_26 ( struct V_63 * V_64 , int V_81 )
{
if ( V_64 -> V_114 )
return false ;
switch ( V_64 -> V_70 . V_9 [ V_81 ] . type ) {
case V_19 :
case V_12 :
return false ;
default:
return true ;
}
}
static int F_27 ( struct V_63 * V_64 ,
struct V_3 * V_4 , int V_17 , int V_93 )
{
if ( V_4 -> type != V_15 && V_4 -> type != V_23 ) {
if ( V_17 % V_93 != 0 ) {
F_2 ( L_40 ,
V_17 , V_93 ) ;
return - V_85 ;
} else {
return 0 ;
}
}
if ( F_28 ( V_115 ) )
return 0 ;
if ( V_4 -> V_16 && V_93 != 1 ) {
F_2 ( L_41 ) ;
return - V_85 ;
}
if ( V_4 -> type == V_15 &&
( V_116 + V_4 -> V_17 + V_17 ) % V_93 != 0 ) {
F_2 ( L_42 ,
V_116 , V_4 -> V_17 , V_17 , V_93 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_29 ( struct V_63 * V_64 , T_2 V_81 , int V_17 ,
int V_87 , enum V_107 V_6 ,
int V_94 )
{
struct V_1 * V_2 = & V_64 -> V_70 ;
struct V_3 * V_4 = & V_2 -> V_9 [ V_81 ] ;
int V_93 , V_75 = 0 ;
if ( V_4 -> type == V_13 )
V_17 += V_4 -> V_14 ;
V_93 = F_18 ( V_87 ) ;
if ( V_93 < 0 )
return V_93 ;
V_75 = F_27 ( V_64 , V_4 , V_17 , V_93 ) ;
if ( V_75 )
return V_75 ;
if ( V_4 -> type == V_21 ||
V_4 -> type == V_23 ) {
if ( V_6 == V_117 && V_94 >= 0 &&
F_26 ( V_64 , V_94 ) ) {
F_2 ( L_43 , V_94 ) ;
return - V_85 ;
}
if ( V_4 -> type == V_23 ) {
if ( V_118 )
F_1 ( V_2 ) ;
V_64 -> V_119 = true ;
if ( V_4 -> V_27 < 0 ) {
F_2 ( L_44 ,
V_81 ) ;
return - V_85 ;
}
V_75 = F_22 ( V_64 , V_81 , V_4 -> V_27 + V_17 ,
V_93 ) ;
if ( V_75 ) {
F_2 ( L_45 ,
V_81 ) ;
return V_75 ;
}
if ( V_4 -> V_29 == V_30 ) {
F_2 ( L_46 ,
V_81 ) ;
return - V_85 ;
}
V_17 += V_4 -> V_29 ;
}
V_75 = F_22 ( V_64 , V_81 , V_17 , V_93 ) ;
if ( ! V_75 && V_6 == V_120 && V_94 >= 0 )
F_14 ( V_2 -> V_9 , V_94 ) ;
} else if ( V_4 -> type == V_80 ) {
enum V_5 V_108 = V_19 ;
if ( V_6 == V_117 && V_94 >= 0 &&
F_26 ( V_64 , V_94 ) ) {
F_2 ( L_47 , V_94 ) ;
return - V_85 ;
}
V_75 = F_25 ( V_64 , V_17 , V_93 , V_6 , & V_108 ) ;
if ( ! V_75 && V_6 == V_120 && V_94 >= 0 ) {
F_14 ( V_2 -> V_9 , V_94 ) ;
V_2 -> V_9 [ V_94 ] . type = V_108 ;
}
} else if ( V_4 -> type == V_78 || V_4 -> type == V_13 ) {
if ( V_17 >= 0 || V_17 < - V_31 ) {
F_2 ( L_48 , V_17 , V_93 ) ;
return - V_85 ;
}
if ( V_6 == V_117 ) {
if ( ! V_64 -> V_114 &&
V_2 -> V_33 [ V_31 + V_17 ] == V_34 &&
V_93 != V_32 ) {
F_2 ( L_49 ) ;
return - V_85 ;
}
V_75 = F_20 ( V_2 , V_17 , V_93 , V_94 ) ;
} else {
V_75 = F_21 ( V_2 , V_17 , V_93 , V_94 ) ;
}
} else if ( V_2 -> V_9 [ V_81 ] . type == V_15 ) {
if ( V_6 == V_117 && ! F_23 ( V_64 , NULL ) ) {
F_2 ( L_50 ) ;
return - V_85 ;
}
if ( V_6 == V_117 && V_94 >= 0 &&
F_26 ( V_64 , V_94 ) ) {
F_2 ( L_51 , V_94 ) ;
return - V_85 ;
}
V_75 = F_24 ( V_64 , V_81 , V_17 , V_93 ) ;
if ( ! V_75 && V_6 == V_120 && V_94 >= 0 )
F_14 ( V_2 -> V_9 , V_94 ) ;
} else {
F_2 ( L_52 ,
V_81 , V_11 [ V_4 -> type ] ) ;
return - V_85 ;
}
if ( ! V_75 && V_93 <= 2 && V_94 >= 0 && V_64 -> V_114 &&
V_2 -> V_9 [ V_94 ] . type == V_19 ) {
V_2 -> V_9 [ V_94 ] . V_14 = 64 - V_93 * 8 ;
}
return V_75 ;
}
static int F_30 ( struct V_63 * V_64 , struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
int V_75 ;
if ( ( F_8 ( V_37 -> V_39 ) != V_88 && F_8 ( V_37 -> V_39 ) != V_91 ) ||
V_37 -> V_14 != 0 ) {
F_2 ( L_53 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_29 ( V_64 , V_37 -> V_43 , V_37 -> V_17 ,
F_8 ( V_37 -> V_39 ) , V_120 , - 1 ) ;
if ( V_75 )
return V_75 ;
return F_29 ( V_64 , V_37 -> V_43 , V_37 -> V_17 ,
F_8 ( V_37 -> V_39 ) , V_117 , - 1 ) ;
}
static int F_31 ( struct V_63 * V_64 , int V_81 ,
int V_121 , bool V_122 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = & V_64 -> V_70 ;
struct V_3 * V_9 = V_2 -> V_9 ;
int V_17 , V_7 ;
if ( V_9 [ V_81 ] . type != V_13 ) {
if ( V_122 && V_121 == 0 &&
V_9 [ V_81 ] . type == V_12 &&
V_9 [ V_81 ] . V_14 == 0 )
return 0 ;
F_2 ( L_54 , V_81 ,
V_11 [ V_9 [ V_81 ] . type ] ,
V_11 [ V_13 ] ) ;
return - V_85 ;
}
V_17 = V_9 [ V_81 ] . V_14 ;
if ( V_17 >= 0 || V_17 < - V_31 || V_17 + V_121 > 0 ||
V_121 <= 0 ) {
F_2 ( L_55 ,
V_81 , V_17 , V_121 ) ;
return - V_85 ;
}
if ( V_100 && V_100 -> V_123 ) {
V_100 -> V_121 = V_121 ;
V_100 -> V_81 = V_81 ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_121 ; V_7 ++ ) {
if ( V_2 -> V_33 [ V_31 + V_17 + V_7 ] != V_95 ) {
F_2 ( L_56 ,
V_17 , V_7 , V_121 ) ;
return - V_85 ;
}
}
return 0 ;
}
static int F_32 ( struct V_63 * V_64 , T_2 V_81 ,
enum V_124 V_125 ,
struct V_99 * V_100 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 , * V_4 = & V_9 [ V_81 ] ;
enum V_5 V_126 , type = V_4 -> type ;
int V_75 = 0 ;
if ( V_125 == V_127 )
return 0 ;
if ( type == V_10 ) {
F_2 ( L_32 , V_81 ) ;
return - V_85 ;
}
if ( V_125 == V_128 ) {
if ( F_26 ( V_64 , V_81 ) ) {
F_2 ( L_57 , V_81 ) ;
return - V_85 ;
}
return 0 ;
}
if ( type == V_15 && ! F_23 ( V_64 , V_100 ) ) {
F_2 ( L_58 ) ;
return - V_85 ;
}
if ( V_125 == V_129 ||
V_125 == V_130 ) {
V_126 = V_13 ;
if ( type != V_15 && type != V_126 )
goto V_131;
} else if ( V_125 == V_132 ||
V_125 == V_133 ) {
V_126 = V_12 ;
if ( type != V_126 )
goto V_131;
} else if ( V_125 == V_134 ) {
V_126 = V_20 ;
if ( type != V_126 )
goto V_131;
} else if ( V_125 == V_135 ) {
V_126 = V_80 ;
if ( type != V_126 )
goto V_131;
} else if ( V_125 == V_136 ||
V_125 == V_137 ) {
V_126 = V_13 ;
if ( type == V_12 && V_4 -> V_14 == 0 )
;
else if ( type != V_15 && type != V_126 )
goto V_131;
V_100 -> V_123 = V_125 == V_137 ;
} else {
F_2 ( L_59 , V_125 ) ;
return - V_138 ;
}
if ( V_125 == V_134 ) {
V_100 -> V_24 = V_4 -> V_24 ;
} else if ( V_125 == V_129 ) {
if ( ! V_100 -> V_24 ) {
F_2 ( L_60 ) ;
return - V_85 ;
}
if ( type == V_15 )
V_75 = F_24 ( V_64 , V_81 , 0 ,
V_100 -> V_24 -> V_25 ) ;
else
V_75 = F_31 ( V_64 , V_81 ,
V_100 -> V_24 -> V_25 ,
false , NULL ) ;
} else if ( V_125 == V_130 ) {
if ( ! V_100 -> V_24 ) {
F_2 ( L_61 ) ;
return - V_85 ;
}
if ( type == V_15 )
V_75 = F_24 ( V_64 , V_81 , 0 ,
V_100 -> V_24 -> V_26 ) ;
else
V_75 = F_31 ( V_64 , V_81 ,
V_100 -> V_24 -> V_26 ,
false , NULL ) ;
} else if ( V_125 == V_132 ||
V_125 == V_133 ) {
bool V_122 = ( V_125 == V_133 ) ;
if ( V_81 == 0 ) {
F_2 ( L_62 ) ;
return - V_85 ;
}
if ( V_9 [ V_81 - 1 ] . type == V_15 )
V_75 = F_24 ( V_64 , V_81 - 1 , 0 , V_4 -> V_14 ) ;
else
V_75 = F_31 ( V_64 , V_81 - 1 , V_4 -> V_14 ,
V_122 , V_100 ) ;
}
return V_75 ;
V_131:
F_2 ( L_54 , V_81 ,
V_11 [ type ] , V_11 [ V_126 ] ) ;
return - V_85 ;
}
static int F_33 ( struct V_97 * V_98 , int V_139 )
{
if ( ! V_98 )
return 0 ;
switch ( V_98 -> V_140 ) {
case V_141 :
if ( V_139 != V_142 )
goto error;
break;
case V_143 :
if ( V_139 != V_144 &&
V_139 != V_145 )
goto error;
break;
case V_146 :
if ( V_139 != V_147 )
goto error;
break;
case V_148 :
if ( V_139 != V_149 &&
V_139 != V_150 )
goto error;
break;
default:
break;
}
switch ( V_139 ) {
case V_142 :
if ( V_98 -> V_140 != V_141 )
goto error;
break;
case V_144 :
case V_145 :
if ( V_98 -> V_140 != V_143 )
goto error;
break;
case V_147 :
if ( V_98 -> V_140 != V_146 )
goto error;
break;
case V_150 :
case V_149 :
if ( V_98 -> V_140 != V_148 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_2 ( L_63 ,
V_98 -> V_140 , V_139 ) ;
return - V_83 ;
}
static int F_34 ( const struct V_151 * V_152 )
{
int V_153 = 0 ;
if ( V_152 -> V_154 == V_137 )
V_153 ++ ;
if ( V_152 -> V_155 == V_137 )
V_153 ++ ;
if ( V_152 -> V_156 == V_137 )
V_153 ++ ;
if ( V_152 -> V_157 == V_137 )
V_153 ++ ;
if ( V_152 -> V_158 == V_137 )
V_153 ++ ;
return V_153 > 1 ? - V_83 : 0 ;
}
static void F_35 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = & V_64 -> V_70 ;
struct V_3 * V_9 = V_2 -> V_9 , * V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
if ( V_9 [ V_7 ] . type == V_15 ||
V_9 [ V_7 ] . type == V_92 )
F_14 ( V_9 , V_7 ) ;
for ( V_7 = 0 ; V_7 < V_31 ; V_7 += V_32 ) {
if ( V_2 -> V_33 [ V_7 ] != V_34 )
continue;
V_4 = & V_2 -> V_35 [ V_7 / V_32 ] ;
if ( V_4 -> type != V_15 &&
V_4 -> type != V_92 )
continue;
V_4 -> type = V_19 ;
V_4 -> V_14 = 0 ;
}
}
static int F_36 ( struct V_63 * V_64 , int V_139 )
{
struct V_1 * V_2 = & V_64 -> V_70 ;
const struct V_151 * V_152 = NULL ;
struct V_3 * V_9 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_99 V_100 ;
bool V_159 ;
int V_7 , V_75 ;
if ( V_139 < 0 || V_139 >= V_160 ) {
F_2 ( L_64 , V_139 ) ;
return - V_83 ;
}
if ( V_64 -> V_101 -> V_110 -> V_111 -> V_161 )
V_152 = V_64 -> V_101 -> V_110 -> V_111 -> V_161 ( V_139 ) ;
if ( ! V_152 ) {
F_2 ( L_65 , V_139 ) ;
return - V_83 ;
}
if ( ! V_64 -> V_101 -> V_162 && V_152 -> V_163 ) {
F_2 ( L_66 ) ;
return - V_83 ;
}
V_159 = F_37 ( V_152 -> V_164 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_105 = V_152 -> V_105 ;
V_75 = F_34 ( V_152 ) ;
if ( V_75 ) {
F_2 ( L_67 , V_139 ) ;
return V_75 ;
}
V_75 = F_32 ( V_64 , V_79 , V_152 -> V_154 , & V_100 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_32 ( V_64 , V_165 , V_152 -> V_155 , & V_100 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_32 ( V_64 , V_166 , V_152 -> V_156 , & V_100 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_32 ( V_64 , V_167 , V_152 -> V_157 , & V_100 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_32 ( V_64 , V_168 , V_152 -> V_158 , & V_100 ) ;
if ( V_75 )
return V_75 ;
for ( V_7 = 0 ; V_7 < V_100 . V_121 ; V_7 ++ ) {
V_75 = F_29 ( V_64 , V_100 . V_81 , V_7 , V_90 , V_117 , - 1 ) ;
if ( V_75 )
return V_75 ;
}
for ( V_7 = 0 ; V_7 < V_169 ; V_7 ++ ) {
V_4 = V_9 + V_170 [ V_7 ] ;
V_4 -> type = V_10 ;
V_4 -> V_14 = 0 ;
}
if ( V_152 -> V_171 == V_172 ) {
V_9 [ V_173 ] . type = V_19 ;
} else if ( V_152 -> V_171 == V_174 ) {
V_9 [ V_173 ] . type = V_10 ;
} else if ( V_152 -> V_171 == V_175 ) {
V_9 [ V_173 ] . type = V_22 ;
V_9 [ V_173 ] . V_29 = V_9 [ V_173 ] . V_27 = 0 ;
if ( V_100 . V_24 == NULL ) {
F_2 ( L_68 ) ;
return - V_83 ;
}
V_9 [ V_173 ] . V_24 = V_100 . V_24 ;
} else {
F_2 ( L_69 ,
V_152 -> V_171 , V_139 ) ;
return - V_83 ;
}
V_75 = F_33 ( V_100 . V_24 , V_139 ) ;
if ( V_75 )
return V_75 ;
if ( V_159 )
F_35 ( V_64 ) ;
return 0 ;
}
static int F_38 ( struct V_63 * V_64 ,
struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
struct V_3 * V_43 = & V_9 [ V_37 -> V_43 ] ;
struct V_3 * V_45 = & V_9 [ V_37 -> V_45 ] ;
struct V_3 V_176 ;
T_3 V_14 ;
if ( F_5 ( V_37 -> V_39 ) == V_177 ) {
V_14 = V_37 -> V_14 ;
V_178:
if ( V_14 <= 0 ) {
F_2 ( L_70 ) ;
return - V_85 ;
}
if ( V_14 >= V_179 ||
V_14 + V_43 -> V_17 >= V_179 ) {
F_2 ( L_71 ,
V_14 ) ;
return - V_85 ;
}
V_43 -> V_17 += V_14 ;
} else {
if ( V_45 -> type == V_15 ) {
V_176 = * V_43 ;
* V_43 = * V_45 ;
V_45 = & V_176 ;
}
if ( V_45 -> type == V_12 ) {
V_14 = V_45 -> V_14 ;
goto V_178;
}
if ( V_45 -> type != V_19 ) {
F_2 ( L_72 ,
V_11 [ V_45 -> type ] ) ;
return - V_85 ;
}
if ( V_45 -> V_14 < 48 ) {
F_2 ( L_73 ,
V_45 -> V_14 ) ;
return - V_85 ;
}
V_43 -> V_16 = ++ V_64 -> V_180 ;
V_43 -> V_17 = 0 ;
V_43 -> V_18 = 0 ;
}
return 0 ;
}
static int F_39 ( struct V_63 * V_64 , struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
struct V_3 * V_43 = & V_9 [ V_37 -> V_43 ] ;
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
T_4 V_181 ;
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
struct V_3 * V_45 = & V_9 [ V_37 -> V_45 ] ;
if ( V_45 -> type == V_19 && V_45 -> V_14 > 0 &&
V_43 -> V_14 && V_57 == V_182 ) {
V_43 -> V_14 = F_40 ( V_43 -> V_14 , V_45 -> V_14 ) ;
V_43 -> V_14 -- ;
return 0 ;
}
if ( V_45 -> type == V_12 && V_45 -> V_14 > 0 &&
V_43 -> V_14 && V_57 == V_182 ) {
V_181 = F_41 ( ( long long ) V_45 -> V_14 ) ;
V_43 -> V_14 = F_40 ( V_43 -> V_14 , 63 - V_181 ) ;
V_43 -> V_14 -- ;
return 0 ;
}
V_43 -> V_14 = 0 ;
return 0 ;
}
V_181 = F_41 ( ( long long ) V_37 -> V_14 ) ;
if ( V_43 -> V_14 && V_57 == V_183 ) {
V_43 -> V_14 -= V_37 -> V_14 ;
} else if ( V_43 -> V_14 && V_57 == V_184 ) {
V_43 -> V_14 -= V_181 + 1 ;
} else if ( V_57 == V_185 ) {
V_43 -> V_14 = 63 - V_181 ;
} else if ( V_43 -> V_14 && V_57 == V_182 ) {
V_43 -> V_14 = F_40 ( V_43 -> V_14 , 63 - V_181 ) ;
V_43 -> V_14 -- ;
} else if ( V_57 == V_186 ) {
V_43 -> V_14 += V_37 -> V_14 ;
if ( F_42 ( V_43 -> V_14 > 64 ) )
V_43 -> V_14 = 64 ;
} else {
V_43 -> V_14 = 0 ;
}
if ( V_43 -> V_14 < 0 ) {
V_43 -> V_14 = 0 ;
}
return 0 ;
}
static int F_43 ( struct V_63 * V_64 ,
struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
struct V_3 * V_43 = & V_9 [ V_37 -> V_43 ] ;
struct V_3 * V_45 = & V_9 [ V_37 -> V_45 ] ;
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
if ( V_57 == V_182 && F_5 ( V_37 -> V_39 ) == V_177 )
V_43 -> V_14 += V_37 -> V_14 ;
else if ( V_57 == V_182 && F_5 ( V_37 -> V_39 ) == V_42 &&
V_45 -> type == V_12 )
V_43 -> V_14 += V_45 -> V_14 ;
else
F_14 ( V_9 , V_37 -> V_43 ) ;
return 0 ;
}
static void F_44 ( struct V_3 * V_4 )
{
if ( V_4 -> V_29 > V_30 )
V_4 -> V_29 = V_30 ;
if ( V_4 -> V_27 < V_28 ||
V_4 -> V_27 > V_30 )
V_4 -> V_27 = V_28 ;
}
static void F_45 ( struct V_63 * V_64 ,
struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 , * V_43 ;
T_4 V_187 = V_28 ;
T_5 V_188 = V_30 ;
bool V_189 = false , V_190 = false ;
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
V_43 = & V_9 [ V_37 -> V_43 ] ;
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
F_44 ( & V_9 [ V_37 -> V_45 ] ) ;
V_187 = V_9 [ V_37 -> V_45 ] . V_27 ;
V_188 = V_9 [ V_37 -> V_45 ] . V_29 ;
if ( V_9 [ V_37 -> V_45 ] . type != V_12 &&
V_9 [ V_37 -> V_45 ] . type != V_19 ) {
V_187 = V_28 ;
V_188 = V_30 ;
}
} else if ( V_37 -> V_14 < V_30 &&
( T_4 ) V_37 -> V_14 > V_28 ) {
V_187 = V_188 = V_37 -> V_14 ;
V_189 = V_190 = true ;
}
if ( V_187 == V_28 &&
V_188 == V_30 ) {
F_16 ( V_9 , V_37 -> V_43 ) ;
return;
}
if ( V_187 == V_28 )
V_43 -> V_27 = V_28 ;
if ( V_188 == V_30 )
V_43 -> V_29 = V_30 ;
switch ( V_57 ) {
case V_182 :
if ( V_43 -> V_27 != V_28 )
V_43 -> V_27 += V_187 ;
if ( V_43 -> V_29 != V_30 )
V_43 -> V_29 += V_188 ;
break;
case V_191 :
if ( V_43 -> V_27 != V_28 )
V_43 -> V_27 -= V_187 ;
if ( V_43 -> V_29 != V_30 )
V_43 -> V_29 -= V_188 ;
break;
case V_184 :
if ( V_43 -> V_27 != V_28 )
V_43 -> V_27 *= V_187 ;
if ( V_43 -> V_29 != V_30 )
V_43 -> V_29 *= V_188 ;
break;
case V_185 :
if ( V_187 < 0 )
V_43 -> V_27 = V_28 ;
else
V_43 -> V_27 = 0 ;
V_43 -> V_29 = V_188 ;
break;
case V_183 :
if ( V_187 > F_46 ( V_30 ) )
V_43 -> V_27 = V_28 ;
else if ( V_43 -> V_27 != V_28 )
V_43 -> V_27 <<= V_187 ;
if ( V_188 > F_46 ( V_30 ) )
V_43 -> V_29 = V_30 ;
else if ( V_43 -> V_29 != V_30 )
V_43 -> V_29 <<= V_188 ;
break;
case V_186 :
if ( V_187 < 0 || V_43 -> V_27 < 0 )
V_43 -> V_27 = V_28 ;
else
V_43 -> V_27 =
( T_5 ) ( V_43 -> V_27 ) >> V_187 ;
if ( V_43 -> V_29 != V_30 )
V_43 -> V_29 >>= V_188 ;
break;
default:
F_16 ( V_9 , V_37 -> V_43 ) ;
break;
}
F_44 ( V_43 ) ;
}
static int F_47 ( struct V_63 * V_64 , struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 , * V_43 ;
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
int V_75 ;
if ( V_57 == V_192 || V_57 == V_193 ) {
if ( V_57 == V_193 ) {
if ( F_5 ( V_37 -> V_39 ) != 0 ||
V_37 -> V_45 != V_173 ||
V_37 -> V_17 != 0 || V_37 -> V_14 != 0 ) {
F_2 ( L_74 ) ;
return - V_83 ;
}
} else {
if ( V_37 -> V_45 != V_173 || V_37 -> V_17 != 0 ||
( V_37 -> V_14 != 16 && V_37 -> V_14 != 32 && V_37 -> V_14 != 64 ) ) {
F_2 ( L_75 ) ;
return - V_83 ;
}
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_84 ) ;
if ( V_75 )
return V_75 ;
if ( F_26 ( V_64 , V_37 -> V_43 ) ) {
F_2 ( L_76 ,
V_37 -> V_43 ) ;
return - V_85 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_86 ) ;
if ( V_75 )
return V_75 ;
} else if ( V_57 == V_194 ) {
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
if ( V_37 -> V_14 != 0 || V_37 -> V_17 != 0 ) {
F_2 ( L_77 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
} else {
if ( V_37 -> V_45 != V_173 || V_37 -> V_17 != 0 ) {
F_2 ( L_77 ) ;
return - V_83 ;
}
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_86 ) ;
if ( V_75 )
return V_75 ;
F_16 ( V_9 , V_37 -> V_43 ) ;
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
if ( F_4 ( V_37 -> V_39 ) == V_41 ) {
V_9 [ V_37 -> V_43 ] = V_9 [ V_37 -> V_45 ] ;
} else {
if ( F_26 ( V_64 , V_37 -> V_45 ) ) {
F_2 ( L_78 ,
V_37 -> V_45 ) ;
return - V_85 ;
}
V_9 [ V_37 -> V_43 ] . type = V_19 ;
V_9 [ V_37 -> V_43 ] . V_24 = NULL ;
}
} else {
V_9 [ V_37 -> V_43 ] . type = V_12 ;
V_9 [ V_37 -> V_43 ] . V_14 = V_37 -> V_14 ;
V_9 [ V_37 -> V_43 ] . V_29 = V_37 -> V_14 ;
V_9 [ V_37 -> V_43 ] . V_27 = V_37 -> V_14 ;
}
} else if ( V_57 > V_192 ) {
F_2 ( L_79 , V_57 ) ;
return - V_83 ;
} else {
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
if ( V_37 -> V_14 != 0 || V_37 -> V_17 != 0 ) {
F_2 ( L_80 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
} else {
if ( V_37 -> V_45 != V_173 || V_37 -> V_17 != 0 ) {
F_2 ( L_80 ) ;
return - V_83 ;
}
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_84 ) ;
if ( V_75 )
return V_75 ;
if ( ( V_57 == V_195 || V_57 == V_196 ) &&
F_5 ( V_37 -> V_39 ) == V_177 && V_37 -> V_14 == 0 ) {
F_2 ( L_81 ) ;
return - V_83 ;
}
if ( ( V_57 == V_183 || V_57 == V_186 ||
V_57 == V_197 ) && F_5 ( V_37 -> V_39 ) == V_177 ) {
int V_93 = F_4 ( V_37 -> V_39 ) == V_41 ? 64 : 32 ;
if ( V_37 -> V_14 < 0 || V_37 -> V_14 >= V_93 ) {
F_2 ( L_82 , V_37 -> V_14 ) ;
return - V_83 ;
}
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_198 ) ;
if ( V_75 )
return V_75 ;
V_43 = & V_9 [ V_37 -> V_43 ] ;
F_45 ( V_64 , V_37 ) ;
if ( V_57 == V_182 && F_4 ( V_37 -> V_39 ) == V_41 &&
V_43 -> type == V_78 && F_5 ( V_37 -> V_39 ) == V_177 ) {
V_43 -> type = V_13 ;
V_43 -> V_14 = V_37 -> V_14 ;
return 0 ;
} else if ( V_57 == V_182 &&
F_4 ( V_37 -> V_39 ) == V_41 &&
( V_43 -> type == V_15 ||
( F_5 ( V_37 -> V_39 ) == V_42 &&
V_9 [ V_37 -> V_45 ] . type == V_15 ) ) ) {
return F_38 ( V_64 , V_37 ) ;
} else if ( F_4 ( V_37 -> V_39 ) == V_41 &&
V_43 -> type == V_19 &&
V_64 -> V_114 ) {
return F_39 ( V_64 , V_37 ) ;
} else if ( F_4 ( V_37 -> V_39 ) == V_41 &&
V_43 -> type == V_12 &&
V_64 -> V_114 ) {
return F_43 ( V_64 , V_37 ) ;
} else if ( F_26 ( V_64 , V_37 -> V_43 ) ) {
F_2 ( L_76 ,
V_37 -> V_43 ) ;
return - V_85 ;
} else if ( F_5 ( V_37 -> V_39 ) == V_42 &&
F_26 ( V_64 , V_37 -> V_45 ) ) {
F_2 ( L_76 ,
V_37 -> V_45 ) ;
return - V_85 ;
}
if ( V_64 -> V_114 &&
( V_43 -> type == V_21 ||
V_43 -> type == V_23 ) )
V_43 -> type = V_23 ;
else
F_14 ( V_9 , V_37 -> V_43 ) ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_3 * V_43 )
{
struct V_3 * V_9 = V_2 -> V_9 , * V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
if ( V_9 [ V_7 ] . type == V_15 && V_9 [ V_7 ] . V_16 == V_43 -> V_16 )
V_9 [ V_7 ] . V_18 = V_43 -> V_17 ;
for ( V_7 = 0 ; V_7 < V_31 ; V_7 += V_32 ) {
if ( V_2 -> V_33 [ V_7 ] != V_34 )
continue;
V_4 = & V_2 -> V_35 [ V_7 / V_32 ] ;
if ( V_4 -> type == V_15 && V_4 -> V_16 == V_43 -> V_16 )
V_4 -> V_18 = V_43 -> V_17 ;
}
}
static void F_49 ( struct V_3 * V_199 ,
struct V_3 * V_200 , T_5 V_201 ,
T_1 V_57 )
{
switch ( V_57 ) {
case V_202 :
V_199 -> V_29 = V_199 -> V_27 = V_201 ;
break;
case V_203 :
V_200 -> V_29 = V_200 -> V_27 = V_201 ;
break;
case V_204 :
V_200 -> V_27 = 0 ;
case V_205 :
V_200 -> V_29 = V_201 ;
V_199 -> V_27 = V_201 + 1 ;
break;
case V_206 :
V_200 -> V_27 = 0 ;
case V_207 :
V_200 -> V_29 = V_201 - 1 ;
V_199 -> V_27 = V_201 ;
break;
default:
break;
}
F_44 ( V_200 ) ;
F_44 ( V_199 ) ;
}
static void F_50 ( struct V_3 * V_199 ,
struct V_3 * V_200 , T_5 V_201 ,
T_1 V_57 )
{
switch ( V_57 ) {
case V_202 :
V_199 -> V_29 = V_199 -> V_27 = V_201 ;
break;
case V_203 :
V_200 -> V_29 = V_200 -> V_27 = V_201 ;
break;
case V_204 :
V_199 -> V_27 = 0 ;
case V_205 :
V_200 -> V_27 = V_201 ;
V_199 -> V_29 = V_201 - 1 ;
break;
case V_206 :
V_199 -> V_27 = 0 ;
case V_207 :
V_200 -> V_27 = V_201 + 1 ;
V_199 -> V_29 = V_201 ;
break;
default:
break;
}
F_44 ( V_200 ) ;
F_44 ( V_199 ) ;
}
static int F_51 ( struct V_63 * V_64 ,
struct V_36 * V_37 , int * V_68 )
{
struct V_1 * V_208 , * V_209 = & V_64 -> V_70 ;
struct V_3 * V_9 = V_209 -> V_9 , * V_43 ;
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
int V_75 ;
if ( V_57 > V_60 ) {
F_2 ( L_83 , V_57 ) ;
return - V_83 ;
}
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
if ( V_37 -> V_14 != 0 ) {
F_2 ( L_84 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
if ( F_26 ( V_64 , V_37 -> V_45 ) ) {
F_2 ( L_85 ,
V_37 -> V_45 ) ;
return - V_85 ;
}
} else {
if ( V_37 -> V_45 != V_173 ) {
F_2 ( L_84 ) ;
return - V_83 ;
}
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_43 = & V_9 [ V_37 -> V_43 ] ;
if ( F_5 ( V_37 -> V_39 ) == V_177 &&
( V_57 == V_202 || V_57 == V_203 ) &&
V_43 -> type == V_12 && V_43 -> V_14 == V_37 -> V_14 ) {
if ( V_57 == V_202 ) {
* V_68 += V_37 -> V_17 ;
return 0 ;
} else {
return 0 ;
}
}
V_208 = F_11 ( V_64 , * V_68 + V_37 -> V_17 + 1 , * V_68 ) ;
if ( ! V_208 )
return - V_138 ;
if ( F_5 ( V_37 -> V_39 ) == V_42 ) {
if ( V_9 [ V_37 -> V_45 ] . type == V_12 )
F_49 ( & V_208 -> V_9 [ V_37 -> V_43 ] ,
V_43 , V_9 [ V_37 -> V_45 ] . V_14 ,
V_57 ) ;
else if ( V_43 -> type == V_12 )
F_50 ( & V_208 -> V_9 [ V_37 -> V_45 ] ,
& V_9 [ V_37 -> V_45 ] , V_43 -> V_14 ,
V_57 ) ;
} else {
F_49 ( & V_208 -> V_9 [ V_37 -> V_43 ] ,
V_43 , V_37 -> V_14 , V_57 ) ;
}
if ( F_5 ( V_37 -> V_39 ) == V_177 &&
V_37 -> V_14 == 0 && ( V_57 == V_202 || V_57 == V_203 ) &&
V_43 -> type == V_22 ) {
if ( V_57 == V_202 ) {
V_9 [ V_37 -> V_43 ] . type = V_21 ;
F_14 ( V_208 -> V_9 ,
V_37 -> V_43 ) ;
} else {
V_208 -> V_9 [ V_37 -> V_43 ] . type = V_21 ;
F_14 ( V_9 , V_37 -> V_43 ) ;
}
} else if ( F_5 ( V_37 -> V_39 ) == V_42 && V_57 == V_204 &&
V_43 -> type == V_15 &&
V_9 [ V_37 -> V_45 ] . type == V_92 ) {
F_48 ( V_209 , V_43 ) ;
} else if ( F_5 ( V_37 -> V_39 ) == V_42 && V_57 == V_206 &&
V_43 -> type == V_92 &&
V_9 [ V_37 -> V_45 ] . type == V_15 ) {
F_48 ( V_208 , & V_9 [ V_37 -> V_45 ] ) ;
} else if ( F_26 ( V_64 , V_37 -> V_43 ) ) {
F_2 ( L_85 , V_37 -> V_43 ) ;
return - V_85 ;
}
if ( V_118 )
F_1 ( V_209 ) ;
return 0 ;
}
static struct V_97 * F_52 ( struct V_36 * V_37 )
{
T_5 V_210 = ( ( T_5 ) ( T_2 ) V_37 [ 0 ] . V_14 ) | ( ( T_5 ) ( T_2 ) V_37 [ 1 ] . V_14 ) << 32 ;
return (struct V_97 * ) ( unsigned long ) V_210 ;
}
static int F_53 ( struct V_63 * V_64 , struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
int V_75 ;
if ( F_8 ( V_37 -> V_39 ) != V_91 ) {
F_2 ( L_86 ) ;
return - V_83 ;
}
if ( V_37 -> V_17 != 0 ) {
F_2 ( L_87 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_86 ) ;
if ( V_75 )
return V_75 ;
if ( V_37 -> V_45 == 0 ) {
T_5 V_14 = ( ( T_5 ) ( V_37 + 1 ) -> V_14 << 32 ) | ( T_2 ) V_37 -> V_14 ;
if ( ! V_64 -> V_109 )
return 0 ;
V_9 [ V_37 -> V_43 ] . type = V_12 ;
V_9 [ V_37 -> V_43 ] . V_14 = V_14 ;
return 0 ;
}
F_15 ( V_37 -> V_45 != V_211 ) ;
V_9 [ V_37 -> V_43 ] . type = V_20 ;
V_9 [ V_37 -> V_43 ] . V_24 = F_52 ( V_37 ) ;
return 0 ;
}
static bool F_54 ( enum V_212 type )
{
switch ( type ) {
case V_213 :
case V_102 :
case V_103 :
return true ;
default:
return false ;
}
}
static int F_55 ( struct V_63 * V_64 , struct V_36 * V_37 )
{
struct V_3 * V_9 = V_64 -> V_70 . V_9 ;
T_1 V_214 = F_7 ( V_37 -> V_39 ) ;
struct V_3 * V_4 ;
int V_7 , V_75 ;
if ( ! F_54 ( V_64 -> V_101 -> type ) ) {
F_2 ( L_88 ) ;
return - V_83 ;
}
if ( V_37 -> V_43 != V_173 || V_37 -> V_17 != 0 ||
F_8 ( V_37 -> V_39 ) == V_91 ||
( V_214 == V_53 && V_37 -> V_45 != V_173 ) ) {
F_2 ( L_89 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_215 , V_84 ) ;
if ( V_75 )
return V_75 ;
if ( V_9 [ V_215 ] . type != V_80 ) {
F_2 ( L_90 ) ;
return - V_83 ;
}
if ( V_214 == V_54 ) {
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
}
for ( V_7 = 0 ; V_7 < V_169 ; V_7 ++ ) {
V_4 = V_9 + V_170 [ V_7 ] ;
V_4 -> type = V_10 ;
V_4 -> V_14 = 0 ;
}
V_9 [ V_173 ] . type = V_19 ;
return 0 ;
}
static int F_56 ( int V_6 , int V_216 , int V_217 , struct V_63 * V_64 )
{
if ( V_217 == V_218 && V_219 [ V_6 ] >= ( V_220 | V_218 ) )
return 0 ;
if ( V_217 == V_221 && V_219 [ V_6 ] >= ( V_220 | V_221 ) )
return 0 ;
if ( V_216 < 0 || V_216 >= V_64 -> V_101 -> V_222 ) {
F_2 ( L_91 , V_6 , V_216 ) ;
return - V_83 ;
}
if ( V_217 == V_221 )
V_64 -> V_223 [ V_216 ] = V_224 ;
if ( V_219 [ V_216 ] == 0 ) {
V_219 [ V_6 ] = V_220 | V_217 ;
V_219 [ V_216 ] = V_220 ;
if ( V_225 >= V_64 -> V_101 -> V_222 )
return - V_226 ;
V_227 [ V_225 ++ ] = V_216 ;
return 1 ;
} else if ( ( V_219 [ V_216 ] & 0xF0 ) == V_220 ) {
F_2 ( L_92 , V_6 , V_216 ) ;
return - V_83 ;
} else if ( V_219 [ V_216 ] == V_228 ) {
V_219 [ V_6 ] = V_220 | V_217 ;
} else {
F_2 ( L_93 ) ;
return - V_138 ;
}
return 0 ;
}
static int F_57 ( struct V_63 * V_64 )
{
struct V_36 * V_229 = V_64 -> V_101 -> V_230 ;
int V_231 = V_64 -> V_101 -> V_222 ;
int V_232 = 0 ;
int V_7 , V_6 ;
V_219 = F_58 ( V_231 , sizeof( int ) , V_74 ) ;
if ( ! V_219 )
return - V_233 ;
V_227 = F_58 ( V_231 , sizeof( int ) , V_74 ) ;
if ( ! V_227 ) {
F_10 ( V_219 ) ;
return - V_233 ;
}
V_219 [ 0 ] = V_220 ;
V_227 [ 0 ] = 0 ;
V_225 = 1 ;
V_234:
if ( V_225 == 0 )
goto V_235;
V_6 = V_227 [ V_225 - 1 ] ;
if ( F_4 ( V_229 [ V_6 ] . V_39 ) == V_56 ) {
T_1 V_57 = F_6 ( V_229 [ V_6 ] . V_39 ) ;
if ( V_57 == V_60 ) {
goto V_236;
} else if ( V_57 == V_58 ) {
V_232 = F_56 ( V_6 , V_6 + 1 , V_218 , V_64 ) ;
if ( V_232 == 1 )
goto V_234;
else if ( V_232 < 0 )
goto V_237;
if ( V_6 + 1 < V_231 )
V_64 -> V_223 [ V_6 + 1 ] = V_224 ;
} else if ( V_57 == V_59 ) {
if ( F_5 ( V_229 [ V_6 ] . V_39 ) != V_177 ) {
V_232 = - V_83 ;
goto V_237;
}
V_232 = F_56 ( V_6 , V_6 + V_229 [ V_6 ] . V_17 + 1 ,
V_218 , V_64 ) ;
if ( V_232 == 1 )
goto V_234;
else if ( V_232 < 0 )
goto V_237;
if ( V_6 + 1 < V_231 )
V_64 -> V_223 [ V_6 + 1 ] = V_224 ;
} else {
V_232 = F_56 ( V_6 , V_6 + 1 , V_218 , V_64 ) ;
if ( V_232 == 1 )
goto V_234;
else if ( V_232 < 0 )
goto V_237;
V_232 = F_56 ( V_6 , V_6 + V_229 [ V_6 ] . V_17 + 1 , V_221 , V_64 ) ;
if ( V_232 == 1 )
goto V_234;
else if ( V_232 < 0 )
goto V_237;
}
} else {
V_232 = F_56 ( V_6 , V_6 + 1 , V_218 , V_64 ) ;
if ( V_232 == 1 )
goto V_234;
else if ( V_232 < 0 )
goto V_237;
}
V_236:
V_219 [ V_6 ] = V_228 ;
if ( V_225 -- <= 0 ) {
F_2 ( L_94 ) ;
V_232 = - V_138 ;
goto V_237;
}
goto V_234;
V_235:
for ( V_7 = 0 ; V_7 < V_231 ; V_7 ++ ) {
if ( V_219 [ V_7 ] != V_228 ) {
F_2 ( L_95 , V_7 ) ;
V_232 = - V_83 ;
goto V_237;
}
}
V_232 = 0 ;
V_237:
F_10 ( V_219 ) ;
F_10 ( V_227 ) ;
return V_232 ;
}
static bool F_59 ( struct V_3 * V_238 ,
struct V_3 * V_239 )
{
if ( V_238 -> V_16 != V_239 -> V_16 )
return false ;
if ( V_238 -> V_17 == V_239 -> V_17 && V_238 -> V_18 < V_239 -> V_18 )
return true ;
if ( V_238 -> V_17 <= V_239 -> V_17 &&
V_238 -> V_17 >= V_238 -> V_18 && V_239 -> V_17 >= V_239 -> V_18 )
return true ;
return false ;
}
static bool F_60 ( struct V_63 * V_64 ,
struct V_1 * V_238 ,
struct V_1 * V_239 )
{
bool V_240 = V_64 -> V_119 ;
struct V_3 * V_241 , * V_242 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_241 = & V_238 -> V_9 [ V_7 ] ;
V_242 = & V_239 -> V_9 [ V_7 ] ;
if ( memcmp ( V_241 , V_242 , sizeof( * V_241 ) ) == 0 )
continue;
if ( ! V_240 &&
V_241 -> type == V_242 -> type && V_241 -> V_14 == V_242 -> V_14 )
continue;
if ( V_241 -> type == V_10 ||
( ! V_240 && V_241 -> type == V_19 &&
V_242 -> type != V_10 ) )
continue;
if ( V_241 -> type == V_15 && V_242 -> type == V_15 &&
F_59 ( V_241 , V_242 ) )
continue;
return false ;
}
for ( V_7 = 0 ; V_7 < V_31 ; V_7 ++ ) {
if ( V_238 -> V_33 [ V_7 ] == V_243 )
continue;
if ( V_238 -> V_33 [ V_7 ] != V_239 -> V_33 [ V_7 ] )
return false ;
if ( V_7 % V_32 )
continue;
if ( memcmp ( & V_238 -> V_35 [ V_7 / V_32 ] ,
& V_239 -> V_35 [ V_7 / V_32 ] ,
sizeof( V_238 -> V_35 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_61 ( struct V_63 * V_64 , int V_68 )
{
struct V_244 * V_245 ;
struct V_244 * V_246 ;
V_246 = V_64 -> V_223 [ V_68 ] ;
if ( ! V_246 )
return 0 ;
while ( V_246 != V_224 ) {
if ( F_60 ( V_64 , & V_246 -> V_2 , & V_64 -> V_70 ) )
return 1 ;
V_246 = V_246 -> V_72 ;
}
V_245 = F_12 ( sizeof( struct V_244 ) , V_247 ) ;
if ( ! V_245 )
return - V_233 ;
memcpy ( & V_245 -> V_2 , & V_64 -> V_70 , sizeof( V_64 -> V_70 ) ) ;
V_245 -> V_72 = V_64 -> V_223 [ V_68 ] ;
V_64 -> V_223 [ V_68 ] = V_245 ;
return 0 ;
}
static int F_62 ( struct V_63 * V_64 ,
int V_68 , int V_65 )
{
if ( ! V_64 -> V_109 || ! V_64 -> V_109 -> V_248 )
return 0 ;
return V_64 -> V_109 -> V_248 ( V_64 , V_68 , V_65 ) ;
}
static int F_63 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = & V_64 -> V_70 ;
struct V_36 * V_229 = V_64 -> V_101 -> V_230 ;
struct V_3 * V_9 = V_2 -> V_9 ;
int V_231 = V_64 -> V_101 -> V_222 ;
int V_68 , V_65 = 0 ;
int V_249 = 0 ;
bool V_250 = false ;
F_13 ( V_9 ) ;
V_68 = 0 ;
V_64 -> V_119 = false ;
for (; ; ) {
struct V_36 * V_37 ;
T_1 V_38 ;
int V_75 ;
if ( V_68 >= V_231 ) {
F_2 ( L_96 ,
V_68 , V_231 ) ;
return - V_138 ;
}
V_37 = & V_229 [ V_68 ] ;
V_38 = F_4 ( V_37 -> V_39 ) ;
if ( ++ V_249 > V_251 ) {
F_2 ( L_97 ,
V_249 ) ;
return - V_226 ;
}
V_75 = F_61 ( V_64 , V_68 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_75 == 1 ) {
if ( V_118 ) {
if ( V_250 )
F_2 ( L_98 ,
V_65 , V_68 ) ;
else
F_2 ( L_99 , V_68 ) ;
}
goto V_252;
}
if ( V_118 && V_250 ) {
F_2 ( L_100 , V_65 , V_68 ) ;
F_1 ( & V_64 -> V_70 ) ;
V_250 = false ;
}
if ( V_118 ) {
F_2 ( L_101 , V_68 ) ;
F_3 ( V_37 ) ;
}
V_75 = F_62 ( V_64 , V_68 , V_65 ) ;
if ( V_75 )
return V_75 ;
if ( V_38 == V_40 || V_38 == V_41 ) {
V_75 = F_47 ( V_64 , V_37 ) ;
if ( V_75 )
return V_75 ;
} else if ( V_38 == V_51 ) {
enum V_5 * V_253 , V_254 ;
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_198 ) ;
if ( V_75 )
return V_75 ;
V_254 = V_9 [ V_37 -> V_45 ] . type ;
V_75 = F_29 ( V_64 , V_37 -> V_45 , V_37 -> V_17 ,
F_8 ( V_37 -> V_39 ) , V_120 ,
V_37 -> V_43 ) ;
if ( V_75 )
return V_75 ;
F_16 ( V_9 , V_37 -> V_43 ) ;
if ( F_8 ( V_37 -> V_39 ) != V_88 &&
F_8 ( V_37 -> V_39 ) != V_91 ) {
V_68 ++ ;
continue;
}
V_253 = & V_64 -> V_255 [ V_68 ] . V_256 ;
if ( * V_253 == V_10 ) {
* V_253 = V_254 ;
} else if ( V_254 != * V_253 &&
( V_254 == V_80 ||
* V_253 == V_80 ) ) {
F_2 ( L_102 ) ;
return - V_83 ;
}
} else if ( V_38 == V_46 ) {
enum V_5 * V_257 , V_258 ;
if ( F_7 ( V_37 -> V_39 ) == V_49 ) {
V_75 = F_30 ( V_64 , V_37 ) ;
if ( V_75 )
return V_75 ;
V_68 ++ ;
continue;
}
V_75 = F_17 ( V_9 , V_37 -> V_45 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_258 = V_9 [ V_37 -> V_43 ] . type ;
V_75 = F_29 ( V_64 , V_37 -> V_43 , V_37 -> V_17 ,
F_8 ( V_37 -> V_39 ) , V_117 ,
V_37 -> V_45 ) ;
if ( V_75 )
return V_75 ;
V_257 = & V_64 -> V_255 [ V_68 ] . V_256 ;
if ( * V_257 == V_10 ) {
* V_257 = V_258 ;
} else if ( V_258 != * V_257 &&
( V_258 == V_80 ||
* V_257 == V_80 ) ) {
F_2 ( L_102 ) ;
return - V_83 ;
}
} else if ( V_38 == V_50 ) {
if ( F_7 ( V_37 -> V_39 ) != V_47 ||
V_37 -> V_45 != V_173 ) {
F_2 ( L_103 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_37 -> V_43 , V_84 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_29 ( V_64 , V_37 -> V_43 , V_37 -> V_17 ,
F_8 ( V_37 -> V_39 ) , V_117 ,
- 1 ) ;
if ( V_75 )
return V_75 ;
} else if ( V_38 == V_56 ) {
T_1 V_57 = F_6 ( V_37 -> V_39 ) ;
if ( V_57 == V_58 ) {
if ( F_5 ( V_37 -> V_39 ) != V_177 ||
V_37 -> V_17 != 0 ||
V_37 -> V_45 != V_173 ||
V_37 -> V_43 != V_173 ) {
F_2 ( L_104 ) ;
return - V_83 ;
}
V_75 = F_36 ( V_64 , V_37 -> V_14 ) ;
if ( V_75 )
return V_75 ;
} else if ( V_57 == V_59 ) {
if ( F_5 ( V_37 -> V_39 ) != V_177 ||
V_37 -> V_14 != 0 ||
V_37 -> V_45 != V_173 ||
V_37 -> V_43 != V_173 ) {
F_2 ( L_105 ) ;
return - V_83 ;
}
V_68 += V_37 -> V_17 + 1 ;
continue;
} else if ( V_57 == V_60 ) {
if ( F_5 ( V_37 -> V_39 ) != V_177 ||
V_37 -> V_14 != 0 ||
V_37 -> V_45 != V_173 ||
V_37 -> V_43 != V_173 ) {
F_2 ( L_106 ) ;
return - V_83 ;
}
V_75 = F_17 ( V_9 , V_173 , V_84 ) ;
if ( V_75 )
return V_75 ;
if ( F_26 ( V_64 , V_173 ) ) {
F_2 ( L_107 ) ;
return - V_85 ;
}
V_252:
V_68 = F_9 ( V_64 , & V_65 ) ;
if ( V_68 < 0 ) {
break;
} else {
V_250 = true ;
continue;
}
} else {
V_75 = F_51 ( V_64 , V_37 , & V_68 ) ;
if ( V_75 )
return V_75 ;
}
} else if ( V_38 == V_52 ) {
T_1 V_214 = F_7 ( V_37 -> V_39 ) ;
if ( V_214 == V_53 || V_214 == V_54 ) {
V_75 = F_55 ( V_64 , V_37 ) ;
if ( V_75 )
return V_75 ;
} else if ( V_214 == V_55 ) {
V_75 = F_53 ( V_64 , V_37 ) ;
if ( V_75 )
return V_75 ;
V_68 ++ ;
} else {
F_2 ( L_108 ) ;
return - V_83 ;
}
F_16 ( V_9 , V_37 -> V_43 ) ;
} else {
F_2 ( L_109 , V_38 ) ;
return - V_83 ;
}
V_68 ++ ;
}
F_2 ( L_110 , V_249 ) ;
return 0 ;
}
static int F_64 ( struct V_97 * V_98 ,
struct V_259 * V_101 )
{
if ( V_101 -> type == V_260 &&
( V_98 -> V_140 == V_261 ||
V_98 -> V_140 == V_262 ) &&
( V_98 -> V_263 & V_264 ) ) {
F_2 ( L_111 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_65 ( struct V_63 * V_64 )
{
struct V_36 * V_37 = V_64 -> V_101 -> V_230 ;
int V_231 = V_64 -> V_101 -> V_222 ;
int V_7 , V_265 , V_75 ;
for ( V_7 = 0 ; V_7 < V_231 ; V_7 ++ , V_37 ++ ) {
if ( F_4 ( V_37 -> V_39 ) == V_51 &&
( F_7 ( V_37 -> V_39 ) != V_47 || V_37 -> V_14 != 0 ) ) {
F_2 ( L_112 ) ;
return - V_83 ;
}
if ( F_4 ( V_37 -> V_39 ) == V_46 &&
( ( F_7 ( V_37 -> V_39 ) != V_47 &&
F_7 ( V_37 -> V_39 ) != V_49 ) || V_37 -> V_14 != 0 ) ) {
F_2 ( L_113 ) ;
return - V_83 ;
}
if ( V_37 [ 0 ] . V_39 == ( V_52 | V_55 | V_91 ) ) {
struct V_97 * V_98 ;
struct V_266 V_267 ;
if ( V_7 == V_231 - 1 || V_37 [ 1 ] . V_39 != 0 ||
V_37 [ 1 ] . V_43 != 0 || V_37 [ 1 ] . V_45 != 0 ||
V_37 [ 1 ] . V_17 != 0 ) {
F_2 ( L_114 ) ;
return - V_83 ;
}
if ( V_37 -> V_45 == 0 )
goto V_268;
if ( V_37 -> V_45 != V_211 ) {
F_2 ( L_115 ) ;
return - V_83 ;
}
V_267 = F_66 ( V_37 -> V_14 ) ;
V_98 = F_67 ( V_267 ) ;
if ( F_68 ( V_98 ) ) {
F_2 ( L_116 ,
V_37 -> V_14 ) ;
return F_69 ( V_98 ) ;
}
V_75 = F_64 ( V_98 , V_64 -> V_101 ) ;
if ( V_75 ) {
F_70 ( V_267 ) ;
return V_75 ;
}
V_37 [ 0 ] . V_14 = ( T_2 ) ( unsigned long ) V_98 ;
V_37 [ 1 ] . V_14 = ( ( T_5 ) ( unsigned long ) V_98 ) >> 32 ;
for ( V_265 = 0 ; V_265 < V_64 -> V_269 ; V_265 ++ )
if ( V_64 -> V_270 [ V_265 ] == V_98 ) {
F_70 ( V_267 ) ;
goto V_268;
}
if ( V_64 -> V_269 >= V_271 ) {
F_70 ( V_267 ) ;
return - V_226 ;
}
V_98 = F_71 ( V_98 , false ) ;
if ( F_68 ( V_98 ) ) {
F_70 ( V_267 ) ;
return F_69 ( V_98 ) ;
}
V_64 -> V_270 [ V_64 -> V_269 ++ ] = V_98 ;
F_70 ( V_267 ) ;
V_268:
V_37 ++ ;
V_7 ++ ;
}
}
return 0 ;
}
static void F_72 ( struct V_63 * V_64 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_64 -> V_269 ; V_7 ++ )
F_73 ( V_64 -> V_270 [ V_7 ] ) ;
}
static void F_74 ( struct V_63 * V_64 )
{
struct V_36 * V_37 = V_64 -> V_101 -> V_230 ;
int V_231 = V_64 -> V_101 -> V_222 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_231 ; V_7 ++ , V_37 ++ )
if ( V_37 -> V_39 == ( V_52 | V_55 | V_91 ) )
V_37 -> V_45 = 0 ;
}
static int F_75 ( struct V_63 * V_64 )
{
const struct V_272 * V_111 = V_64 -> V_101 -> V_110 -> V_111 ;
const int V_231 = V_64 -> V_101 -> V_222 ;
struct V_36 V_273 [ 16 ] , * V_37 ;
struct V_259 * V_274 ;
enum V_107 type ;
int V_7 , V_275 , V_276 = 0 ;
if ( V_111 -> V_277 ) {
V_275 = V_111 -> V_277 ( V_273 , V_64 -> V_106 ,
V_64 -> V_101 ) ;
if ( V_275 >= F_76 ( V_273 ) ) {
F_2 ( L_117 ) ;
return - V_83 ;
} else if ( V_275 ) {
V_274 = F_77 ( V_64 -> V_101 , 0 ,
V_273 , V_275 ) ;
if ( ! V_274 )
return - V_233 ;
V_64 -> V_101 = V_274 ;
V_276 += V_275 - 1 ;
}
}
if ( ! V_111 -> V_278 )
return 0 ;
V_37 = V_64 -> V_101 -> V_230 + V_276 ;
for ( V_7 = 0 ; V_7 < V_231 ; V_7 ++ , V_37 ++ ) {
if ( V_37 -> V_39 == ( V_51 | V_47 | V_88 ) ||
V_37 -> V_39 == ( V_51 | V_47 | V_91 ) )
type = V_120 ;
else if ( V_37 -> V_39 == ( V_46 | V_47 | V_88 ) ||
V_37 -> V_39 == ( V_46 | V_47 | V_91 ) )
type = V_117 ;
else
continue;
if ( V_64 -> V_255 [ V_7 ] . V_256 != V_80 )
continue;
V_275 = V_111 -> V_278 ( type , V_37 -> V_43 , V_37 -> V_45 ,
V_37 -> V_17 , V_273 , V_64 -> V_101 ) ;
if ( V_275 == 0 || V_275 >= F_76 ( V_273 ) ) {
F_2 ( L_117 ) ;
return - V_83 ;
}
V_274 = F_77 ( V_64 -> V_101 , V_7 + V_276 , V_273 ,
V_275 ) ;
if ( ! V_274 )
return - V_233 ;
V_276 += V_275 - 1 ;
V_64 -> V_101 = V_274 ;
V_37 = V_274 -> V_230 + V_7 + V_276 ;
}
return 0 ;
}
static void F_78 ( struct V_63 * V_64 )
{
struct V_244 * V_246 , * V_279 ;
int V_7 ;
if ( ! V_64 -> V_223 )
return;
for ( V_7 = 0 ; V_7 < V_64 -> V_101 -> V_222 ; V_7 ++ ) {
V_246 = V_64 -> V_223 [ V_7 ] ;
if ( V_246 )
while ( V_246 != V_224 ) {
V_279 = V_246 -> V_72 ;
F_10 ( V_246 ) ;
V_246 = V_279 ;
}
}
F_10 ( V_64 -> V_223 ) ;
}
int F_79 ( struct V_259 * * V_101 , union V_280 * V_281 )
{
char T_6 * V_282 = NULL ;
struct V_63 * V_64 ;
int V_232 = - V_83 ;
if ( ( * V_101 ) -> V_222 <= 0 || ( * V_101 ) -> V_222 > V_283 )
return - V_226 ;
V_64 = F_80 ( sizeof( struct V_63 ) , V_74 ) ;
if ( ! V_64 )
return - V_233 ;
V_64 -> V_255 = F_81 ( sizeof( struct V_284 ) *
( * V_101 ) -> V_222 ) ;
V_232 = - V_233 ;
if ( ! V_64 -> V_255 )
goto V_285;
V_64 -> V_101 = * V_101 ;
F_82 ( & V_286 ) ;
if ( V_281 -> V_118 || V_281 -> V_287 || V_281 -> V_288 ) {
V_118 = V_281 -> V_118 ;
V_282 = ( char T_6 * ) ( unsigned long ) V_281 -> V_287 ;
V_288 = V_281 -> V_288 ;
V_289 = 0 ;
V_232 = - V_83 ;
if ( V_288 < 128 || V_288 > V_290 >> 8 ||
V_118 == 0 || V_282 == NULL )
goto V_291;
V_232 = - V_233 ;
V_287 = F_83 ( V_288 ) ;
if ( ! V_287 )
goto V_291;
} else {
V_118 = 0 ;
}
V_232 = F_65 ( V_64 ) ;
if ( V_232 < 0 )
goto V_292;
V_64 -> V_223 = F_58 ( V_64 -> V_101 -> V_222 ,
sizeof( struct V_244 * ) ,
V_247 ) ;
V_232 = - V_233 ;
if ( ! V_64 -> V_223 )
goto V_292;
V_232 = F_57 ( V_64 ) ;
if ( V_232 < 0 )
goto V_292;
V_64 -> V_114 = F_84 ( V_293 ) ;
V_232 = F_63 ( V_64 ) ;
V_292:
while ( F_9 ( V_64 , NULL ) >= 0 ) ;
F_78 ( V_64 ) ;
if ( V_232 == 0 )
V_232 = F_75 ( V_64 ) ;
if ( V_118 && V_289 >= V_288 - 1 ) {
F_15 ( V_289 >= V_288 ) ;
V_232 = - V_294 ;
}
if ( V_118 && F_85 ( V_282 , V_287 , V_289 + 1 ) != 0 ) {
V_232 = - V_138 ;
goto V_295;
}
if ( V_232 == 0 && V_64 -> V_269 ) {
V_64 -> V_101 -> V_110 -> V_270 = F_86 ( V_64 -> V_269 ,
sizeof( V_64 -> V_270 [ 0 ] ) ,
V_74 ) ;
if ( ! V_64 -> V_101 -> V_110 -> V_270 ) {
V_232 = - V_233 ;
goto V_295;
}
memcpy ( V_64 -> V_101 -> V_110 -> V_270 , V_64 -> V_270 ,
sizeof( V_64 -> V_270 [ 0 ] ) * V_64 -> V_269 ) ;
V_64 -> V_101 -> V_110 -> V_269 = V_64 -> V_269 ;
F_74 ( V_64 ) ;
}
V_295:
if ( V_118 )
F_87 ( V_287 ) ;
if ( ! V_64 -> V_101 -> V_110 -> V_270 )
F_72 ( V_64 ) ;
* V_101 = V_64 -> V_101 ;
V_291:
F_88 ( & V_286 ) ;
F_87 ( V_64 -> V_255 ) ;
V_285:
F_10 ( V_64 ) ;
return V_232 ;
}
int F_89 ( struct V_259 * V_101 , const struct V_296 * V_111 ,
void * V_297 )
{
struct V_63 * V_64 ;
int V_232 ;
V_64 = F_80 ( sizeof( struct V_63 ) , V_74 ) ;
if ( ! V_64 )
return - V_233 ;
V_64 -> V_255 = F_81 ( sizeof( struct V_284 ) *
V_101 -> V_222 ) ;
V_232 = - V_233 ;
if ( ! V_64 -> V_255 )
goto V_285;
V_64 -> V_101 = V_101 ;
V_64 -> V_109 = V_111 ;
V_64 -> V_298 = V_297 ;
F_82 ( & V_286 ) ;
V_118 = 0 ;
V_64 -> V_223 = F_58 ( V_64 -> V_101 -> V_222 ,
sizeof( struct V_244 * ) ,
V_74 ) ;
V_232 = - V_233 ;
if ( ! V_64 -> V_223 )
goto V_292;
V_232 = F_57 ( V_64 ) ;
if ( V_232 < 0 )
goto V_292;
V_64 -> V_114 = F_84 ( V_293 ) ;
V_232 = F_63 ( V_64 ) ;
V_292:
while ( F_9 ( V_64 , NULL ) >= 0 ) ;
F_78 ( V_64 ) ;
F_88 ( & V_286 ) ;
F_87 ( V_64 -> V_255 ) ;
V_285:
F_10 ( V_64 ) ;
return V_232 ;
}
