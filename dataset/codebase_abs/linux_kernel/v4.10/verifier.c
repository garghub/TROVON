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
static int F_21 ( struct V_6 * V_12 , T_2 V_83 ,
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
static int F_22 ( int V_89 )
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
static bool F_23 ( enum V_8 type )
{
switch ( type ) {
case V_23 :
case V_24 :
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
static int F_24 ( struct V_4 * V_5 , int V_19 ,
int V_95 , int V_96 )
{
int V_10 ;
if ( V_96 >= 0 &&
F_23 ( V_5 -> V_12 [ V_96 ] . type ) ) {
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
static int F_25 ( struct V_4 * V_5 , int V_19 , int V_95 ,
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
F_18 ( V_5 -> V_12 , V_96 ) ;
return 0 ;
}
}
static int F_26 ( struct V_65 * V_66 , T_2 V_83 , int V_19 ,
int V_95 )
{
struct V_99 * V_100 = V_66 -> V_72 . V_12 [ V_83 ] . V_26 ;
if ( V_19 < 0 || V_19 + V_95 > V_100 -> V_28 ) {
F_5 ( L_38 ,
V_100 -> V_28 , V_19 , V_95 ) ;
return - V_87 ;
}
return 0 ;
}
static bool F_27 ( struct V_65 * V_66 ,
const struct V_101 * V_102 ,
enum V_103 V_9 )
{
switch ( V_66 -> V_104 -> type ) {
case V_105 :
case V_106 :
if ( V_9 == V_107 )
return false ;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
if ( V_102 )
return V_102 -> V_112 ;
V_66 -> V_113 = true ;
return true ;
default:
return false ;
}
}
static int F_28 ( struct V_65 * V_66 , T_2 V_83 , int V_19 ,
int V_95 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_7 = & V_12 [ V_83 ] ;
V_19 += V_7 -> V_19 ;
if ( V_19 < 0 || V_95 <= 0 || V_19 + V_95 > V_7 -> V_20 ) {
F_5 ( L_39 ,
V_19 , V_95 , V_83 , V_7 -> V_1 , V_7 -> V_19 , V_7 -> V_20 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_29 ( struct V_65 * V_66 , int V_19 , int V_95 ,
enum V_103 V_9 , enum V_8 * V_114 )
{
if ( V_66 -> V_115 )
return 0 ;
if ( V_66 -> V_104 -> V_116 -> V_117 -> V_118 &&
V_66 -> V_104 -> V_116 -> V_117 -> V_118 ( V_19 , V_95 , V_9 , V_114 ) ) {
if ( V_66 -> V_104 -> V_116 -> V_119 < V_19 + V_95 )
V_66 -> V_104 -> V_116 -> V_119 = V_19 + V_95 ;
return 0 ;
}
F_5 ( L_40 , V_19 , V_95 ) ;
return - V_87 ;
}
static bool F_30 ( struct V_65 * V_66 , int V_83 )
{
if ( V_66 -> V_120 )
return false ;
switch ( V_66 -> V_72 . V_12 [ V_83 ] . type ) {
case V_21 :
case V_15 :
return false ;
default:
return true ;
}
}
static int F_31 ( struct V_65 * V_66 ,
struct V_6 * V_7 , int V_19 , int V_95 )
{
if ( V_7 -> type != V_18 && V_7 -> type != V_25 ) {
if ( V_19 % V_95 != 0 ) {
F_5 ( L_41 ,
V_19 , V_95 ) ;
return - V_87 ;
} else {
return 0 ;
}
}
if ( F_32 ( V_121 ) )
return 0 ;
if ( V_7 -> V_1 && V_95 != 1 ) {
F_5 ( L_42 ) ;
return - V_87 ;
}
if ( V_7 -> type == V_18 &&
( V_122 + V_7 -> V_19 + V_19 ) % V_95 != 0 ) {
F_5 ( L_43 ,
V_122 , V_7 -> V_19 , V_19 , V_95 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_33 ( struct V_65 * V_66 , T_2 V_83 , int V_19 ,
int V_89 , enum V_103 V_9 ,
int V_96 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_83 ] ;
int V_95 , V_77 = 0 ;
if ( V_7 -> type == V_16 )
V_19 += V_7 -> V_17 ;
V_95 = F_22 ( V_89 ) ;
if ( V_95 < 0 )
return V_95 ;
V_77 = F_31 ( V_66 , V_7 , V_19 , V_95 ) ;
if ( V_77 )
return V_77 ;
if ( V_7 -> type == V_23 ||
V_7 -> type == V_25 ) {
if ( V_9 == V_107 && V_96 >= 0 &&
F_30 ( V_66 , V_96 ) ) {
F_5 ( L_44 , V_96 ) ;
return - V_87 ;
}
if ( V_7 -> type == V_25 ) {
if ( V_123 )
F_4 ( V_5 ) ;
V_66 -> V_124 = true ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_45 ,
V_83 ) ;
return - V_87 ;
}
V_77 = F_26 ( V_66 , V_83 , V_7 -> V_29 + V_19 ,
V_95 ) ;
if ( V_77 ) {
F_5 ( L_46 ,
V_83 ) ;
return V_77 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_47 ,
V_83 ) ;
return - V_87 ;
}
V_19 += V_7 -> V_31 ;
}
V_77 = F_26 ( V_66 , V_83 , V_19 , V_95 ) ;
if ( ! V_77 && V_9 == V_125 && V_96 >= 0 )
F_18 ( V_5 -> V_12 , V_96 ) ;
} else if ( V_7 -> type == V_82 ) {
enum V_8 V_114 = V_21 ;
if ( V_9 == V_107 && V_96 >= 0 &&
F_30 ( V_66 , V_96 ) ) {
F_5 ( L_48 , V_96 ) ;
return - V_87 ;
}
V_77 = F_29 ( V_66 , V_19 , V_95 , V_9 , & V_114 ) ;
if ( ! V_77 && V_9 == V_125 && V_96 >= 0 ) {
F_18 ( V_5 -> V_12 , V_96 ) ;
V_5 -> V_12 [ V_96 ] . type = V_114 ;
}
} else if ( V_7 -> type == V_80 || V_7 -> type == V_16 ) {
if ( V_19 >= 0 || V_19 < - V_33 ) {
F_5 ( L_49 , V_19 , V_95 ) ;
return - V_87 ;
}
if ( V_9 == V_107 ) {
if ( ! V_66 -> V_120 &&
V_5 -> V_35 [ V_33 + V_19 ] == V_36 &&
V_95 != V_34 ) {
F_5 ( L_50 ) ;
return - V_87 ;
}
V_77 = F_24 ( V_5 , V_19 , V_95 , V_96 ) ;
} else {
V_77 = F_25 ( V_5 , V_19 , V_95 , V_96 ) ;
}
} else if ( V_5 -> V_12 [ V_83 ] . type == V_18 ) {
if ( V_9 == V_107 && ! F_27 ( V_66 , NULL , V_9 ) ) {
F_5 ( L_51 ) ;
return - V_87 ;
}
if ( V_9 == V_107 && V_96 >= 0 &&
F_30 ( V_66 , V_96 ) ) {
F_5 ( L_52 , V_96 ) ;
return - V_87 ;
}
V_77 = F_28 ( V_66 , V_83 , V_19 , V_95 ) ;
if ( ! V_77 && V_9 == V_125 && V_96 >= 0 )
F_18 ( V_5 -> V_12 , V_96 ) ;
} else {
F_5 ( L_53 ,
V_83 , V_14 [ V_7 -> type ] ) ;
return - V_87 ;
}
if ( ! V_77 && V_95 <= 2 && V_96 >= 0 && V_66 -> V_120 &&
V_5 -> V_12 [ V_96 ] . type == V_21 ) {
V_5 -> V_12 [ V_96 ] . V_17 = 64 - V_95 * 8 ;
}
return V_77 ;
}
static int F_34 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
int V_77 ;
if ( ( F_11 ( V_39 -> V_41 ) != V_90 && F_11 ( V_39 -> V_41 ) != V_93 ) ||
V_39 -> V_17 != 0 ) {
F_5 ( L_54 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_33 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_125 , - 1 ) ;
if ( V_77 )
return V_77 ;
return F_33 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_107 , - 1 ) ;
}
static int F_35 ( struct V_65 * V_66 , int V_83 ,
int V_126 , bool V_127 ,
struct V_101 * V_102 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_19 , V_10 ;
if ( V_12 [ V_83 ] . type != V_16 ) {
if ( V_127 && V_126 == 0 &&
V_12 [ V_83 ] . type == V_15 &&
V_12 [ V_83 ] . V_17 == 0 )
return 0 ;
F_5 ( L_55 , V_83 ,
V_14 [ V_12 [ V_83 ] . type ] ,
V_14 [ V_16 ] ) ;
return - V_87 ;
}
V_19 = V_12 [ V_83 ] . V_17 ;
if ( V_19 >= 0 || V_19 < - V_33 || V_19 + V_126 > 0 ||
V_126 <= 0 ) {
F_5 ( L_56 ,
V_83 , V_19 , V_126 ) ;
return - V_87 ;
}
if ( V_102 && V_102 -> V_128 ) {
V_102 -> V_126 = V_126 ;
V_102 -> V_83 = V_83 ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_126 ; V_10 ++ ) {
if ( V_5 -> V_35 [ V_33 + V_19 + V_10 ] != V_97 ) {
F_5 ( L_57 ,
V_19 , V_10 , V_126 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int F_36 ( struct V_65 * V_66 , T_2 V_83 ,
enum V_129 V_130 ,
struct V_101 * V_102 )
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
if ( F_30 ( V_66 , V_83 ) ) {
F_5 ( L_58 , V_83 ) ;
return - V_87 ;
}
return 0 ;
}
if ( type == V_18 &&
! F_27 ( V_66 , V_102 , V_125 ) ) {
F_5 ( L_59 ) ;
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
if ( type != V_131 )
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
else if ( type != V_18 && type != V_131 )
goto V_136;
V_102 -> V_128 = V_130 == V_142 ;
} else {
F_5 ( L_60 , V_130 ) ;
return - V_143 ;
}
if ( V_130 == V_139 ) {
V_102 -> V_26 = V_7 -> V_26 ;
} else if ( V_130 == V_134 ) {
if ( ! V_102 -> V_26 ) {
F_5 ( L_61 ) ;
return - V_87 ;
}
if ( type == V_18 )
V_77 = F_28 ( V_66 , V_83 , 0 ,
V_102 -> V_26 -> V_27 ) ;
else
V_77 = F_35 ( V_66 , V_83 ,
V_102 -> V_26 -> V_27 ,
false , NULL ) ;
} else if ( V_130 == V_135 ) {
if ( ! V_102 -> V_26 ) {
F_5 ( L_62 ) ;
return - V_87 ;
}
if ( type == V_18 )
V_77 = F_28 ( V_66 , V_83 , 0 ,
V_102 -> V_26 -> V_28 ) ;
else
V_77 = F_35 ( V_66 , V_83 ,
V_102 -> V_26 -> V_28 ,
false , NULL ) ;
} else if ( V_130 == V_137 ||
V_130 == V_138 ) {
bool V_127 = ( V_130 == V_138 ) ;
if ( V_83 == 0 ) {
F_5 ( L_63 ) ;
return - V_87 ;
}
if ( V_12 [ V_83 - 1 ] . type == V_18 )
V_77 = F_28 ( V_66 , V_83 - 1 , 0 , V_7 -> V_17 ) ;
else
V_77 = F_35 ( V_66 , V_83 - 1 , V_7 -> V_17 ,
V_127 , V_102 ) ;
}
return V_77 ;
V_136:
F_5 ( L_55 , V_83 ,
V_14 [ type ] , V_14 [ V_131 ] ) ;
return - V_87 ;
}
static int F_37 ( struct V_99 * V_100 , int V_144 )
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
F_5 ( L_64 ,
V_100 -> V_145 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
static int F_38 ( const struct V_156 * V_157 )
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
static void F_39 ( struct V_65 * V_66 )
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
static int F_40 ( struct V_65 * V_66 , int V_144 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
const struct V_156 * V_157 = NULL ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_6 * V_7 ;
struct V_101 V_102 ;
bool V_164 ;
int V_10 , V_77 ;
if ( V_144 < 0 || V_144 >= V_3 ) {
F_5 ( L_65 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
if ( V_66 -> V_104 -> V_116 -> V_117 -> V_165 )
V_157 = V_66 -> V_104 -> V_116 -> V_117 -> V_165 ( V_144 ) ;
if ( ! V_157 ) {
F_5 ( L_66 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
if ( ! V_66 -> V_104 -> V_166 && V_157 -> V_167 ) {
F_5 ( L_67 ) ;
return - V_85 ;
}
V_164 = F_41 ( V_157 -> V_168 ) ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_112 = V_157 -> V_112 ;
V_77 = F_38 ( V_157 ) ;
if ( V_77 ) {
F_5 ( L_68 ,
F_1 ( V_144 ) , V_144 ) ;
return V_77 ;
}
V_77 = F_36 ( V_66 , V_81 , V_157 -> V_159 , & V_102 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_36 ( V_66 , V_169 , V_157 -> V_160 , & V_102 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_36 ( V_66 , V_170 , V_157 -> V_161 , & V_102 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_36 ( V_66 , V_171 , V_157 -> V_162 , & V_102 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_36 ( V_66 , V_172 , V_157 -> V_163 , & V_102 ) ;
if ( V_77 )
return V_77 ;
for ( V_10 = 0 ; V_10 < V_102 . V_126 ; V_10 ++ ) {
V_77 = F_33 ( V_66 , V_102 . V_83 , V_10 , V_92 , V_107 , - 1 ) ;
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
if ( V_102 . V_26 == NULL ) {
F_5 ( L_69 ) ;
return - V_85 ;
}
V_12 [ V_177 ] . V_26 = V_102 . V_26 ;
V_12 [ V_177 ] . V_1 = ++ V_66 -> V_180 ;
} else {
F_5 ( L_70 ,
V_157 -> V_175 , F_1 ( V_144 ) , V_144 ) ;
return - V_85 ;
}
V_77 = F_37 ( V_102 . V_26 , V_144 ) ;
if ( V_77 )
return V_77 ;
if ( V_164 )
F_39 ( V_66 ) ;
return 0 ;
}
static int F_42 ( struct V_65 * V_66 ,
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
if ( V_17 <= 0 ) {
F_5 ( L_71 ) ;
return - V_87 ;
}
if ( V_17 >= V_184 ||
V_17 + V_45 -> V_19 >= V_184 ) {
F_5 ( L_72 ,
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
F_5 ( L_73 ,
V_14 [ V_47 -> type ] ) ;
return - V_87 ;
}
if ( V_47 -> V_17 < 48 ) {
F_5 ( L_74 ,
V_47 -> V_17 ) ;
return - V_87 ;
}
V_45 -> V_1 = ++ V_66 -> V_180 ;
V_45 -> V_19 = 0 ;
V_45 -> V_20 = 0 ;
}
return 0 ;
}
static int F_43 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_45 = & V_12 [ V_39 -> V_45 ] ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
T_4 V_185 ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
struct V_6 * V_47 = & V_12 [ V_39 -> V_47 ] ;
if ( V_47 -> type == V_21 && V_47 -> V_17 > 0 &&
V_45 -> V_17 && V_59 == V_186 ) {
V_45 -> V_17 = F_44 ( V_45 -> V_17 , V_47 -> V_17 ) ;
V_45 -> V_17 -- ;
return 0 ;
}
if ( V_47 -> type == V_15 && V_47 -> V_17 > 0 &&
V_45 -> V_17 && V_59 == V_186 ) {
V_185 = F_45 ( ( long long ) V_47 -> V_17 ) ;
V_45 -> V_17 = F_44 ( V_45 -> V_17 , 63 - V_185 ) ;
V_45 -> V_17 -- ;
return 0 ;
}
V_45 -> V_17 = 0 ;
return 0 ;
}
V_185 = F_45 ( ( long long ) V_39 -> V_17 ) ;
if ( V_45 -> V_17 && V_59 == V_187 ) {
V_45 -> V_17 -= V_39 -> V_17 ;
} else if ( V_45 -> V_17 && V_59 == V_188 ) {
V_45 -> V_17 -= V_185 + 1 ;
} else if ( V_59 == V_189 ) {
V_45 -> V_17 = 63 - V_185 ;
} else if ( V_45 -> V_17 && V_59 == V_186 ) {
V_45 -> V_17 = F_44 ( V_45 -> V_17 , 63 - V_185 ) ;
V_45 -> V_17 -- ;
} else if ( V_59 == V_190 ) {
V_45 -> V_17 += V_39 -> V_17 ;
if ( F_46 ( V_45 -> V_17 > 64 ) )
V_45 -> V_17 = 64 ;
} else {
V_45 -> V_17 = 0 ;
}
if ( V_45 -> V_17 < 0 ) {
V_45 -> V_17 = 0 ;
}
return 0 ;
}
static int F_47 ( struct V_65 * V_66 ,
struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
struct V_6 * V_45 = & V_12 [ V_39 -> V_45 ] ;
struct V_6 * V_47 = & V_12 [ V_39 -> V_47 ] ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
if ( V_59 == V_186 && F_8 ( V_39 -> V_41 ) == V_182 )
V_45 -> V_17 += V_39 -> V_17 ;
else if ( V_59 == V_186 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 )
V_45 -> V_17 += V_47 -> V_17 ;
else if ( V_59 == V_191 && F_8 ( V_39 -> V_41 ) == V_182 )
V_45 -> V_17 |= V_39 -> V_17 ;
else if ( V_59 == V_191 && F_8 ( V_39 -> V_41 ) == V_44 &&
V_47 -> type == V_15 )
V_45 -> V_17 |= V_47 -> V_17 ;
else
F_18 ( V_12 , V_39 -> V_45 ) ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 )
{
if ( V_7 -> V_31 > V_32 )
V_7 -> V_31 = V_32 ;
if ( V_7 -> V_29 < V_30 ||
V_7 -> V_29 > V_32 )
V_7 -> V_29 = V_30 ;
}
static void F_49 ( struct V_65 * V_66 ,
struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 , * V_45 ;
T_4 V_192 = V_30 ;
T_5 V_193 = V_32 ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
V_45 = & V_12 [ V_39 -> V_45 ] ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
F_48 ( & V_12 [ V_39 -> V_47 ] ) ;
V_192 = V_12 [ V_39 -> V_47 ] . V_29 ;
V_193 = V_12 [ V_39 -> V_47 ] . V_31 ;
if ( V_12 [ V_39 -> V_47 ] . type != V_15 &&
V_12 [ V_39 -> V_47 ] . type != V_21 ) {
V_192 = V_30 ;
V_193 = V_32 ;
}
} else if ( V_39 -> V_17 < V_32 &&
( T_4 ) V_39 -> V_17 > V_30 ) {
V_192 = V_193 = V_39 -> V_17 ;
}
if ( V_192 == V_30 &&
V_193 == V_32 ) {
F_20 ( V_12 , V_39 -> V_45 ) ;
return;
}
if ( V_192 == V_30 )
V_45 -> V_29 = V_30 ;
if ( V_193 == V_32 )
V_45 -> V_31 = V_32 ;
switch ( V_59 ) {
case V_186 :
if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 += V_192 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 += V_193 ;
break;
case V_194 :
if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 -= V_192 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 -= V_193 ;
break;
case V_188 :
if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 *= V_192 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 *= V_193 ;
break;
case V_189 :
if ( V_192 < 0 )
V_45 -> V_29 = V_30 ;
else
V_45 -> V_29 = 0 ;
V_45 -> V_31 = V_193 ;
break;
case V_187 :
if ( V_192 > F_50 ( V_32 ) )
V_45 -> V_29 = V_30 ;
else if ( V_45 -> V_29 != V_30 )
V_45 -> V_29 <<= V_192 ;
if ( V_193 > F_50 ( V_32 ) )
V_45 -> V_31 = V_32 ;
else if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 <<= V_193 ;
break;
case V_190 :
if ( V_192 < 0 || V_45 -> V_29 < 0 )
V_45 -> V_29 = V_30 ;
else
V_45 -> V_29 =
( T_5 ) ( V_45 -> V_29 ) >> V_192 ;
if ( V_45 -> V_31 != V_32 )
V_45 -> V_31 >>= V_193 ;
break;
default:
F_20 ( V_12 , V_39 -> V_45 ) ;
break;
}
F_48 ( V_45 ) ;
}
static int F_51 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 , * V_45 ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
int V_77 ;
if ( V_59 == V_195 || V_59 == V_196 ) {
if ( V_59 == V_196 ) {
if ( F_8 ( V_39 -> V_41 ) != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_19 != 0 || V_39 -> V_17 != 0 ) {
F_5 ( L_75 ) ;
return - V_85 ;
}
} else {
if ( V_39 -> V_47 != V_177 || V_39 -> V_19 != 0 ||
( V_39 -> V_17 != 16 && V_39 -> V_17 != 32 && V_39 -> V_17 != 64 ) ) {
F_5 ( L_76 ) ;
return - V_85 ;
}
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( F_30 ( V_66 , V_39 -> V_45 ) ) {
F_5 ( L_77 ,
V_39 -> V_45 ) ;
return - V_87 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_88 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_59 == V_197 ) {
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_39 -> V_17 != 0 || V_39 -> V_19 != 0 ) {
F_5 ( L_78 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
} else {
if ( V_39 -> V_47 != V_177 || V_39 -> V_19 != 0 ) {
F_5 ( L_78 ) ;
return - V_85 ;
}
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_88 ) ;
if ( V_77 )
return V_77 ;
F_20 ( V_12 , V_39 -> V_45 ) ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( F_7 ( V_39 -> V_41 ) == V_43 ) {
V_12 [ V_39 -> V_45 ] = V_12 [ V_39 -> V_47 ] ;
} else {
if ( F_30 ( V_66 , V_39 -> V_47 ) ) {
F_5 ( L_79 ,
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
} else if ( V_59 > V_195 ) {
F_5 ( L_80 , V_59 ) ;
return - V_85 ;
} else {
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_39 -> V_17 != 0 || V_39 -> V_19 != 0 ) {
F_5 ( L_81 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
} else {
if ( V_39 -> V_47 != V_177 || V_39 -> V_19 != 0 ) {
F_5 ( L_81 ) ;
return - V_85 ;
}
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( ( V_59 == V_198 || V_59 == V_199 ) &&
F_8 ( V_39 -> V_41 ) == V_182 && V_39 -> V_17 == 0 ) {
F_5 ( L_82 ) ;
return - V_85 ;
}
if ( ( V_59 == V_187 || V_59 == V_190 ||
V_59 == V_200 ) && F_8 ( V_39 -> V_41 ) == V_182 ) {
int V_95 = F_7 ( V_39 -> V_41 ) == V_43 ? 64 : 32 ;
if ( V_39 -> V_17 < 0 || V_39 -> V_17 >= V_95 ) {
F_5 ( L_83 , V_39 -> V_17 ) ;
return - V_85 ;
}
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_201 ) ;
if ( V_77 )
return V_77 ;
V_45 = & V_12 [ V_39 -> V_45 ] ;
F_49 ( V_66 , V_39 ) ;
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
return F_42 ( V_66 , V_39 ) ;
} else if ( F_7 ( V_39 -> V_41 ) == V_43 &&
V_45 -> type == V_21 &&
V_66 -> V_120 ) {
return F_43 ( V_66 , V_39 ) ;
} else if ( F_7 ( V_39 -> V_41 ) == V_43 &&
V_45 -> type == V_15 &&
V_66 -> V_120 ) {
return F_47 ( V_66 , V_39 ) ;
} else if ( F_30 ( V_66 , V_39 -> V_45 ) ) {
F_5 ( L_77 ,
V_39 -> V_45 ) ;
return - V_87 ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 &&
F_30 ( V_66 , V_39 -> V_47 ) ) {
F_5 ( L_77 ,
V_39 -> V_47 ) ;
return - V_87 ;
}
if ( V_66 -> V_120 &&
( V_45 -> type == V_23 ||
V_45 -> type == V_25 ) )
V_45 -> type = V_25 ;
else
F_18 ( V_12 , V_39 -> V_45 ) ;
}
return 0 ;
}
static void F_52 ( struct V_4 * V_5 ,
struct V_6 * V_45 )
{
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 && V_12 [ V_10 ] . V_1 == V_45 -> V_1 )
V_12 [ V_10 ] . V_20 = V_45 -> V_19 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 += V_34 ) {
if ( V_5 -> V_35 [ V_10 ] != V_36 )
continue;
V_7 = & V_5 -> V_37 [ V_10 / V_34 ] ;
if ( V_7 -> type == V_18 && V_7 -> V_1 == V_45 -> V_1 )
V_7 -> V_20 = V_45 -> V_19 ;
}
}
static void F_53 ( struct V_6 * V_202 ,
struct V_6 * V_203 , T_5 V_204 ,
T_1 V_59 )
{
switch ( V_59 ) {
case V_205 :
V_202 -> V_31 = V_202 -> V_29 = V_204 ;
break;
case V_206 :
V_203 -> V_31 = V_203 -> V_29 = V_204 ;
break;
case V_207 :
V_203 -> V_29 = 0 ;
case V_208 :
V_203 -> V_31 = V_204 ;
V_202 -> V_29 = V_204 + 1 ;
break;
case V_209 :
V_203 -> V_29 = 0 ;
case V_210 :
V_203 -> V_31 = V_204 - 1 ;
V_202 -> V_29 = V_204 ;
break;
default:
break;
}
F_48 ( V_203 ) ;
F_48 ( V_202 ) ;
}
static void F_54 ( struct V_6 * V_202 ,
struct V_6 * V_203 , T_5 V_204 ,
T_1 V_59 )
{
switch ( V_59 ) {
case V_205 :
V_202 -> V_31 = V_202 -> V_29 = V_204 ;
break;
case V_206 :
V_203 -> V_31 = V_203 -> V_29 = V_204 ;
break;
case V_207 :
V_202 -> V_29 = 0 ;
case V_208 :
V_203 -> V_29 = V_204 ;
V_202 -> V_31 = V_204 - 1 ;
break;
case V_209 :
V_202 -> V_29 = 0 ;
case V_210 :
V_203 -> V_29 = V_204 + 1 ;
V_202 -> V_31 = V_204 ;
break;
default:
break;
}
F_48 ( V_203 ) ;
F_48 ( V_202 ) ;
}
static void F_55 ( struct V_6 * V_12 , T_2 V_83 , T_2 V_1 ,
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
static void F_56 ( struct V_4 * V_5 , T_2 V_83 ,
enum V_8 type )
{
struct V_6 * V_12 = V_5 -> V_12 ;
T_2 V_1 = V_12 [ V_83 ] . V_1 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_55 ( V_12 , V_10 , V_1 , type ) ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 += V_34 ) {
if ( V_5 -> V_35 [ V_10 ] != V_36 )
continue;
F_55 ( V_5 -> V_37 , V_10 / V_34 , V_1 , type ) ;
}
}
static int F_57 ( struct V_65 * V_66 ,
struct V_38 * V_39 , int * V_70 )
{
struct V_4 * V_211 , * V_212 = & V_66 -> V_72 ;
struct V_6 * V_12 = V_212 -> V_12 , * V_45 ;
T_1 V_59 = F_9 ( V_39 -> V_41 ) ;
int V_77 ;
if ( V_59 > V_62 ) {
F_5 ( L_84 , V_59 ) ;
return - V_85 ;
}
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_39 -> V_17 != 0 ) {
F_5 ( L_85 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( F_30 ( V_66 , V_39 -> V_47 ) ) {
F_5 ( L_86 ,
V_39 -> V_47 ) ;
return - V_87 ;
}
} else {
if ( V_39 -> V_47 != V_177 ) {
F_5 ( L_85 ) ;
return - V_85 ;
}
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_45 = & V_12 [ V_39 -> V_45 ] ;
if ( F_8 ( V_39 -> V_41 ) == V_182 &&
( V_59 == V_205 || V_59 == V_206 ) &&
V_45 -> type == V_15 && V_45 -> V_17 == V_39 -> V_17 ) {
if ( V_59 == V_205 ) {
* V_70 += V_39 -> V_19 ;
return 0 ;
} else {
return 0 ;
}
}
V_211 = F_14 ( V_66 , * V_70 + V_39 -> V_19 + 1 , * V_70 ) ;
if ( ! V_211 )
return - V_143 ;
if ( F_8 ( V_39 -> V_41 ) == V_44 ) {
if ( V_12 [ V_39 -> V_47 ] . type == V_15 )
F_53 ( & V_211 -> V_12 [ V_39 -> V_45 ] ,
V_45 , V_12 [ V_39 -> V_47 ] . V_17 ,
V_59 ) ;
else if ( V_45 -> type == V_15 )
F_54 ( & V_211 -> V_12 [ V_39 -> V_47 ] ,
& V_12 [ V_39 -> V_47 ] , V_45 -> V_17 ,
V_59 ) ;
} else {
F_53 ( & V_211 -> V_12 [ V_39 -> V_45 ] ,
V_45 , V_39 -> V_17 , V_59 ) ;
}
if ( F_8 ( V_39 -> V_41 ) == V_182 &&
V_39 -> V_17 == 0 && ( V_59 == V_205 || V_59 == V_206 ) &&
V_45 -> type == V_24 ) {
F_56 ( V_212 , V_39 -> V_45 ,
V_59 == V_205 ? V_23 : V_21 ) ;
F_56 ( V_211 , V_39 -> V_45 ,
V_59 == V_205 ? V_21 : V_23 ) ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 && V_59 == V_207 &&
V_45 -> type == V_18 &&
V_12 [ V_39 -> V_47 ] . type == V_94 ) {
F_52 ( V_212 , V_45 ) ;
} else if ( F_8 ( V_39 -> V_41 ) == V_44 && V_59 == V_209 &&
V_45 -> type == V_94 &&
V_12 [ V_39 -> V_47 ] . type == V_18 ) {
F_52 ( V_211 , & V_12 [ V_39 -> V_47 ] ) ;
} else if ( F_30 ( V_66 , V_39 -> V_45 ) ) {
F_5 ( L_86 , V_39 -> V_45 ) ;
return - V_87 ;
}
if ( V_123 )
F_4 ( V_212 ) ;
return 0 ;
}
static struct V_99 * F_58 ( struct V_38 * V_39 )
{
T_5 V_213 = ( ( T_5 ) ( T_2 ) V_39 [ 0 ] . V_17 ) | ( ( T_5 ) ( T_2 ) V_39 [ 1 ] . V_17 ) << 32 ;
return (struct V_99 * ) ( unsigned long ) V_213 ;
}
static int F_59 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
int V_77 ;
if ( F_11 ( V_39 -> V_41 ) != V_93 ) {
F_5 ( L_87 ) ;
return - V_85 ;
}
if ( V_39 -> V_19 != 0 ) {
F_5 ( L_88 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_88 ) ;
if ( V_77 )
return V_77 ;
if ( V_39 -> V_47 == 0 ) {
T_5 V_17 = ( ( T_5 ) ( V_39 + 1 ) -> V_17 << 32 ) | ( T_2 ) V_39 -> V_17 ;
if ( ! V_66 -> V_115 )
return 0 ;
V_12 [ V_39 -> V_45 ] . type = V_15 ;
V_12 [ V_39 -> V_45 ] . V_17 = V_17 ;
return 0 ;
}
F_19 ( V_39 -> V_47 != V_214 ) ;
V_12 [ V_39 -> V_45 ] . type = V_22 ;
V_12 [ V_39 -> V_45 ] . V_26 = F_58 ( V_39 ) ;
return 0 ;
}
static bool F_60 ( enum V_215 type )
{
switch ( type ) {
case V_216 :
case V_108 :
case V_109 :
return true ;
default:
return false ;
}
}
static int F_61 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_6 * V_12 = V_66 -> V_72 . V_12 ;
T_1 V_217 = F_10 ( V_39 -> V_41 ) ;
struct V_6 * V_7 ;
int V_10 , V_77 ;
if ( ! F_60 ( V_66 -> V_104 -> type ) ) {
F_5 ( L_89 ) ;
return - V_85 ;
}
if ( V_39 -> V_45 != V_177 || V_39 -> V_19 != 0 ||
F_11 ( V_39 -> V_41 ) == V_93 ||
( V_217 == V_55 && V_39 -> V_47 != V_177 ) ) {
F_5 ( L_90 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_218 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( V_12 [ V_218 ] . type != V_82 ) {
F_5 ( L_91 ) ;
return - V_85 ;
}
if ( V_217 == V_56 ) {
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
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
static int F_62 ( int V_9 , int V_219 , int V_220 , struct V_65 * V_66 )
{
if ( V_220 == V_221 && V_222 [ V_9 ] >= ( V_223 | V_221 ) )
return 0 ;
if ( V_220 == V_224 && V_222 [ V_9 ] >= ( V_223 | V_224 ) )
return 0 ;
if ( V_219 < 0 || V_219 >= V_66 -> V_104 -> V_225 ) {
F_5 ( L_92 , V_9 , V_219 ) ;
return - V_85 ;
}
if ( V_220 == V_224 )
V_66 -> V_226 [ V_219 ] = V_227 ;
if ( V_222 [ V_219 ] == 0 ) {
V_222 [ V_9 ] = V_223 | V_220 ;
V_222 [ V_219 ] = V_223 ;
if ( V_228 >= V_66 -> V_104 -> V_225 )
return - V_229 ;
V_230 [ V_228 ++ ] = V_219 ;
return 1 ;
} else if ( ( V_222 [ V_219 ] & 0xF0 ) == V_223 ) {
F_5 ( L_93 , V_9 , V_219 ) ;
return - V_85 ;
} else if ( V_222 [ V_219 ] == V_231 ) {
V_222 [ V_9 ] = V_223 | V_220 ;
} else {
F_5 ( L_94 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_63 ( struct V_65 * V_66 )
{
struct V_38 * V_232 = V_66 -> V_104 -> V_233 ;
int V_234 = V_66 -> V_104 -> V_225 ;
int V_235 = 0 ;
int V_10 , V_9 ;
V_222 = F_64 ( V_234 , sizeof( int ) , V_76 ) ;
if ( ! V_222 )
return - V_236 ;
V_230 = F_64 ( V_234 , sizeof( int ) , V_76 ) ;
if ( ! V_230 ) {
F_13 ( V_222 ) ;
return - V_236 ;
}
V_222 [ 0 ] = V_223 ;
V_230 [ 0 ] = 0 ;
V_228 = 1 ;
V_237:
if ( V_228 == 0 )
goto V_238;
V_9 = V_230 [ V_228 - 1 ] ;
if ( F_7 ( V_232 [ V_9 ] . V_41 ) == V_58 ) {
T_1 V_59 = F_9 ( V_232 [ V_9 ] . V_41 ) ;
if ( V_59 == V_62 ) {
goto V_239;
} else if ( V_59 == V_60 ) {
V_235 = F_62 ( V_9 , V_9 + 1 , V_221 , V_66 ) ;
if ( V_235 == 1 )
goto V_237;
else if ( V_235 < 0 )
goto V_240;
if ( V_9 + 1 < V_234 )
V_66 -> V_226 [ V_9 + 1 ] = V_227 ;
} else if ( V_59 == V_61 ) {
if ( F_8 ( V_232 [ V_9 ] . V_41 ) != V_182 ) {
V_235 = - V_85 ;
goto V_240;
}
V_235 = F_62 ( V_9 , V_9 + V_232 [ V_9 ] . V_19 + 1 ,
V_221 , V_66 ) ;
if ( V_235 == 1 )
goto V_237;
else if ( V_235 < 0 )
goto V_240;
if ( V_9 + 1 < V_234 )
V_66 -> V_226 [ V_9 + 1 ] = V_227 ;
} else {
V_235 = F_62 ( V_9 , V_9 + 1 , V_221 , V_66 ) ;
if ( V_235 == 1 )
goto V_237;
else if ( V_235 < 0 )
goto V_240;
V_235 = F_62 ( V_9 , V_9 + V_232 [ V_9 ] . V_19 + 1 , V_224 , V_66 ) ;
if ( V_235 == 1 )
goto V_237;
else if ( V_235 < 0 )
goto V_240;
}
} else {
V_235 = F_62 ( V_9 , V_9 + 1 , V_221 , V_66 ) ;
if ( V_235 == 1 )
goto V_237;
else if ( V_235 < 0 )
goto V_240;
}
V_239:
V_222 [ V_9 ] = V_231 ;
if ( V_228 -- <= 0 ) {
F_5 ( L_95 ) ;
V_235 = - V_143 ;
goto V_240;
}
goto V_237;
V_238:
for ( V_10 = 0 ; V_10 < V_234 ; V_10 ++ ) {
if ( V_222 [ V_10 ] != V_231 ) {
F_5 ( L_96 , V_10 ) ;
V_235 = - V_85 ;
goto V_240;
}
}
V_235 = 0 ;
V_240:
F_13 ( V_222 ) ;
F_13 ( V_230 ) ;
return V_235 ;
}
static bool F_65 ( struct V_6 * V_241 ,
struct V_6 * V_242 )
{
if ( V_241 -> V_1 != V_242 -> V_1 )
return false ;
if ( V_241 -> V_19 == V_242 -> V_19 && V_241 -> V_20 < V_242 -> V_20 )
return true ;
if ( V_241 -> V_19 <= V_242 -> V_19 &&
V_241 -> V_19 >= V_241 -> V_20 && V_242 -> V_19 >= V_242 -> V_20 )
return true ;
return false ;
}
static bool F_66 ( struct V_65 * V_66 ,
struct V_4 * V_241 ,
struct V_4 * V_242 )
{
bool V_243 = V_66 -> V_124 ;
struct V_6 * V_244 , * V_245 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_244 = & V_241 -> V_12 [ V_10 ] ;
V_245 = & V_242 -> V_12 [ V_10 ] ;
if ( memcmp ( V_244 , V_245 , sizeof( * V_244 ) ) == 0 )
continue;
if ( ! V_243 &&
memcmp ( V_244 , V_245 , F_67 ( struct V_6 , V_1 ) ) == 0 )
continue;
if ( V_244 -> type == V_13 ||
( ! V_243 && V_244 -> type == V_21 &&
V_245 -> type != V_13 ) )
continue;
if ( V_244 -> type == V_18 && V_245 -> type == V_18 &&
F_65 ( V_244 , V_245 ) )
continue;
return false ;
}
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
if ( V_241 -> V_35 [ V_10 ] == V_246 )
continue;
if ( V_241 -> V_35 [ V_10 ] != V_242 -> V_35 [ V_10 ] )
return false ;
if ( V_10 % V_34 )
continue;
if ( memcmp ( & V_241 -> V_37 [ V_10 / V_34 ] ,
& V_242 -> V_37 [ V_10 / V_34 ] ,
sizeof( V_241 -> V_37 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_68 ( struct V_65 * V_66 , int V_70 )
{
struct V_247 * V_248 ;
struct V_247 * V_249 ;
V_249 = V_66 -> V_226 [ V_70 ] ;
if ( ! V_249 )
return 0 ;
while ( V_249 != V_227 ) {
if ( F_66 ( V_66 , & V_249 -> V_5 , & V_66 -> V_72 ) )
return 1 ;
V_249 = V_249 -> V_74 ;
}
V_248 = F_15 ( sizeof( struct V_247 ) , V_250 ) ;
if ( ! V_248 )
return - V_236 ;
memcpy ( & V_248 -> V_5 , & V_66 -> V_72 , sizeof( V_66 -> V_72 ) ) ;
V_248 -> V_74 = V_66 -> V_226 [ V_70 ] ;
V_66 -> V_226 [ V_70 ] = V_248 ;
return 0 ;
}
static int F_69 ( struct V_65 * V_66 ,
int V_70 , int V_67 )
{
if ( ! V_66 -> V_115 || ! V_66 -> V_115 -> V_251 )
return 0 ;
return V_66 -> V_115 -> V_251 ( V_66 , V_70 , V_67 ) ;
}
static int F_70 ( struct V_65 * V_66 )
{
struct V_4 * V_5 = & V_66 -> V_72 ;
struct V_38 * V_232 = V_66 -> V_104 -> V_233 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_234 = V_66 -> V_104 -> V_225 ;
int V_70 , V_67 = 0 ;
int V_252 = 0 ;
bool V_253 = false ;
F_16 ( V_12 ) ;
V_70 = 0 ;
V_66 -> V_124 = false ;
for (; ; ) {
struct V_38 * V_39 ;
T_1 V_40 ;
int V_77 ;
if ( V_70 >= V_234 ) {
F_5 ( L_97 ,
V_70 , V_234 ) ;
return - V_143 ;
}
V_39 = & V_232 [ V_70 ] ;
V_40 = F_7 ( V_39 -> V_41 ) ;
if ( ++ V_252 > V_254 ) {
F_5 ( L_98 ,
V_252 ) ;
return - V_229 ;
}
V_77 = F_68 ( V_66 , V_70 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( V_77 == 1 ) {
if ( V_123 ) {
if ( V_253 )
F_5 ( L_99 ,
V_67 , V_70 ) ;
else
F_5 ( L_100 , V_70 ) ;
}
goto V_255;
}
if ( V_123 && V_253 ) {
F_5 ( L_101 , V_67 , V_70 ) ;
F_4 ( & V_66 -> V_72 ) ;
V_253 = false ;
}
if ( V_123 ) {
F_5 ( L_102 , V_70 ) ;
F_6 ( V_39 ) ;
}
V_77 = F_69 ( V_66 , V_70 , V_67 ) ;
if ( V_77 )
return V_77 ;
if ( V_40 == V_42 || V_40 == V_43 ) {
V_77 = F_51 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_40 == V_53 ) {
enum V_8 * V_256 , V_257 ;
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_201 ) ;
if ( V_77 )
return V_77 ;
V_257 = V_12 [ V_39 -> V_47 ] . type ;
V_77 = F_33 ( V_66 , V_39 -> V_47 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_125 ,
V_39 -> V_45 ) ;
if ( V_77 )
return V_77 ;
F_20 ( V_12 , V_39 -> V_45 ) ;
if ( F_11 ( V_39 -> V_41 ) != V_90 &&
F_11 ( V_39 -> V_41 ) != V_93 ) {
V_70 ++ ;
continue;
}
V_256 = & V_66 -> V_258 [ V_70 ] . V_259 ;
if ( * V_256 == V_13 ) {
* V_256 = V_257 ;
} else if ( V_257 != * V_256 &&
( V_257 == V_82 ||
* V_256 == V_82 ) ) {
F_5 ( L_103 ) ;
return - V_85 ;
}
} else if ( V_40 == V_48 ) {
enum V_8 * V_260 , V_261 ;
if ( F_10 ( V_39 -> V_41 ) == V_51 ) {
V_77 = F_34 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
V_70 ++ ;
continue;
}
V_77 = F_21 ( V_12 , V_39 -> V_47 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_261 = V_12 [ V_39 -> V_45 ] . type ;
V_77 = F_33 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_107 ,
V_39 -> V_47 ) ;
if ( V_77 )
return V_77 ;
V_260 = & V_66 -> V_258 [ V_70 ] . V_259 ;
if ( * V_260 == V_13 ) {
* V_260 = V_261 ;
} else if ( V_261 != * V_260 &&
( V_261 == V_82 ||
* V_260 == V_82 ) ) {
F_5 ( L_103 ) ;
return - V_85 ;
}
} else if ( V_40 == V_52 ) {
if ( F_10 ( V_39 -> V_41 ) != V_49 ||
V_39 -> V_47 != V_177 ) {
F_5 ( L_104 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_39 -> V_45 , V_86 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_33 ( V_66 , V_39 -> V_45 , V_39 -> V_19 ,
F_11 ( V_39 -> V_41 ) , V_107 ,
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
F_5 ( L_105 ) ;
return - V_85 ;
}
V_77 = F_40 ( V_66 , V_39 -> V_17 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_59 == V_61 ) {
if ( F_8 ( V_39 -> V_41 ) != V_182 ||
V_39 -> V_17 != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_45 != V_177 ) {
F_5 ( L_106 ) ;
return - V_85 ;
}
V_70 += V_39 -> V_19 + 1 ;
continue;
} else if ( V_59 == V_62 ) {
if ( F_8 ( V_39 -> V_41 ) != V_182 ||
V_39 -> V_17 != 0 ||
V_39 -> V_47 != V_177 ||
V_39 -> V_45 != V_177 ) {
F_5 ( L_107 ) ;
return - V_85 ;
}
V_77 = F_21 ( V_12 , V_177 , V_86 ) ;
if ( V_77 )
return V_77 ;
if ( F_30 ( V_66 , V_177 ) ) {
F_5 ( L_108 ) ;
return - V_87 ;
}
V_255:
V_70 = F_12 ( V_66 , & V_67 ) ;
if ( V_70 < 0 ) {
break;
} else {
V_253 = true ;
continue;
}
} else {
V_77 = F_57 ( V_66 , V_39 , & V_70 ) ;
if ( V_77 )
return V_77 ;
}
} else if ( V_40 == V_54 ) {
T_1 V_217 = F_10 ( V_39 -> V_41 ) ;
if ( V_217 == V_55 || V_217 == V_56 ) {
V_77 = F_61 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
} else if ( V_217 == V_57 ) {
V_77 = F_59 ( V_66 , V_39 ) ;
if ( V_77 )
return V_77 ;
V_70 ++ ;
} else {
F_5 ( L_109 ) ;
return - V_85 ;
}
F_20 ( V_12 , V_39 -> V_45 ) ;
} else {
F_5 ( L_110 , V_40 ) ;
return - V_85 ;
}
V_70 ++ ;
}
F_5 ( L_111 , V_252 ) ;
return 0 ;
}
static int F_71 ( struct V_99 * V_100 ,
struct V_262 * V_104 )
{
if ( V_104 -> type == V_263 &&
( V_100 -> V_145 == V_264 ||
V_100 -> V_145 == V_265 ) &&
( V_100 -> V_266 & V_267 ) ) {
F_5 ( L_112 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_72 ( struct V_65 * V_66 )
{
struct V_38 * V_39 = V_66 -> V_104 -> V_233 ;
int V_234 = V_66 -> V_104 -> V_225 ;
int V_10 , V_268 , V_77 ;
V_77 = F_73 ( V_66 -> V_104 ) ;
if ( V_77 )
return V_77 ;
for ( V_10 = 0 ; V_10 < V_234 ; V_10 ++ , V_39 ++ ) {
if ( F_7 ( V_39 -> V_41 ) == V_53 &&
( F_10 ( V_39 -> V_41 ) != V_49 || V_39 -> V_17 != 0 ) ) {
F_5 ( L_113 ) ;
return - V_85 ;
}
if ( F_7 ( V_39 -> V_41 ) == V_48 &&
( ( F_10 ( V_39 -> V_41 ) != V_49 &&
F_10 ( V_39 -> V_41 ) != V_51 ) || V_39 -> V_17 != 0 ) ) {
F_5 ( L_114 ) ;
return - V_85 ;
}
if ( V_39 [ 0 ] . V_41 == ( V_54 | V_57 | V_93 ) ) {
struct V_99 * V_100 ;
struct V_269 V_270 ;
if ( V_10 == V_234 - 1 || V_39 [ 1 ] . V_41 != 0 ||
V_39 [ 1 ] . V_45 != 0 || V_39 [ 1 ] . V_47 != 0 ||
V_39 [ 1 ] . V_19 != 0 ) {
F_5 ( L_115 ) ;
return - V_85 ;
}
if ( V_39 -> V_47 == 0 )
goto V_271;
if ( V_39 -> V_47 != V_214 ) {
F_5 ( L_116 ) ;
return - V_85 ;
}
V_270 = F_74 ( V_39 -> V_17 ) ;
V_100 = F_75 ( V_270 ) ;
if ( F_76 ( V_100 ) ) {
F_5 ( L_117 ,
V_39 -> V_17 ) ;
return F_77 ( V_100 ) ;
}
V_77 = F_71 ( V_100 , V_66 -> V_104 ) ;
if ( V_77 ) {
F_78 ( V_270 ) ;
return V_77 ;
}
V_39 [ 0 ] . V_17 = ( T_2 ) ( unsigned long ) V_100 ;
V_39 [ 1 ] . V_17 = ( ( T_5 ) ( unsigned long ) V_100 ) >> 32 ;
for ( V_268 = 0 ; V_268 < V_66 -> V_272 ; V_268 ++ )
if ( V_66 -> V_273 [ V_268 ] == V_100 ) {
F_78 ( V_270 ) ;
goto V_271;
}
if ( V_66 -> V_272 >= V_274 ) {
F_78 ( V_270 ) ;
return - V_229 ;
}
V_100 = F_79 ( V_100 , false ) ;
if ( F_76 ( V_100 ) ) {
F_78 ( V_270 ) ;
return F_77 ( V_100 ) ;
}
V_66 -> V_273 [ V_66 -> V_272 ++ ] = V_100 ;
F_78 ( V_270 ) ;
V_271:
V_39 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_80 ( struct V_65 * V_66 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_66 -> V_272 ; V_10 ++ )
F_81 ( V_66 -> V_273 [ V_10 ] ) ;
}
static void F_82 ( struct V_65 * V_66 )
{
struct V_38 * V_39 = V_66 -> V_104 -> V_233 ;
int V_234 = V_66 -> V_104 -> V_225 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_234 ; V_10 ++ , V_39 ++ )
if ( V_39 -> V_41 == ( V_54 | V_57 | V_93 ) )
V_39 -> V_47 = 0 ;
}
static int F_83 ( struct V_65 * V_66 )
{
const struct V_275 * V_117 = V_66 -> V_104 -> V_116 -> V_117 ;
const int V_234 = V_66 -> V_104 -> V_225 ;
struct V_38 V_276 [ 16 ] , * V_39 ;
struct V_262 * V_277 ;
enum V_103 type ;
int V_10 , V_278 , V_279 = 0 ;
if ( V_117 -> V_280 ) {
V_278 = V_117 -> V_280 ( V_276 , V_66 -> V_113 ,
V_66 -> V_104 ) ;
if ( V_278 >= F_3 ( V_276 ) ) {
F_5 ( L_118 ) ;
return - V_85 ;
} else if ( V_278 ) {
V_277 = F_84 ( V_66 -> V_104 , 0 ,
V_276 , V_278 ) ;
if ( ! V_277 )
return - V_236 ;
V_66 -> V_104 = V_277 ;
V_279 += V_278 - 1 ;
}
}
if ( ! V_117 -> V_281 )
return 0 ;
V_39 = V_66 -> V_104 -> V_233 + V_279 ;
for ( V_10 = 0 ; V_10 < V_234 ; V_10 ++ , V_39 ++ ) {
if ( V_39 -> V_41 == ( V_53 | V_49 | V_90 ) ||
V_39 -> V_41 == ( V_53 | V_49 | V_93 ) )
type = V_125 ;
else if ( V_39 -> V_41 == ( V_48 | V_49 | V_90 ) ||
V_39 -> V_41 == ( V_48 | V_49 | V_93 ) )
type = V_107 ;
else
continue;
if ( V_66 -> V_258 [ V_10 ] . V_259 != V_82 )
continue;
V_278 = V_117 -> V_281 ( type , V_39 -> V_45 , V_39 -> V_47 ,
V_39 -> V_19 , V_276 , V_66 -> V_104 ) ;
if ( V_278 == 0 || V_278 >= F_3 ( V_276 ) ) {
F_5 ( L_118 ) ;
return - V_85 ;
}
V_277 = F_84 ( V_66 -> V_104 , V_10 + V_279 , V_276 ,
V_278 ) ;
if ( ! V_277 )
return - V_236 ;
V_279 += V_278 - 1 ;
V_66 -> V_104 = V_277 ;
V_39 = V_277 -> V_233 + V_10 + V_279 ;
}
return 0 ;
}
static void F_85 ( struct V_65 * V_66 )
{
struct V_247 * V_249 , * V_282 ;
int V_10 ;
if ( ! V_66 -> V_226 )
return;
for ( V_10 = 0 ; V_10 < V_66 -> V_104 -> V_225 ; V_10 ++ ) {
V_249 = V_66 -> V_226 [ V_10 ] ;
if ( V_249 )
while ( V_249 != V_227 ) {
V_282 = V_249 -> V_74 ;
F_13 ( V_249 ) ;
V_249 = V_282 ;
}
}
F_13 ( V_66 -> V_226 ) ;
}
int F_86 ( struct V_262 * * V_104 , union V_283 * V_284 )
{
char T_6 * V_285 = NULL ;
struct V_65 * V_66 ;
int V_235 = - V_85 ;
V_66 = F_87 ( sizeof( struct V_65 ) , V_76 ) ;
if ( ! V_66 )
return - V_236 ;
V_66 -> V_258 = F_88 ( sizeof( struct V_286 ) *
( * V_104 ) -> V_225 ) ;
V_235 = - V_236 ;
if ( ! V_66 -> V_258 )
goto V_287;
V_66 -> V_104 = * V_104 ;
F_89 ( & V_288 ) ;
if ( V_284 -> V_123 || V_284 -> V_289 || V_284 -> V_290 ) {
V_123 = V_284 -> V_123 ;
V_285 = ( char T_6 * ) ( unsigned long ) V_284 -> V_289 ;
V_290 = V_284 -> V_290 ;
V_291 = 0 ;
V_235 = - V_85 ;
if ( V_290 < 128 || V_290 > V_292 >> 8 ||
V_123 == 0 || V_285 == NULL )
goto V_293;
V_235 = - V_236 ;
V_289 = F_90 ( V_290 ) ;
if ( ! V_289 )
goto V_293;
} else {
V_123 = 0 ;
}
V_235 = F_72 ( V_66 ) ;
if ( V_235 < 0 )
goto V_294;
V_66 -> V_226 = F_64 ( V_66 -> V_104 -> V_225 ,
sizeof( struct V_247 * ) ,
V_250 ) ;
V_235 = - V_236 ;
if ( ! V_66 -> V_226 )
goto V_294;
V_235 = F_63 ( V_66 ) ;
if ( V_235 < 0 )
goto V_294;
V_66 -> V_120 = F_91 ( V_295 ) ;
V_235 = F_70 ( V_66 ) ;
V_294:
while ( F_12 ( V_66 , NULL ) >= 0 ) ;
F_85 ( V_66 ) ;
if ( V_235 == 0 )
V_235 = F_83 ( V_66 ) ;
if ( V_123 && V_291 >= V_290 - 1 ) {
F_19 ( V_291 >= V_290 ) ;
V_235 = - V_296 ;
}
if ( V_123 && F_92 ( V_285 , V_289 , V_291 + 1 ) != 0 ) {
V_235 = - V_143 ;
goto V_297;
}
if ( V_235 == 0 && V_66 -> V_272 ) {
V_66 -> V_104 -> V_116 -> V_273 = F_93 ( V_66 -> V_272 ,
sizeof( V_66 -> V_273 [ 0 ] ) ,
V_76 ) ;
if ( ! V_66 -> V_104 -> V_116 -> V_273 ) {
V_235 = - V_236 ;
goto V_297;
}
memcpy ( V_66 -> V_104 -> V_116 -> V_273 , V_66 -> V_273 ,
sizeof( V_66 -> V_273 [ 0 ] ) * V_66 -> V_272 ) ;
V_66 -> V_104 -> V_116 -> V_272 = V_66 -> V_272 ;
F_82 ( V_66 ) ;
}
V_297:
if ( V_123 )
F_94 ( V_289 ) ;
if ( ! V_66 -> V_104 -> V_116 -> V_273 )
F_80 ( V_66 ) ;
* V_104 = V_66 -> V_104 ;
V_293:
F_95 ( & V_288 ) ;
F_94 ( V_66 -> V_258 ) ;
V_287:
F_13 ( V_66 ) ;
return V_235 ;
}
int F_96 ( struct V_262 * V_104 , const struct V_298 * V_117 ,
void * V_299 )
{
struct V_65 * V_66 ;
int V_235 ;
V_66 = F_87 ( sizeof( struct V_65 ) , V_76 ) ;
if ( ! V_66 )
return - V_236 ;
V_66 -> V_258 = F_88 ( sizeof( struct V_286 ) *
V_104 -> V_225 ) ;
V_235 = - V_236 ;
if ( ! V_66 -> V_258 )
goto V_287;
V_66 -> V_104 = V_104 ;
V_66 -> V_115 = V_117 ;
V_66 -> V_300 = V_299 ;
F_89 ( & V_288 ) ;
V_123 = 0 ;
V_66 -> V_226 = F_64 ( V_66 -> V_104 -> V_225 ,
sizeof( struct V_247 * ) ,
V_76 ) ;
V_235 = - V_236 ;
if ( ! V_66 -> V_226 )
goto V_294;
V_235 = F_63 ( V_66 ) ;
if ( V_235 < 0 )
goto V_294;
V_66 -> V_120 = F_91 ( V_295 ) ;
V_235 = F_70 ( V_66 ) ;
V_294:
while ( F_12 ( V_66 , NULL ) >= 0 ) ;
F_85 ( V_66 ) ;
F_95 ( & V_288 ) ;
F_94 ( V_66 -> V_258 ) ;
V_287:
F_13 ( V_66 ) ;
return V_235 ;
}
