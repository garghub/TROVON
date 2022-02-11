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
if ( V_7 -> V_33 )
F_5 ( L_8 , V_7 -> V_33 ) ;
if ( V_7 -> V_34 )
F_5 ( L_9 , V_7 -> V_34 ) ;
if ( V_7 -> V_35 )
F_5 ( L_10 , V_7 -> V_35 ) ;
}
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] == V_39 )
F_5 ( L_11 , - V_36 + V_10 ,
V_14 [ V_5 -> V_40 [ V_10 / V_37 ] . type ] ) ;
}
F_5 ( L_12 ) ;
}
static void F_6 ( const struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
T_1 V_45 = F_7 ( V_44 -> V_46 ) ;
if ( V_45 == V_47 || V_45 == V_48 ) {
if ( F_8 ( V_44 -> V_46 ) == V_49 )
F_5 ( L_13 ,
V_44 -> V_46 , V_45 == V_47 ? L_14 : L_15 ,
V_44 -> V_50 ,
V_51 [ F_9 ( V_44 -> V_46 ) >> 4 ] ,
V_45 == V_47 ? L_14 : L_15 ,
V_44 -> V_52 ) ;
else
F_5 ( L_16 ,
V_44 -> V_46 , V_45 == V_47 ? L_14 : L_15 ,
V_44 -> V_50 ,
V_51 [ F_9 ( V_44 -> V_46 ) >> 4 ] ,
V_45 == V_47 ? L_14 : L_15 ,
V_44 -> V_17 ) ;
} else if ( V_45 == V_53 ) {
if ( F_10 ( V_44 -> V_46 ) == V_54 )
F_5 ( L_17 ,
V_44 -> V_46 ,
V_55 [ F_11 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_50 ,
V_44 -> V_19 , V_44 -> V_52 ) ;
else if ( F_10 ( V_44 -> V_46 ) == V_56 )
F_5 ( L_18 ,
V_44 -> V_46 ,
V_55 [ F_11 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_50 , V_44 -> V_19 ,
V_44 -> V_52 ) ;
else
F_5 ( L_19 , V_44 -> V_46 ) ;
} else if ( V_45 == V_57 ) {
if ( F_10 ( V_44 -> V_46 ) != V_54 ) {
F_5 ( L_20 , V_44 -> V_46 ) ;
return;
}
F_5 ( L_21 ,
V_44 -> V_46 ,
V_55 [ F_11 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_50 ,
V_44 -> V_19 , V_44 -> V_17 ) ;
} else if ( V_45 == V_58 ) {
if ( F_10 ( V_44 -> V_46 ) != V_54 ) {
F_5 ( L_22 , V_44 -> V_46 ) ;
return;
}
F_5 ( L_23 ,
V_44 -> V_46 , V_44 -> V_50 ,
V_55 [ F_11 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_52 , V_44 -> V_19 ) ;
} else if ( V_45 == V_59 ) {
if ( F_10 ( V_44 -> V_46 ) == V_60 ) {
F_5 ( L_24 ,
V_44 -> V_46 ,
V_55 [ F_11 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_17 ) ;
} else if ( F_10 ( V_44 -> V_46 ) == V_61 ) {
F_5 ( L_25 ,
V_44 -> V_46 ,
V_55 [ F_11 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_52 , V_44 -> V_17 ) ;
} else if ( F_10 ( V_44 -> V_46 ) == V_62 &&
F_11 ( V_44 -> V_46 ) == V_63 ) {
T_2 V_17 = ( ( T_2 ) ( V_44 + 1 ) -> V_17 << 32 ) | ( V_64 ) V_44 -> V_17 ;
bool V_26 = V_44 -> V_52 == V_65 ;
if ( V_26 && ! V_42 -> V_66 )
V_17 = 0 ;
F_5 ( L_26 , V_44 -> V_46 ,
V_44 -> V_50 , ( unsigned long long ) V_17 ) ;
} else {
F_5 ( L_27 , V_44 -> V_46 ) ;
return;
}
} else if ( V_45 == V_67 ) {
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
if ( V_68 == V_69 ) {
F_5 ( L_28 , V_44 -> V_46 ,
F_1 ( V_44 -> V_17 ) , V_44 -> V_17 ) ;
} else if ( V_44 -> V_46 == ( V_67 | V_70 ) ) {
F_5 ( L_29 ,
V_44 -> V_46 , V_44 -> V_19 ) ;
} else if ( V_44 -> V_46 == ( V_67 | V_71 ) ) {
F_5 ( L_30 , V_44 -> V_46 ) ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
F_5 ( L_31 ,
V_44 -> V_46 , V_44 -> V_50 ,
V_72 [ F_9 ( V_44 -> V_46 ) >> 4 ] ,
V_44 -> V_52 , V_44 -> V_19 ) ;
} else {
F_5 ( L_32 ,
V_44 -> V_46 , V_44 -> V_50 ,
V_72 [ F_9 ( V_44 -> V_46 ) >> 4 ] ,
V_44 -> V_17 , V_44 -> V_19 ) ;
}
} else {
F_5 ( L_33 , V_44 -> V_46 , V_73 [ V_45 ] ) ;
}
}
static int F_12 ( struct V_41 * V_42 , int * V_74 )
{
struct V_75 * V_76 ;
int V_77 ;
if ( V_42 -> V_78 == NULL )
return - 1 ;
memcpy ( & V_42 -> V_79 , & V_42 -> V_78 -> V_80 , sizeof( V_42 -> V_79 ) ) ;
V_77 = V_42 -> V_78 -> V_77 ;
if ( V_74 )
* V_74 = V_42 -> V_78 -> V_74 ;
V_76 = V_42 -> V_78 -> V_81 ;
F_13 ( V_42 -> V_78 ) ;
V_42 -> V_78 = V_76 ;
V_42 -> V_82 -- ;
return V_77 ;
}
static struct V_4 * F_14 ( struct V_41 * V_42 ,
int V_77 , int V_74 )
{
struct V_75 * V_76 ;
V_76 = F_15 ( sizeof( struct V_75 ) , V_83 ) ;
if ( ! V_76 )
goto V_84;
memcpy ( & V_76 -> V_80 , & V_42 -> V_79 , sizeof( V_42 -> V_79 ) ) ;
V_76 -> V_77 = V_77 ;
V_76 -> V_74 = V_74 ;
V_76 -> V_81 = V_42 -> V_78 ;
V_42 -> V_78 = V_76 ;
V_42 -> V_82 ++ ;
if ( V_42 -> V_82 > V_85 ) {
F_5 ( L_34 ) ;
goto V_84;
}
return & V_76 -> V_80 ;
V_84:
while ( F_12 ( V_42 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_16 ( struct V_6 * V_12 , V_64 V_86 )
{
F_17 ( V_86 >= V_11 ) ;
memset ( & V_12 [ V_86 ] , 0 , sizeof( V_12 [ V_86 ] ) ) ;
V_12 [ V_86 ] . type = V_13 ;
V_12 [ V_86 ] . V_29 = V_30 ;
V_12 [ V_86 ] . V_31 = V_32 ;
}
static void F_18 ( struct V_6 * V_12 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_16 ( V_12 , V_10 ) ;
V_12 [ V_87 ] . type = V_88 ;
V_12 [ V_89 ] . type = V_90 ;
}
static void F_19 ( struct V_6 * V_12 , V_64 V_86 )
{
V_12 [ V_86 ] . type = V_21 ;
V_12 [ V_86 ] . V_1 = 0 ;
V_12 [ V_86 ] . V_17 = 0 ;
}
static void F_20 ( struct V_6 * V_12 , V_64 V_86 )
{
F_17 ( V_86 >= V_11 ) ;
F_19 ( V_12 , V_86 ) ;
}
static void F_21 ( struct V_6 * V_12 , V_64 V_86 )
{
V_12 [ V_86 ] . V_29 = V_30 ;
V_12 [ V_86 ] . V_31 = V_32 ;
V_12 [ V_86 ] . V_33 = 0 ;
}
static void F_22 ( struct V_6 * V_12 ,
V_64 V_86 )
{
F_20 ( V_12 , V_86 ) ;
F_21 ( V_12 , V_86 ) ;
}
static int F_23 ( struct V_6 * V_12 , V_64 V_86 ,
enum V_91 V_9 )
{
if ( V_86 >= V_11 ) {
F_5 ( L_35 , V_86 ) ;
return - V_92 ;
}
if ( V_9 == V_93 ) {
if ( V_12 [ V_86 ] . type == V_13 ) {
F_5 ( L_36 , V_86 ) ;
return - V_94 ;
}
} else {
if ( V_86 == V_87 ) {
F_5 ( L_37 ) ;
return - V_94 ;
}
if ( V_9 == V_95 )
F_20 ( V_12 , V_86 ) ;
}
return 0 ;
}
static int F_24 ( int V_96 )
{
if ( V_96 == V_97 )
return 4 ;
else if ( V_96 == V_98 )
return 2 ;
else if ( V_96 == V_99 )
return 1 ;
else if ( V_96 == V_63 )
return 8 ;
else
return - V_92 ;
}
static bool F_25 ( enum V_8 type )
{
switch ( type ) {
case V_23 :
case V_24 :
case V_25 :
case V_16 :
case V_90 :
case V_18 :
case V_100 :
case V_88 :
case V_22 :
return true ;
default:
return false ;
}
}
static int F_26 ( struct V_4 * V_5 , int V_19 ,
int V_101 , int V_102 )
{
int V_10 ;
if ( V_102 >= 0 &&
F_25 ( V_5 -> V_12 [ V_102 ] . type ) ) {
if ( V_101 != V_37 ) {
F_5 ( L_38 ) ;
return - V_94 ;
}
V_5 -> V_40 [ ( V_36 + V_19 ) / V_37 ] =
V_5 -> V_12 [ V_102 ] ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ )
V_5 -> V_38 [ V_36 + V_19 + V_10 ] = V_39 ;
} else {
V_5 -> V_40 [ ( V_36 + V_19 ) / V_37 ] =
(struct V_6 ) {} ;
for ( V_10 = 0 ; V_10 < V_101 ; V_10 ++ )
V_5 -> V_38 [ V_36 + V_19 + V_10 ] = V_103 ;
}
return 0 ;
}
static int F_27 ( struct V_4 * V_5 , int V_19 , int V_101 ,
int V_102 )
{
T_1 * V_104 ;
int V_10 ;
V_104 = & V_5 -> V_38 [ V_36 + V_19 ] ;
if ( V_104 [ 0 ] == V_39 ) {
if ( V_101 != V_37 ) {
F_5 ( L_38 ) ;
return - V_94 ;
}
for ( V_10 = 1 ; V_10 < V_37 ; V_10 ++ ) {
if ( V_104 [ V_10 ] != V_39 ) {
F_5 ( L_39 ) ;
return - V_94 ;
}
}
if ( V_102 >= 0 )
V_5 -> V_12 [ V_102 ] =
V_5 -> V_40 [ ( V_36 + V_19 ) / V_37 ] ;
return 0 ;
} else {
for ( V_10 = 0 ; V_10 < V_101 ; V_10 ++ ) {
if ( V_104 [ V_10 ] != V_103 ) {
F_5 ( L_40 ,
V_19 , V_10 , V_101 ) ;
return - V_94 ;
}
}
if ( V_102 >= 0 )
F_22 ( V_5 -> V_12 ,
V_102 ) ;
return 0 ;
}
}
static int F_28 ( struct V_41 * V_42 , V_64 V_86 , int V_19 ,
int V_101 )
{
struct V_105 * V_106 = V_42 -> V_79 . V_12 [ V_86 ] . V_26 ;
if ( V_19 < 0 || V_101 <= 0 || V_19 + V_101 > V_106 -> V_28 ) {
F_5 ( L_41 ,
V_106 -> V_28 , V_19 , V_101 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_29 ( struct V_41 * V_42 , V_64 V_86 ,
int V_19 , int V_101 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_86 ] ;
int V_84 ;
if ( V_107 )
F_4 ( V_5 ) ;
V_42 -> V_108 = true ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_42 ,
V_86 ) ;
return - V_94 ;
}
V_84 = F_28 ( V_42 , V_86 , V_7 -> V_29 + V_19 , V_101 ) ;
if ( V_84 ) {
F_5 ( L_43 ,
V_86 ) ;
return V_84 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_44 ,
V_86 ) ;
return - V_94 ;
}
return F_28 ( V_42 , V_86 , V_7 -> V_31 + V_19 , V_101 ) ;
}
static bool F_30 ( struct V_41 * V_42 ,
const struct V_109 * V_110 ,
enum V_111 V_9 )
{
switch ( V_42 -> V_112 -> type ) {
case V_113 :
case V_114 :
if ( V_9 == V_115 )
return false ;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
if ( V_110 )
return V_110 -> V_120 ;
V_42 -> V_121 = true ;
return true ;
default:
return false ;
}
}
static int F_31 ( struct V_41 * V_42 , V_64 V_86 , int V_19 ,
int V_101 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_7 = & V_12 [ V_86 ] ;
V_19 += V_7 -> V_19 ;
if ( V_19 < 0 || V_101 <= 0 || V_19 + V_101 > V_7 -> V_20 ) {
F_5 ( L_45 ,
V_19 , V_101 , V_86 , V_7 -> V_1 , V_7 -> V_19 , V_7 -> V_20 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_32 ( struct V_41 * V_42 , int V_19 , int V_101 ,
enum V_111 V_9 , enum V_8 * V_122 )
{
if ( V_42 -> V_123 )
return 0 ;
if ( V_42 -> V_112 -> V_124 -> V_125 -> V_126 &&
V_42 -> V_112 -> V_124 -> V_125 -> V_126 ( V_19 , V_101 , V_9 , V_122 ) ) {
if ( V_42 -> V_112 -> V_124 -> V_127 < V_19 + V_101 )
V_42 -> V_112 -> V_124 -> V_127 = V_19 + V_101 ;
return 0 ;
}
F_5 ( L_46 , V_19 , V_101 ) ;
return - V_94 ;
}
static bool F_33 ( struct V_41 * V_42 , int V_86 )
{
if ( V_42 -> V_66 )
return false ;
switch ( V_42 -> V_79 . V_12 [ V_86 ] . type ) {
case V_21 :
case V_15 :
return false ;
default:
return true ;
}
}
static int F_34 ( const struct V_6 * V_7 ,
int V_19 , int V_101 , bool V_128 )
{
int V_129 ;
int V_130 ;
if ( ! V_128 || V_101 == 1 )
return 0 ;
V_130 = V_7 -> V_19 ;
if ( V_7 -> V_1 ) {
if ( V_7 -> V_35 % V_101 ) {
F_5 ( L_47 ,
V_7 -> V_35 , V_101 ) ;
return - V_94 ;
}
V_130 += V_7 -> V_34 ;
}
V_129 = 2 ;
if ( ( V_129 + V_130 + V_19 ) % V_101 != 0 ) {
F_5 ( L_48 ,
V_129 , V_130 , V_19 , V_101 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_35 ( const struct V_6 * V_7 ,
int V_101 , bool V_128 )
{
if ( V_128 && V_101 != 1 ) {
F_5 ( L_49 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_36 ( struct V_41 * V_42 ,
const struct V_6 * V_7 ,
int V_19 , int V_101 )
{
bool V_128 = V_42 -> V_131 ;
switch ( V_7 -> type ) {
case V_18 :
return F_34 ( V_7 , V_19 , V_101 , V_128 ) ;
case V_25 :
return F_35 ( V_7 , V_101 , V_128 ) ;
default:
if ( V_19 % V_101 != 0 ) {
F_5 ( L_50 ,
V_19 , V_101 ) ;
return - V_94 ;
}
return 0 ;
}
}
static int F_37 ( struct V_41 * V_42 , V_64 V_86 , int V_19 ,
int V_96 , enum V_111 V_9 ,
int V_102 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_86 ] ;
int V_101 , V_84 = 0 ;
if ( V_7 -> type == V_16 )
V_19 += V_7 -> V_17 ;
V_101 = F_24 ( V_96 ) ;
if ( V_101 < 0 )
return V_101 ;
V_84 = F_36 ( V_42 , V_7 , V_19 , V_101 ) ;
if ( V_84 )
return V_84 ;
if ( V_7 -> type == V_23 ||
V_7 -> type == V_25 ) {
if ( V_9 == V_115 && V_102 >= 0 &&
F_33 ( V_42 , V_102 ) ) {
F_5 ( L_51 , V_102 ) ;
return - V_94 ;
}
if ( V_7 -> type == V_25 )
V_84 = F_29 ( V_42 , V_86 , V_19 , V_101 ) ;
else
V_84 = F_28 ( V_42 , V_86 , V_19 , V_101 ) ;
if ( ! V_84 && V_9 == V_132 && V_102 >= 0 )
F_22 ( V_5 -> V_12 ,
V_102 ) ;
} else if ( V_7 -> type == V_90 ) {
enum V_8 V_122 = V_21 ;
if ( V_9 == V_115 && V_102 >= 0 &&
F_33 ( V_42 , V_102 ) ) {
F_5 ( L_52 , V_102 ) ;
return - V_94 ;
}
V_84 = F_32 ( V_42 , V_19 , V_101 , V_9 , & V_122 ) ;
if ( ! V_84 && V_9 == V_132 && V_102 >= 0 ) {
F_22 ( V_5 -> V_12 ,
V_102 ) ;
V_5 -> V_12 [ V_102 ] . type = V_122 ;
V_5 -> V_12 [ V_102 ] . V_34 = 0 ;
V_5 -> V_12 [ V_102 ] . V_35 = 0 ;
}
} else if ( V_7 -> type == V_88 || V_7 -> type == V_16 ) {
if ( V_19 >= 0 || V_19 < - V_36 ) {
F_5 ( L_53 , V_19 , V_101 ) ;
return - V_94 ;
}
if ( V_9 == V_115 ) {
if ( ! V_42 -> V_66 &&
V_5 -> V_38 [ V_36 + V_19 ] == V_39 &&
V_101 != V_37 ) {
F_5 ( L_54 ) ;
return - V_94 ;
}
V_84 = F_26 ( V_5 , V_19 , V_101 , V_102 ) ;
} else {
V_84 = F_27 ( V_5 , V_19 , V_101 , V_102 ) ;
}
} else if ( V_5 -> V_12 [ V_86 ] . type == V_18 ) {
if ( V_9 == V_115 && ! F_30 ( V_42 , NULL , V_9 ) ) {
F_5 ( L_55 ) ;
return - V_94 ;
}
if ( V_9 == V_115 && V_102 >= 0 &&
F_33 ( V_42 , V_102 ) ) {
F_5 ( L_56 , V_102 ) ;
return - V_94 ;
}
V_84 = F_31 ( V_42 , V_86 , V_19 , V_101 ) ;
if ( ! V_84 && V_9 == V_132 && V_102 >= 0 )
F_22 ( V_5 -> V_12 ,
V_102 ) ;
} else {
F_5 ( L_57 ,
V_86 , V_14 [ V_7 -> type ] ) ;
return - V_94 ;
}
if ( ! V_84 && V_101 <= 2 && V_102 >= 0 && V_42 -> V_66 &&
V_5 -> V_12 [ V_102 ] . type == V_21 ) {
V_5 -> V_12 [ V_102 ] . V_17 = 64 - V_101 * 8 ;
}
return V_84 ;
}
static int F_38 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
int V_84 ;
if ( ( F_11 ( V_44 -> V_46 ) != V_97 && F_11 ( V_44 -> V_46 ) != V_63 ) ||
V_44 -> V_17 != 0 ) {
F_5 ( L_58 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_93 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_59 , V_44 -> V_52 ) ;
return - V_94 ;
}
V_84 = F_37 ( V_42 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_132 , - 1 ) ;
if ( V_84 )
return V_84 ;
return F_37 ( V_42 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_115 , - 1 ) ;
}
static int F_39 ( struct V_41 * V_42 , int V_86 ,
int V_133 , bool V_134 ,
struct V_109 * V_110 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_19 , V_10 ;
if ( V_12 [ V_86 ] . type != V_16 ) {
if ( V_134 && V_133 == 0 &&
V_12 [ V_86 ] . type == V_15 &&
V_12 [ V_86 ] . V_17 == 0 )
return 0 ;
F_5 ( L_60 , V_86 ,
V_14 [ V_12 [ V_86 ] . type ] ,
V_14 [ V_16 ] ) ;
return - V_94 ;
}
V_19 = V_12 [ V_86 ] . V_17 ;
if ( V_19 >= 0 || V_19 < - V_36 || V_19 + V_133 > 0 ||
V_133 <= 0 ) {
F_5 ( L_61 ,
V_86 , V_19 , V_133 ) ;
return - V_94 ;
}
if ( V_110 && V_110 -> V_135 ) {
V_110 -> V_133 = V_133 ;
V_110 -> V_86 = V_86 ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_133 ; V_10 ++ ) {
if ( V_5 -> V_38 [ V_36 + V_19 + V_10 ] != V_103 ) {
F_5 ( L_62 ,
V_19 , V_10 , V_133 ) ;
return - V_94 ;
}
}
return 0 ;
}
static int F_40 ( struct V_41 * V_42 , int V_86 ,
int V_133 , bool V_134 ,
struct V_109 * V_110 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
switch ( V_12 [ V_86 ] . type ) {
case V_18 :
return F_31 ( V_42 , V_86 , 0 , V_133 ) ;
case V_23 :
return F_28 ( V_42 , V_86 , 0 , V_133 ) ;
case V_25 :
return F_29 ( V_42 , V_86 , 0 , V_133 ) ;
default:
return F_39 ( V_42 , V_86 , V_133 ,
V_134 , V_110 ) ;
}
}
static int F_41 ( struct V_41 * V_42 , V_64 V_86 ,
enum V_136 V_137 ,
struct V_109 * V_110 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 , * V_7 = & V_12 [ V_86 ] ;
enum V_8 V_138 , type = V_7 -> type ;
int V_84 = 0 ;
if ( V_137 == V_139 )
return 0 ;
if ( type == V_13 ) {
F_5 ( L_36 , V_86 ) ;
return - V_94 ;
}
if ( V_137 == V_140 ) {
if ( F_33 ( V_42 , V_86 ) ) {
F_5 ( L_63 , V_86 ) ;
return - V_94 ;
}
return 0 ;
}
if ( type == V_18 &&
! F_30 ( V_42 , V_110 , V_132 ) ) {
F_5 ( L_64 ) ;
return - V_94 ;
}
if ( V_137 == V_141 ||
V_137 == V_142 ) {
V_138 = V_16 ;
if ( type != V_18 && type != V_138 )
goto V_143;
} else if ( V_137 == V_144 ||
V_137 == V_145 ) {
V_138 = V_15 ;
if ( type != V_21 && type != V_138 )
goto V_143;
} else if ( V_137 == V_146 ) {
V_138 = V_22 ;
if ( type != V_138 )
goto V_143;
} else if ( V_137 == V_147 ) {
V_138 = V_90 ;
if ( type != V_138 )
goto V_143;
} else if ( V_137 == V_148 ||
V_137 == V_149 ) {
V_138 = V_16 ;
if ( type == V_15 && V_7 -> V_17 == 0 )
;
else if ( type != V_18 && type != V_23 &&
type != V_25 && type != V_138 )
goto V_143;
V_110 -> V_135 = V_137 == V_149 ;
} else {
F_5 ( L_65 , V_137 ) ;
return - V_150 ;
}
if ( V_137 == V_146 ) {
V_110 -> V_26 = V_7 -> V_26 ;
} else if ( V_137 == V_141 ) {
if ( ! V_110 -> V_26 ) {
F_5 ( L_66 ) ;
return - V_94 ;
}
if ( type == V_18 )
V_84 = F_31 ( V_42 , V_86 , 0 ,
V_110 -> V_26 -> V_27 ) ;
else
V_84 = F_39 ( V_42 , V_86 ,
V_110 -> V_26 -> V_27 ,
false , NULL ) ;
} else if ( V_137 == V_142 ) {
if ( ! V_110 -> V_26 ) {
F_5 ( L_67 ) ;
return - V_94 ;
}
if ( type == V_18 )
V_84 = F_31 ( V_42 , V_86 , 0 ,
V_110 -> V_26 -> V_28 ) ;
else
V_84 = F_39 ( V_42 , V_86 ,
V_110 -> V_26 -> V_28 ,
false , NULL ) ;
} else if ( V_137 == V_144 ||
V_137 == V_145 ) {
bool V_134 = ( V_137 == V_145 ) ;
if ( V_86 == 0 ) {
F_5 ( L_68 ) ;
return - V_94 ;
}
if ( type == V_21 ) {
V_110 = NULL ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_69 ,
V_86 ) ;
return - V_94 ;
}
if ( V_7 -> V_29 == 0 ) {
V_84 = F_40 ( V_42 , V_86 - 1 , 0 ,
V_134 ,
V_110 ) ;
if ( V_84 )
return V_84 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_70 ,
V_86 ) ;
return - V_94 ;
}
V_84 = F_40 ( V_42 , V_86 - 1 ,
V_7 -> V_31 ,
V_134 , V_110 ) ;
if ( V_84 )
return V_84 ;
} else {
V_84 = F_40 ( V_42 , V_86 - 1 , V_7 -> V_17 ,
V_134 , V_110 ) ;
}
}
return V_84 ;
V_143:
F_5 ( L_60 , V_86 ,
V_14 [ type ] , V_14 [ V_138 ] ) ;
return - V_94 ;
}
static int F_42 ( struct V_105 * V_106 , int V_151 )
{
if ( ! V_106 )
return 0 ;
switch ( V_106 -> V_152 ) {
case V_153 :
if ( V_151 != V_154 )
goto error;
break;
case V_155 :
if ( V_151 != V_156 &&
V_151 != V_157 )
goto error;
break;
case V_158 :
if ( V_151 != V_159 )
goto error;
break;
case V_160 :
if ( V_151 != V_161 &&
V_151 != V_162 )
goto error;
break;
case V_163 :
case V_164 :
if ( V_151 != V_165 )
goto error;
default:
break;
}
switch ( V_151 ) {
case V_154 :
if ( V_106 -> V_152 != V_153 )
goto error;
break;
case V_156 :
case V_157 :
if ( V_106 -> V_152 != V_155 )
goto error;
break;
case V_159 :
if ( V_106 -> V_152 != V_158 )
goto error;
break;
case V_162 :
case V_161 :
if ( V_106 -> V_152 != V_160 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_5 ( L_71 ,
V_106 -> V_152 , F_1 ( V_151 ) , V_151 ) ;
return - V_92 ;
}
static int F_43 ( const struct V_166 * V_167 )
{
int V_168 = 0 ;
if ( V_167 -> V_169 == V_149 )
V_168 ++ ;
if ( V_167 -> V_170 == V_149 )
V_168 ++ ;
if ( V_167 -> V_171 == V_149 )
V_168 ++ ;
if ( V_167 -> V_172 == V_149 )
V_168 ++ ;
if ( V_167 -> V_173 == V_149 )
V_168 ++ ;
return V_168 > 1 ? - V_92 : 0 ;
}
static void F_44 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 ||
V_12 [ V_10 ] . type == V_100 )
F_20 ( V_12 , V_10 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
V_7 = & V_5 -> V_40 [ V_10 / V_37 ] ;
if ( V_7 -> type != V_18 &&
V_7 -> type != V_100 )
continue;
V_7 -> type = V_21 ;
V_7 -> V_17 = 0 ;
}
}
static int F_45 ( struct V_41 * V_42 , int V_151 , int V_77 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
const struct V_166 * V_167 = NULL ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_109 V_110 ;
bool V_174 ;
int V_10 , V_84 ;
if ( V_151 < 0 || V_151 >= V_3 ) {
F_5 ( L_72 , F_1 ( V_151 ) , V_151 ) ;
return - V_92 ;
}
if ( V_42 -> V_112 -> V_124 -> V_125 -> V_175 )
V_167 = V_42 -> V_112 -> V_124 -> V_125 -> V_175 ( V_151 ) ;
if ( ! V_167 ) {
F_5 ( L_73 , F_1 ( V_151 ) , V_151 ) ;
return - V_92 ;
}
if ( ! V_42 -> V_112 -> V_176 && V_167 -> V_177 ) {
F_5 ( L_74 ) ;
return - V_92 ;
}
V_174 = F_46 ( V_167 -> V_178 ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_120 = V_167 -> V_120 ;
V_84 = F_43 ( V_167 ) ;
if ( V_84 ) {
F_5 ( L_75 ,
F_1 ( V_151 ) , V_151 ) ;
return V_84 ;
}
V_84 = F_41 ( V_42 , V_89 , V_167 -> V_169 , & V_110 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_41 ( V_42 , V_179 , V_167 -> V_170 , & V_110 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_41 ( V_42 , V_180 , V_167 -> V_171 , & V_110 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_41 ( V_42 , V_181 , V_167 -> V_172 , & V_110 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_41 ( V_42 , V_182 , V_167 -> V_173 , & V_110 ) ;
if ( V_84 )
return V_84 ;
for ( V_10 = 0 ; V_10 < V_110 . V_133 ; V_10 ++ ) {
V_84 = F_37 ( V_42 , V_110 . V_86 , V_10 , V_99 , V_115 , - 1 ) ;
if ( V_84 )
return V_84 ;
}
for ( V_10 = 0 ; V_10 < V_183 ; V_10 ++ )
F_16 ( V_12 , V_184 [ V_10 ] ) ;
if ( V_167 -> V_185 == V_186 ) {
V_12 [ V_187 ] . type = V_21 ;
} else if ( V_167 -> V_185 == V_188 ) {
V_12 [ V_187 ] . type = V_13 ;
} else if ( V_167 -> V_185 == V_189 ) {
struct V_190 * V_191 ;
V_12 [ V_187 ] . type = V_24 ;
V_12 [ V_187 ] . V_31 = V_12 [ V_187 ] . V_29 = 0 ;
if ( V_110 . V_26 == NULL ) {
F_5 ( L_76 ) ;
return - V_92 ;
}
V_12 [ V_187 ] . V_26 = V_110 . V_26 ;
V_12 [ V_187 ] . V_1 = ++ V_42 -> V_192 ;
V_191 = & V_42 -> V_193 [ V_77 ] ;
if ( ! V_191 -> V_26 )
V_191 -> V_26 = V_110 . V_26 ;
else if ( V_191 -> V_26 != V_110 . V_26 )
V_191 -> V_26 = V_194 ;
} else {
F_5 ( L_77 ,
V_167 -> V_185 , F_1 ( V_151 ) , V_151 ) ;
return - V_92 ;
}
V_84 = F_42 ( V_110 . V_26 , V_151 ) ;
if ( V_84 )
return V_84 ;
if ( V_174 )
F_44 ( V_42 ) ;
return 0 ;
}
static int F_47 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
struct V_6 V_195 ;
T_3 V_17 ;
if ( F_8 ( V_44 -> V_46 ) == V_196 ) {
V_17 = V_44 -> V_17 ;
V_197:
if ( V_17 < 0 ) {
F_5 ( L_78 ) ;
return - V_94 ;
}
if ( V_17 >= V_198 ||
V_17 + V_50 -> V_19 >= V_198 ) {
F_5 ( L_79 ,
V_17 ) ;
return - V_94 ;
}
V_50 -> V_19 += V_17 ;
} else {
bool V_199 ;
if ( V_52 -> type == V_18 ) {
V_195 = * V_50 ;
* V_50 = * V_52 ;
V_52 = & V_195 ;
}
if ( V_52 -> type == V_15 ) {
V_17 = V_52 -> V_17 ;
goto V_197;
}
if ( V_52 -> type != V_21 ) {
F_5 ( L_80 ,
V_14 [ V_52 -> type ] ) ;
return - V_94 ;
}
if ( V_52 -> V_17 < 48 ) {
F_5 ( L_81 ,
V_52 -> V_17 ) ;
return - V_94 ;
}
V_199 = ( V_50 -> V_1 != 0 ) ;
V_50 -> V_1 = ++ V_42 -> V_192 ;
V_50 -> V_34 += V_50 -> V_19 ;
V_50 -> V_19 = 0 ;
V_50 -> V_20 = 0 ;
if ( V_199 )
V_50 -> V_35 = F_48 ( V_50 -> V_35 ,
V_52 -> V_33 ) ;
else
V_50 -> V_35 = V_52 -> V_33 ;
}
return 0 ;
}
static int F_49 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
T_4 V_200 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
if ( V_52 -> type == V_21 && V_52 -> V_17 > 0 &&
V_50 -> V_17 && V_68 == V_201 ) {
V_50 -> V_17 = F_48 ( V_50 -> V_17 , V_52 -> V_17 ) ;
V_50 -> V_17 -- ;
return 0 ;
}
if ( V_52 -> type == V_15 && V_52 -> V_17 > 0 &&
V_50 -> V_17 && V_68 == V_201 ) {
V_200 = F_50 ( ( long long ) V_52 -> V_17 ) ;
V_50 -> V_17 = F_48 ( V_50 -> V_17 , 63 - V_200 ) ;
V_50 -> V_17 -- ;
return 0 ;
}
V_50 -> V_17 = 0 ;
return 0 ;
}
V_200 = F_50 ( ( long long ) V_44 -> V_17 ) ;
if ( V_50 -> V_17 && V_68 == V_202 ) {
V_50 -> V_17 -= V_44 -> V_17 ;
} else if ( V_50 -> V_17 && V_68 == V_203 ) {
V_50 -> V_17 -= V_200 + 1 ;
} else if ( V_68 == V_204 ) {
V_50 -> V_17 = 63 - V_200 ;
} else if ( V_50 -> V_17 && V_68 == V_201 ) {
V_50 -> V_17 = F_48 ( V_50 -> V_17 , 63 - V_200 ) ;
V_50 -> V_17 -- ;
} else if ( V_68 == V_205 ) {
V_50 -> V_17 += V_44 -> V_17 ;
if ( F_51 ( V_50 -> V_17 > 64 ) )
V_50 -> V_17 = 64 ;
} else {
V_50 -> V_17 = 0 ;
}
if ( V_50 -> V_17 < 0 ) {
V_50 -> V_17 = 0 ;
}
return 0 ;
}
static int F_52 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
T_2 V_206 = V_50 -> V_17 ;
if ( V_68 == V_201 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 += V_44 -> V_17 ;
} else if ( V_68 == V_201 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 += V_52 -> V_17 ;
} else if ( V_68 == V_207 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 -= V_44 -> V_17 ;
} else if ( V_68 == V_207 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 -= V_52 -> V_17 ;
} else if ( V_68 == V_203 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 *= V_44 -> V_17 ;
} else if ( V_68 == V_203 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 *= V_52 -> V_17 ;
} else if ( V_68 == V_208 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 |= V_44 -> V_17 ;
} else if ( V_68 == V_208 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 |= V_52 -> V_17 ;
} else if ( V_68 == V_204 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 &= V_44 -> V_17 ;
} else if ( V_68 == V_204 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 &= V_52 -> V_17 ;
} else if ( V_68 == V_205 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 >>= V_44 -> V_17 ;
} else if ( V_68 == V_205 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 >>= V_52 -> V_17 ;
} else if ( V_68 == V_202 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_206 <<= V_44 -> V_17 ;
} else if ( V_68 == V_202 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_206 <<= V_52 -> V_17 ;
} else {
F_20 ( V_12 , V_44 -> V_50 ) ;
goto V_209;
}
V_50 -> V_17 = V_206 ;
V_209:
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
static V_64 F_54 ( V_64 V_17 )
{
if ( ! V_17 )
return 1U << 31 ;
return V_17 - ( ( V_17 - 1 ) & V_17 ) ;
}
static void F_55 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 , * V_50 ;
T_4 V_210 = V_30 ;
T_2 V_211 = V_32 ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
V_64 V_212 , V_213 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
V_213 = 0 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
F_53 ( & V_12 [ V_44 -> V_52 ] ) ;
V_210 = V_12 [ V_44 -> V_52 ] . V_29 ;
V_211 = V_12 [ V_44 -> V_52 ] . V_31 ;
if ( V_12 [ V_44 -> V_52 ] . type != V_15 &&
V_12 [ V_44 -> V_52 ] . type != V_21 ) {
V_210 = V_30 ;
V_211 = V_32 ;
V_213 = 0 ;
} else {
V_213 = V_12 [ V_44 -> V_52 ] . V_33 ;
}
} else if ( V_44 -> V_17 < V_32 &&
( T_4 ) V_44 -> V_17 > V_30 ) {
V_210 = V_211 = V_44 -> V_17 ;
V_213 = F_54 ( V_44 -> V_17 ) ;
}
V_212 = V_50 -> V_33 ;
if ( V_210 == V_30 &&
V_211 == V_32 ) {
F_21 ( V_12 , V_44 -> V_50 ) ;
return;
}
if ( V_210 == V_30 )
V_50 -> V_29 = V_30 ;
if ( V_211 == V_32 )
V_50 -> V_31 = V_32 ;
switch ( V_68 ) {
case V_201 :
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 += V_210 ;
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 += V_211 ;
V_50 -> V_33 = F_48 ( V_213 , V_212 ) ;
break;
case V_207 :
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 -= V_210 ;
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 -= V_211 ;
V_50 -> V_33 = F_48 ( V_213 , V_212 ) ;
break;
case V_203 :
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 *= V_210 ;
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 *= V_211 ;
V_50 -> V_33 = F_56 ( V_213 , V_212 ) ;
break;
case V_204 :
if ( V_210 < 0 )
V_50 -> V_29 = V_30 ;
else
V_50 -> V_29 = 0 ;
V_50 -> V_31 = V_211 ;
V_50 -> V_33 = F_56 ( V_213 , V_212 ) ;
break;
case V_202 :
if ( V_210 > F_57 ( V_32 ) ) {
V_50 -> V_29 = V_30 ;
V_50 -> V_33 = 1 ;
} else {
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 <<= V_210 ;
if ( ! V_50 -> V_33 )
V_50 -> V_33 = 1 ;
V_50 -> V_33 <<= V_210 ;
}
if ( V_211 > F_57 ( V_32 ) )
V_50 -> V_31 = V_32 ;
else if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 <<= V_211 ;
break;
case V_205 :
if ( V_210 < 0 || V_50 -> V_29 < 0 ) {
V_50 -> V_29 = V_30 ;
} else {
V_50 -> V_29 =
( T_2 ) ( V_50 -> V_29 ) >> V_210 ;
}
if ( V_210 < 0 ) {
V_50 -> V_33 = 1 ;
} else {
V_50 -> V_33 >>= ( T_2 ) V_210 ;
if ( ! V_50 -> V_33 )
V_50 -> V_33 = 1 ;
}
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 >>= V_211 ;
break;
default:
F_21 ( V_12 , V_44 -> V_50 ) ;
break;
}
F_53 ( V_50 ) ;
}
static int F_58 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 , * V_50 ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
int V_84 ;
if ( V_68 == V_214 || V_68 == V_215 ) {
if ( V_68 == V_215 ) {
if ( F_8 ( V_44 -> V_46 ) != 0 ||
V_44 -> V_52 != V_187 ||
V_44 -> V_19 != 0 || V_44 -> V_17 != 0 ) {
F_5 ( L_82 ) ;
return - V_92 ;
}
} else {
if ( V_44 -> V_52 != V_187 || V_44 -> V_19 != 0 ||
( V_44 -> V_17 != 16 && V_44 -> V_17 != 32 && V_44 -> V_17 != 64 ) ) {
F_5 ( L_83 ) ;
return - V_92 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_93 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_84 ,
V_44 -> V_50 ) ;
return - V_94 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_95 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_68 == V_216 ) {
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_17 != 0 || V_44 -> V_19 != 0 ) {
F_5 ( L_85 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
} else {
if ( V_44 -> V_52 != V_187 || V_44 -> V_19 != 0 ) {
F_5 ( L_85 ) ;
return - V_92 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_95 ) ;
if ( V_84 )
return V_84 ;
F_21 ( V_12 , V_44 -> V_50 ) ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( F_7 ( V_44 -> V_46 ) == V_48 ) {
V_12 [ V_44 -> V_50 ] = V_12 [ V_44 -> V_52 ] ;
} else {
if ( F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_86 ,
V_44 -> V_52 ) ;
return - V_94 ;
}
F_20 ( V_12 , V_44 -> V_50 ) ;
}
} else {
V_12 [ V_44 -> V_50 ] . type = V_15 ;
V_12 [ V_44 -> V_50 ] . V_17 = V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . V_31 = V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . V_29 = V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . V_33 = F_54 ( V_44 -> V_17 ) ;
}
} else if ( V_68 > V_214 ) {
F_5 ( L_87 , V_68 ) ;
return - V_92 ;
} else {
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_17 != 0 || V_44 -> V_19 != 0 ) {
F_5 ( L_88 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
} else {
if ( V_44 -> V_52 != V_187 || V_44 -> V_19 != 0 ) {
F_5 ( L_88 ) ;
return - V_92 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_93 ) ;
if ( V_84 )
return V_84 ;
if ( ( V_68 == V_217 || V_68 == V_218 ) &&
F_8 ( V_44 -> V_46 ) == V_196 && V_44 -> V_17 == 0 ) {
F_5 ( L_89 ) ;
return - V_92 ;
}
if ( ( V_68 == V_202 || V_68 == V_205 ||
V_68 == V_219 ) && F_8 ( V_44 -> V_46 ) == V_196 ) {
int V_101 = F_7 ( V_44 -> V_46 ) == V_48 ? 64 : 32 ;
if ( V_44 -> V_17 < 0 || V_44 -> V_17 >= V_101 ) {
F_5 ( L_90 , V_44 -> V_17 ) ;
return - V_92 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_220 ) ;
if ( V_84 )
return V_84 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
F_55 ( V_42 , V_44 ) ;
if ( V_68 == V_201 && F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_88 && F_8 ( V_44 -> V_46 ) == V_196 ) {
V_50 -> type = V_16 ;
V_50 -> V_17 = V_44 -> V_17 ;
return 0 ;
} else if ( V_68 == V_201 &&
F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_16 &&
( ( F_8 ( V_44 -> V_46 ) == V_49 &&
V_12 [ V_44 -> V_52 ] . type == V_15 ) ||
F_8 ( V_44 -> V_46 ) == V_196 ) ) {
if ( F_8 ( V_44 -> V_46 ) == V_49 )
V_50 -> V_17 += V_12 [ V_44 -> V_52 ] . V_17 ;
else
V_50 -> V_17 += V_44 -> V_17 ;
return 0 ;
} else if ( V_68 == V_201 &&
F_7 ( V_44 -> V_46 ) == V_48 &&
( V_50 -> type == V_18 ||
( F_8 ( V_44 -> V_46 ) == V_49 &&
V_12 [ V_44 -> V_52 ] . type == V_18 ) ) ) {
return F_47 ( V_42 , V_44 ) ;
} else if ( F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_21 &&
V_42 -> V_66 ) {
return F_49 ( V_42 , V_44 ) ;
} else if ( F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_15 &&
V_42 -> V_66 ) {
return F_52 ( V_42 , V_44 ) ;
} else if ( F_33 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_84 ,
V_44 -> V_50 ) ;
return - V_94 ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 &&
F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_84 ,
V_44 -> V_52 ) ;
return - V_94 ;
}
if ( V_42 -> V_66 &&
F_7 ( V_44 -> V_46 ) == V_48 && V_68 == V_201 &&
( V_50 -> type == V_23 ||
V_50 -> type == V_25 ) )
V_50 -> type = V_25 ;
else
F_20 ( V_12 , V_44 -> V_50 ) ;
}
return 0 ;
}
static void F_59 ( struct V_4 * V_5 ,
struct V_6 * V_50 )
{
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 && V_12 [ V_10 ] . V_1 == V_50 -> V_1 )
V_12 [ V_10 ] . V_20 = F_56 ( V_12 [ V_10 ] . V_20 , V_50 -> V_19 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
V_7 = & V_5 -> V_40 [ V_10 / V_37 ] ;
if ( V_7 -> type == V_18 && V_7 -> V_1 == V_50 -> V_1 )
V_7 -> V_20 = F_56 ( V_7 -> V_20 , V_50 -> V_19 ) ;
}
}
static void F_60 ( struct V_6 * V_221 ,
struct V_6 * V_222 , T_2 V_223 ,
T_1 V_68 )
{
switch ( V_68 ) {
case V_224 :
V_221 -> V_31 = V_221 -> V_29 = V_223 ;
break;
case V_225 :
V_222 -> V_31 = V_222 -> V_29 = V_223 ;
break;
case V_226 :
V_222 -> V_29 = 0 ;
case V_227 :
V_222 -> V_31 = V_223 ;
V_221 -> V_29 = V_223 + 1 ;
break;
case V_228 :
V_222 -> V_29 = 0 ;
case V_229 :
V_222 -> V_31 = V_223 - 1 ;
V_221 -> V_29 = V_223 ;
break;
default:
break;
}
F_53 ( V_222 ) ;
F_53 ( V_221 ) ;
}
static void F_61 ( struct V_6 * V_221 ,
struct V_6 * V_222 , T_2 V_223 ,
T_1 V_68 )
{
switch ( V_68 ) {
case V_224 :
V_221 -> V_31 = V_221 -> V_29 = V_223 ;
break;
case V_225 :
V_222 -> V_31 = V_222 -> V_29 = V_223 ;
break;
case V_226 :
V_221 -> V_29 = 0 ;
case V_227 :
V_222 -> V_29 = V_223 ;
V_221 -> V_31 = V_223 - 1 ;
break;
case V_228 :
V_221 -> V_29 = 0 ;
case V_229 :
V_222 -> V_29 = V_223 + 1 ;
V_221 -> V_31 = V_223 ;
break;
default:
break;
}
F_53 ( V_222 ) ;
F_53 ( V_221 ) ;
}
static void F_62 ( struct V_6 * V_12 , V_64 V_86 , V_64 V_1 ,
enum V_8 type )
{
struct V_6 * V_7 = & V_12 [ V_86 ] ;
if ( V_7 -> type == V_24 && V_7 -> V_1 == V_1 ) {
if ( type == V_21 ) {
F_19 ( V_12 , V_86 ) ;
} else if ( V_7 -> V_26 -> V_230 ) {
V_7 -> type = V_22 ;
V_7 -> V_26 = V_7 -> V_26 -> V_230 ;
} else {
V_7 -> type = type ;
}
V_7 -> V_1 = 0 ;
}
}
static void F_63 ( struct V_4 * V_5 , V_64 V_86 ,
enum V_8 type )
{
struct V_6 * V_12 = V_5 -> V_12 ;
V_64 V_1 = V_12 [ V_86 ] . V_1 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_62 ( V_12 , V_10 , V_1 , type ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
F_62 ( V_5 -> V_40 , V_10 / V_37 , V_1 , type ) ;
}
}
static int F_64 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int * V_77 )
{
struct V_4 * V_231 , * V_232 = & V_42 -> V_79 ;
struct V_6 * V_12 = V_232 -> V_12 , * V_50 ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
int V_84 ;
if ( V_68 > V_71 ) {
F_5 ( L_91 , V_68 ) ;
return - V_92 ;
}
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_17 != 0 ) {
F_5 ( L_92 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_93 ,
V_44 -> V_52 ) ;
return - V_94 ;
}
} else {
if ( V_44 -> V_52 != V_187 ) {
F_5 ( L_92 ) ;
return - V_92 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_93 ) ;
if ( V_84 )
return V_84 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
if ( F_8 ( V_44 -> V_46 ) == V_196 &&
( V_68 == V_224 || V_68 == V_225 ) &&
V_50 -> type == V_15 && V_50 -> V_17 == V_44 -> V_17 ) {
if ( V_68 == V_224 ) {
* V_77 += V_44 -> V_19 ;
return 0 ;
} else {
return 0 ;
}
}
V_231 = F_14 ( V_42 , * V_77 + V_44 -> V_19 + 1 , * V_77 ) ;
if ( ! V_231 )
return - V_150 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_12 [ V_44 -> V_52 ] . type == V_15 )
F_60 ( & V_231 -> V_12 [ V_44 -> V_50 ] ,
V_50 , V_12 [ V_44 -> V_52 ] . V_17 ,
V_68 ) ;
else if ( V_50 -> type == V_15 )
F_61 ( & V_231 -> V_12 [ V_44 -> V_52 ] ,
& V_12 [ V_44 -> V_52 ] , V_50 -> V_17 ,
V_68 ) ;
} else {
F_60 ( & V_231 -> V_12 [ V_44 -> V_50 ] ,
V_50 , V_44 -> V_17 , V_68 ) ;
}
if ( F_8 ( V_44 -> V_46 ) == V_196 &&
V_44 -> V_17 == 0 && ( V_68 == V_224 || V_68 == V_225 ) &&
V_50 -> type == V_24 ) {
F_63 ( V_232 , V_44 -> V_50 ,
V_68 == V_224 ? V_23 : V_21 ) ;
F_63 ( V_231 , V_44 -> V_50 ,
V_68 == V_224 ? V_21 : V_23 ) ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 && V_68 == V_226 &&
V_50 -> type == V_18 &&
V_12 [ V_44 -> V_52 ] . type == V_100 ) {
F_59 ( V_232 , V_50 ) ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 && V_68 == V_228 &&
V_50 -> type == V_100 &&
V_12 [ V_44 -> V_52 ] . type == V_18 ) {
F_59 ( V_231 , & V_12 [ V_44 -> V_52 ] ) ;
} else if ( F_33 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_93 , V_44 -> V_50 ) ;
return - V_94 ;
}
if ( V_107 )
F_4 ( V_232 ) ;
return 0 ;
}
static struct V_105 * F_65 ( struct V_43 * V_44 )
{
T_2 V_233 = ( ( T_2 ) ( V_64 ) V_44 [ 0 ] . V_17 ) | ( ( T_2 ) ( V_64 ) V_44 [ 1 ] . V_17 ) << 32 ;
return (struct V_105 * ) ( unsigned long ) V_233 ;
}
static int F_66 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
int V_84 ;
if ( F_11 ( V_44 -> V_46 ) != V_63 ) {
F_5 ( L_94 ) ;
return - V_92 ;
}
if ( V_44 -> V_19 != 0 ) {
F_5 ( L_95 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_95 ) ;
if ( V_84 )
return V_84 ;
if ( V_44 -> V_52 == 0 ) {
T_2 V_17 = ( ( T_2 ) ( V_44 + 1 ) -> V_17 << 32 ) | ( V_64 ) V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . type = V_15 ;
V_12 [ V_44 -> V_50 ] . V_17 = V_17 ;
return 0 ;
}
F_17 ( V_44 -> V_52 != V_65 ) ;
V_12 [ V_44 -> V_50 ] . type = V_22 ;
V_12 [ V_44 -> V_50 ] . V_26 = F_65 ( V_44 ) ;
return 0 ;
}
static bool F_67 ( enum V_234 type )
{
switch ( type ) {
case V_235 :
case V_116 :
case V_117 :
return true ;
default:
return false ;
}
}
static int F_68 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
T_1 V_236 = F_10 ( V_44 -> V_46 ) ;
int V_10 , V_84 ;
if ( ! F_67 ( V_42 -> V_112 -> type ) ) {
F_5 ( L_96 ) ;
return - V_92 ;
}
if ( V_44 -> V_50 != V_187 || V_44 -> V_19 != 0 ||
F_11 ( V_44 -> V_46 ) == V_63 ||
( V_236 == V_60 && V_44 -> V_52 != V_187 ) ) {
F_5 ( L_97 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_237 , V_93 ) ;
if ( V_84 )
return V_84 ;
if ( V_12 [ V_237 ] . type != V_90 ) {
F_5 ( L_98 ) ;
return - V_92 ;
}
if ( V_236 == V_61 ) {
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
}
for ( V_10 = 0 ; V_10 < V_183 ; V_10 ++ )
F_16 ( V_12 , V_184 [ V_10 ] ) ;
V_12 [ V_187 ] . type = V_21 ;
return 0 ;
}
static int F_69 ( int V_9 , int V_238 , int V_239 , struct V_41 * V_42 )
{
if ( V_239 == V_240 && V_241 [ V_9 ] >= ( V_242 | V_240 ) )
return 0 ;
if ( V_239 == V_243 && V_241 [ V_9 ] >= ( V_242 | V_243 ) )
return 0 ;
if ( V_238 < 0 || V_238 >= V_42 -> V_112 -> V_244 ) {
F_5 ( L_99 , V_9 , V_238 ) ;
return - V_92 ;
}
if ( V_239 == V_243 )
V_42 -> V_245 [ V_238 ] = V_246 ;
if ( V_241 [ V_238 ] == 0 ) {
V_241 [ V_9 ] = V_242 | V_239 ;
V_241 [ V_238 ] = V_242 ;
if ( V_247 >= V_42 -> V_112 -> V_244 )
return - V_248 ;
V_249 [ V_247 ++ ] = V_238 ;
return 1 ;
} else if ( ( V_241 [ V_238 ] & 0xF0 ) == V_242 ) {
F_5 ( L_100 , V_9 , V_238 ) ;
return - V_92 ;
} else if ( V_241 [ V_238 ] == V_250 ) {
V_241 [ V_9 ] = V_242 | V_239 ;
} else {
F_5 ( L_101 ) ;
return - V_150 ;
}
return 0 ;
}
static int F_70 ( struct V_41 * V_42 )
{
struct V_43 * V_251 = V_42 -> V_112 -> V_252 ;
int V_253 = V_42 -> V_112 -> V_244 ;
int V_254 = 0 ;
int V_10 , V_9 ;
V_241 = F_71 ( V_253 , sizeof( int ) , V_83 ) ;
if ( ! V_241 )
return - V_255 ;
V_249 = F_71 ( V_253 , sizeof( int ) , V_83 ) ;
if ( ! V_249 ) {
F_13 ( V_241 ) ;
return - V_255 ;
}
V_241 [ 0 ] = V_242 ;
V_249 [ 0 ] = 0 ;
V_247 = 1 ;
V_256:
if ( V_247 == 0 )
goto V_257;
V_9 = V_249 [ V_247 - 1 ] ;
if ( F_7 ( V_251 [ V_9 ] . V_46 ) == V_67 ) {
T_1 V_68 = F_9 ( V_251 [ V_9 ] . V_46 ) ;
if ( V_68 == V_71 ) {
goto V_258;
} else if ( V_68 == V_69 ) {
V_254 = F_69 ( V_9 , V_9 + 1 , V_240 , V_42 ) ;
if ( V_254 == 1 )
goto V_256;
else if ( V_254 < 0 )
goto V_259;
if ( V_9 + 1 < V_253 )
V_42 -> V_245 [ V_9 + 1 ] = V_246 ;
} else if ( V_68 == V_70 ) {
if ( F_8 ( V_251 [ V_9 ] . V_46 ) != V_196 ) {
V_254 = - V_92 ;
goto V_259;
}
V_254 = F_69 ( V_9 , V_9 + V_251 [ V_9 ] . V_19 + 1 ,
V_240 , V_42 ) ;
if ( V_254 == 1 )
goto V_256;
else if ( V_254 < 0 )
goto V_259;
if ( V_9 + 1 < V_253 )
V_42 -> V_245 [ V_9 + 1 ] = V_246 ;
} else {
V_42 -> V_245 [ V_9 ] = V_246 ;
V_254 = F_69 ( V_9 , V_9 + 1 , V_240 , V_42 ) ;
if ( V_254 == 1 )
goto V_256;
else if ( V_254 < 0 )
goto V_259;
V_254 = F_69 ( V_9 , V_9 + V_251 [ V_9 ] . V_19 + 1 , V_243 , V_42 ) ;
if ( V_254 == 1 )
goto V_256;
else if ( V_254 < 0 )
goto V_259;
}
} else {
V_254 = F_69 ( V_9 , V_9 + 1 , V_240 , V_42 ) ;
if ( V_254 == 1 )
goto V_256;
else if ( V_254 < 0 )
goto V_259;
}
V_258:
V_241 [ V_9 ] = V_250 ;
if ( V_247 -- <= 0 ) {
F_5 ( L_102 ) ;
V_254 = - V_150 ;
goto V_259;
}
goto V_256;
V_257:
for ( V_10 = 0 ; V_10 < V_253 ; V_10 ++ ) {
if ( V_241 [ V_10 ] != V_250 ) {
F_5 ( L_103 , V_10 ) ;
V_254 = - V_92 ;
goto V_259;
}
}
V_254 = 0 ;
V_259:
F_13 ( V_241 ) ;
F_13 ( V_249 ) ;
return V_254 ;
}
static bool F_72 ( struct V_41 * V_42 ,
struct V_6 * V_260 ,
struct V_6 * V_261 )
{
if ( V_260 -> V_1 != V_261 -> V_1 )
return false ;
if ( V_260 -> V_19 == V_261 -> V_19 && V_260 -> V_20 < V_261 -> V_20 )
return true ;
if ( ! V_42 -> V_131 && V_260 -> V_19 <= V_261 -> V_19 &&
V_260 -> V_19 >= V_260 -> V_20 && V_261 -> V_19 >= V_261 -> V_20 )
return true ;
return false ;
}
static bool F_73 ( struct V_41 * V_42 ,
struct V_4 * V_260 ,
struct V_4 * V_261 )
{
bool V_262 = V_42 -> V_108 ;
struct V_6 * V_263 , * V_264 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_263 = & V_260 -> V_12 [ V_10 ] ;
V_264 = & V_261 -> V_12 [ V_10 ] ;
if ( memcmp ( V_263 , V_264 , sizeof( * V_263 ) ) == 0 )
continue;
if ( ! V_262 &&
memcmp ( V_263 , V_264 , F_74 ( struct V_6 , V_1 ) ) == 0 )
continue;
if ( V_263 -> type == V_13 ||
( ! V_262 && V_263 -> type == V_21 &&
V_264 -> type != V_13 ) )
continue;
if ( V_263 -> type == V_24 &&
V_264 -> type == V_24 &&
V_263 -> V_26 == V_264 -> V_26 )
continue;
if ( V_263 -> type == V_18 && V_264 -> type == V_18 &&
F_72 ( V_42 , V_263 , V_264 ) )
continue;
return false ;
}
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
if ( V_260 -> V_38 [ V_10 ] == V_265 )
continue;
if ( V_260 -> V_38 [ V_10 ] != V_261 -> V_38 [ V_10 ] )
return false ;
if ( V_10 % V_37 )
continue;
if ( memcmp ( & V_260 -> V_40 [ V_10 / V_37 ] ,
& V_261 -> V_40 [ V_10 / V_37 ] ,
sizeof( V_260 -> V_40 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_75 ( struct V_41 * V_42 , int V_77 )
{
struct V_266 * V_267 ;
struct V_266 * V_268 ;
V_268 = V_42 -> V_245 [ V_77 ] ;
if ( ! V_268 )
return 0 ;
while ( V_268 != V_246 ) {
if ( F_73 ( V_42 , & V_268 -> V_5 , & V_42 -> V_79 ) )
return 1 ;
V_268 = V_268 -> V_81 ;
}
V_267 = F_15 ( sizeof( struct V_266 ) , V_269 ) ;
if ( ! V_267 )
return - V_255 ;
memcpy ( & V_267 -> V_5 , & V_42 -> V_79 , sizeof( V_42 -> V_79 ) ) ;
V_267 -> V_81 = V_42 -> V_245 [ V_77 ] ;
V_42 -> V_245 [ V_77 ] = V_267 ;
return 0 ;
}
static int F_76 ( struct V_41 * V_42 ,
int V_77 , int V_74 )
{
if ( ! V_42 -> V_123 || ! V_42 -> V_123 -> V_270 )
return 0 ;
return V_42 -> V_123 -> V_270 ( V_42 , V_77 , V_74 ) ;
}
static int F_77 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_43 * V_251 = V_42 -> V_112 -> V_252 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_253 = V_42 -> V_112 -> V_244 ;
int V_77 , V_74 = 0 ;
int V_271 = 0 ;
bool V_272 = false ;
F_18 ( V_12 ) ;
V_77 = 0 ;
V_42 -> V_108 = false ;
for (; ; ) {
struct V_43 * V_44 ;
T_1 V_45 ;
int V_84 ;
if ( V_77 >= V_253 ) {
F_5 ( L_104 ,
V_77 , V_253 ) ;
return - V_150 ;
}
V_44 = & V_251 [ V_77 ] ;
V_45 = F_7 ( V_44 -> V_46 ) ;
if ( ++ V_271 > V_273 ) {
F_5 ( L_105 ,
V_271 ) ;
return - V_248 ;
}
V_84 = F_75 ( V_42 , V_77 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( V_84 == 1 ) {
if ( V_107 ) {
if ( V_272 )
F_5 ( L_106 ,
V_74 , V_77 ) ;
else
F_5 ( L_107 , V_77 ) ;
}
goto V_274;
}
if ( F_78 () )
F_79 () ;
if ( V_107 > 1 || ( V_107 && V_272 ) ) {
if ( V_107 > 1 )
F_5 ( L_108 , V_77 ) ;
else
F_5 ( L_109 ,
V_74 , V_77 ) ;
F_4 ( & V_42 -> V_79 ) ;
V_272 = false ;
}
if ( V_107 ) {
F_5 ( L_110 , V_77 ) ;
F_6 ( V_42 , V_44 ) ;
}
V_84 = F_76 ( V_42 , V_77 , V_74 ) ;
if ( V_84 )
return V_84 ;
if ( V_45 == V_47 || V_45 == V_48 ) {
V_84 = F_58 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_45 == V_58 ) {
enum V_8 * V_275 , V_276 ;
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_220 ) ;
if ( V_84 )
return V_84 ;
V_276 = V_12 [ V_44 -> V_52 ] . type ;
V_84 = F_37 ( V_42 , V_44 -> V_52 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_132 ,
V_44 -> V_50 ) ;
if ( V_84 )
return V_84 ;
if ( F_11 ( V_44 -> V_46 ) != V_97 &&
F_11 ( V_44 -> V_46 ) != V_63 ) {
V_77 ++ ;
continue;
}
V_275 = & V_42 -> V_193 [ V_77 ] . V_277 ;
if ( * V_275 == V_13 ) {
* V_275 = V_276 ;
} else if ( V_276 != * V_275 &&
( V_276 == V_90 ||
* V_275 == V_90 ) ) {
F_5 ( L_111 ) ;
return - V_92 ;
}
} else if ( V_45 == V_53 ) {
enum V_8 * V_278 , V_279 ;
if ( F_10 ( V_44 -> V_46 ) == V_56 ) {
V_84 = F_38 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
V_77 ++ ;
continue;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_93 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_93 ) ;
if ( V_84 )
return V_84 ;
V_279 = V_12 [ V_44 -> V_50 ] . type ;
V_84 = F_37 ( V_42 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_115 ,
V_44 -> V_52 ) ;
if ( V_84 )
return V_84 ;
V_278 = & V_42 -> V_193 [ V_77 ] . V_277 ;
if ( * V_278 == V_13 ) {
* V_278 = V_279 ;
} else if ( V_279 != * V_278 &&
( V_279 == V_90 ||
* V_278 == V_90 ) ) {
F_5 ( L_111 ) ;
return - V_92 ;
}
} else if ( V_45 == V_57 ) {
if ( F_10 ( V_44 -> V_46 ) != V_54 ||
V_44 -> V_52 != V_187 ) {
F_5 ( L_112 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_93 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_37 ( V_42 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_115 ,
- 1 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_45 == V_67 ) {
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
if ( V_68 == V_69 ) {
if ( F_8 ( V_44 -> V_46 ) != V_196 ||
V_44 -> V_19 != 0 ||
V_44 -> V_52 != V_187 ||
V_44 -> V_50 != V_187 ) {
F_5 ( L_113 ) ;
return - V_92 ;
}
V_84 = F_45 ( V_42 , V_44 -> V_17 , V_77 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_68 == V_70 ) {
if ( F_8 ( V_44 -> V_46 ) != V_196 ||
V_44 -> V_17 != 0 ||
V_44 -> V_52 != V_187 ||
V_44 -> V_50 != V_187 ) {
F_5 ( L_114 ) ;
return - V_92 ;
}
V_77 += V_44 -> V_19 + 1 ;
continue;
} else if ( V_68 == V_71 ) {
if ( F_8 ( V_44 -> V_46 ) != V_196 ||
V_44 -> V_17 != 0 ||
V_44 -> V_52 != V_187 ||
V_44 -> V_50 != V_187 ) {
F_5 ( L_115 ) ;
return - V_92 ;
}
V_84 = F_23 ( V_12 , V_187 , V_93 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_187 ) ) {
F_5 ( L_116 ) ;
return - V_94 ;
}
V_274:
V_77 = F_12 ( V_42 , & V_74 ) ;
if ( V_77 < 0 ) {
break;
} else {
V_272 = true ;
continue;
}
} else {
V_84 = F_64 ( V_42 , V_44 , & V_77 ) ;
if ( V_84 )
return V_84 ;
}
} else if ( V_45 == V_59 ) {
T_1 V_236 = F_10 ( V_44 -> V_46 ) ;
if ( V_236 == V_60 || V_236 == V_61 ) {
V_84 = F_68 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_236 == V_62 ) {
V_84 = F_66 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
V_77 ++ ;
} else {
F_5 ( L_117 ) ;
return - V_92 ;
}
F_21 ( V_12 , V_44 -> V_50 ) ;
} else {
F_5 ( L_118 , V_45 ) ;
return - V_92 ;
}
V_77 ++ ;
}
F_5 ( L_119 , V_271 ) ;
return 0 ;
}
static int F_80 ( struct V_105 * V_106 )
{
return ( V_106 -> V_152 != V_280 &&
V_106 -> V_152 != V_281 &&
V_106 -> V_152 != V_164 ) ||
! ( V_106 -> V_282 & V_283 ) ;
}
static int F_81 ( struct V_105 * V_106 ,
struct V_284 * V_112 )
{
if ( V_112 -> type == V_285 ) {
if ( ! F_80 ( V_106 ) ) {
F_5 ( L_120 ) ;
return - V_92 ;
}
if ( V_106 -> V_230 &&
! F_80 ( V_106 -> V_230 ) ) {
F_5 ( L_121 ) ;
return - V_92 ;
}
}
return 0 ;
}
static int F_82 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_112 -> V_252 ;
int V_253 = V_42 -> V_112 -> V_244 ;
int V_10 , V_286 , V_84 ;
V_84 = F_83 ( V_42 -> V_112 ) ;
if ( V_84 )
return V_84 ;
for ( V_10 = 0 ; V_10 < V_253 ; V_10 ++ , V_44 ++ ) {
if ( F_7 ( V_44 -> V_46 ) == V_58 &&
( F_10 ( V_44 -> V_46 ) != V_54 || V_44 -> V_17 != 0 ) ) {
F_5 ( L_122 ) ;
return - V_92 ;
}
if ( F_7 ( V_44 -> V_46 ) == V_53 &&
( ( F_10 ( V_44 -> V_46 ) != V_54 &&
F_10 ( V_44 -> V_46 ) != V_56 ) || V_44 -> V_17 != 0 ) ) {
F_5 ( L_123 ) ;
return - V_92 ;
}
if ( V_44 [ 0 ] . V_46 == ( V_59 | V_62 | V_63 ) ) {
struct V_105 * V_106 ;
struct V_287 V_288 ;
if ( V_10 == V_253 - 1 || V_44 [ 1 ] . V_46 != 0 ||
V_44 [ 1 ] . V_50 != 0 || V_44 [ 1 ] . V_52 != 0 ||
V_44 [ 1 ] . V_19 != 0 ) {
F_5 ( L_124 ) ;
return - V_92 ;
}
if ( V_44 -> V_52 == 0 )
goto V_289;
if ( V_44 -> V_52 != V_65 ) {
F_5 ( L_125 ) ;
return - V_92 ;
}
V_288 = F_84 ( V_44 -> V_17 ) ;
V_106 = F_85 ( V_288 ) ;
if ( F_86 ( V_106 ) ) {
F_5 ( L_126 ,
V_44 -> V_17 ) ;
return F_87 ( V_106 ) ;
}
V_84 = F_81 ( V_106 , V_42 -> V_112 ) ;
if ( V_84 ) {
F_88 ( V_288 ) ;
return V_84 ;
}
V_44 [ 0 ] . V_17 = ( V_64 ) ( unsigned long ) V_106 ;
V_44 [ 1 ] . V_17 = ( ( T_2 ) ( unsigned long ) V_106 ) >> 32 ;
for ( V_286 = 0 ; V_286 < V_42 -> V_290 ; V_286 ++ )
if ( V_42 -> V_291 [ V_286 ] == V_106 ) {
F_88 ( V_288 ) ;
goto V_289;
}
if ( V_42 -> V_290 >= V_292 ) {
F_88 ( V_288 ) ;
return - V_248 ;
}
V_106 = F_89 ( V_106 , false ) ;
if ( F_86 ( V_106 ) ) {
F_88 ( V_288 ) ;
return F_87 ( V_106 ) ;
}
V_42 -> V_291 [ V_42 -> V_290 ++ ] = V_106 ;
F_88 ( V_288 ) ;
V_289:
V_44 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_90 ( struct V_41 * V_42 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_42 -> V_290 ; V_10 ++ )
F_91 ( V_42 -> V_291 [ V_10 ] ) ;
}
static void F_92 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_112 -> V_252 ;
int V_253 = V_42 -> V_112 -> V_244 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_253 ; V_10 ++ , V_44 ++ )
if ( V_44 -> V_46 == ( V_59 | V_62 | V_63 ) )
V_44 -> V_52 = 0 ;
}
static int F_93 ( struct V_41 * V_42 , V_64 V_293 ,
V_64 V_19 , V_64 V_294 )
{
struct V_190 * V_295 , * V_296 = V_42 -> V_193 ;
if ( V_294 == 1 )
return 0 ;
V_295 = F_94 ( sizeof( struct V_190 ) * V_293 ) ;
if ( ! V_295 )
return - V_255 ;
memcpy ( V_295 , V_296 , sizeof( struct V_190 ) * V_19 ) ;
memcpy ( V_295 + V_19 + V_294 - 1 , V_296 + V_19 ,
sizeof( struct V_190 ) * ( V_293 - V_19 - V_294 + 1 ) ) ;
V_42 -> V_193 = V_295 ;
F_95 ( V_296 ) ;
return 0 ;
}
static struct V_284 * F_96 ( struct V_41 * V_42 , V_64 V_19 ,
const struct V_43 * V_297 , V_64 V_244 )
{
struct V_284 * V_298 ;
V_298 = F_97 ( V_42 -> V_112 , V_19 , V_297 , V_244 ) ;
if ( ! V_298 )
return NULL ;
if ( F_93 ( V_42 , V_298 -> V_244 , V_19 , V_244 ) )
return NULL ;
return V_298 ;
}
static int F_98 ( struct V_41 * V_42 )
{
const struct V_299 * V_125 = V_42 -> V_112 -> V_124 -> V_125 ;
const int V_253 = V_42 -> V_112 -> V_244 ;
struct V_43 V_300 [ 16 ] , * V_44 ;
struct V_284 * V_298 ;
enum V_111 type ;
int V_10 , V_294 , V_301 = 0 ;
if ( V_125 -> V_302 ) {
V_294 = V_125 -> V_302 ( V_300 , V_42 -> V_121 ,
V_42 -> V_112 ) ;
if ( V_294 >= F_3 ( V_300 ) ) {
F_5 ( L_127 ) ;
return - V_92 ;
} else if ( V_294 ) {
V_298 = F_96 ( V_42 , 0 , V_300 , V_294 ) ;
if ( ! V_298 )
return - V_255 ;
V_42 -> V_112 = V_298 ;
V_301 += V_294 - 1 ;
}
}
if ( ! V_125 -> V_303 )
return 0 ;
V_44 = V_42 -> V_112 -> V_252 + V_301 ;
for ( V_10 = 0 ; V_10 < V_253 ; V_10 ++ , V_44 ++ ) {
if ( V_44 -> V_46 == ( V_58 | V_54 | V_99 ) ||
V_44 -> V_46 == ( V_58 | V_54 | V_98 ) ||
V_44 -> V_46 == ( V_58 | V_54 | V_97 ) ||
V_44 -> V_46 == ( V_58 | V_54 | V_63 ) )
type = V_132 ;
else if ( V_44 -> V_46 == ( V_53 | V_54 | V_99 ) ||
V_44 -> V_46 == ( V_53 | V_54 | V_98 ) ||
V_44 -> V_46 == ( V_53 | V_54 | V_97 ) ||
V_44 -> V_46 == ( V_53 | V_54 | V_63 ) )
type = V_115 ;
else
continue;
if ( V_42 -> V_193 [ V_10 + V_301 ] . V_277 != V_90 )
continue;
V_294 = V_125 -> V_303 ( type , V_44 , V_300 , V_42 -> V_112 ) ;
if ( V_294 == 0 || V_294 >= F_3 ( V_300 ) ) {
F_5 ( L_127 ) ;
return - V_92 ;
}
V_298 = F_96 ( V_42 , V_10 + V_301 , V_300 , V_294 ) ;
if ( ! V_298 )
return - V_255 ;
V_301 += V_294 - 1 ;
V_42 -> V_112 = V_298 ;
V_44 = V_298 -> V_252 + V_10 + V_301 ;
}
return 0 ;
}
static int F_99 ( struct V_41 * V_42 )
{
struct V_284 * V_112 = V_42 -> V_112 ;
struct V_43 * V_44 = V_112 -> V_252 ;
const struct V_166 * V_167 ;
const int V_253 = V_112 -> V_244 ;
struct V_43 V_300 [ 16 ] ;
struct V_284 * V_298 ;
struct V_105 * V_26 ;
int V_10 , V_294 , V_301 = 0 ;
for ( V_10 = 0 ; V_10 < V_253 ; V_10 ++ , V_44 ++ ) {
if ( V_44 -> V_46 != ( V_67 | V_69 ) )
continue;
if ( V_44 -> V_17 == V_304 )
V_112 -> V_305 = 1 ;
if ( V_44 -> V_17 == V_306 )
F_100 () ;
if ( V_44 -> V_17 == V_154 ) {
V_112 -> V_307 = 1 ;
V_44 -> V_17 = 0 ;
V_44 -> V_46 |= V_49 ;
continue;
}
if ( F_101 () && V_44 -> V_17 == V_165 ) {
V_26 = V_42 -> V_193 [ V_10 + V_301 ] . V_26 ;
if ( V_26 == V_194 ||
! V_26 -> V_125 -> V_308 )
goto V_309;
V_294 = V_26 -> V_125 -> V_308 ( V_26 , V_300 ) ;
if ( V_294 == 0 || V_294 >= F_3 ( V_300 ) ) {
F_5 ( L_127 ) ;
return - V_92 ;
}
V_298 = F_96 ( V_42 , V_10 + V_301 , V_300 ,
V_294 ) ;
if ( ! V_298 )
return - V_255 ;
V_301 += V_294 - 1 ;
V_42 -> V_112 = V_112 = V_298 ;
V_44 = V_298 -> V_252 + V_10 + V_301 ;
continue;
}
V_309:
V_167 = V_112 -> V_124 -> V_125 -> V_175 ( V_44 -> V_17 ) ;
if ( ! V_167 -> V_178 ) {
F_5 ( L_75 ,
F_1 ( V_44 -> V_17 ) , V_44 -> V_17 ) ;
return - V_150 ;
}
V_44 -> V_17 = V_167 -> V_178 - V_310 ;
}
return 0 ;
}
static void F_102 ( struct V_41 * V_42 )
{
struct V_266 * V_268 , * V_311 ;
int V_10 ;
if ( ! V_42 -> V_245 )
return;
for ( V_10 = 0 ; V_10 < V_42 -> V_112 -> V_244 ; V_10 ++ ) {
V_268 = V_42 -> V_245 [ V_10 ] ;
if ( V_268 )
while ( V_268 != V_246 ) {
V_311 = V_268 -> V_81 ;
F_13 ( V_268 ) ;
V_268 = V_311 ;
}
}
F_13 ( V_42 -> V_245 ) ;
}
int F_103 ( struct V_284 * * V_112 , union V_312 * V_313 )
{
char T_5 * V_314 = NULL ;
struct V_41 * V_42 ;
int V_254 = - V_92 ;
V_42 = F_104 ( sizeof( struct V_41 ) , V_83 ) ;
if ( ! V_42 )
return - V_255 ;
V_42 -> V_193 = F_94 ( sizeof( struct V_190 ) *
( * V_112 ) -> V_244 ) ;
V_254 = - V_255 ;
if ( ! V_42 -> V_193 )
goto V_315;
V_42 -> V_112 = * V_112 ;
F_105 ( & V_316 ) ;
if ( V_313 -> V_107 || V_313 -> V_317 || V_313 -> V_318 ) {
V_107 = V_313 -> V_107 ;
V_314 = ( char T_5 * ) ( unsigned long ) V_313 -> V_317 ;
V_318 = V_313 -> V_318 ;
V_319 = 0 ;
V_254 = - V_92 ;
if ( V_318 < 128 || V_318 > V_320 >> 8 ||
V_107 == 0 || V_314 == NULL )
goto V_321;
V_254 = - V_255 ;
V_317 = F_106 ( V_318 ) ;
if ( ! V_317 )
goto V_321;
} else {
V_107 = 0 ;
}
V_42 -> V_131 = ! ! ( V_313 -> V_322 & V_323 ) ;
if ( ! F_107 ( V_324 ) )
V_42 -> V_131 = true ;
V_254 = F_82 ( V_42 ) ;
if ( V_254 < 0 )
goto V_325;
V_42 -> V_245 = F_71 ( V_42 -> V_112 -> V_244 ,
sizeof( struct V_266 * ) ,
V_269 ) ;
V_254 = - V_255 ;
if ( ! V_42 -> V_245 )
goto V_325;
V_254 = F_70 ( V_42 ) ;
if ( V_254 < 0 )
goto V_325;
V_42 -> V_66 = F_108 ( V_326 ) ;
V_254 = F_77 ( V_42 ) ;
V_325:
while ( F_12 ( V_42 , NULL ) >= 0 ) ;
F_102 ( V_42 ) ;
if ( V_254 == 0 )
V_254 = F_98 ( V_42 ) ;
if ( V_254 == 0 )
V_254 = F_99 ( V_42 ) ;
if ( V_107 && V_319 >= V_318 - 1 ) {
F_17 ( V_319 >= V_318 ) ;
V_254 = - V_327 ;
}
if ( V_107 && F_109 ( V_314 , V_317 , V_319 + 1 ) != 0 ) {
V_254 = - V_150 ;
goto V_328;
}
if ( V_254 == 0 && V_42 -> V_290 ) {
V_42 -> V_112 -> V_124 -> V_291 = F_110 ( V_42 -> V_290 ,
sizeof( V_42 -> V_291 [ 0 ] ) ,
V_83 ) ;
if ( ! V_42 -> V_112 -> V_124 -> V_291 ) {
V_254 = - V_255 ;
goto V_328;
}
memcpy ( V_42 -> V_112 -> V_124 -> V_291 , V_42 -> V_291 ,
sizeof( V_42 -> V_291 [ 0 ] ) * V_42 -> V_290 ) ;
V_42 -> V_112 -> V_124 -> V_290 = V_42 -> V_290 ;
F_92 ( V_42 ) ;
}
V_328:
if ( V_107 )
F_95 ( V_317 ) ;
if ( ! V_42 -> V_112 -> V_124 -> V_291 )
F_90 ( V_42 ) ;
* V_112 = V_42 -> V_112 ;
V_321:
F_111 ( & V_316 ) ;
F_95 ( V_42 -> V_193 ) ;
V_315:
F_13 ( V_42 ) ;
return V_254 ;
}
int F_112 ( struct V_284 * V_112 , const struct V_329 * V_125 ,
void * V_330 )
{
struct V_41 * V_42 ;
int V_254 ;
V_42 = F_104 ( sizeof( struct V_41 ) , V_83 ) ;
if ( ! V_42 )
return - V_255 ;
V_42 -> V_193 = F_94 ( sizeof( struct V_190 ) *
V_112 -> V_244 ) ;
V_254 = - V_255 ;
if ( ! V_42 -> V_193 )
goto V_315;
V_42 -> V_112 = V_112 ;
V_42 -> V_123 = V_125 ;
V_42 -> V_331 = V_330 ;
F_105 ( & V_316 ) ;
V_107 = 0 ;
V_42 -> V_131 = false ;
if ( ! F_107 ( V_324 ) )
V_42 -> V_131 = true ;
V_42 -> V_245 = F_71 ( V_42 -> V_112 -> V_244 ,
sizeof( struct V_266 * ) ,
V_83 ) ;
V_254 = - V_255 ;
if ( ! V_42 -> V_245 )
goto V_325;
V_254 = F_70 ( V_42 ) ;
if ( V_254 < 0 )
goto V_325;
V_42 -> V_66 = F_108 ( V_326 ) ;
V_254 = F_77 ( V_42 ) ;
V_325:
while ( F_12 ( V_42 , NULL ) >= 0 ) ;
F_102 ( V_42 ) ;
F_111 ( & V_316 ) ;
F_95 ( V_42 -> V_193 ) ;
V_315:
F_13 ( V_42 ) ;
return V_254 ;
}
