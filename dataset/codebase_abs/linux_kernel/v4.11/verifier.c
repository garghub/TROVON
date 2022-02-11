static const char * F_1 ( int V_1 )
{
F_2 ( F_3 ( V_2 ) != V_3 ) ;
if ( V_1 >= 0 && V_1 < V_3 && V_2 [ V_1 ] )
return V_2 [ V_1 ] ;
else
return L_1 ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
enum V_8 V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_7 = & V_5 -> V_12 [ V_10 ] ;
V_9 = V_7 -> type ;
if ( V_9 == V_13 )
continue;
F_5 ( L_2 , V_10 , V_14 [ V_9 ] ) ;
if ( V_9 == V_15 || V_9 == V_16 )
F_5 ( L_3 , V_7 -> V_17 ) ;
else if ( V_9 == V_18 )
F_5 ( L_4 ,
V_7 -> V_1 , V_7 -> V_19 , V_7 -> V_20 ) ;
else if ( V_9 == V_21 && V_7 -> V_17 )
F_5 ( L_3 , V_7 -> V_17 ) ;
else if ( V_9 == V_22 || V_9 == V_23 ||
V_9 == V_24 ||
V_9 == V_25 )
F_5 ( L_5 ,
V_7 -> V_26 -> V_27 ,
V_7 -> V_26 -> V_28 ,
V_7 -> V_1 ) ;
if ( V_7 -> V_29 != V_30 )
F_5 ( L_6 ,
( long long ) V_7 -> V_29 ) ;
if ( V_7 -> V_31 != V_32 )
F_5 ( L_7 ,
( unsigned long long ) V_7 -> V_31 ) ;
}
for ( V_10 = 0 ; V_10 < V_33 ; V_10 += V_34 ) {
if ( V_5 -> V_35 [ V_10 ] == V_36 )
F_5 ( L_8 , - V_33 + V_10 ,
V_14 [ V_5 -> V_37 [ V_10 / V_34 ] . type ] ) ;
}
F_5 ( L_9 ) ;
}
static void F_6 ( struct V_38 * V_39 )
{
T_1 V_40 = F_7 ( V_39 -> V_41 ) ;
if ( V_40 == V_42 || V_40 == V_43 ) {
if ( F_8 ( V_39 -> V_41 ) == V_44 )
F_5 ( L_10 ,
V_39 -> V_41 , V_40 == V_42 ? L_11 : L_12 ,
V_39 -> V_45 ,
V_46 [ F_9 ( V_39 -> V_41 ) >> 4 ] ,
V_40 == V_42 ? L_11 : L_12 ,
V_39 -> V_47 ) ;
else
F_5 ( L_13 ,
V_39 -> V_41 , V_40 == V_42 ? L_11 : L_12 ,
V_39 -> V_45 ,
V_46 [ F_9 ( V_39 -> V_41 ) >> 4 ] ,
V_40 == V_42 ? L_11 : L_12 ,
V_39 -> V_17 ) ;
} else if ( V_40 == V_48 ) {
if ( F_10 ( V_39 -> V_41 ) == V_49 )
F_5 ( L_14 ,
V_39 -> V_41 ,
V_50 [ F_11 ( V_39 -> V_41 ) >> 3 ] ,
V_39 -> V_45 ,
V_39 -> V_19 , V_39 -> V_47 ) ;
else if ( F_10 ( V_39 -> V_41 ) == V_51 )
F_5 ( L_15 ,
V_39 -> V_41 ,
V_50 [ F_11 ( V_39 -> V_41 ) >> 3 ] ,
V_39 -> V_45 , V_39 -> V_19 ,
V_39 -> V_47 ) ;
else
F_5 ( L_16 , V_39 -> V_41 ) ;
} else if ( V_40 == V_52 ) {
if ( F_10 ( V_39 -> V_41 ) != V_49 ) {
F_5 ( L_17 , V_39 -> V_41 ) ;
return;
}
F_5 ( L_18 ,
V_39 -> V_41 ,
V_50 [ F_11 ( V_39 -> V_41 ) >> 3 ] ,
V_39 -> V_45 ,
V_39 -> V_19 , V_39 -> V_17 ) ;
} else if ( V_40 == V_53 ) {
if ( F_10 ( V_39 -> V_41 ) != V_49 ) {
F_5 ( L_19 , V_39 -> V_41 ) ;
return;
}
F_5 ( L_20 ,
V_39 -> V_41 , V_39 -> V_45 ,
V_50 [ F_11 ( V_39 -> V_41 ) >> 3 ] ,
V_39 -> V_47 , V_39 -> V_19 ) ;
} else if ( V_40 == V_54 ) {
if ( F_10 ( V_39 -> V_41 ) == V_55 ) {
F_5 ( L_21 ,
V_39 -> V_41 ,
V_50 [ F_11 ( V_39 -> V_41 ) >> 3 ] ,
V_39 -> V_17 ) ;
} else if ( F_10 ( V_39 -> V_41 ) == V_56 ) {
F_5 ( L_22 ,
V_39 -> V_41 ,
V_50 [ F_11 ( V_39 -> V_41 ) >> 3 ] ,
V_39 -> V_47 , V_39 -> V_17 ) ;
} else if ( F_10 ( V_39 -> V_41 ) == V_57 ) {
F_5 ( L_23 ,
V_39 -> V_41 , V_39 -> V_45 , V_39 -> V_17 ) ;
} else {
F_5 ( L_24 , V_39 -> V_41 ) ;
return;
}
} else if ( V_40 == V_58 ) {
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
if ( V_59 == V_60 ) {
F_5 ( L_25 , V_39 -> V_41 ,
F_1 ( V_39 -> V_17 ) , V_39 -> V_17 ) ;
} else if ( V_39 -> V_41 == ( V_58 | V_61 ) ) {
F_5 ( L_26 ,
V_39 -> V_41 , V_39 -> V_19 ) ;
} else if ( V_39 -> V_41 == ( V_58 | V_62 ) ) {
F_5 ( L_27 , V_39 -> V_41 ) ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
F_5 ( L_28 ,
V_39 -> V_41 , V_39 -> V_45 ,
V_63 [ F_9 ( V_39 -> V_41 ) >> 4 ] ,
V_39 -> V_47 , V_39 -> V_19 ) ;
} else {
F_5 ( L_29 ,
V_39 -> V_41 , V_39 -> V_45 ,
V_63 [ F_9 ( V_39 -> V_41 ) >> 4 ] ,
V_39 -> V_17 , V_39 -> V_19 ) ;
}
} else {
F_5 ( L_30 , V_39 -> V_41 , V_64 [ V_40 ] ) ;
}
}
static int F_12 ( struct V_65 * V_66 , int * V_67 )
{
struct V_68 * V_69 ;
int V_70 ;
if ( V_66 -> V_71 == NULL )
return - 1 ;
memcpy ( & V_66 -> V_72 , & V_66 -> V_71 -> V_73 , sizeof( V_66 -> V_72 ) ) ;
V_70 = V_66 -> V_71 -> V_70 ;
if ( V_67 )
* V_67 = V_66 -> V_71 -> V_67 ;
V_69 = V_66 -> V_71 -> V_74 ;
F_13 ( V_66 -> V_71 ) ;
V_66 -> V_71 = V_69 ;
V_66 -> V_75 -- ;
return V_70 ;
}
static struct V_4 * F_14 ( struct V_65 * V_66 ,
int V_70 , int V_67 )
{
struct V_68 * V_69 ;
V_69 = F_15 ( sizeof( struct V_68 ) , V_76 ) ;
if ( ! V_69 )
goto V_77;
memcpy ( & V_69 -> V_73 , & V_66 -> V_72 , sizeof( V_66 -> V_72 ) ) ;
V_69 -> V_70 = V_70 ;
V_69 -> V_67 = V_67 ;
V_69 -> V_74 = V_66 -> V_71 ;
V_66 -> V_71 = V_69 ;
V_66 -> V_75 ++ ;
if ( V_66 -> V_75 > V_78 ) {
F_5 ( L_31 ) ;
goto V_77;
}
return & V_69 -> V_73 ;
V_77:
while ( F_12 ( V_66 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_16 ( struct V_6 * V_12 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_12 [ V_10 ] . type = V_13 ;
V_12 [ V_10 ] . V_17 = 0 ;
V_12 [ V_10 ] . V_29 = V_30 ;
V_12 [ V_10 ] . V_31 = V_32 ;
}
V_12 [ V_79 ] . type = V_80 ;
V_12 [ V_81 ] . type = V_82 ;
}
static void F_17 ( struct V_6 * V_12 , T_2 V_83 )
{
V_12 [ V_83 ] . type = V_21 ;
V_12 [ V_83 ] . V_1 = 0 ;
V_12 [ V_83 ] . V_17 = 0 ;
}
static void F_18 ( struct V_6 * V_12 , T_2 V_83 )
{
F_19 ( V_83 >= V_11 ) ;
F_17 ( V_12 , V_83 ) ;
}
static void F_20 ( struct V_6 * V_12 , T_2 V_83 )
{
V_12 [ V_83 ] . V_29 = V_30 ;
V_12 [ V_83 ] . V_31 = V_32 ;
}
static void F_21 ( struct V_6 * V_12 ,
T_2 V_83 )
{
F_18 ( V_12 , V_83 ) ;
F_20 ( V_12 , V_83 ) ;
}
static int F_22 ( struct V_6 * V_12 , T_2 V_83 ,
enum V_84 V_9 )
{
if ( V_83 >= V_11 ) {
F_5 ( L_32 , V_83 ) ;
return - V_85 ;
}
if ( V_9 == V_86 ) {
if ( V_12 [ V_83 ] . type == V_13 ) {
F_5 ( L_33 , V_83 ) ;
return - V_87 ;
}
} else {
if ( V_83 == V_79 ) {
F_5 ( L_34 ) ;
return - V_87 ;
}
if ( V_9 == V_88 )
F_18 ( V_12 , V_83 ) ;
}
return 0 ;
}
static int F_23 ( int V_89 )
{
if ( V_89 == V_90 )
return 4 ;
else if ( V_89 == V_91 )
return 2 ;
else if ( V_89 == V_92 )
return 1 ;
else if ( V_89 == V_93 )
return 8 ;
else
return - V_85 ;
}
static bool F_24 ( enum V_8 type )
{
switch ( type ) {
case V_23 :
case V_24 :
case V_25 :
case V_16 :
case V_82 :
case V_18 :
case V_94 :
case V_80 :
case V_22 :
return true ;
default:
return false ;
}
}
static int F_25 ( struct V_4 * V_5 , int V_19 ,
int V_95 , int V_96 )
{
int V_10 ;
if ( V_96 >= 0 &&
F_24 ( V_5 -> V_12 [ V_96 ] . type ) ) {
if ( V_95 != V_34 ) {
F_5 ( L_35 ) ;
return - V_87 ;
}
V_5 -> V_37 [ ( V_33 + V_19 ) / V_34 ] =
V_5 -> V_12 [ V_96 ] ;
for ( V_10 = 0 ; V_10 < V_34 ; V_10 ++ )
V_5 -> V_35 [ V_33 + V_19 + V_10 ] = V_36 ;
} else {
V_5 -> V_37 [ ( V_33 + V_19 ) / V_34 ] =
(struct V_6 ) {} ;
for ( V_10 = 0 ; V_10 < V_95 ; V_10 ++ )
V_5 -> V_35 [ V_33 + V_19 + V_10 ] = V_97 ;
}
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , int V_19 , int V_95 ,
int V_96 )
{
T_1 * V_98 ;
int V_10 ;
V_98 = & V_5 -> V_35 [ V_33 + V_19 ] ;
if ( V_98 [ 0 ] == V_36 ) {
if ( V_95 != V_34 ) {
F_5 ( L_35 ) ;
return - V_87 ;
}
for ( V_10 = 1 ; V_10 < V_34 ; V_10 ++ ) {
if ( V_98 [ V_10 ] != V_36 ) {
F_5 ( L_36 ) ;
return - V_87 ;
}
}
if ( V_96 >= 0 )
V_5 -> V_12 [ V_96 ] =
V_5 -> V_37 [ ( V_33 + V_19 ) / V_34 ] ;
return 0 ;
} else {
for ( V_10 = 0 ; V_10 < V_95 ; V_10 ++ ) {
if ( V_98 [ V_10 ] != V_97 ) {
F_5 ( L_37 ,
V_19 , V_10 , V_95 ) ;
return - V_87 ;
}
}
if ( V_96 >= 0 )
F_21 ( V_5 -> V_12 ,
V_96 ) ;
return 0 ;
}
}
static int F_27 ( struct V_65 * V_66 , T_2 V_83 , int V_19 ,
int V_95 )
{
struct V_99 * V_100 = V_66 -> V_72 . V_12 [ V_83 ] . V_26 ;
if ( V_19 < 0 || V_95 <= 0 || V_19 + V_95 > V_100 -> V_28 ) {
F_5 ( L_38 ,
V_100 -> V_28 , V_19 , V_95 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_28 ( struct V_65 * V_66 , T_2 V_83 ,
int V_19 , int V_95 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_83 ] ;
int V_77 ;
if ( V_101 )
F_4 ( V_5 ) ;
V_66 -> V_102 = true ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_39 ,
V_83 ) ;
return - V_87 ;
}
V_77 = F_27 ( V_66 , V_83 , V_7 -> V_29 + V_19 , V_95 ) ;
if ( V_77 ) {
F_5 ( L_40 ,
V_83 ) ;
return V_77 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_41 ,
V_83 ) ;
return - V_87 ;
}
return F_27 ( V_66 , V_83 , V_7 -> V_31 + V_19 , V_95 ) ;
}
static bool F_29 ( struct V_65 * V_66 ,
const struct V_103 * V_104 ,
enum V_105 V_9 )
{
switch ( V_66 -> V_106 -> type ) {
case V_107 :
case V_108 :
if ( V_9 == V_109 )
return false ;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
if ( V_104 )
return V_104 -> V_114 ;
V_66 -> V_115 = true ;
return true ;
default:
return false ;
}
}
static int F_30 ( struct V_65 * V_66 , T_2 V_83 , int V_19 ,
int V_95 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_7 = & V_12 [ V_83 ] ;
V_19 += V_7 -> V_19 ;
if ( V_19 < 0 || V_95 <= 0 || V_19 + V_95 > V_7 -> V_20 ) {
F_5 ( L_42 ,
V_19 , V_95 , V_83 , V_7 -> V_1 , V_7 -> V_19 , V_7 -> V_20 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_31 ( struct V_65 * V_66 , int V_19 , int V_95 ,
enum V_105 V_9 , enum V_8 * V_116 )
{
if ( V_66 -> V_117 )
return 0 ;
if ( V_66 -> V_106 -> V_118 -> V_119 -> V_120 &&
V_66 -> V_106 -> V_118 -> V_119 -> V_120 ( V_19 , V_95 , V_9 , V_116 ) ) {
if ( V_66 -> V_106 -> V_118 -> V_121 < V_19 + V_95 )
V_66 -> V_106 -> V_118 -> V_121 = V_19 + V_95 ;
return 0 ;
}
F_5 ( L_43 , V_19 , V_95 ) ;
return - V_87 ;
}
static bool F_32 ( struct V_65 * V_66 , int V_83 )
{
if ( V_66 -> V_122 )
return false ;
switch ( V_66 -> V_72 . V_12 [ V_83 ] . type ) {
case V_21 :
case V_15 :
return false ;
default:
return true ;
}
}
static int F_33 ( const struct V_6 * V_7 ,
int V_19 , int V_95 )
{
if ( V_7 -> V_1 && V_95 != 1 ) {
F_5 ( L_44 ) ;
return - V_87 ;
}
if ( ( V_123 + V_7 -> V_19 + V_19 ) % V_95 != 0 ) {
F_5 ( L_45 ,
V_123 , V_7 -> V_19 , V_19 , V_95 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_34 ( const struct V_6 * V_7 ,
int V_95 )
{
if ( V_95 != 1 ) {
F_5 ( L_46 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_35 ( const struct V_6 * V_7 ,
int V_19 , int V_95 )
{
switch ( V_7 -> type ) {
case V_18 :
return F_36 ( V_124 ) ? 0 :
F_33 ( V_7 , V_19 , V_95 ) ;
case V_25 :
return F_36 ( V_124 ) ? 0 :
F_34 ( V_7 , V_95 ) ;
default:
if ( V_19 % V_95 != 0 ) {
F_5 ( L_47 ,
V_19 , V_95 ) ;
return - V_87 ;
}
return 0 ;
}
}
static int F_37 ( struct V_65 * V_66 , T_2 V_83 , int V_19 ,
int V_89 , enum V_105 V_9 ,
int V_96 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_83 ] ;
int V_95 , V_77 = 0 ;
if ( V_7 -> type == V_16 )
V_19 += V_7 -> V_17 ;
V_95 = F_23 ( V_89 ) ;
if ( V_95 < 0 )
return V_95 ;
V_77 = F_35 ( V_7 , V_19 , V_95 ) ;
if ( V_77 )
return V_77 ;
if ( V_7 -> type == V_23 ||
V_7 -> type == V_25 ) {
if ( V_9 == V_109 && V_96 >= 0 &&
F_32 ( V_66 , V_96 ) ) {
F_5 ( L_48 , V_96 ) ;
return - V_87 ;
}
if ( V_7 -> type == V_25 )
V_77 = F_28 ( V_66 , V_83 , V_19 , V_95 ) ;
else
V_77 = F_27 ( V_66 , V_83 , V_19 , V_95 ) ;
if ( ! V_77 && V_9 == V_125 && V_96 >= 0 )
F_21 ( V_5 -> V_12 ,
V_96 ) ;
} else if ( V_7 -> type == V_82 ) {
enum V_8 V_116 = V_21 ;
if ( V_9 == V_109 && V_96 >= 0 &&
F_32 ( V_66 , V_96 ) ) {
F_5 ( L_49 , V_96 ) ;
return - V_87 ;
}
V_77 = F_31 ( V_66 , V_19 , V_95 , V_9 , & V_116 ) ;
if ( ! V_77 && V_9 == V_125 && V_96 >= 0 ) {
F_21 ( V_5 -> V_12 ,
V_96 ) ;
V_5 -> V_12 [ V_96 ] . type = V_116 ;
}
} else if ( V_7 -> type == V_80 || V_7 -> type == V_16 ) {
if ( V_19 >= 0 || V_19 < - V_33 ) {
F_5 ( L_50 , V_19 , V_95 ) ;
return - V_87 ;
}
if ( V_9 == V_109 ) {
if ( ! V_66 -> V_122 &&
V_5 -> V_35 [ V_33 + V_19 ] == V_36 &&
V_95 != V_34 ) {
F_5 ( L_51 ) ;
return - V_87 ;
}
V_77 = F_25 ( V_5 , V_19 , V_95 , V_96 ) ;
} else {
V_77 = F_26 ( V_5 , V_19 , V_95 , V_96 ) ;
}
} else if ( V_5 -> V_12 [ V_83 ] . type == V_18 ) {
if ( V_9 == V_109 && ! F_29 ( V_66 , NULL , V_9 ) ) {
F_5 ( L_52 ) ;
return - V_87 ;
}
if ( V_9 == V_109 && V_96 >= 0 &&
F_32 ( V_66 , V_96 ) ) {
F_5 ( L_53 , V_96 ) ;
return - V_87 ;
}
V_77 = F_30 ( V_66 , V_83 , V_19 , V_95 ) ;
if ( ! V_77 && V_9 == V_125 && V_96 >= 0 )
F_21 ( V_5 -> V_12 ,
V_96 ) ;
} else {
F_5 ( L_54 ,
V_83 , V_14 [ V_7 -> type ] ) ;
return - V_87 ;
}
if ( ! V_77 && V_95 <= 2 && V_96 >= 0 && V_66 -> V_122 &&
V_5 -> V_12 [ V_96 ] . type == V_21 ) {
V_5 -> V_12 [ V_96 ] . V_17 = 64 - V_95 * 8 ;
}
return V_77 ;
}
static int F_38 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
int V_77 ;
if ( ( F_11 ( V_39 -> V_41 ) != V_90 && F_11 ( V_39 -> V_41 ) != V_93 ) ||
V_39 -> V_17 != 0 ) {
F_5 ( L_55 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_37 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_125 , - 1 ) ;
if ( V_77 )
return V_77 ;
return F_37 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_109 , - 1 ) ;
}
static int F_39 ( struct V_65 * V_66 , int V_83 ,
int V_126 , bool V_127 ,
struct V_103 * V_104 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_19 , V_10 ;
if ( V_12 [ V_83 ] . type != V_16 ) {
if ( V_127 && V_126 == 0 &&
V_12 [ V_83 ] . type == V_15 &&
V_12 [ V_83 ] . V_17 == 0 )
return 0 ;
F_5 ( L_56 , V_83 ,
V_14 [ V_12 [ V_83 ] . type ] ,
V_14 [ V_16 ] ) ;
return - V_87 ;
}
V_19 = V_12 [ V_83 ] . V_17 ;
if ( V_19 >= 0 || V_19 < - V_33 || V_19 + V_126 > 0 ||
V_126 <= 0 ) {
F_5 ( L_57 ,
V_83 , V_19 , V_126 ) ;
return - V_87 ;
}
if ( V_104 && V_104 -> V_128 ) {
V_104 -> V_126 = V_126 ;
V_104 -> V_83 = V_83 ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_126 ; V_10 ++ ) {
if ( V_5 -> V_35 [ V_33 + V_19 + V_10 ] != V_97 ) {
F_5 ( L_58 ,
V_19 , V_10 , V_126 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int F_40 ( struct V_65 * V_66 , int V_83 ,
int V_126 , bool V_127 ,
struct V_103 * V_104 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
switch ( V_12 [ V_83 ] . type ) {
case V_18 :
return F_30 ( V_66 , V_83 , 0 , V_126 ) ;
case V_23 :
return F_27 ( V_66 , V_83 , 0 , V_126 ) ;
case V_25 :
return F_28 ( V_66 , V_83 , 0 , V_126 ) ;
default:
return F_39 ( V_66 , V_83 , V_126 ,
V_127 , V_104 ) ;
}
}
static int F_41 ( struct V_65 * V_66 , T_2 V_83 ,
enum V_129 V_130 ,
struct V_103 * V_104 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 , * V_7 = & V_12 [ V_83 ] ;
enum V_8 V_131 , type = V_7 -> type ;
int V_77 = 0 ;
if ( V_130 == V_132 )
return 0 ;
if ( type == V_13 ) {
F_5 ( L_33 , V_83 ) ;
return - V_87 ;
}
if ( V_130 == V_133 ) {
if ( F_32 ( V_66 , V_83 ) ) {
F_5 ( L_59 , V_83 ) ;
return - V_87 ;
}
return 0 ;
}
if ( type == V_18 &&
! F_29 ( V_66 , V_104 , V_125 ) ) {
F_5 ( L_60 ) ;
return - V_87 ;
}
if ( V_130 == V_134 ||
V_130 == V_135 ) {
V_131 = V_16 ;
if ( type != V_18 && type != V_131 )
goto V_136;
} else if ( V_130 == V_137 ||
V_130 == V_138 ) {
V_131 = V_15 ;
if ( type != V_21 && type != V_131 )
goto V_136;
} else if ( V_130 == V_139 ) {
V_131 = V_22 ;
if ( type != V_131 )
goto V_136;
} else if ( V_130 == V_140 ) {
V_131 = V_82 ;
if ( type != V_131 )
goto V_136;
} else if ( V_130 == V_141 ||
V_130 == V_142 ) {
V_131 = V_16 ;
if ( type == V_15 && V_7 -> V_17 == 0 )
;
else if ( type != V_18 && type != V_23 &&
type != V_25 && type != V_131 )
goto V_136;
V_104 -> V_128 = V_130 == V_142 ;
} else {
F_5 ( L_61 , V_130 ) ;
return - V_143 ;
}
if ( V_130 == V_139 ) {
V_104 -> V_26 = V_7 -> V_26 ;
} else if ( V_130 == V_134 ) {
if ( ! V_104 -> V_26 ) {
F_5 ( L_62 ) ;
return - V_87 ;
}
if ( type == V_18 )
V_77 = F_30 ( V_66 , V_83 , 0 ,
V_104 -> V_26 -> V_27 ) ;
else
V_77 = F_39 ( V_66 , V_83 ,
V_104 -> V_26 -> V_27 ,
false , NULL ) ;
} else if ( V_130 == V_135 ) {
if ( ! V_104 -> V_26 ) {
F_5 ( L_63 ) ;
return - V_87 ;
}
if ( type == V_18 )
V_77 = F_30 ( V_66 , V_83 , 0 ,
V_104 -> V_26 -> V_28 ) ;
else
V_77 = F_39 ( V_66 , V_83 ,
V_104 -> V_26 -> V_28 ,
false , NULL ) ;
} else if ( V_130 == V_137 ||
V_130 == V_138 ) {
bool V_127 = ( V_130 == V_138 ) ;
if ( V_83 == 0 ) {
F_5 ( L_64 ) ;
return - V_87 ;
}
if ( type == V_21 ) {
V_104 = NULL ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_65 ,
V_83 ) ;
return - V_87 ;
}
if ( V_7 -> V_29 == 0 ) {
V_77 = F_40 ( V_66 , V_83 - 1 , 0 ,
V_127 ,
V_104 ) ;
if ( V_77 )
return V_77 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_66 ,
V_83 ) ;
return - V_87 ;
}
V_77 = F_40 ( V_66 , V_83 - 1 ,
V_7 -> V_31 ,
V_127 , V_104 ) ;
if ( V_77 )
return V_77 ;
} else {
V_77 = F_40 ( V_66 , V_83 - 1 , V_7 -> V_17 ,
V_127 , V_104 ) ;
}
}
return V_77 ;
V_136:
F_5 ( L_56 , V_83 ,
V_14 [ type ] , V_14 [ V_131 ] ) ;
return - V_87 ;
}
static int F_42 ( struct V_99 * V_100 , int V_144 )
{
if ( ! V_100 )
return 0 ;
switch ( V_100 -> V_145 ) {
case V_146 :
if ( V_144 != V_147 )
goto error;
break;
case V_148 :
if ( V_144 != V_149 &&
V_144 != V_150 )
goto error;
break;
case V_151 :
if ( V_144 != V_152 )
goto error;
break;
case V_153 :
if ( V_144 != V_154 &&
V_144 != V_155 )
goto error;
break;
default:
break;
}
switch ( V_144 ) {
case V_147 :
if ( V_100 -> V_145 != V_146 )
goto error;
break;
case V_149 :
case V_150 :
if ( V_100 -> V_145 != V_148 )
goto error;
break;
case V_152 :
if ( V_100 -> V_145 != V_151 )
goto error;
break;
case V_155 :
case V_154 :
if ( V_100 -> V_145 != V_153 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_5 ( L_67 ,
V_100 -> V_145 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
static int F_43 ( const struct V_156 * V_157 )
{
int V_158 = 0 ;
if ( V_157 -> V_159 == V_142 )
V_158 ++ ;
if ( V_157 -> V_160 == V_142 )
V_158 ++ ;
if ( V_157 -> V_161 == V_142 )
V_158 ++ ;
if ( V_157 -> V_162 == V_142 )
V_158 ++ ;
if ( V_157 -> V_163 == V_142 )
V_158 ++ ;
return V_158 > 1 ? - V_85 : 0 ;
}
static void F_44 ( struct V_65 * V_66 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 ||
V_12 [ V_10 ] . type == V_94 )
F_18 ( V_12 , V_10 ) ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 += V_34 ) {
if ( V_5 -> V_35 [ V_10 ] != V_36 )
continue;
V_7 = & V_5 -> V_37 [ V_10 / V_34 ] ;
if ( V_7 -> type != V_18 &&
V_7 -> type != V_94 )
continue;
V_7 -> type = V_21 ;
V_7 -> V_17 = 0 ;
}
}
static int F_45 ( struct V_65 * V_66 , int V_144 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
const struct V_156 * V_157 = NULL ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_6 * V_7 ;
struct V_103 V_104 ;
bool V_164 ;
int V_10 , V_77 ;
if ( V_144 < 0 || V_144 >= V_3 ) {
F_5 ( L_68 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
if ( V_66 -> V_106 -> V_118 -> V_119 -> V_165 )
V_157 = V_66 -> V_106 -> V_118 -> V_119 -> V_165 ( V_144 ) ;
if ( ! V_157 ) {
F_5 ( L_69 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
if ( ! V_66 -> V_106 -> V_166 && V_157 -> V_167 ) {
F_5 ( L_70 ) ;
return - V_85 ;
}
V_164 = F_46 ( V_157 -> V_168 ) ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_114 = V_157 -> V_114 ;
V_77 = F_43 ( V_157 ) ;
if ( V_77 ) {
F_5 ( L_71 ,
F_1 ( V_144 ) , V_144 ) ;
return V_77 ;
}
V_77 = F_41 ( V_66 , V_81 , V_157 -> V_159 , & V_104 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_41 ( V_66 , V_169 , V_157 -> V_160 , & V_104 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_41 ( V_66 , V_170 , V_157 -> V_161 , & V_104 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_41 ( V_66 , V_171 , V_157 -> V_162 , & V_104 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_41 ( V_66 , V_172 , V_157 -> V_163 , & V_104 ) ;
if ( V_77 )
return V_77 ;
for ( V_10 = 0 ; V_10 < V_104 . V_126 ; V_10 ++ ) {
V_77 = F_37 ( V_66 , V_104 . V_83 , V_10 , V_92 , V_109 , - 1 ) ;
if ( V_77 )
return V_77 ;
}
for ( V_10 = 0 ; V_10 < V_173 ; V_10 ++ ) {
V_7 = V_12 + V_174 [ V_10 ] ;
V_7 -> type = V_13 ;
V_7 -> V_17 = 0 ;
}
if ( V_157 -> V_175 == V_176 ) {
V_12 [ V_177 ] . type = V_21 ;
} else if ( V_157 -> V_175 == V_178 ) {
V_12 [ V_177 ] . type = V_13 ;
} else if ( V_157 -> V_175 == V_179 ) {
V_12 [ V_177 ] . type = V_24 ;
V_12 [ V_177 ] . V_31 = V_12 [ V_177 ] . V_29 = 0 ;
if ( V_104 . V_26 == NULL ) {
F_5 ( L_72 ) ;
return - V_85 ;
}
V_12 [ V_177 ] . V_26 = V_104 . V_26 ;
V_12 [ V_177 ] . V_1 = ++ V_66 -> V_180 ;
} else {
F_5 ( L_73 ,
V_157 -> V_175 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
V_77 = F_42 ( V_104 . V_26 , V_144 ) ;
if ( V_77 )
return V_77 ;
if ( V_164 )
F_44 ( V_66 ) ;
return 0 ;
}
static int F_47 ( struct V_65 * V_66 ,
struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_45 = & V_12 [ V_39 -> V_45 ] ;
struct V_6 * V_47 = & V_12 [ V_39 -> V_47 ] ;
struct V_6 V_181 ;
T_3 V_17 ;
if ( F_8 ( V_39 -> V_41 ) == V_182 ) {
V_17 = V_39 -> V_17 ;
V_183:
if ( V_17 < 0 ) {
F_5 ( L_74 ) ;
return - V_87 ;
}
if ( V_17 >= V_184 ||
V_17 + V_45 -> V_19 >= V_184 ) {
F_5 ( L_75 ,
V_17 ) ;
return - V_87 ;
}
V_45 -> V_19 += V_17 ;
} else {
if ( V_47 -> type == V_18 ) {
V_181 = * V_45 ;
* V_45 = * V_47 ;
V_47 = & V_181 ;
}
if ( V_47 -> type == V_15 ) {
V_17 = V_47 -> V_17 ;
goto V_183;
}
if ( V_47 -> type != V_21 ) {
F_5 ( L_76 ,
V_14 [ V_47 -> type ] ) ;
return - V_87 ;
}
if ( V_47 -> V_17 < 48 ) {
F_5 ( L_77 ,
V_47 -> V_17 ) ;
return - V_87 ;
}
V_45 -> V_1 = ++ V_66 -> V_180 ;
V_45 -> V_19 = 0 ;
V_45 -> V_20 = 0 ;
}
return 0 ;
}
static int F_48 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_45 = & V_12 [ V_39 -> V_45 ] ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
T_4 V_185 ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
struct V_6 * V_47 = & V_12 [ V_39 -> V_47 ] ;
if ( V_47 -> type == V_21 && V_47 -> V_17 > 0 &&
V_45 -> V_17 && V_59 == V_186 ) {
V_45 -> V_17 = F_49 ( V_45 -> V_17 , V_47 -> V_17 ) ;
V_45 -> V_17 -- ;
return 0 ;
}
if ( V_47 -> type == V_15 && V_47 -> V_17 > 0 &&
V_45 -> V_17 && V_59 == V_186 ) {
V_185 = F_50 ( ( long long ) V_47 -> V_17 ) ;
V_45 -> V_17 = F_49 ( V_45 -> V_17 , 63 - V_185 ) ;
V_45 -> V_17 -- ;
return 0 ;
}
V_45 -> V_17 = 0 ;
return 0 ;
}
V_185 = F_50 ( ( long long ) V_39 -> V_17 ) ;
if ( V_45 -> V_17 && V_59 == V_187 ) {
V_45 -> V_17 -= V_39 -> V_17 ;
} else if ( V_45 -> V_17 && V_59 == V_188 ) {
V_45 -> V_17 -= V_185 + 1 ;
} else if ( V_59 == V_189 ) {
V_45 -> V_17 = 63 - V_185 ;
} else if ( V_45 -> V_17 && V_59 == V_186 ) {
V_45 -> V_17 = F_49 ( V_45 -> V_17 , 63 - V_185 ) ;
V_45 -> V_17 -- ;
} else if ( V_59 == V_190 ) {
V_45 -> V_17 += V_39 -> V_17 ;
if ( F_51 ( V_45 -> V_17 > 64 ) )
V_45 -> V_17 = 64 ;
} else {
V_45 -> V_17 = 0 ;
}
if ( V_45 -> V_17 < 0 ) {
V_45 -> V_17 = 0 ;
}
return 0 ;
}
static int F_52 ( struct V_65 * V_66 ,
struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_45 = & V_12 [ V_39 -> V_45 ] ;
struct V_6 * V_47 = & V_12 [ V_39 -> V_47 ] ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
T_5 V_191 = V_45 -> V_17 ;
if ( V_59 == V_186 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 += V_39 -> V_17 ;
} else if ( V_59 == V_186 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 += V_47 -> V_17 ;
} else if ( V_59 == V_192 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 -= V_39 -> V_17 ;
} else if ( V_59 == V_192 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 -= V_47 -> V_17 ;
} else if ( V_59 == V_188 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 *= V_39 -> V_17 ;
} else if ( V_59 == V_188 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 *= V_47 -> V_17 ;
} else if ( V_59 == V_193 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 |= V_39 -> V_17 ;
} else if ( V_59 == V_193 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 |= V_47 -> V_17 ;
} else if ( V_59 == V_189 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 &= V_39 -> V_17 ;
} else if ( V_59 == V_189 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 &= V_47 -> V_17 ;
} else if ( V_59 == V_190 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 >>= V_39 -> V_17 ;
} else if ( V_59 == V_190 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 >>= V_47 -> V_17 ;
} else if ( V_59 == V_187 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_191 <<= V_39 -> V_17 ;
} else if ( V_59 == V_187 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 ) {
V_191 <<= V_47 -> V_17 ;
} else {
F_18 ( V_12 , V_39 -> V_45 ) ;
goto V_194;
}
V_45 -> V_17 = V_191 ;
V_194:
return 0 ;
}
static void F_53 ( struct V_6 * V_7 )
{
if ( V_7 -> V_31 > V_32 )
V_7 -> V_31 = V_32 ;
if ( V_7 -> V_29 < V_30 ||
V_7 -> V_29 > V_32 )
V_7 -> V_29 = V_30 ;
}
static void F_54 ( struct V_65 * V_66 ,
struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 , * V_45 ;
T_4 V_195 = V_30 ;
T_5 V_196 = V_32 ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
V_45 = & V_12 [ V_39 -> V_45 ] ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
F_53 ( & V_12 [ V_39 -> V_47 ] ) ;
V_195 = V_12 [ V_39 -> V_47 ] . V_29 ;
V_196 = V_12 [ V_39 -> V_47 ] . V_31 ;
if ( V_12 [ V_39 -> V_47 ] . type != V_15 &&
V_12 [ V_39 -> V_47 ] . type != V_21 ) {
V_195 = V_30 ;
V_196 = V_32 ;
}
} else if ( V_39 -> V_17 < V_32 &&
( T_4 ) V_39 -> V_17 > V_30 ) {
V_195 = V_196 = V_39 -> V_17 ;
}
if ( V_195 == V_30 &&
V_196 == V_32 ) {
F_20 ( V_12 , V_39 -> V_45 ) ;
return;
}
if ( V_195 == V_30 )
V_45 -> V_29 = V_30 ;
if ( V_196 == V_32 )
V_45 -> V_31 = V_32 ;
switch ( V_59 ) {
case V_186 :
if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 += V_195 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 += V_196 ;
break;
case V_192 :
if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 -= V_195 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 -= V_196 ;
break;
case V_188 :
if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 *= V_195 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 *= V_196 ;
break;
case V_189 :
if ( V_195 < 0 )
V_45 -> V_29 = V_30 ;
else
V_45 -> V_29 = 0 ;
V_45 -> V_31 = V_196 ;
break;
case V_187 :
if ( V_195 > F_55 ( V_32 ) )
V_45 -> V_29 = V_30 ;
else if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 <<= V_195 ;
if ( V_196 > F_55 ( V_32 ) )
V_45 -> V_31 = V_32 ;
else if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 <<= V_196 ;
break;
case V_190 :
if ( V_195 < 0 || V_45 -> V_29 < 0 )
V_45 -> V_29 = V_30 ;
else
V_45 -> V_29 =
( T_5 ) ( V_45 -> V_29 ) >> V_195 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 >>= V_196 ;
break;
default:
F_20 ( V_12 , V_39 -> V_45 ) ;
break;
}
F_53 ( V_45 ) ;
}
static int F_56 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 , * V_45 ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
int V_77 ;
if ( V_59 == V_197 || V_59 == V_198 ) {
if ( V_59 == V_198 ) {
if ( F_8 ( V_39 -> V_41 ) != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_19 != 0 || V_39 -> V_17 != 0 ) {
F_5 ( L_78 ) ;
return - V_85 ;
}
} else {
if ( V_39 -> V_47 != V_177 || V_39 -> V_19 != 0 ||
( V_39 -> V_17 != 16 && V_39 -> V_17 != 32 && V_39 -> V_17 != 64 ) ) {
F_5 ( L_79 ) ;
return - V_85 ;
}
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( F_32 ( V_66 , V_39 -> V_45 ) ) {
F_5 ( L_80 ,
V_39 -> V_45 ) ;
return - V_87 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_88 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_59 == V_199 ) {
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_39 -> V_17 != 0 || V_39 -> V_19 != 0 ) {
F_5 ( L_81 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
} else {
if ( V_39 -> V_47 != V_177 || V_39 -> V_19 != 0 ) {
F_5 ( L_81 ) ;
return - V_85 ;
}
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_88 ) ;
if ( V_77 )
return V_77 ;
F_20 ( V_12 , V_39 -> V_45 ) ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( F_7 ( V_39 -> V_41 ) == V_43 ) {
V_12 [ V_39 -> V_45 ] = V_12 [ V_39 -> V_47 ] ;
} else {
if ( F_32 ( V_66 , V_39 -> V_47 ) ) {
F_5 ( L_82 ,
V_39 -> V_47 ) ;
return - V_87 ;
}
F_18 ( V_12 , V_39 -> V_45 ) ;
}
} else {
V_12 [ V_39 -> V_45 ] . type = V_15 ;
V_12 [ V_39 -> V_45 ] . V_17 = V_39 -> V_17 ;
V_12 [ V_39 -> V_45 ] . V_31 = V_39 -> V_17 ;
V_12 [ V_39 -> V_45 ] . V_29 = V_39 -> V_17 ;
}
} else if ( V_59 > V_197 ) {
F_5 ( L_83 , V_59 ) ;
return - V_85 ;
} else {
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_39 -> V_17 != 0 || V_39 -> V_19 != 0 ) {
F_5 ( L_84 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
} else {
if ( V_39 -> V_47 != V_177 || V_39 -> V_19 != 0 ) {
F_5 ( L_84 ) ;
return - V_85 ;
}
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( ( V_59 == V_200 || V_59 == V_201 ) &&
F_8 ( V_39 -> V_41 ) == V_182 && V_39 -> V_17 == 0 ) {
F_5 ( L_85 ) ;
return - V_85 ;
}
if ( ( V_59 == V_187 || V_59 == V_190 ||
V_59 == V_202 ) && F_8 ( V_39 -> V_41 ) == V_182 ) {
int V_95 = F_7 ( V_39 -> V_41 ) == V_43 ? 64 : 32 ;
if ( V_39 -> V_17 < 0 || V_39 -> V_17 >= V_95 ) {
F_5 ( L_86 , V_39 -> V_17 ) ;
return - V_85 ;
}
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_203 ) ;
if ( V_77 )
return V_77 ;
V_45 = & V_12 [ V_39 -> V_45 ] ;
F_54 ( V_66 , V_39 ) ;
if ( V_59 == V_186 && F_7 ( V_39 -> V_41 ) == V_43 &&
V_45 -> type == V_80 && F_8 ( V_39 -> V_41 ) == V_182 ) {
V_45 -> type = V_16 ;
V_45 -> V_17 = V_39 -> V_17 ;
return 0 ;
} else if ( V_59 == V_186 &&
F_7 ( V_39 -> V_41 ) == V_43 &&
( V_45 -> type == V_18 ||
( F_8 ( V_39 -> V_41 ) == V_44 &&
V_12 [ V_39 -> V_47 ] . type == V_18 ) ) ) {
return F_47 ( V_66 , V_39 ) ;
} else if ( F_7 ( V_39 -> V_41 ) == V_43 &&
V_45 -> type == V_21 &&
V_66 -> V_122 ) {
return F_48 ( V_66 , V_39 ) ;
} else if ( F_7 ( V_39 -> V_41 ) == V_43 &&
V_45 -> type == V_15 &&
V_66 -> V_122 ) {
return F_52 ( V_66 , V_39 ) ;
} else if ( F_32 ( V_66 , V_39 -> V_45 ) ) {
F_5 ( L_80 ,
V_39 -> V_45 ) ;
return - V_87 ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 &&
F_32 ( V_66 , V_39 -> V_47 ) ) {
F_5 ( L_80 ,
V_39 -> V_47 ) ;
return - V_87 ;
}
if ( V_66 -> V_122 &&
F_7 ( V_39 -> V_41 ) == V_43 && V_59 == V_186 &&
( V_45 -> type == V_23 ||
V_45 -> type == V_25 ) )
V_45 -> type = V_25 ;
else
F_18 ( V_12 , V_39 -> V_45 ) ;
}
return 0 ;
}
static void F_57 ( struct V_4 * V_5 ,
struct V_6 * V_45 )
{
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 && V_12 [ V_10 ] . V_1 == V_45 -> V_1 )
V_12 [ V_10 ] . V_20 = F_58 ( V_12 [ V_10 ] . V_20 , V_45 -> V_19 ) ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 += V_34 ) {
if ( V_5 -> V_35 [ V_10 ] != V_36 )
continue;
V_7 = & V_5 -> V_37 [ V_10 / V_34 ] ;
if ( V_7 -> type == V_18 && V_7 -> V_1 == V_45 -> V_1 )
V_7 -> V_20 = F_58 ( V_7 -> V_20 , V_45 -> V_19 ) ;
}
}
static void F_59 ( struct V_6 * V_204 ,
struct V_6 * V_205 , T_5 V_206 ,
T_1 V_59 )
{
switch ( V_59 ) {
case V_207 :
V_204 -> V_31 = V_204 -> V_29 = V_206 ;
break;
case V_208 :
V_205 -> V_31 = V_205 -> V_29 = V_206 ;
break;
case V_209 :
V_205 -> V_29 = 0 ;
case V_210 :
V_205 -> V_31 = V_206 ;
V_204 -> V_29 = V_206 + 1 ;
break;
case V_211 :
V_205 -> V_29 = 0 ;
case V_212 :
V_205 -> V_31 = V_206 - 1 ;
V_204 -> V_29 = V_206 ;
break;
default:
break;
}
F_53 ( V_205 ) ;
F_53 ( V_204 ) ;
}
static void F_60 ( struct V_6 * V_204 ,
struct V_6 * V_205 , T_5 V_206 ,
T_1 V_59 )
{
switch ( V_59 ) {
case V_207 :
V_204 -> V_31 = V_204 -> V_29 = V_206 ;
break;
case V_208 :
V_205 -> V_31 = V_205 -> V_29 = V_206 ;
break;
case V_209 :
V_204 -> V_29 = 0 ;
case V_210 :
V_205 -> V_29 = V_206 ;
V_204 -> V_31 = V_206 - 1 ;
break;
case V_211 :
V_204 -> V_29 = 0 ;
case V_212 :
V_205 -> V_29 = V_206 + 1 ;
V_204 -> V_31 = V_206 ;
break;
default:
break;
}
F_53 ( V_205 ) ;
F_53 ( V_204 ) ;
}
static void F_61 ( struct V_6 * V_12 , T_2 V_83 , T_2 V_1 ,
enum V_8 type )
{
struct V_6 * V_7 = & V_12 [ V_83 ] ;
if ( V_7 -> type == V_24 && V_7 -> V_1 == V_1 ) {
V_7 -> type = type ;
V_7 -> V_1 = 0 ;
if ( type == V_21 )
F_17 ( V_12 , V_83 ) ;
}
}
static void F_62 ( struct V_4 * V_5 , T_2 V_83 ,
enum V_8 type )
{
struct V_6 * V_12 = V_5 -> V_12 ;
T_2 V_1 = V_12 [ V_83 ] . V_1 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_61 ( V_12 , V_10 , V_1 , type ) ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 += V_34 ) {
if ( V_5 -> V_35 [ V_10 ] != V_36 )
continue;
F_61 ( V_5 -> V_37 , V_10 / V_34 , V_1 , type ) ;
}
}
static int F_63 ( struct V_65 * V_66 ,
struct V_38 * V_39 , int * V_70 )
{
struct V_4 * V_213 , * V_214 = & V_66 -> V_72 ;
struct V_6 * V_12 = V_214 -> V_12 , * V_45 ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
int V_77 ;
if ( V_59 > V_62 ) {
F_5 ( L_87 , V_59 ) ;
return - V_85 ;
}
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_39 -> V_17 != 0 ) {
F_5 ( L_88 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( F_32 ( V_66 , V_39 -> V_47 ) ) {
F_5 ( L_89 ,
V_39 -> V_47 ) ;
return - V_87 ;
}
} else {
if ( V_39 -> V_47 != V_177 ) {
F_5 ( L_88 ) ;
return - V_85 ;
}
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_45 = & V_12 [ V_39 -> V_45 ] ;
if ( F_8 ( V_39 -> V_41 ) == V_182 &&
( V_59 == V_207 || V_59 == V_208 ) &&
V_45 -> type == V_15 && V_45 -> V_17 == V_39 -> V_17 ) {
if ( V_59 == V_207 ) {
* V_70 += V_39 -> V_19 ;
return 0 ;
} else {
return 0 ;
}
}
V_213 = F_14 ( V_66 , * V_70 + V_39 -> V_19 + 1 , * V_70 ) ;
if ( ! V_213 )
return - V_143 ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_12 [ V_39 -> V_47 ] . type == V_15 )
F_59 ( & V_213 -> V_12 [ V_39 -> V_45 ] ,
V_45 , V_12 [ V_39 -> V_47 ] . V_17 ,
V_59 ) ;
else if ( V_45 -> type == V_15 )
F_60 ( & V_213 -> V_12 [ V_39 -> V_47 ] ,
& V_12 [ V_39 -> V_47 ] , V_45 -> V_17 ,
V_59 ) ;
} else {
F_59 ( & V_213 -> V_12 [ V_39 -> V_45 ] ,
V_45 , V_39 -> V_17 , V_59 ) ;
}
if ( F_8 ( V_39 -> V_41 ) == V_182 &&
V_39 -> V_17 == 0 && ( V_59 == V_207 || V_59 == V_208 ) &&
V_45 -> type == V_24 ) {
F_62 ( V_214 , V_39 -> V_45 ,
V_59 == V_207 ? V_23 : V_21 ) ;
F_62 ( V_213 , V_39 -> V_45 ,
V_59 == V_207 ? V_21 : V_23 ) ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 && V_59 == V_209 &&
V_45 -> type == V_18 &&
V_12 [ V_39 -> V_47 ] . type == V_94 ) {
F_57 ( V_214 , V_45 ) ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 && V_59 == V_211 &&
V_45 -> type == V_94 &&
V_12 [ V_39 -> V_47 ] . type == V_18 ) {
F_57 ( V_213 , & V_12 [ V_39 -> V_47 ] ) ;
} else if ( F_32 ( V_66 , V_39 -> V_45 ) ) {
F_5 ( L_89 , V_39 -> V_45 ) ;
return - V_87 ;
}
if ( V_101 )
F_4 ( V_214 ) ;
return 0 ;
}
static struct V_99 * F_64 ( struct V_38 * V_39 )
{
T_5 V_215 = ( ( T_5 ) ( T_2 ) V_39 [ 0 ] . V_17 ) | ( ( T_5 ) ( T_2 ) V_39 [ 1 ] . V_17 ) << 32 ;
return (struct V_99 * ) ( unsigned long ) V_215 ;
}
static int F_65 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
int V_77 ;
if ( F_11 ( V_39 -> V_41 ) != V_93 ) {
F_5 ( L_90 ) ;
return - V_85 ;
}
if ( V_39 -> V_19 != 0 ) {
F_5 ( L_91 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_88 ) ;
if ( V_77 )
return V_77 ;
if ( V_39 -> V_47 == 0 ) {
T_5 V_17 = ( ( T_5 ) ( V_39 + 1 ) -> V_17 << 32 ) | ( T_2 ) V_39 -> V_17 ;
V_12 [ V_39 -> V_45 ] . type = V_15 ;
V_12 [ V_39 -> V_45 ] . V_17 = V_17 ;
return 0 ;
}
F_19 ( V_39 -> V_47 != V_216 ) ;
V_12 [ V_39 -> V_45 ] . type = V_22 ;
V_12 [ V_39 -> V_45 ] . V_26 = F_64 ( V_39 ) ;
return 0 ;
}
static bool F_66 ( enum V_217 type )
{
switch ( type ) {
case V_218 :
case V_110 :
case V_111 :
return true ;
default:
return false ;
}
}
static int F_67 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
T_1 V_219 = F_10 ( V_39 -> V_41 ) ;
struct V_6 * V_7 ;
int V_10 , V_77 ;
if ( ! F_66 ( V_66 -> V_106 -> type ) ) {
F_5 ( L_92 ) ;
return - V_85 ;
}
if ( V_39 -> V_45 != V_177 || V_39 -> V_19 != 0 ||
F_11 ( V_39 -> V_41 ) == V_93 ||
( V_219 == V_55 && V_39 -> V_47 != V_177 ) ) {
F_5 ( L_93 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_220 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( V_12 [ V_220 ] . type != V_82 ) {
F_5 ( L_94 ) ;
return - V_85 ;
}
if ( V_219 == V_56 ) {
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
}
for ( V_10 = 0 ; V_10 < V_173 ; V_10 ++ ) {
V_7 = V_12 + V_174 [ V_10 ] ;
V_7 -> type = V_13 ;
V_7 -> V_17 = 0 ;
}
V_12 [ V_177 ] . type = V_21 ;
return 0 ;
}
static int F_68 ( int V_9 , int V_221 , int V_222 , struct V_65 * V_66 )
{
if ( V_222 == V_223 && V_224 [ V_9 ] >= ( V_225 | V_223 ) )
return 0 ;
if ( V_222 == V_226 && V_224 [ V_9 ] >= ( V_225 | V_226 ) )
return 0 ;
if ( V_221 < 0 || V_221 >= V_66 -> V_106 -> V_227 ) {
F_5 ( L_95 , V_9 , V_221 ) ;
return - V_85 ;
}
if ( V_222 == V_226 )
V_66 -> V_228 [ V_221 ] = V_229 ;
if ( V_224 [ V_221 ] == 0 ) {
V_224 [ V_9 ] = V_225 | V_222 ;
V_224 [ V_221 ] = V_225 ;
if ( V_230 >= V_66 -> V_106 -> V_227 )
return - V_231 ;
V_232 [ V_230 ++ ] = V_221 ;
return 1 ;
} else if ( ( V_224 [ V_221 ] & 0xF0 ) == V_225 ) {
F_5 ( L_96 , V_9 , V_221 ) ;
return - V_85 ;
} else if ( V_224 [ V_221 ] == V_233 ) {
V_224 [ V_9 ] = V_225 | V_222 ;
} else {
F_5 ( L_97 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_69 ( struct V_65 * V_66 )
{
struct V_38 * V_234 = V_66 -> V_106 -> V_235 ;
int V_236 = V_66 -> V_106 -> V_227 ;
int V_237 = 0 ;
int V_10 , V_9 ;
V_224 = F_70 ( V_236 , sizeof( int ) , V_76 ) ;
if ( ! V_224 )
return - V_238 ;
V_232 = F_70 ( V_236 , sizeof( int ) , V_76 ) ;
if ( ! V_232 ) {
F_13 ( V_224 ) ;
return - V_238 ;
}
V_224 [ 0 ] = V_225 ;
V_232 [ 0 ] = 0 ;
V_230 = 1 ;
V_239:
if ( V_230 == 0 )
goto V_240;
V_9 = V_232 [ V_230 - 1 ] ;
if ( F_7 ( V_234 [ V_9 ] . V_41 ) == V_58 ) {
T_1 V_59 = F_9 ( V_234 [ V_9 ] . V_41 ) ;
if ( V_59 == V_62 ) {
goto V_241;
} else if ( V_59 == V_60 ) {
V_237 = F_68 ( V_9 , V_9 + 1 , V_223 , V_66 ) ;
if ( V_237 == 1 )
goto V_239;
else if ( V_237 < 0 )
goto V_242;
if ( V_9 + 1 < V_236 )
V_66 -> V_228 [ V_9 + 1 ] = V_229 ;
} else if ( V_59 == V_61 ) {
if ( F_8 ( V_234 [ V_9 ] . V_41 ) != V_182 ) {
V_237 = - V_85 ;
goto V_242;
}
V_237 = F_68 ( V_9 , V_9 + V_234 [ V_9 ] . V_19 + 1 ,
V_223 , V_66 ) ;
if ( V_237 == 1 )
goto V_239;
else if ( V_237 < 0 )
goto V_242;
if ( V_9 + 1 < V_236 )
V_66 -> V_228 [ V_9 + 1 ] = V_229 ;
} else {
V_237 = F_68 ( V_9 , V_9 + 1 , V_223 , V_66 ) ;
if ( V_237 == 1 )
goto V_239;
else if ( V_237 < 0 )
goto V_242;
V_237 = F_68 ( V_9 , V_9 + V_234 [ V_9 ] . V_19 + 1 , V_226 , V_66 ) ;
if ( V_237 == 1 )
goto V_239;
else if ( V_237 < 0 )
goto V_242;
}
} else {
V_237 = F_68 ( V_9 , V_9 + 1 , V_223 , V_66 ) ;
if ( V_237 == 1 )
goto V_239;
else if ( V_237 < 0 )
goto V_242;
}
V_241:
V_224 [ V_9 ] = V_233 ;
if ( V_230 -- <= 0 ) {
F_5 ( L_98 ) ;
V_237 = - V_143 ;
goto V_242;
}
goto V_239;
V_240:
for ( V_10 = 0 ; V_10 < V_236 ; V_10 ++ ) {
if ( V_224 [ V_10 ] != V_233 ) {
F_5 ( L_99 , V_10 ) ;
V_237 = - V_85 ;
goto V_242;
}
}
V_237 = 0 ;
V_242:
F_13 ( V_224 ) ;
F_13 ( V_232 ) ;
return V_237 ;
}
static bool F_71 ( struct V_6 * V_243 ,
struct V_6 * V_244 )
{
if ( V_243 -> V_1 != V_244 -> V_1 )
return false ;
if ( V_243 -> V_19 == V_244 -> V_19 && V_243 -> V_20 < V_244 -> V_20 )
return true ;
if ( V_243 -> V_19 <= V_244 -> V_19 &&
V_243 -> V_19 >= V_243 -> V_20 && V_244 -> V_19 >= V_244 -> V_20 )
return true ;
return false ;
}
static bool F_72 ( struct V_65 * V_66 ,
struct V_4 * V_243 ,
struct V_4 * V_244 )
{
bool V_245 = V_66 -> V_102 ;
struct V_6 * V_246 , * V_247 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_246 = & V_243 -> V_12 [ V_10 ] ;
V_247 = & V_244 -> V_12 [ V_10 ] ;
if ( memcmp ( V_246 , V_247 , sizeof( * V_246 ) ) == 0 )
continue;
if ( ! V_245 &&
memcmp ( V_246 , V_247 , F_73 ( struct V_6 , V_1 ) ) == 0 )
continue;
if ( V_246 -> type == V_13 ||
( ! V_245 && V_246 -> type == V_21 &&
V_247 -> type != V_13 ) )
continue;
if ( V_246 -> type == V_18 && V_247 -> type == V_18 &&
F_71 ( V_246 , V_247 ) )
continue;
return false ;
}
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
if ( V_243 -> V_35 [ V_10 ] == V_248 )
continue;
if ( V_243 -> V_35 [ V_10 ] != V_244 -> V_35 [ V_10 ] )
return false ;
if ( V_10 % V_34 )
continue;
if ( memcmp ( & V_243 -> V_37 [ V_10 / V_34 ] ,
& V_244 -> V_37 [ V_10 / V_34 ] ,
sizeof( V_243 -> V_37 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_74 ( struct V_65 * V_66 , int V_70 )
{
struct V_249 * V_250 ;
struct V_249 * V_251 ;
V_251 = V_66 -> V_228 [ V_70 ] ;
if ( ! V_251 )
return 0 ;
while ( V_251 != V_229 ) {
if ( F_72 ( V_66 , & V_251 -> V_5 , & V_66 -> V_72 ) )
return 1 ;
V_251 = V_251 -> V_74 ;
}
V_250 = F_15 ( sizeof( struct V_249 ) , V_252 ) ;
if ( ! V_250 )
return - V_238 ;
memcpy ( & V_250 -> V_5 , & V_66 -> V_72 , sizeof( V_66 -> V_72 ) ) ;
V_250 -> V_74 = V_66 -> V_228 [ V_70 ] ;
V_66 -> V_228 [ V_70 ] = V_250 ;
return 0 ;
}
static int F_75 ( struct V_65 * V_66 ,
int V_70 , int V_67 )
{
if ( ! V_66 -> V_117 || ! V_66 -> V_117 -> V_253 )
return 0 ;
return V_66 -> V_117 -> V_253 ( V_66 , V_70 , V_67 ) ;
}
static int F_76 ( struct V_65 * V_66 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_38 * V_234 = V_66 -> V_106 -> V_235 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_236 = V_66 -> V_106 -> V_227 ;
int V_70 , V_67 = 0 ;
int V_254 = 0 ;
bool V_255 = false ;
F_16 ( V_12 ) ;
V_70 = 0 ;
V_66 -> V_102 = false ;
for (; ; ) {
struct V_38 * V_39 ;
T_1 V_40 ;
int V_77 ;
if ( V_70 >= V_236 ) {
F_5 ( L_100 ,
V_70 , V_236 ) ;
return - V_143 ;
}
V_39 = & V_234 [ V_70 ] ;
V_40 = F_7 ( V_39 -> V_41 ) ;
if ( ++ V_254 > V_256 ) {
F_5 ( L_101 ,
V_254 ) ;
return - V_231 ;
}
V_77 = F_74 ( V_66 , V_70 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( V_77 == 1 ) {
if ( V_101 ) {
if ( V_255 )
F_5 ( L_102 ,
V_67 , V_70 ) ;
else
F_5 ( L_103 , V_70 ) ;
}
goto V_257;
}
if ( V_101 && V_255 ) {
F_5 ( L_104 , V_67 , V_70 ) ;
F_4 ( & V_66 -> V_72 ) ;
V_255 = false ;
}
if ( V_101 ) {
F_5 ( L_105 , V_70 ) ;
F_6 ( V_39 ) ;
}
V_77 = F_75 ( V_66 , V_70 , V_67 ) ;
if ( V_77 )
return V_77 ;
if ( V_40 == V_42 || V_40 == V_43 ) {
V_77 = F_56 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_40 == V_53 ) {
enum V_8 * V_258 , V_259 ;
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_203 ) ;
if ( V_77 )
return V_77 ;
V_259 = V_12 [ V_39 -> V_47 ] . type ;
V_77 = F_37 ( V_66 , V_39 -> V_47 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_125 ,
V_39 -> V_45 ) ;
if ( V_77 )
return V_77 ;
if ( F_11 ( V_39 -> V_41 ) != V_90 &&
F_11 ( V_39 -> V_41 ) != V_93 ) {
V_70 ++ ;
continue;
}
V_258 = & V_66 -> V_260 [ V_70 ] . V_261 ;
if ( * V_258 == V_13 ) {
* V_258 = V_259 ;
} else if ( V_259 != * V_258 &&
( V_259 == V_82 ||
* V_258 == V_82 ) ) {
F_5 ( L_106 ) ;
return - V_85 ;
}
} else if ( V_40 == V_48 ) {
enum V_8 * V_262 , V_263 ;
if ( F_10 ( V_39 -> V_41 ) == V_51 ) {
V_77 = F_38 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
V_70 ++ ;
continue;
}
V_77 = F_22 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_263 = V_12 [ V_39 -> V_45 ] . type ;
V_77 = F_37 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_109 ,
V_39 -> V_47 ) ;
if ( V_77 )
return V_77 ;
V_262 = & V_66 -> V_260 [ V_70 ] . V_261 ;
if ( * V_262 == V_13 ) {
* V_262 = V_263 ;
} else if ( V_263 != * V_262 &&
( V_263 == V_82 ||
* V_262 == V_82 ) ) {
F_5 ( L_106 ) ;
return - V_85 ;
}
} else if ( V_40 == V_52 ) {
if ( F_10 ( V_39 -> V_41 ) != V_49 ||
V_39 -> V_47 != V_177 ) {
F_5 ( L_107 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_37 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_109 ,
- 1 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_40 == V_58 ) {
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
if ( V_59 == V_60 ) {
if ( F_8 ( V_39 -> V_41 ) != V_182 ||
V_39 -> V_19 != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_45 != V_177 ) {
F_5 ( L_108 ) ;
return - V_85 ;
}
V_77 = F_45 ( V_66 , V_39 -> V_17 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_59 == V_61 ) {
if ( F_8 ( V_39 -> V_41 ) != V_182 ||
V_39 -> V_17 != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_45 != V_177 ) {
F_5 ( L_109 ) ;
return - V_85 ;
}
V_70 += V_39 -> V_19 + 1 ;
continue;
} else if ( V_59 == V_62 ) {
if ( F_8 ( V_39 -> V_41 ) != V_182 ||
V_39 -> V_17 != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_45 != V_177 ) {
F_5 ( L_110 ) ;
return - V_85 ;
}
V_77 = F_22 ( V_12 , V_177 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( F_32 ( V_66 , V_177 ) ) {
F_5 ( L_111 ) ;
return - V_87 ;
}
V_257:
V_70 = F_12 ( V_66 , & V_67 ) ;
if ( V_70 < 0 ) {
break;
} else {
V_255 = true ;
continue;
}
} else {
V_77 = F_63 ( V_66 , V_39 , & V_70 ) ;
if ( V_77 )
return V_77 ;
}
} else if ( V_40 == V_54 ) {
T_1 V_219 = F_10 ( V_39 -> V_41 ) ;
if ( V_219 == V_55 || V_219 == V_56 ) {
V_77 = F_67 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_219 == V_57 ) {
V_77 = F_65 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
V_70 ++ ;
} else {
F_5 ( L_112 ) ;
return - V_85 ;
}
F_20 ( V_12 , V_39 -> V_45 ) ;
} else {
F_5 ( L_113 , V_40 ) ;
return - V_85 ;
}
V_70 ++ ;
}
F_5 ( L_114 , V_254 ) ;
return 0 ;
}
static int F_77 ( struct V_99 * V_100 ,
struct V_264 * V_106 )
{
if ( V_106 -> type == V_265 &&
( V_100 -> V_145 == V_266 ||
V_100 -> V_145 == V_267 ) &&
( V_100 -> V_268 & V_269 ) ) {
F_5 ( L_115 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_78 ( struct V_65 * V_66 )
{
struct V_38 * V_39 = V_66 -> V_106 -> V_235 ;
int V_236 = V_66 -> V_106 -> V_227 ;
int V_10 , V_270 , V_77 ;
V_77 = F_79 ( V_66 -> V_106 ) ;
if ( V_77 )
return V_77 ;
for ( V_10 = 0 ; V_10 < V_236 ; V_10 ++ , V_39 ++ ) {
if ( F_7 ( V_39 -> V_41 ) == V_53 &&
( F_10 ( V_39 -> V_41 ) != V_49 || V_39 -> V_17 != 0 ) ) {
F_5 ( L_116 ) ;
return - V_85 ;
}
if ( F_7 ( V_39 -> V_41 ) == V_48 &&
( ( F_10 ( V_39 -> V_41 ) != V_49 &&
F_10 ( V_39 -> V_41 ) != V_51 ) || V_39 -> V_17 != 0 ) ) {
F_5 ( L_117 ) ;
return - V_85 ;
}
if ( V_39 [ 0 ] . V_41 == ( V_54 | V_57 | V_93 ) ) {
struct V_99 * V_100 ;
struct V_271 V_272 ;
if ( V_10 == V_236 - 1 || V_39 [ 1 ] . V_41 != 0 ||
V_39 [ 1 ] . V_45 != 0 || V_39 [ 1 ] . V_47 != 0 ||
V_39 [ 1 ] . V_19 != 0 ) {
F_5 ( L_118 ) ;
return - V_85 ;
}
if ( V_39 -> V_47 == 0 )
goto V_273;
if ( V_39 -> V_47 != V_216 ) {
F_5 ( L_119 ) ;
return - V_85 ;
}
V_272 = F_80 ( V_39 -> V_17 ) ;
V_100 = F_81 ( V_272 ) ;
if ( F_82 ( V_100 ) ) {
F_5 ( L_120 ,
V_39 -> V_17 ) ;
return F_83 ( V_100 ) ;
}
V_77 = F_77 ( V_100 , V_66 -> V_106 ) ;
if ( V_77 ) {
F_84 ( V_272 ) ;
return V_77 ;
}
V_39 [ 0 ] . V_17 = ( T_2 ) ( unsigned long ) V_100 ;
V_39 [ 1 ] . V_17 = ( ( T_5 ) ( unsigned long ) V_100 ) >> 32 ;
for ( V_270 = 0 ; V_270 < V_66 -> V_274 ; V_270 ++ )
if ( V_66 -> V_275 [ V_270 ] == V_100 ) {
F_84 ( V_272 ) ;
goto V_273;
}
if ( V_66 -> V_274 >= V_276 ) {
F_84 ( V_272 ) ;
return - V_231 ;
}
V_100 = F_85 ( V_100 , false ) ;
if ( F_82 ( V_100 ) ) {
F_84 ( V_272 ) ;
return F_83 ( V_100 ) ;
}
V_66 -> V_275 [ V_66 -> V_274 ++ ] = V_100 ;
F_84 ( V_272 ) ;
V_273:
V_39 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_86 ( struct V_65 * V_66 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_66 -> V_274 ; V_10 ++ )
F_87 ( V_66 -> V_275 [ V_10 ] ) ;
}
static void F_88 ( struct V_65 * V_66 )
{
struct V_38 * V_39 = V_66 -> V_106 -> V_235 ;
int V_236 = V_66 -> V_106 -> V_227 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_236 ; V_10 ++ , V_39 ++ )
if ( V_39 -> V_41 == ( V_54 | V_57 | V_93 ) )
V_39 -> V_47 = 0 ;
}
static int F_89 ( struct V_65 * V_66 )
{
const struct V_277 * V_119 = V_66 -> V_106 -> V_118 -> V_119 ;
const int V_236 = V_66 -> V_106 -> V_227 ;
struct V_38 V_278 [ 16 ] , * V_39 ;
struct V_264 * V_279 ;
enum V_105 type ;
int V_10 , V_280 , V_281 = 0 ;
if ( V_119 -> V_282 ) {
V_280 = V_119 -> V_282 ( V_278 , V_66 -> V_115 ,
V_66 -> V_106 ) ;
if ( V_280 >= F_3 ( V_278 ) ) {
F_5 ( L_121 ) ;
return - V_85 ;
} else if ( V_280 ) {
V_279 = F_90 ( V_66 -> V_106 , 0 ,
V_278 , V_280 ) ;
if ( ! V_279 )
return - V_238 ;
V_66 -> V_106 = V_279 ;
V_281 += V_280 - 1 ;
}
}
if ( ! V_119 -> V_283 )
return 0 ;
V_39 = V_66 -> V_106 -> V_235 + V_281 ;
for ( V_10 = 0 ; V_10 < V_236 ; V_10 ++ , V_39 ++ ) {
if ( V_39 -> V_41 == ( V_53 | V_49 | V_92 ) ||
V_39 -> V_41 == ( V_53 | V_49 | V_91 ) ||
V_39 -> V_41 == ( V_53 | V_49 | V_90 ) ||
V_39 -> V_41 == ( V_53 | V_49 | V_93 ) )
type = V_125 ;
else if ( V_39 -> V_41 == ( V_48 | V_49 | V_92 ) ||
V_39 -> V_41 == ( V_48 | V_49 | V_91 ) ||
V_39 -> V_41 == ( V_48 | V_49 | V_90 ) ||
V_39 -> V_41 == ( V_48 | V_49 | V_93 ) )
type = V_109 ;
else
continue;
if ( V_66 -> V_260 [ V_10 ] . V_261 != V_82 )
continue;
V_280 = V_119 -> V_283 ( type , V_39 , V_278 , V_66 -> V_106 ) ;
if ( V_280 == 0 || V_280 >= F_3 ( V_278 ) ) {
F_5 ( L_121 ) ;
return - V_85 ;
}
V_279 = F_90 ( V_66 -> V_106 , V_10 + V_281 , V_278 ,
V_280 ) ;
if ( ! V_279 )
return - V_238 ;
V_281 += V_280 - 1 ;
V_66 -> V_106 = V_279 ;
V_39 = V_279 -> V_235 + V_10 + V_281 ;
}
return 0 ;
}
static void F_91 ( struct V_65 * V_66 )
{
struct V_249 * V_251 , * V_284 ;
int V_10 ;
if ( ! V_66 -> V_228 )
return;
for ( V_10 = 0 ; V_10 < V_66 -> V_106 -> V_227 ; V_10 ++ ) {
V_251 = V_66 -> V_228 [ V_10 ] ;
if ( V_251 )
while ( V_251 != V_229 ) {
V_284 = V_251 -> V_74 ;
F_13 ( V_251 ) ;
V_251 = V_284 ;
}
}
F_13 ( V_66 -> V_228 ) ;
}
int F_92 ( struct V_264 * * V_106 , union V_285 * V_286 )
{
char T_6 * V_287 = NULL ;
struct V_65 * V_66 ;
int V_237 = - V_85 ;
V_66 = F_93 ( sizeof( struct V_65 ) , V_76 ) ;
if ( ! V_66 )
return - V_238 ;
V_66 -> V_260 = F_94 ( sizeof( struct V_288 ) *
( * V_106 ) -> V_227 ) ;
V_237 = - V_238 ;
if ( ! V_66 -> V_260 )
goto V_289;
V_66 -> V_106 = * V_106 ;
F_95 ( & V_290 ) ;
if ( V_286 -> V_101 || V_286 -> V_291 || V_286 -> V_292 ) {
V_101 = V_286 -> V_101 ;
V_287 = ( char T_6 * ) ( unsigned long ) V_286 -> V_291 ;
V_292 = V_286 -> V_292 ;
V_293 = 0 ;
V_237 = - V_85 ;
if ( V_292 < 128 || V_292 > V_294 >> 8 ||
V_101 == 0 || V_287 == NULL )
goto V_295;
V_237 = - V_238 ;
V_291 = F_96 ( V_292 ) ;
if ( ! V_291 )
goto V_295;
} else {
V_101 = 0 ;
}
V_237 = F_78 ( V_66 ) ;
if ( V_237 < 0 )
goto V_296;
V_66 -> V_228 = F_70 ( V_66 -> V_106 -> V_227 ,
sizeof( struct V_249 * ) ,
V_252 ) ;
V_237 = - V_238 ;
if ( ! V_66 -> V_228 )
goto V_296;
V_237 = F_69 ( V_66 ) ;
if ( V_237 < 0 )
goto V_296;
V_66 -> V_122 = F_97 ( V_297 ) ;
V_237 = F_76 ( V_66 ) ;
V_296:
while ( F_12 ( V_66 , NULL ) >= 0 ) ;
F_91 ( V_66 ) ;
if ( V_237 == 0 )
V_237 = F_89 ( V_66 ) ;
if ( V_101 && V_293 >= V_292 - 1 ) {
F_19 ( V_293 >= V_292 ) ;
V_237 = - V_298 ;
}
if ( V_101 && F_98 ( V_287 , V_291 , V_293 + 1 ) != 0 ) {
V_237 = - V_143 ;
goto V_299;
}
if ( V_237 == 0 && V_66 -> V_274 ) {
V_66 -> V_106 -> V_118 -> V_275 = F_99 ( V_66 -> V_274 ,
sizeof( V_66 -> V_275 [ 0 ] ) ,
V_76 ) ;
if ( ! V_66 -> V_106 -> V_118 -> V_275 ) {
V_237 = - V_238 ;
goto V_299;
}
memcpy ( V_66 -> V_106 -> V_118 -> V_275 , V_66 -> V_275 ,
sizeof( V_66 -> V_275 [ 0 ] ) * V_66 -> V_274 ) ;
V_66 -> V_106 -> V_118 -> V_274 = V_66 -> V_274 ;
F_88 ( V_66 ) ;
}
V_299:
if ( V_101 )
F_100 ( V_291 ) ;
if ( ! V_66 -> V_106 -> V_118 -> V_275 )
F_86 ( V_66 ) ;
* V_106 = V_66 -> V_106 ;
V_295:
F_101 ( & V_290 ) ;
F_100 ( V_66 -> V_260 ) ;
V_289:
F_13 ( V_66 ) ;
return V_237 ;
}
int F_102 ( struct V_264 * V_106 , const struct V_300 * V_119 ,
void * V_301 )
{
struct V_65 * V_66 ;
int V_237 ;
V_66 = F_93 ( sizeof( struct V_65 ) , V_76 ) ;
if ( ! V_66 )
return - V_238 ;
V_66 -> V_260 = F_94 ( sizeof( struct V_288 ) *
V_106 -> V_227 ) ;
V_237 = - V_238 ;
if ( ! V_66 -> V_260 )
goto V_289;
V_66 -> V_106 = V_106 ;
V_66 -> V_117 = V_119 ;
V_66 -> V_302 = V_301 ;
F_95 ( & V_290 ) ;
V_101 = 0 ;
V_66 -> V_228 = F_70 ( V_66 -> V_106 -> V_227 ,
sizeof( struct V_249 * ) ,
V_76 ) ;
V_237 = - V_238 ;
if ( ! V_66 -> V_228 )
goto V_296;
V_237 = F_69 ( V_66 ) ;
if ( V_237 < 0 )
goto V_296;
V_66 -> V_122 = F_97 ( V_297 ) ;
V_237 = F_76 ( V_66 ) ;
V_296:
while ( F_12 ( V_66 , NULL ) >= 0 ) ;
F_91 ( V_66 ) ;
F_101 ( & V_290 ) ;
F_100 ( V_66 -> V_260 ) ;
V_289:
F_13 ( V_66 ) ;
return V_237 ;
}
