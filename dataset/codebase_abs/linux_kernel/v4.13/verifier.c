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
V_12 [ V_86 ] . V_91 = false ;
V_12 [ V_86 ] . V_33 = 0 ;
}
static void F_22 ( struct V_6 * V_12 ,
V_64 V_86 )
{
F_20 ( V_12 , V_86 ) ;
F_21 ( V_12 , V_86 ) ;
}
static int F_23 ( struct V_6 * V_12 , V_64 V_86 ,
enum V_92 V_9 )
{
if ( V_86 >= V_11 ) {
F_5 ( L_35 , V_86 ) ;
return - V_93 ;
}
if ( V_9 == V_94 ) {
if ( V_12 [ V_86 ] . type == V_13 ) {
F_5 ( L_36 , V_86 ) ;
return - V_95 ;
}
} else {
if ( V_86 == V_87 ) {
F_5 ( L_37 ) ;
return - V_95 ;
}
if ( V_9 == V_96 )
F_20 ( V_12 , V_86 ) ;
}
return 0 ;
}
static bool F_24 ( enum V_8 type )
{
switch ( type ) {
case V_23 :
case V_24 :
case V_25 :
case V_16 :
case V_90 :
case V_18 :
case V_97 :
case V_88 :
case V_22 :
return true ;
default:
return false ;
}
}
static int F_25 ( struct V_4 * V_5 , int V_19 ,
int V_98 , int V_99 )
{
int V_10 ;
if ( V_99 >= 0 &&
F_24 ( V_5 -> V_12 [ V_99 ] . type ) ) {
if ( V_98 != V_37 ) {
F_5 ( L_38 ) ;
return - V_95 ;
}
V_5 -> V_40 [ ( V_36 + V_19 ) / V_37 ] =
V_5 -> V_12 [ V_99 ] ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ )
V_5 -> V_38 [ V_36 + V_19 + V_10 ] = V_39 ;
} else {
V_5 -> V_40 [ ( V_36 + V_19 ) / V_37 ] =
(struct V_6 ) {} ;
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ )
V_5 -> V_38 [ V_36 + V_19 + V_10 ] = V_100 ;
}
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , int V_19 , int V_98 ,
int V_99 )
{
T_1 * V_101 ;
int V_10 ;
V_101 = & V_5 -> V_38 [ V_36 + V_19 ] ;
if ( V_101 [ 0 ] == V_39 ) {
if ( V_98 != V_37 ) {
F_5 ( L_38 ) ;
return - V_95 ;
}
for ( V_10 = 1 ; V_10 < V_37 ; V_10 ++ ) {
if ( V_101 [ V_10 ] != V_39 ) {
F_5 ( L_39 ) ;
return - V_95 ;
}
}
if ( V_99 >= 0 )
V_5 -> V_12 [ V_99 ] =
V_5 -> V_40 [ ( V_36 + V_19 ) / V_37 ] ;
return 0 ;
} else {
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ ) {
if ( V_101 [ V_10 ] != V_100 ) {
F_5 ( L_40 ,
V_19 , V_10 , V_98 ) ;
return - V_95 ;
}
}
if ( V_99 >= 0 )
F_22 ( V_5 -> V_12 ,
V_99 ) ;
return 0 ;
}
}
static int F_27 ( struct V_41 * V_42 , V_64 V_86 , int V_19 ,
int V_98 )
{
struct V_102 * V_103 = V_42 -> V_79 . V_12 [ V_86 ] . V_26 ;
if ( V_19 < 0 || V_98 <= 0 || V_19 + V_98 > V_103 -> V_28 ) {
F_5 ( L_41 ,
V_103 -> V_28 , V_19 , V_98 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_28 ( struct V_41 * V_42 , V_64 V_86 ,
int V_19 , int V_98 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_86 ] ;
int V_84 ;
if ( V_104 )
F_4 ( V_5 ) ;
V_42 -> V_105 = true ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_42 ,
V_86 ) ;
return - V_95 ;
}
V_84 = F_27 ( V_42 , V_86 , V_7 -> V_29 + V_19 , V_98 ) ;
if ( V_84 ) {
F_5 ( L_43 ,
V_86 ) ;
return V_84 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_44 ,
V_86 ) ;
return - V_95 ;
}
return F_27 ( V_42 , V_86 , V_7 -> V_31 + V_19 , V_98 ) ;
}
static bool F_29 ( struct V_41 * V_42 ,
const struct V_106 * V_107 ,
enum V_108 V_9 )
{
switch ( V_42 -> V_109 -> type ) {
case V_110 :
case V_111 :
if ( V_9 == V_112 )
return false ;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
if ( V_107 )
return V_107 -> V_117 ;
V_42 -> V_118 = true ;
return true ;
default:
return false ;
}
}
static int F_30 ( struct V_41 * V_42 , V_64 V_86 , int V_19 ,
int V_98 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_7 = & V_12 [ V_86 ] ;
V_19 += V_7 -> V_19 ;
if ( V_19 < 0 || V_98 <= 0 || V_19 + V_98 > V_7 -> V_20 ) {
F_5 ( L_45 ,
V_19 , V_98 , V_86 , V_7 -> V_1 , V_7 -> V_19 , V_7 -> V_20 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_31 ( struct V_41 * V_42 , int V_77 , int V_19 , int V_98 ,
enum V_108 V_9 , enum V_8 * V_119 )
{
struct V_120 V_121 = {
. V_119 = * V_119 ,
} ;
if ( V_42 -> V_122 )
return 0 ;
if ( V_42 -> V_109 -> V_123 -> V_124 -> V_125 &&
V_42 -> V_109 -> V_123 -> V_124 -> V_125 ( V_19 , V_98 , V_9 , & V_121 ) ) {
V_42 -> V_126 [ V_77 ] . V_127 = V_121 . V_127 ;
* V_119 = V_121 . V_119 ;
if ( V_42 -> V_109 -> V_123 -> V_128 < V_19 + V_98 )
V_42 -> V_109 -> V_123 -> V_128 = V_19 + V_98 ;
return 0 ;
}
F_5 ( L_46 , V_19 , V_98 ) ;
return - V_95 ;
}
static bool F_32 ( bool V_66 ,
const struct V_6 * V_7 )
{
if ( V_66 )
return false ;
switch ( V_7 -> type ) {
case V_21 :
case V_15 :
return false ;
default:
return true ;
}
}
static bool F_33 ( struct V_41 * V_42 , int V_86 )
{
return F_32 ( V_42 -> V_66 , & V_42 -> V_79 . V_12 [ V_86 ] ) ;
}
static int F_34 ( const struct V_6 * V_7 ,
int V_19 , int V_98 , bool V_129 )
{
int V_130 ;
int V_131 ;
if ( ! V_129 || V_98 == 1 )
return 0 ;
V_131 = V_7 -> V_19 ;
if ( V_7 -> V_1 ) {
if ( V_7 -> V_35 % V_98 ) {
F_5 ( L_47 ,
V_7 -> V_35 , V_98 ) ;
return - V_95 ;
}
V_131 += V_7 -> V_34 ;
}
V_130 = 2 ;
if ( ( V_130 + V_131 + V_19 ) % V_98 != 0 ) {
F_5 ( L_48 ,
V_130 , V_131 , V_19 , V_98 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_35 ( const struct V_6 * V_7 ,
int V_98 , bool V_129 )
{
if ( V_129 && V_98 != 1 ) {
F_5 ( L_49 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_36 ( struct V_41 * V_42 ,
const struct V_6 * V_7 ,
int V_19 , int V_98 )
{
bool V_129 = V_42 -> V_132 ;
switch ( V_7 -> type ) {
case V_18 :
return F_34 ( V_7 , V_19 , V_98 , V_129 ) ;
case V_25 :
return F_35 ( V_7 , V_98 , V_129 ) ;
default:
if ( V_19 % V_98 != 0 ) {
F_5 ( L_50 ,
V_19 , V_98 ) ;
return - V_95 ;
}
return 0 ;
}
}
static int F_37 ( struct V_41 * V_42 , int V_77 , V_64 V_86 , int V_19 ,
int V_133 , enum V_108 V_9 ,
int V_99 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_86 ] ;
int V_98 , V_84 = 0 ;
if ( V_7 -> type == V_16 )
V_19 += V_7 -> V_17 ;
V_98 = F_38 ( V_133 ) ;
if ( V_98 < 0 )
return V_98 ;
V_84 = F_36 ( V_42 , V_7 , V_19 , V_98 ) ;
if ( V_84 )
return V_84 ;
if ( V_7 -> type == V_23 ||
V_7 -> type == V_25 ) {
if ( V_9 == V_112 && V_99 >= 0 &&
F_33 ( V_42 , V_99 ) ) {
F_5 ( L_51 , V_99 ) ;
return - V_95 ;
}
if ( V_7 -> type == V_25 )
V_84 = F_28 ( V_42 , V_86 , V_19 , V_98 ) ;
else
V_84 = F_27 ( V_42 , V_86 , V_19 , V_98 ) ;
if ( ! V_84 && V_9 == V_134 && V_99 >= 0 )
F_22 ( V_5 -> V_12 ,
V_99 ) ;
} else if ( V_7 -> type == V_90 ) {
enum V_8 V_119 = V_21 ;
if ( V_9 == V_112 && V_99 >= 0 &&
F_33 ( V_42 , V_99 ) ) {
F_5 ( L_52 , V_99 ) ;
return - V_95 ;
}
V_84 = F_31 ( V_42 , V_77 , V_19 , V_98 , V_9 , & V_119 ) ;
if ( ! V_84 && V_9 == V_134 && V_99 >= 0 ) {
F_22 ( V_5 -> V_12 ,
V_99 ) ;
V_5 -> V_12 [ V_99 ] . type = V_119 ;
V_5 -> V_12 [ V_99 ] . V_34 = 0 ;
V_5 -> V_12 [ V_99 ] . V_35 = 0 ;
}
} else if ( V_7 -> type == V_88 || V_7 -> type == V_16 ) {
if ( V_19 >= 0 || V_19 < - V_36 ) {
F_5 ( L_53 , V_19 , V_98 ) ;
return - V_95 ;
}
if ( V_42 -> V_109 -> V_123 -> V_135 < - V_19 )
V_42 -> V_109 -> V_123 -> V_135 = - V_19 ;
if ( V_9 == V_112 ) {
if ( ! V_42 -> V_66 &&
V_5 -> V_38 [ V_36 + V_19 ] == V_39 &&
V_98 != V_37 ) {
F_5 ( L_54 ) ;
return - V_95 ;
}
V_84 = F_25 ( V_5 , V_19 , V_98 , V_99 ) ;
} else {
V_84 = F_26 ( V_5 , V_19 , V_98 , V_99 ) ;
}
} else if ( V_5 -> V_12 [ V_86 ] . type == V_18 ) {
if ( V_9 == V_112 && ! F_29 ( V_42 , NULL , V_9 ) ) {
F_5 ( L_55 ) ;
return - V_95 ;
}
if ( V_9 == V_112 && V_99 >= 0 &&
F_33 ( V_42 , V_99 ) ) {
F_5 ( L_56 , V_99 ) ;
return - V_95 ;
}
V_84 = F_30 ( V_42 , V_86 , V_19 , V_98 ) ;
if ( ! V_84 && V_9 == V_134 && V_99 >= 0 )
F_22 ( V_5 -> V_12 ,
V_99 ) ;
} else {
F_5 ( L_57 ,
V_86 , V_14 [ V_7 -> type ] ) ;
return - V_95 ;
}
if ( ! V_84 && V_98 <= 2 && V_99 >= 0 && V_42 -> V_66 &&
V_5 -> V_12 [ V_99 ] . type == V_21 ) {
V_5 -> V_12 [ V_99 ] . V_17 = 64 - V_98 * 8 ;
}
return V_84 ;
}
static int F_39 ( struct V_41 * V_42 , int V_77 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
int V_84 ;
if ( ( F_11 ( V_44 -> V_46 ) != V_136 && F_11 ( V_44 -> V_46 ) != V_63 ) ||
V_44 -> V_17 != 0 ) {
F_5 ( L_58 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_94 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_59 , V_44 -> V_52 ) ;
return - V_95 ;
}
V_84 = F_37 ( V_42 , V_77 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_134 , - 1 ) ;
if ( V_84 )
return V_84 ;
return F_37 ( V_42 , V_77 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_112 , - 1 ) ;
}
static int F_40 ( struct V_41 * V_42 , int V_86 ,
int V_137 , bool V_138 ,
struct V_106 * V_107 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_19 , V_10 ;
if ( V_12 [ V_86 ] . type != V_16 ) {
if ( V_138 && V_137 == 0 &&
V_12 [ V_86 ] . type == V_15 &&
V_12 [ V_86 ] . V_17 == 0 )
return 0 ;
F_5 ( L_60 , V_86 ,
V_14 [ V_12 [ V_86 ] . type ] ,
V_14 [ V_16 ] ) ;
return - V_95 ;
}
V_19 = V_12 [ V_86 ] . V_17 ;
if ( V_19 >= 0 || V_19 < - V_36 || V_19 + V_137 > 0 ||
V_137 <= 0 ) {
F_5 ( L_61 ,
V_86 , V_19 , V_137 ) ;
return - V_95 ;
}
if ( V_42 -> V_109 -> V_123 -> V_135 < - V_19 )
V_42 -> V_109 -> V_123 -> V_135 = - V_19 ;
if ( V_107 && V_107 -> V_139 ) {
V_107 -> V_137 = V_137 ;
V_107 -> V_86 = V_86 ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_137 ; V_10 ++ ) {
if ( V_5 -> V_38 [ V_36 + V_19 + V_10 ] != V_100 ) {
F_5 ( L_62 ,
V_19 , V_10 , V_137 ) ;
return - V_95 ;
}
}
return 0 ;
}
static int F_41 ( struct V_41 * V_42 , int V_86 ,
int V_137 , bool V_138 ,
struct V_106 * V_107 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
switch ( V_12 [ V_86 ] . type ) {
case V_18 :
return F_30 ( V_42 , V_86 , 0 , V_137 ) ;
case V_23 :
return F_27 ( V_42 , V_86 , 0 , V_137 ) ;
case V_25 :
return F_28 ( V_42 , V_86 , 0 , V_137 ) ;
default:
return F_40 ( V_42 , V_86 , V_137 ,
V_138 , V_107 ) ;
}
}
static int F_42 ( struct V_41 * V_42 , V_64 V_86 ,
enum V_140 V_141 ,
struct V_106 * V_107 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 , * V_7 = & V_12 [ V_86 ] ;
enum V_8 V_142 , type = V_7 -> type ;
int V_84 = 0 ;
if ( V_141 == V_143 )
return 0 ;
if ( type == V_13 ) {
F_5 ( L_36 , V_86 ) ;
return - V_95 ;
}
if ( V_141 == V_144 ) {
if ( F_33 ( V_42 , V_86 ) ) {
F_5 ( L_63 , V_86 ) ;
return - V_95 ;
}
return 0 ;
}
if ( type == V_18 &&
! F_29 ( V_42 , V_107 , V_134 ) ) {
F_5 ( L_64 ) ;
return - V_95 ;
}
if ( V_141 == V_145 ||
V_141 == V_146 ) {
V_142 = V_16 ;
if ( type != V_18 && type != V_142 )
goto V_147;
} else if ( V_141 == V_148 ||
V_141 == V_149 ) {
V_142 = V_15 ;
if ( type != V_21 && type != V_142 )
goto V_147;
} else if ( V_141 == V_150 ) {
V_142 = V_22 ;
if ( type != V_142 )
goto V_147;
} else if ( V_141 == V_151 ) {
V_142 = V_90 ;
if ( type != V_142 )
goto V_147;
} else if ( V_141 == V_152 ||
V_141 == V_153 ) {
V_142 = V_16 ;
if ( type == V_15 && V_7 -> V_17 == 0 )
;
else if ( type != V_18 && type != V_23 &&
type != V_25 && type != V_142 )
goto V_147;
V_107 -> V_139 = V_141 == V_153 ;
} else {
F_5 ( L_65 , V_141 ) ;
return - V_154 ;
}
if ( V_141 == V_150 ) {
V_107 -> V_26 = V_7 -> V_26 ;
} else if ( V_141 == V_145 ) {
if ( ! V_107 -> V_26 ) {
F_5 ( L_66 ) ;
return - V_95 ;
}
if ( type == V_18 )
V_84 = F_30 ( V_42 , V_86 , 0 ,
V_107 -> V_26 -> V_27 ) ;
else
V_84 = F_40 ( V_42 , V_86 ,
V_107 -> V_26 -> V_27 ,
false , NULL ) ;
} else if ( V_141 == V_146 ) {
if ( ! V_107 -> V_26 ) {
F_5 ( L_67 ) ;
return - V_95 ;
}
if ( type == V_18 )
V_84 = F_30 ( V_42 , V_86 , 0 ,
V_107 -> V_26 -> V_28 ) ;
else
V_84 = F_40 ( V_42 , V_86 ,
V_107 -> V_26 -> V_28 ,
false , NULL ) ;
} else if ( V_141 == V_148 ||
V_141 == V_149 ) {
bool V_138 = ( V_141 == V_149 ) ;
if ( V_86 == 0 ) {
F_5 ( L_68 ) ;
return - V_95 ;
}
if ( type == V_21 ) {
V_107 = NULL ;
if ( V_7 -> V_29 < 0 ) {
F_5 ( L_69 ,
V_86 ) ;
return - V_95 ;
}
if ( V_7 -> V_29 == 0 ) {
V_84 = F_41 ( V_42 , V_86 - 1 , 0 ,
V_138 ,
V_107 ) ;
if ( V_84 )
return V_84 ;
}
if ( V_7 -> V_31 == V_32 ) {
F_5 ( L_70 ,
V_86 ) ;
return - V_95 ;
}
V_84 = F_41 ( V_42 , V_86 - 1 ,
V_7 -> V_31 ,
V_138 , V_107 ) ;
if ( V_84 )
return V_84 ;
} else {
V_84 = F_41 ( V_42 , V_86 - 1 , V_7 -> V_17 ,
V_138 , V_107 ) ;
}
}
return V_84 ;
V_147:
F_5 ( L_60 , V_86 ,
V_14 [ type ] , V_14 [ V_142 ] ) ;
return - V_95 ;
}
static int F_43 ( struct V_102 * V_103 , int V_155 )
{
if ( ! V_103 )
return 0 ;
switch ( V_103 -> V_156 ) {
case V_157 :
if ( V_155 != V_158 )
goto error;
break;
case V_159 :
if ( V_155 != V_160 &&
V_155 != V_161 )
goto error;
break;
case V_162 :
if ( V_155 != V_163 )
goto error;
break;
case V_164 :
if ( V_155 != V_165 &&
V_155 != V_166 )
goto error;
break;
case V_167 :
case V_168 :
if ( V_155 != V_169 )
goto error;
default:
break;
}
switch ( V_155 ) {
case V_158 :
if ( V_103 -> V_156 != V_157 )
goto error;
break;
case V_160 :
case V_161 :
if ( V_103 -> V_156 != V_159 )
goto error;
break;
case V_163 :
if ( V_103 -> V_156 != V_162 )
goto error;
break;
case V_166 :
case V_165 :
if ( V_103 -> V_156 != V_164 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_5 ( L_71 ,
V_103 -> V_156 , F_1 ( V_155 ) , V_155 ) ;
return - V_93 ;
}
static int F_44 ( const struct V_170 * V_171 )
{
int V_172 = 0 ;
if ( V_171 -> V_173 == V_153 )
V_172 ++ ;
if ( V_171 -> V_174 == V_153 )
V_172 ++ ;
if ( V_171 -> V_175 == V_153 )
V_172 ++ ;
if ( V_171 -> V_176 == V_153 )
V_172 ++ ;
if ( V_171 -> V_177 == V_153 )
V_172 ++ ;
return V_172 > 1 ? - V_93 : 0 ;
}
static void F_45 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 ||
V_12 [ V_10 ] . type == V_97 )
F_20 ( V_12 , V_10 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
V_7 = & V_5 -> V_40 [ V_10 / V_37 ] ;
if ( V_7 -> type != V_18 &&
V_7 -> type != V_97 )
continue;
F_19 ( V_5 -> V_40 ,
V_10 / V_37 ) ;
}
}
static int F_46 ( struct V_41 * V_42 , int V_155 , int V_77 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
const struct V_170 * V_171 = NULL ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_106 V_107 ;
bool V_178 ;
int V_10 , V_84 ;
if ( V_155 < 0 || V_155 >= V_3 ) {
F_5 ( L_72 , F_1 ( V_155 ) , V_155 ) ;
return - V_93 ;
}
if ( V_42 -> V_109 -> V_123 -> V_124 -> V_179 )
V_171 = V_42 -> V_109 -> V_123 -> V_124 -> V_179 ( V_155 ) ;
if ( ! V_171 ) {
F_5 ( L_73 , F_1 ( V_155 ) , V_155 ) ;
return - V_93 ;
}
if ( ! V_42 -> V_109 -> V_180 && V_171 -> V_181 ) {
F_5 ( L_74 ) ;
return - V_93 ;
}
V_178 = F_47 ( V_171 -> V_182 ) ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_117 = V_171 -> V_117 ;
V_84 = F_44 ( V_171 ) ;
if ( V_84 ) {
F_5 ( L_75 ,
F_1 ( V_155 ) , V_155 ) ;
return V_84 ;
}
V_84 = F_42 ( V_42 , V_89 , V_171 -> V_173 , & V_107 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_42 ( V_42 , V_183 , V_171 -> V_174 , & V_107 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_42 ( V_42 , V_184 , V_171 -> V_175 , & V_107 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_42 ( V_42 , V_185 , V_171 -> V_176 , & V_107 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_42 ( V_42 , V_186 , V_171 -> V_177 , & V_107 ) ;
if ( V_84 )
return V_84 ;
for ( V_10 = 0 ; V_10 < V_107 . V_137 ; V_10 ++ ) {
V_84 = F_37 ( V_42 , V_77 , V_107 . V_86 , V_10 , V_187 , V_112 , - 1 ) ;
if ( V_84 )
return V_84 ;
}
for ( V_10 = 0 ; V_10 < V_188 ; V_10 ++ )
F_16 ( V_12 , V_189 [ V_10 ] ) ;
if ( V_171 -> V_190 == V_191 ) {
V_12 [ V_192 ] . type = V_21 ;
} else if ( V_171 -> V_190 == V_193 ) {
V_12 [ V_192 ] . type = V_13 ;
} else if ( V_171 -> V_190 == V_194 ) {
struct V_195 * V_196 ;
V_12 [ V_192 ] . type = V_24 ;
V_12 [ V_192 ] . V_31 = V_12 [ V_192 ] . V_29 = 0 ;
if ( V_107 . V_26 == NULL ) {
F_5 ( L_76 ) ;
return - V_93 ;
}
V_12 [ V_192 ] . V_26 = V_107 . V_26 ;
V_12 [ V_192 ] . V_1 = ++ V_42 -> V_197 ;
V_196 = & V_42 -> V_126 [ V_77 ] ;
if ( ! V_196 -> V_26 )
V_196 -> V_26 = V_107 . V_26 ;
else if ( V_196 -> V_26 != V_107 . V_26 )
V_196 -> V_26 = V_198 ;
} else {
F_5 ( L_77 ,
V_171 -> V_190 , F_1 ( V_155 ) , V_155 ) ;
return - V_93 ;
}
V_84 = F_43 ( V_107 . V_26 , V_155 ) ;
if ( V_84 )
return V_84 ;
if ( V_178 )
F_45 ( V_42 ) ;
return 0 ;
}
static int F_48 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
struct V_6 V_199 ;
T_3 V_17 ;
if ( F_8 ( V_44 -> V_46 ) == V_200 ) {
V_17 = V_44 -> V_17 ;
V_201:
if ( V_17 < 0 ) {
F_5 ( L_78 ) ;
return - V_95 ;
}
if ( V_17 >= V_202 ||
V_17 + V_50 -> V_19 >= V_202 ) {
F_5 ( L_79 ,
V_17 ) ;
return - V_95 ;
}
V_50 -> V_19 += V_17 ;
} else {
bool V_203 ;
if ( V_52 -> type == V_18 ) {
V_199 = * V_50 ;
* V_50 = * V_52 ;
V_52 = & V_199 ;
}
if ( V_52 -> type == V_15 ) {
V_17 = V_52 -> V_17 ;
goto V_201;
}
if ( V_52 -> type != V_21 ) {
F_5 ( L_80 ,
V_14 [ V_52 -> type ] ) ;
return - V_95 ;
}
if ( V_52 -> V_17 < 48 ) {
F_5 ( L_81 ,
V_52 -> V_17 ) ;
return - V_95 ;
}
V_203 = ( V_50 -> V_1 != 0 ) ;
V_50 -> V_1 = ++ V_42 -> V_197 ;
V_50 -> V_34 += V_50 -> V_19 ;
V_50 -> V_19 = 0 ;
V_50 -> V_20 = 0 ;
if ( V_203 )
V_50 -> V_35 = F_49 ( V_50 -> V_35 ,
V_52 -> V_33 ) ;
else
V_50 -> V_35 = V_52 -> V_33 ;
}
return 0 ;
}
static int F_50 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
T_4 V_204 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
if ( V_52 -> type == V_21 && V_52 -> V_17 > 0 &&
V_50 -> V_17 && V_68 == V_205 ) {
V_50 -> V_17 = F_49 ( V_50 -> V_17 , V_52 -> V_17 ) ;
V_50 -> V_17 -- ;
return 0 ;
}
if ( V_52 -> type == V_15 && V_52 -> V_17 > 0 &&
V_50 -> V_17 && V_68 == V_205 ) {
V_204 = F_51 ( ( long long ) V_52 -> V_17 ) ;
V_50 -> V_17 = F_49 ( V_50 -> V_17 , 63 - V_204 ) ;
V_50 -> V_17 -- ;
return 0 ;
}
V_50 -> V_17 = 0 ;
return 0 ;
}
V_204 = F_51 ( ( long long ) V_44 -> V_17 ) ;
if ( V_50 -> V_17 && V_68 == V_206 ) {
V_50 -> V_17 -= V_44 -> V_17 ;
} else if ( V_50 -> V_17 && V_68 == V_207 ) {
V_50 -> V_17 -= V_204 + 1 ;
} else if ( V_68 == V_208 ) {
V_50 -> V_17 = 63 - V_204 ;
} else if ( V_50 -> V_17 && V_68 == V_205 ) {
V_50 -> V_17 = F_49 ( V_50 -> V_17 , 63 - V_204 ) ;
V_50 -> V_17 -- ;
} else if ( V_68 == V_209 ) {
V_50 -> V_17 += V_44 -> V_17 ;
if ( F_52 ( V_50 -> V_17 > 64 ) )
V_50 -> V_17 = 64 ;
} else {
V_50 -> V_17 = 0 ;
}
if ( V_50 -> V_17 < 0 ) {
V_50 -> V_17 = 0 ;
}
return 0 ;
}
static int F_53 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
T_4 V_204 = F_51 ( ( long long ) V_50 -> V_17 ) ;
if ( V_52 -> V_17 > 0 && V_50 -> V_17 ) {
switch ( V_68 ) {
case V_205 :
V_50 -> V_17 = F_49 ( V_52 -> V_17 , 63 - V_204 ) ;
V_50 -> V_17 -- ;
break;
case V_208 :
V_50 -> V_17 = F_54 ( V_52 -> V_17 , 63 - V_204 ) ;
break;
case V_210 :
V_50 -> V_17 = F_49 ( V_52 -> V_17 , 63 - V_204 ) ;
break;
case V_211 :
case V_207 :
case V_209 :
case V_206 :
default:
F_20 ( V_12 , V_44 -> V_50 ) ;
}
} else {
F_20 ( V_12 , V_44 -> V_50 ) ;
}
V_50 -> type = V_21 ;
return 0 ;
}
static int F_55 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
struct V_6 * V_50 = & V_12 [ V_44 -> V_50 ] ;
struct V_6 * V_52 = & V_12 [ V_44 -> V_52 ] ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
T_2 V_212 = V_50 -> V_17 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 && V_52 -> type == V_21 )
return F_53 ( V_42 , V_44 ) ;
if ( V_68 == V_205 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 += V_44 -> V_17 ;
} else if ( V_68 == V_205 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 += V_52 -> V_17 ;
} else if ( V_68 == V_211 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 -= V_44 -> V_17 ;
} else if ( V_68 == V_211 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 -= V_52 -> V_17 ;
} else if ( V_68 == V_207 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 *= V_44 -> V_17 ;
} else if ( V_68 == V_207 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 *= V_52 -> V_17 ;
} else if ( V_68 == V_210 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 |= V_44 -> V_17 ;
} else if ( V_68 == V_210 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 |= V_52 -> V_17 ;
} else if ( V_68 == V_208 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 &= V_44 -> V_17 ;
} else if ( V_68 == V_208 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 &= V_52 -> V_17 ;
} else if ( V_68 == V_209 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 >>= V_44 -> V_17 ;
} else if ( V_68 == V_209 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 >>= V_52 -> V_17 ;
} else if ( V_68 == V_206 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_212 <<= V_44 -> V_17 ;
} else if ( V_68 == V_206 && F_8 ( V_44 -> V_46 ) == V_49 &&
V_52 -> type == V_15 ) {
V_212 <<= V_52 -> V_17 ;
} else {
F_20 ( V_12 , V_44 -> V_50 ) ;
goto V_213;
}
V_50 -> V_17 = V_212 ;
V_213:
return 0 ;
}
static void F_56 ( struct V_6 * V_7 )
{
if ( V_7 -> V_31 > V_32 )
V_7 -> V_31 = V_32 ;
if ( V_7 -> V_29 < V_30 ||
V_7 -> V_29 > V_32 )
V_7 -> V_29 = V_30 ;
}
static V_64 F_57 ( V_64 V_17 )
{
if ( ! V_17 )
return 1U << 31 ;
return V_17 - ( ( V_17 - 1 ) & V_17 ) ;
}
static void F_58 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 , * V_50 ;
T_4 V_214 = V_30 ;
T_2 V_215 = V_32 ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
V_64 V_216 , V_217 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
V_217 = 0 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
F_56 ( & V_12 [ V_44 -> V_52 ] ) ;
V_214 = V_12 [ V_44 -> V_52 ] . V_29 ;
V_215 = V_12 [ V_44 -> V_52 ] . V_31 ;
if ( V_12 [ V_44 -> V_52 ] . type != V_15 &&
V_12 [ V_44 -> V_52 ] . type != V_21 ) {
V_214 = V_30 ;
V_215 = V_32 ;
V_217 = 0 ;
} else {
V_217 = V_12 [ V_44 -> V_52 ] . V_33 ;
}
} else if ( V_44 -> V_17 < V_32 &&
( T_4 ) V_44 -> V_17 > V_30 ) {
V_214 = V_215 = V_44 -> V_17 ;
V_217 = F_57 ( V_44 -> V_17 ) ;
}
V_216 = V_50 -> V_33 ;
if ( ( V_214 == V_30 &&
V_215 == V_32 ) ||
( F_8 ( V_44 -> V_46 ) == V_49 &&
( ( V_214 != V_30 &&
V_215 == V_32 ) ||
( V_214 == V_30 &&
V_215 != V_32 ) ||
( V_50 -> V_29 != V_30 &&
V_50 -> V_31 == V_32 ) ||
( V_50 -> V_29 == V_30 &&
V_50 -> V_31 != V_32 ) ) &&
V_12 [ V_44 -> V_50 ] . V_91 !=
V_12 [ V_44 -> V_52 ] . V_91 ) ) {
F_21 ( V_12 , V_44 -> V_50 ) ;
return;
}
if ( V_68 != V_211 ) {
if ( V_214 == V_30 )
V_50 -> V_29 = V_30 ;
if ( V_215 == V_32 )
V_50 -> V_31 = V_32 ;
}
switch ( V_68 ) {
case V_205 :
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 += V_214 ;
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 += V_215 ;
V_50 -> V_33 = F_49 ( V_217 , V_216 ) ;
break;
case V_211 :
if ( V_214 == V_30 )
V_50 -> V_31 = V_32 ;
if ( V_215 == V_32 )
V_50 -> V_29 = V_30 ;
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 -= V_215 ;
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 -= V_214 ;
V_50 -> V_33 = F_49 ( V_217 , V_216 ) ;
break;
case V_207 :
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 *= V_214 ;
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 *= V_215 ;
V_50 -> V_33 = F_54 ( V_217 , V_216 ) ;
break;
case V_208 :
if ( V_214 < 0 )
V_50 -> V_29 = V_30 ;
else
V_50 -> V_29 = 0 ;
V_50 -> V_31 = V_215 ;
V_50 -> V_33 = F_54 ( V_217 , V_216 ) ;
break;
case V_206 :
if ( V_214 > F_59 ( V_32 ) ) {
V_50 -> V_29 = V_30 ;
V_50 -> V_33 = 1 ;
} else {
if ( V_50 -> V_29 != V_30 )
V_50 -> V_29 <<= V_214 ;
if ( ! V_50 -> V_33 )
V_50 -> V_33 = 1 ;
V_50 -> V_33 <<= V_214 ;
}
if ( V_215 > F_59 ( V_32 ) )
V_50 -> V_31 = V_32 ;
else if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 <<= V_215 ;
break;
case V_209 :
if ( V_214 < 0 || V_50 -> V_29 < 0 ) {
V_50 -> V_29 = V_30 ;
} else {
V_50 -> V_29 =
( T_2 ) ( V_50 -> V_29 ) >> V_214 ;
}
if ( V_214 < 0 ) {
V_50 -> V_33 = 1 ;
} else {
V_50 -> V_33 >>= ( T_2 ) V_214 ;
if ( ! V_50 -> V_33 )
V_50 -> V_33 = 1 ;
}
if ( V_50 -> V_31 != V_32 )
V_50 -> V_31 >>= V_215 ;
break;
default:
F_21 ( V_12 , V_44 -> V_50 ) ;
break;
}
F_56 ( V_50 ) ;
}
static int F_60 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 , * V_50 ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
int V_84 ;
if ( V_68 == V_218 || V_68 == V_219 ) {
if ( V_68 == V_219 ) {
if ( F_8 ( V_44 -> V_46 ) != 0 ||
V_44 -> V_52 != V_192 ||
V_44 -> V_19 != 0 || V_44 -> V_17 != 0 ) {
F_5 ( L_82 ) ;
return - V_93 ;
}
} else {
if ( V_44 -> V_52 != V_192 || V_44 -> V_19 != 0 ||
( V_44 -> V_17 != 16 && V_44 -> V_17 != 32 && V_44 -> V_17 != 64 ) ) {
F_5 ( L_83 ) ;
return - V_93 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_94 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_84 ,
V_44 -> V_50 ) ;
return - V_95 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_96 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_68 == V_220 ) {
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_17 != 0 || V_44 -> V_19 != 0 ) {
F_5 ( L_85 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
} else {
if ( V_44 -> V_52 != V_192 || V_44 -> V_19 != 0 ) {
F_5 ( L_85 ) ;
return - V_93 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_96 ) ;
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
return - V_95 ;
}
F_20 ( V_12 , V_44 -> V_50 ) ;
}
} else {
V_12 [ V_44 -> V_50 ] . type = V_15 ;
V_12 [ V_44 -> V_50 ] . V_17 = V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . V_1 = 0 ;
V_12 [ V_44 -> V_50 ] . V_31 = V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . V_29 = V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . V_33 = F_57 ( V_44 -> V_17 ) ;
V_12 [ V_44 -> V_50 ] . V_91 = false ;
}
} else if ( V_68 > V_218 ) {
F_5 ( L_87 , V_68 ) ;
return - V_93 ;
} else {
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_17 != 0 || V_44 -> V_19 != 0 ) {
F_5 ( L_88 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
} else {
if ( V_44 -> V_52 != V_192 || V_44 -> V_19 != 0 ) {
F_5 ( L_88 ) ;
return - V_93 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_94 ) ;
if ( V_84 )
return V_84 ;
if ( ( V_68 == V_221 || V_68 == V_222 ) &&
F_8 ( V_44 -> V_46 ) == V_200 && V_44 -> V_17 == 0 ) {
F_5 ( L_89 ) ;
return - V_93 ;
}
if ( ( V_68 == V_206 || V_68 == V_209 ||
V_68 == V_223 ) && F_8 ( V_44 -> V_46 ) == V_200 ) {
int V_98 = F_7 ( V_44 -> V_46 ) == V_48 ? 64 : 32 ;
if ( V_44 -> V_17 < 0 || V_44 -> V_17 >= V_98 ) {
F_5 ( L_90 , V_44 -> V_17 ) ;
return - V_93 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_224 ) ;
if ( V_84 )
return V_84 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
F_58 ( V_42 , V_44 ) ;
if ( V_68 == V_205 && F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_88 && F_8 ( V_44 -> V_46 ) == V_200 ) {
V_50 -> type = V_16 ;
V_50 -> V_17 = V_44 -> V_17 ;
return 0 ;
} else if ( V_68 == V_205 &&
F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_16 &&
( ( F_8 ( V_44 -> V_46 ) == V_49 &&
V_12 [ V_44 -> V_52 ] . type == V_15 ) ||
F_8 ( V_44 -> V_46 ) == V_200 ) ) {
if ( F_8 ( V_44 -> V_46 ) == V_49 )
V_50 -> V_17 += V_12 [ V_44 -> V_52 ] . V_17 ;
else
V_50 -> V_17 += V_44 -> V_17 ;
return 0 ;
} else if ( V_68 == V_205 &&
F_7 ( V_44 -> V_46 ) == V_48 &&
( V_50 -> type == V_18 ||
( F_8 ( V_44 -> V_46 ) == V_49 &&
V_12 [ V_44 -> V_52 ] . type == V_18 ) ) ) {
return F_48 ( V_42 , V_44 ) ;
} else if ( F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_21 &&
V_42 -> V_66 ) {
return F_50 ( V_42 , V_44 ) ;
} else if ( F_7 ( V_44 -> V_46 ) == V_48 &&
V_50 -> type == V_15 &&
V_42 -> V_66 ) {
return F_55 ( V_42 , V_44 ) ;
} else if ( F_33 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_84 ,
V_44 -> V_50 ) ;
return - V_95 ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 &&
F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_84 ,
V_44 -> V_52 ) ;
return - V_95 ;
}
if ( V_42 -> V_66 &&
F_7 ( V_44 -> V_46 ) == V_48 && V_68 == V_205 &&
( V_50 -> type == V_23 ||
V_50 -> type == V_25 ) )
V_50 -> type = V_25 ;
else
F_20 ( V_12 , V_44 -> V_50 ) ;
}
return 0 ;
}
static void F_61 ( struct V_4 * V_5 ,
struct V_6 * V_50 )
{
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_18 && V_12 [ V_10 ] . V_1 == V_50 -> V_1 )
V_12 [ V_10 ] . V_20 = F_54 ( V_12 [ V_10 ] . V_20 , V_50 -> V_19 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
V_7 = & V_5 -> V_40 [ V_10 / V_37 ] ;
if ( V_7 -> type == V_18 && V_7 -> V_1 == V_50 -> V_1 )
V_7 -> V_20 = F_54 ( V_7 -> V_20 , V_50 -> V_19 ) ;
}
}
static void F_62 ( struct V_6 * V_225 ,
struct V_6 * V_226 , T_2 V_227 ,
T_1 V_68 )
{
bool V_91 = true ;
bool V_228 = true ;
switch ( V_68 ) {
case V_229 :
V_225 -> V_31 = V_225 -> V_29 = V_227 ;
V_228 = false ;
break;
case V_230 :
V_226 -> V_31 = V_226 -> V_29 = V_227 ;
V_228 = false ;
break;
case V_231 :
V_91 = false ;
case V_232 :
if ( V_225 -> V_91 != V_91 )
F_21 ( V_225 , 0 ) ;
if ( V_226 -> V_91 != V_91 )
F_21 ( V_226 , 0 ) ;
if ( V_68 == V_231 ) {
V_226 -> V_29 = 0 ;
}
V_226 -> V_31 = V_227 ;
V_226 -> V_91 = V_91 ;
V_225 -> V_29 = V_227 + 1 ;
V_225 -> V_91 = V_91 ;
break;
case V_233 :
V_91 = false ;
case V_234 :
if ( V_225 -> V_91 != V_91 )
F_21 ( V_225 , 0 ) ;
if ( V_226 -> V_91 != V_91 )
F_21 ( V_226 , 0 ) ;
if ( V_68 == V_233 ) {
V_226 -> V_29 = 0 ;
}
V_226 -> V_31 = V_227 - 1 ;
V_226 -> V_91 = V_91 ;
V_225 -> V_29 = V_227 ;
V_225 -> V_91 = V_91 ;
break;
default:
break;
}
F_56 ( V_226 ) ;
F_56 ( V_225 ) ;
if ( V_228 ) {
if ( F_32 ( false , V_226 ) )
F_21 ( V_226 , 0 ) ;
if ( F_32 ( false , V_225 ) )
F_21 ( V_225 , 0 ) ;
}
}
static void F_63 ( struct V_6 * V_225 ,
struct V_6 * V_226 , T_2 V_227 ,
T_1 V_68 )
{
bool V_91 = true ;
bool V_228 = true ;
switch ( V_68 ) {
case V_229 :
V_225 -> V_31 = V_225 -> V_29 = V_227 ;
V_228 = false ;
break;
case V_230 :
V_226 -> V_31 = V_226 -> V_29 = V_227 ;
V_228 = false ;
break;
case V_231 :
V_91 = false ;
case V_232 :
if ( V_225 -> V_91 != V_91 )
F_21 ( V_225 , 0 ) ;
if ( V_226 -> V_91 != V_91 )
F_21 ( V_226 , 0 ) ;
if ( V_68 == V_231 ) {
V_225 -> V_29 = 0 ;
}
V_226 -> V_29 = V_227 ;
V_226 -> V_91 = V_91 ;
V_225 -> V_31 = V_227 - 1 ;
V_225 -> V_91 = V_91 ;
break;
case V_233 :
V_91 = false ;
case V_234 :
if ( V_225 -> V_91 != V_91 )
F_21 ( V_225 , 0 ) ;
if ( V_226 -> V_91 != V_91 )
F_21 ( V_226 , 0 ) ;
if ( V_68 == V_233 ) {
V_225 -> V_29 = 0 ;
}
V_226 -> V_29 = V_227 + 1 ;
V_226 -> V_91 = V_91 ;
V_225 -> V_31 = V_227 ;
V_225 -> V_91 = V_91 ;
break;
default:
break;
}
F_56 ( V_226 ) ;
F_56 ( V_225 ) ;
if ( V_228 ) {
if ( F_32 ( false , V_226 ) )
F_21 ( V_226 , 0 ) ;
if ( F_32 ( false , V_225 ) )
F_21 ( V_225 , 0 ) ;
}
}
static void F_64 ( struct V_6 * V_12 , V_64 V_86 , V_64 V_1 ,
enum V_8 type )
{
struct V_6 * V_7 = & V_12 [ V_86 ] ;
if ( V_7 -> type == V_24 && V_7 -> V_1 == V_1 ) {
if ( type == V_21 ) {
F_19 ( V_12 , V_86 ) ;
} else if ( V_7 -> V_26 -> V_235 ) {
V_7 -> type = V_22 ;
V_7 -> V_26 = V_7 -> V_26 -> V_235 ;
} else {
V_7 -> type = type ;
}
V_7 -> V_1 = 0 ;
}
}
static void F_65 ( struct V_4 * V_5 , V_64 V_86 ,
enum V_8 type )
{
struct V_6 * V_12 = V_5 -> V_12 ;
V_64 V_1 = V_12 [ V_86 ] . V_1 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_64 ( V_12 , V_10 , V_1 , type ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
F_64 ( V_5 -> V_40 , V_10 / V_37 , V_1 , type ) ;
}
}
static int F_66 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int * V_77 )
{
struct V_4 * V_236 , * V_237 = & V_42 -> V_79 ;
struct V_6 * V_12 = V_237 -> V_12 , * V_50 ;
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
int V_84 ;
if ( V_68 > V_71 ) {
F_5 ( L_91 , V_68 ) ;
return - V_93 ;
}
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_17 != 0 ) {
F_5 ( L_92 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_93 ,
V_44 -> V_52 ) ;
return - V_95 ;
}
} else {
if ( V_44 -> V_52 != V_192 ) {
F_5 ( L_92 ) ;
return - V_93 ;
}
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_94 ) ;
if ( V_84 )
return V_84 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
if ( F_8 ( V_44 -> V_46 ) == V_200 &&
( V_68 == V_229 || V_68 == V_230 ) &&
V_50 -> type == V_15 && V_50 -> V_17 == V_44 -> V_17 ) {
if ( V_68 == V_229 ) {
* V_77 += V_44 -> V_19 ;
return 0 ;
} else {
return 0 ;
}
}
V_236 = F_14 ( V_42 , * V_77 + V_44 -> V_19 + 1 , * V_77 ) ;
if ( ! V_236 )
return - V_154 ;
if ( F_8 ( V_44 -> V_46 ) == V_49 ) {
if ( V_12 [ V_44 -> V_52 ] . type == V_15 )
F_62 ( & V_236 -> V_12 [ V_44 -> V_50 ] ,
V_50 , V_12 [ V_44 -> V_52 ] . V_17 ,
V_68 ) ;
else if ( V_50 -> type == V_15 )
F_63 ( & V_236 -> V_12 [ V_44 -> V_52 ] ,
& V_12 [ V_44 -> V_52 ] , V_50 -> V_17 ,
V_68 ) ;
} else {
F_62 ( & V_236 -> V_12 [ V_44 -> V_50 ] ,
V_50 , V_44 -> V_17 , V_68 ) ;
}
if ( F_8 ( V_44 -> V_46 ) == V_200 &&
V_44 -> V_17 == 0 && ( V_68 == V_229 || V_68 == V_230 ) &&
V_50 -> type == V_24 ) {
F_65 ( V_237 , V_44 -> V_50 ,
V_68 == V_229 ? V_23 : V_21 ) ;
F_65 ( V_236 , V_44 -> V_50 ,
V_68 == V_229 ? V_21 : V_23 ) ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 && V_68 == V_231 &&
V_50 -> type == V_18 &&
V_12 [ V_44 -> V_52 ] . type == V_97 ) {
F_61 ( V_237 , V_50 ) ;
} else if ( F_8 ( V_44 -> V_46 ) == V_49 && V_68 == V_233 &&
V_50 -> type == V_97 &&
V_12 [ V_44 -> V_52 ] . type == V_18 ) {
F_61 ( V_236 , & V_12 [ V_44 -> V_52 ] ) ;
} else if ( F_33 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_93 , V_44 -> V_50 ) ;
return - V_95 ;
}
if ( V_104 )
F_4 ( V_237 ) ;
return 0 ;
}
static struct V_102 * F_67 ( struct V_43 * V_44 )
{
T_2 V_238 = ( ( T_2 ) ( V_64 ) V_44 [ 0 ] . V_17 ) | ( ( T_2 ) ( V_64 ) V_44 [ 1 ] . V_17 ) << 32 ;
return (struct V_102 * ) ( unsigned long ) V_238 ;
}
static int F_68 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
int V_84 ;
if ( F_11 ( V_44 -> V_46 ) != V_63 ) {
F_5 ( L_94 ) ;
return - V_93 ;
}
if ( V_44 -> V_19 != 0 ) {
F_5 ( L_95 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_96 ) ;
if ( V_84 )
return V_84 ;
if ( V_44 -> V_52 == 0 ) {
T_2 V_17 = ( ( T_2 ) ( V_44 + 1 ) -> V_17 << 32 ) | ( V_64 ) V_44 -> V_17 ;
V_12 [ V_44 -> V_50 ] . type = V_15 ;
V_12 [ V_44 -> V_50 ] . V_17 = V_17 ;
V_12 [ V_44 -> V_50 ] . V_1 = 0 ;
return 0 ;
}
F_17 ( V_44 -> V_52 != V_65 ) ;
V_12 [ V_44 -> V_50 ] . type = V_22 ;
V_12 [ V_44 -> V_50 ] . V_26 = F_67 ( V_44 ) ;
return 0 ;
}
static bool F_69 ( enum V_239 type )
{
switch ( type ) {
case V_240 :
case V_113 :
case V_114 :
return true ;
default:
return false ;
}
}
static int F_70 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_79 . V_12 ;
T_1 V_241 = F_10 ( V_44 -> V_46 ) ;
int V_10 , V_84 ;
if ( ! F_69 ( V_42 -> V_109 -> type ) ) {
F_5 ( L_96 ) ;
return - V_93 ;
}
if ( V_44 -> V_50 != V_192 || V_44 -> V_19 != 0 ||
F_11 ( V_44 -> V_46 ) == V_63 ||
( V_241 == V_60 && V_44 -> V_52 != V_192 ) ) {
F_5 ( L_97 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_242 , V_94 ) ;
if ( V_84 )
return V_84 ;
if ( V_12 [ V_242 ] . type != V_90 ) {
F_5 ( L_98 ) ;
return - V_93 ;
}
if ( V_241 == V_61 ) {
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
}
for ( V_10 = 0 ; V_10 < V_188 ; V_10 ++ )
F_16 ( V_12 , V_189 [ V_10 ] ) ;
V_12 [ V_192 ] . type = V_21 ;
return 0 ;
}
static int F_71 ( int V_9 , int V_243 , int V_244 , struct V_41 * V_42 )
{
if ( V_244 == V_245 && V_246 [ V_9 ] >= ( V_247 | V_245 ) )
return 0 ;
if ( V_244 == V_248 && V_246 [ V_9 ] >= ( V_247 | V_248 ) )
return 0 ;
if ( V_243 < 0 || V_243 >= V_42 -> V_109 -> V_249 ) {
F_5 ( L_99 , V_9 , V_243 ) ;
return - V_93 ;
}
if ( V_244 == V_248 )
V_42 -> V_250 [ V_243 ] = V_251 ;
if ( V_246 [ V_243 ] == 0 ) {
V_246 [ V_9 ] = V_247 | V_244 ;
V_246 [ V_243 ] = V_247 ;
if ( V_252 >= V_42 -> V_109 -> V_249 )
return - V_253 ;
V_254 [ V_252 ++ ] = V_243 ;
return 1 ;
} else if ( ( V_246 [ V_243 ] & 0xF0 ) == V_247 ) {
F_5 ( L_100 , V_9 , V_243 ) ;
return - V_93 ;
} else if ( V_246 [ V_243 ] == V_255 ) {
V_246 [ V_9 ] = V_247 | V_244 ;
} else {
F_5 ( L_101 ) ;
return - V_154 ;
}
return 0 ;
}
static int F_72 ( struct V_41 * V_42 )
{
struct V_43 * V_256 = V_42 -> V_109 -> V_257 ;
int V_258 = V_42 -> V_109 -> V_249 ;
int V_259 = 0 ;
int V_10 , V_9 ;
V_246 = F_73 ( V_258 , sizeof( int ) , V_83 ) ;
if ( ! V_246 )
return - V_260 ;
V_254 = F_73 ( V_258 , sizeof( int ) , V_83 ) ;
if ( ! V_254 ) {
F_13 ( V_246 ) ;
return - V_260 ;
}
V_246 [ 0 ] = V_247 ;
V_254 [ 0 ] = 0 ;
V_252 = 1 ;
V_261:
if ( V_252 == 0 )
goto V_262;
V_9 = V_254 [ V_252 - 1 ] ;
if ( F_7 ( V_256 [ V_9 ] . V_46 ) == V_67 ) {
T_1 V_68 = F_9 ( V_256 [ V_9 ] . V_46 ) ;
if ( V_68 == V_71 ) {
goto V_263;
} else if ( V_68 == V_69 ) {
V_259 = F_71 ( V_9 , V_9 + 1 , V_245 , V_42 ) ;
if ( V_259 == 1 )
goto V_261;
else if ( V_259 < 0 )
goto V_264;
if ( V_9 + 1 < V_258 )
V_42 -> V_250 [ V_9 + 1 ] = V_251 ;
} else if ( V_68 == V_70 ) {
if ( F_8 ( V_256 [ V_9 ] . V_46 ) != V_200 ) {
V_259 = - V_93 ;
goto V_264;
}
V_259 = F_71 ( V_9 , V_9 + V_256 [ V_9 ] . V_19 + 1 ,
V_245 , V_42 ) ;
if ( V_259 == 1 )
goto V_261;
else if ( V_259 < 0 )
goto V_264;
if ( V_9 + 1 < V_258 )
V_42 -> V_250 [ V_9 + 1 ] = V_251 ;
} else {
V_42 -> V_250 [ V_9 ] = V_251 ;
V_259 = F_71 ( V_9 , V_9 + 1 , V_245 , V_42 ) ;
if ( V_259 == 1 )
goto V_261;
else if ( V_259 < 0 )
goto V_264;
V_259 = F_71 ( V_9 , V_9 + V_256 [ V_9 ] . V_19 + 1 , V_248 , V_42 ) ;
if ( V_259 == 1 )
goto V_261;
else if ( V_259 < 0 )
goto V_264;
}
} else {
V_259 = F_71 ( V_9 , V_9 + 1 , V_245 , V_42 ) ;
if ( V_259 == 1 )
goto V_261;
else if ( V_259 < 0 )
goto V_264;
}
V_263:
V_246 [ V_9 ] = V_255 ;
if ( V_252 -- <= 0 ) {
F_5 ( L_102 ) ;
V_259 = - V_154 ;
goto V_264;
}
goto V_261;
V_262:
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ ) {
if ( V_246 [ V_10 ] != V_255 ) {
F_5 ( L_103 , V_10 ) ;
V_259 = - V_93 ;
goto V_264;
}
}
V_259 = 0 ;
V_264:
F_13 ( V_246 ) ;
F_13 ( V_254 ) ;
return V_259 ;
}
static bool F_74 ( struct V_41 * V_42 ,
struct V_6 * V_265 ,
struct V_6 * V_266 )
{
if ( V_265 -> V_1 != V_266 -> V_1 )
return false ;
if ( V_265 -> V_19 == V_266 -> V_19 && V_265 -> V_20 < V_266 -> V_20 )
return true ;
if ( ! V_42 -> V_132 && V_265 -> V_19 <= V_266 -> V_19 &&
V_265 -> V_19 >= V_265 -> V_20 && V_266 -> V_19 >= V_266 -> V_20 )
return true ;
return false ;
}
static bool F_75 ( struct V_41 * V_42 ,
struct V_4 * V_265 ,
struct V_4 * V_266 )
{
bool V_267 = V_42 -> V_105 ;
struct V_6 * V_268 , * V_269 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_268 = & V_265 -> V_12 [ V_10 ] ;
V_269 = & V_266 -> V_12 [ V_10 ] ;
if ( memcmp ( V_268 , V_269 , sizeof( * V_268 ) ) == 0 )
continue;
if ( ! V_267 &&
memcmp ( V_268 , V_269 , F_76 ( struct V_6 , V_1 ) ) == 0 )
continue;
if ( V_268 -> type == V_13 ||
( ! V_267 && V_268 -> type == V_21 &&
V_269 -> type != V_13 ) )
continue;
if ( V_268 -> type == V_24 &&
V_269 -> type == V_24 &&
V_268 -> V_26 == V_269 -> V_26 )
continue;
if ( V_268 -> type == V_18 && V_269 -> type == V_18 &&
F_74 ( V_42 , V_268 , V_269 ) )
continue;
return false ;
}
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
if ( V_265 -> V_38 [ V_10 ] == V_270 )
continue;
if ( V_265 -> V_38 [ V_10 ] != V_266 -> V_38 [ V_10 ] )
return false ;
if ( V_10 % V_37 )
continue;
if ( V_265 -> V_38 [ V_10 ] != V_39 )
continue;
if ( memcmp ( & V_265 -> V_40 [ V_10 / V_37 ] ,
& V_266 -> V_40 [ V_10 / V_37 ] ,
sizeof( V_265 -> V_40 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_77 ( struct V_41 * V_42 , int V_77 )
{
struct V_271 * V_272 ;
struct V_271 * V_273 ;
V_273 = V_42 -> V_250 [ V_77 ] ;
if ( ! V_273 )
return 0 ;
while ( V_273 != V_251 ) {
if ( F_75 ( V_42 , & V_273 -> V_5 , & V_42 -> V_79 ) )
return 1 ;
V_273 = V_273 -> V_81 ;
}
V_272 = F_15 ( sizeof( struct V_271 ) , V_274 ) ;
if ( ! V_272 )
return - V_260 ;
memcpy ( & V_272 -> V_5 , & V_42 -> V_79 , sizeof( V_42 -> V_79 ) ) ;
V_272 -> V_81 = V_42 -> V_250 [ V_77 ] ;
V_42 -> V_250 [ V_77 ] = V_272 ;
return 0 ;
}
static int F_78 ( struct V_41 * V_42 ,
int V_77 , int V_74 )
{
if ( ! V_42 -> V_122 || ! V_42 -> V_122 -> V_275 )
return 0 ;
return V_42 -> V_122 -> V_275 ( V_42 , V_77 , V_74 ) ;
}
static int F_79 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = & V_42 -> V_79 ;
struct V_43 * V_256 = V_42 -> V_109 -> V_257 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_258 = V_42 -> V_109 -> V_249 ;
int V_77 , V_74 = 0 ;
int V_276 = 0 ;
bool V_277 = false ;
F_18 ( V_12 ) ;
V_77 = 0 ;
V_42 -> V_105 = false ;
for (; ; ) {
struct V_43 * V_44 ;
T_1 V_45 ;
int V_84 ;
if ( V_77 >= V_258 ) {
F_5 ( L_104 ,
V_77 , V_258 ) ;
return - V_154 ;
}
V_44 = & V_256 [ V_77 ] ;
V_45 = F_7 ( V_44 -> V_46 ) ;
if ( ++ V_276 > V_278 ) {
F_5 ( L_105 ,
V_276 ) ;
return - V_253 ;
}
V_84 = F_77 ( V_42 , V_77 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( V_84 == 1 ) {
if ( V_104 ) {
if ( V_277 )
F_5 ( L_106 ,
V_74 , V_77 ) ;
else
F_5 ( L_107 , V_77 ) ;
}
goto V_279;
}
if ( F_80 () )
F_81 () ;
if ( V_104 > 1 || ( V_104 && V_277 ) ) {
if ( V_104 > 1 )
F_5 ( L_108 , V_77 ) ;
else
F_5 ( L_109 ,
V_74 , V_77 ) ;
F_4 ( & V_42 -> V_79 ) ;
V_277 = false ;
}
if ( V_104 ) {
F_5 ( L_110 , V_77 ) ;
F_6 ( V_42 , V_44 ) ;
}
V_84 = F_78 ( V_42 , V_77 , V_74 ) ;
if ( V_84 )
return V_84 ;
if ( V_45 == V_47 || V_45 == V_48 ) {
V_84 = F_60 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_45 == V_58 ) {
enum V_8 * V_280 , V_281 ;
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_224 ) ;
if ( V_84 )
return V_84 ;
V_281 = V_12 [ V_44 -> V_52 ] . type ;
V_84 = F_37 ( V_42 , V_77 , V_44 -> V_52 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_134 ,
V_44 -> V_50 ) ;
if ( V_84 )
return V_84 ;
V_280 = & V_42 -> V_126 [ V_77 ] . V_282 ;
if ( * V_280 == V_13 ) {
* V_280 = V_281 ;
} else if ( V_281 != * V_280 &&
( V_281 == V_90 ||
* V_280 == V_90 ) ) {
F_5 ( L_111 ) ;
return - V_93 ;
}
} else if ( V_45 == V_53 ) {
enum V_8 * V_283 , V_284 ;
if ( F_10 ( V_44 -> V_46 ) == V_56 ) {
V_84 = F_39 ( V_42 , V_77 , V_44 ) ;
if ( V_84 )
return V_84 ;
V_77 ++ ;
continue;
}
V_84 = F_23 ( V_12 , V_44 -> V_52 , V_94 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_94 ) ;
if ( V_84 )
return V_84 ;
V_284 = V_12 [ V_44 -> V_50 ] . type ;
V_84 = F_37 ( V_42 , V_77 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_112 ,
V_44 -> V_52 ) ;
if ( V_84 )
return V_84 ;
V_283 = & V_42 -> V_126 [ V_77 ] . V_282 ;
if ( * V_283 == V_13 ) {
* V_283 = V_284 ;
} else if ( V_284 != * V_283 &&
( V_284 == V_90 ||
* V_283 == V_90 ) ) {
F_5 ( L_111 ) ;
return - V_93 ;
}
} else if ( V_45 == V_57 ) {
if ( F_10 ( V_44 -> V_46 ) != V_54 ||
V_44 -> V_52 != V_192 ) {
F_5 ( L_112 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_44 -> V_50 , V_94 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_37 ( V_42 , V_77 , V_44 -> V_50 , V_44 -> V_19 ,
F_11 ( V_44 -> V_46 ) , V_112 ,
- 1 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_45 == V_67 ) {
T_1 V_68 = F_9 ( V_44 -> V_46 ) ;
if ( V_68 == V_69 ) {
if ( F_8 ( V_44 -> V_46 ) != V_200 ||
V_44 -> V_19 != 0 ||
V_44 -> V_52 != V_192 ||
V_44 -> V_50 != V_192 ) {
F_5 ( L_113 ) ;
return - V_93 ;
}
V_84 = F_46 ( V_42 , V_44 -> V_17 , V_77 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_68 == V_70 ) {
if ( F_8 ( V_44 -> V_46 ) != V_200 ||
V_44 -> V_17 != 0 ||
V_44 -> V_52 != V_192 ||
V_44 -> V_50 != V_192 ) {
F_5 ( L_114 ) ;
return - V_93 ;
}
V_77 += V_44 -> V_19 + 1 ;
continue;
} else if ( V_68 == V_71 ) {
if ( F_8 ( V_44 -> V_46 ) != V_200 ||
V_44 -> V_17 != 0 ||
V_44 -> V_52 != V_192 ||
V_44 -> V_50 != V_192 ) {
F_5 ( L_115 ) ;
return - V_93 ;
}
V_84 = F_23 ( V_12 , V_192 , V_94 ) ;
if ( V_84 )
return V_84 ;
if ( F_33 ( V_42 , V_192 ) ) {
F_5 ( L_116 ) ;
return - V_95 ;
}
V_279:
V_77 = F_12 ( V_42 , & V_74 ) ;
if ( V_77 < 0 ) {
break;
} else {
V_277 = true ;
continue;
}
} else {
V_84 = F_66 ( V_42 , V_44 , & V_77 ) ;
if ( V_84 )
return V_84 ;
}
} else if ( V_45 == V_59 ) {
T_1 V_241 = F_10 ( V_44 -> V_46 ) ;
if ( V_241 == V_60 || V_241 == V_61 ) {
V_84 = F_70 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
} else if ( V_241 == V_62 ) {
V_84 = F_68 ( V_42 , V_44 ) ;
if ( V_84 )
return V_84 ;
V_77 ++ ;
} else {
F_5 ( L_117 ) ;
return - V_93 ;
}
F_21 ( V_12 , V_44 -> V_50 ) ;
} else {
F_5 ( L_118 , V_45 ) ;
return - V_93 ;
}
V_77 ++ ;
}
F_5 ( L_119 ,
V_276 , V_42 -> V_109 -> V_123 -> V_135 ) ;
return 0 ;
}
static int F_82 ( struct V_102 * V_103 )
{
return ( V_103 -> V_156 != V_285 &&
V_103 -> V_156 != V_286 &&
V_103 -> V_156 != V_168 ) ||
! ( V_103 -> V_287 & V_288 ) ;
}
static int F_83 ( struct V_102 * V_103 ,
struct V_289 * V_109 )
{
if ( V_109 -> type == V_290 ) {
if ( ! F_82 ( V_103 ) ) {
F_5 ( L_120 ) ;
return - V_93 ;
}
if ( V_103 -> V_235 &&
! F_82 ( V_103 -> V_235 ) ) {
F_5 ( L_121 ) ;
return - V_93 ;
}
}
return 0 ;
}
static int F_84 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_109 -> V_257 ;
int V_258 = V_42 -> V_109 -> V_249 ;
int V_10 , V_291 , V_84 ;
V_84 = F_85 ( V_42 -> V_109 ) ;
if ( V_84 )
return V_84 ;
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ , V_44 ++ ) {
if ( F_7 ( V_44 -> V_46 ) == V_58 &&
( F_10 ( V_44 -> V_46 ) != V_54 || V_44 -> V_17 != 0 ) ) {
F_5 ( L_122 ) ;
return - V_93 ;
}
if ( F_7 ( V_44 -> V_46 ) == V_53 &&
( ( F_10 ( V_44 -> V_46 ) != V_54 &&
F_10 ( V_44 -> V_46 ) != V_56 ) || V_44 -> V_17 != 0 ) ) {
F_5 ( L_123 ) ;
return - V_93 ;
}
if ( V_44 [ 0 ] . V_46 == ( V_59 | V_62 | V_63 ) ) {
struct V_102 * V_103 ;
struct V_292 V_293 ;
if ( V_10 == V_258 - 1 || V_44 [ 1 ] . V_46 != 0 ||
V_44 [ 1 ] . V_50 != 0 || V_44 [ 1 ] . V_52 != 0 ||
V_44 [ 1 ] . V_19 != 0 ) {
F_5 ( L_124 ) ;
return - V_93 ;
}
if ( V_44 -> V_52 == 0 )
goto V_294;
if ( V_44 -> V_52 != V_65 ) {
F_5 ( L_125 ) ;
return - V_93 ;
}
V_293 = F_86 ( V_44 -> V_17 ) ;
V_103 = F_87 ( V_293 ) ;
if ( F_88 ( V_103 ) ) {
F_5 ( L_126 ,
V_44 -> V_17 ) ;
return F_89 ( V_103 ) ;
}
V_84 = F_83 ( V_103 , V_42 -> V_109 ) ;
if ( V_84 ) {
F_90 ( V_293 ) ;
return V_84 ;
}
V_44 [ 0 ] . V_17 = ( V_64 ) ( unsigned long ) V_103 ;
V_44 [ 1 ] . V_17 = ( ( T_2 ) ( unsigned long ) V_103 ) >> 32 ;
for ( V_291 = 0 ; V_291 < V_42 -> V_295 ; V_291 ++ )
if ( V_42 -> V_296 [ V_291 ] == V_103 ) {
F_90 ( V_293 ) ;
goto V_294;
}
if ( V_42 -> V_295 >= V_297 ) {
F_90 ( V_293 ) ;
return - V_253 ;
}
V_103 = F_91 ( V_103 , false ) ;
if ( F_88 ( V_103 ) ) {
F_90 ( V_293 ) ;
return F_89 ( V_103 ) ;
}
V_42 -> V_296 [ V_42 -> V_295 ++ ] = V_103 ;
F_90 ( V_293 ) ;
V_294:
V_44 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_92 ( struct V_41 * V_42 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_42 -> V_295 ; V_10 ++ )
F_93 ( V_42 -> V_296 [ V_10 ] ) ;
}
static void F_94 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_109 -> V_257 ;
int V_258 = V_42 -> V_109 -> V_249 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ , V_44 ++ )
if ( V_44 -> V_46 == ( V_59 | V_62 | V_63 ) )
V_44 -> V_52 = 0 ;
}
static int F_95 ( struct V_41 * V_42 , V_64 V_298 ,
V_64 V_19 , V_64 V_299 )
{
struct V_195 * V_300 , * V_301 = V_42 -> V_126 ;
if ( V_299 == 1 )
return 0 ;
V_300 = F_96 ( sizeof( struct V_195 ) * V_298 ) ;
if ( ! V_300 )
return - V_260 ;
memcpy ( V_300 , V_301 , sizeof( struct V_195 ) * V_19 ) ;
memcpy ( V_300 + V_19 + V_299 - 1 , V_301 + V_19 ,
sizeof( struct V_195 ) * ( V_298 - V_19 - V_299 + 1 ) ) ;
V_42 -> V_126 = V_300 ;
F_97 ( V_301 ) ;
return 0 ;
}
static struct V_289 * F_98 ( struct V_41 * V_42 , V_64 V_19 ,
const struct V_43 * V_302 , V_64 V_249 )
{
struct V_289 * V_303 ;
V_303 = F_99 ( V_42 -> V_109 , V_19 , V_302 , V_249 ) ;
if ( ! V_303 )
return NULL ;
if ( F_95 ( V_42 , V_303 -> V_249 , V_19 , V_249 ) )
return NULL ;
return V_303 ;
}
static int F_100 ( struct V_41 * V_42 )
{
const struct V_304 * V_124 = V_42 -> V_109 -> V_123 -> V_124 ;
int V_10 , V_299 , V_98 , V_127 , V_305 = 0 ;
const int V_258 = V_42 -> V_109 -> V_249 ;
struct V_43 V_306 [ 16 ] , * V_44 ;
struct V_289 * V_303 ;
enum V_108 type ;
bool V_307 ;
V_64 V_308 ;
if ( V_124 -> V_309 ) {
V_299 = V_124 -> V_309 ( V_306 , V_42 -> V_118 ,
V_42 -> V_109 ) ;
if ( V_299 >= F_3 ( V_306 ) ) {
F_5 ( L_127 ) ;
return - V_93 ;
} else if ( V_299 ) {
V_303 = F_98 ( V_42 , 0 , V_306 , V_299 ) ;
if ( ! V_303 )
return - V_260 ;
V_42 -> V_109 = V_303 ;
V_305 += V_299 - 1 ;
}
}
if ( ! V_124 -> V_310 )
return 0 ;
V_44 = V_42 -> V_109 -> V_257 + V_305 ;
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ , V_44 ++ ) {
if ( V_44 -> V_46 == ( V_58 | V_54 | V_187 ) ||
V_44 -> V_46 == ( V_58 | V_54 | V_311 ) ||
V_44 -> V_46 == ( V_58 | V_54 | V_136 ) ||
V_44 -> V_46 == ( V_58 | V_54 | V_63 ) )
type = V_134 ;
else if ( V_44 -> V_46 == ( V_53 | V_54 | V_187 ) ||
V_44 -> V_46 == ( V_53 | V_54 | V_311 ) ||
V_44 -> V_46 == ( V_53 | V_54 | V_136 ) ||
V_44 -> V_46 == ( V_53 | V_54 | V_63 ) )
type = V_112 ;
else
continue;
if ( V_42 -> V_126 [ V_10 + V_305 ] . V_282 != V_90 )
continue;
V_127 = V_42 -> V_126 [ V_10 + V_305 ] . V_127 ;
V_98 = F_101 ( V_44 ) ;
V_307 = V_98 < V_127 ;
if ( V_307 ) {
V_64 V_19 = V_44 -> V_19 ;
T_1 V_312 ;
if ( type == V_112 ) {
F_5 ( L_128 ) ;
return - V_93 ;
}
V_312 = V_311 ;
if ( V_127 == 4 )
V_312 = V_136 ;
else if ( V_127 == 8 )
V_312 = V_63 ;
V_44 -> V_19 = V_19 & ~ ( V_127 - 1 ) ;
V_44 -> V_46 = V_58 | V_54 | V_312 ;
}
V_308 = 0 ;
V_299 = V_124 -> V_310 ( type , V_44 , V_306 , V_42 -> V_109 ,
& V_308 ) ;
if ( V_299 == 0 || V_299 >= F_3 ( V_306 ) ||
( V_127 && ! V_308 ) ) {
F_5 ( L_127 ) ;
return - V_93 ;
}
if ( V_307 && V_98 < V_308 ) {
if ( V_127 <= 4 )
V_306 [ V_299 ++ ] = F_102 ( V_208 , V_44 -> V_50 ,
( 1 << V_98 * 8 ) - 1 ) ;
else
V_306 [ V_299 ++ ] = F_103 ( V_208 , V_44 -> V_50 ,
( 1 << V_98 * 8 ) - 1 ) ;
}
V_303 = F_98 ( V_42 , V_10 + V_305 , V_306 , V_299 ) ;
if ( ! V_303 )
return - V_260 ;
V_305 += V_299 - 1 ;
V_42 -> V_109 = V_303 ;
V_44 = V_303 -> V_257 + V_10 + V_305 ;
}
return 0 ;
}
static int F_104 ( struct V_41 * V_42 )
{
struct V_289 * V_109 = V_42 -> V_109 ;
struct V_43 * V_44 = V_109 -> V_257 ;
const struct V_170 * V_171 ;
const int V_258 = V_109 -> V_249 ;
struct V_43 V_306 [ 16 ] ;
struct V_289 * V_303 ;
struct V_102 * V_26 ;
int V_10 , V_299 , V_305 = 0 ;
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ , V_44 ++ ) {
if ( V_44 -> V_46 != ( V_67 | V_69 ) )
continue;
if ( V_44 -> V_17 == V_313 )
V_109 -> V_314 = 1 ;
if ( V_44 -> V_17 == V_315 )
F_105 () ;
if ( V_44 -> V_17 == V_158 ) {
V_109 -> V_316 = 1 ;
V_42 -> V_109 -> V_123 -> V_135 = V_36 ;
V_44 -> V_17 = 0 ;
V_44 -> V_46 = V_67 | V_317 ;
continue;
}
if ( F_106 () && V_44 -> V_17 == V_169 ) {
V_26 = V_42 -> V_126 [ V_10 + V_305 ] . V_26 ;
if ( V_26 == V_198 ||
! V_26 -> V_124 -> V_318 )
goto V_319;
V_299 = V_26 -> V_124 -> V_318 ( V_26 , V_306 ) ;
if ( V_299 == 0 || V_299 >= F_3 ( V_306 ) ) {
F_5 ( L_127 ) ;
return - V_93 ;
}
V_303 = F_98 ( V_42 , V_10 + V_305 , V_306 ,
V_299 ) ;
if ( ! V_303 )
return - V_260 ;
V_305 += V_299 - 1 ;
V_42 -> V_109 = V_109 = V_303 ;
V_44 = V_303 -> V_257 + V_10 + V_305 ;
continue;
}
V_319:
V_171 = V_109 -> V_123 -> V_124 -> V_179 ( V_44 -> V_17 ) ;
if ( ! V_171 -> V_182 ) {
F_5 ( L_75 ,
F_1 ( V_44 -> V_17 ) , V_44 -> V_17 ) ;
return - V_154 ;
}
V_44 -> V_17 = V_171 -> V_182 - V_320 ;
}
return 0 ;
}
static void F_107 ( struct V_41 * V_42 )
{
struct V_271 * V_273 , * V_321 ;
int V_10 ;
if ( ! V_42 -> V_250 )
return;
for ( V_10 = 0 ; V_10 < V_42 -> V_109 -> V_249 ; V_10 ++ ) {
V_273 = V_42 -> V_250 [ V_10 ] ;
if ( V_273 )
while ( V_273 != V_251 ) {
V_321 = V_273 -> V_81 ;
F_13 ( V_273 ) ;
V_273 = V_321 ;
}
}
F_13 ( V_42 -> V_250 ) ;
}
int F_108 ( struct V_289 * * V_109 , union V_322 * V_323 )
{
char T_5 * V_324 = NULL ;
struct V_41 * V_42 ;
int V_259 = - V_93 ;
V_42 = F_109 ( sizeof( struct V_41 ) , V_83 ) ;
if ( ! V_42 )
return - V_260 ;
V_42 -> V_126 = F_96 ( sizeof( struct V_195 ) *
( * V_109 ) -> V_249 ) ;
V_259 = - V_260 ;
if ( ! V_42 -> V_126 )
goto V_325;
V_42 -> V_109 = * V_109 ;
F_110 ( & V_326 ) ;
if ( V_323 -> V_104 || V_323 -> V_327 || V_323 -> V_328 ) {
V_104 = V_323 -> V_104 ;
V_324 = ( char T_5 * ) ( unsigned long ) V_323 -> V_327 ;
V_328 = V_323 -> V_328 ;
V_329 = 0 ;
V_259 = - V_93 ;
if ( V_328 < 128 || V_328 > V_330 >> 8 ||
V_104 == 0 || V_324 == NULL )
goto V_331;
V_259 = - V_260 ;
V_327 = F_111 ( V_328 ) ;
if ( ! V_327 )
goto V_331;
} else {
V_104 = 0 ;
}
V_42 -> V_132 = ! ! ( V_323 -> V_332 & V_333 ) ;
if ( ! F_112 ( V_334 ) )
V_42 -> V_132 = true ;
V_259 = F_84 ( V_42 ) ;
if ( V_259 < 0 )
goto V_335;
V_42 -> V_250 = F_73 ( V_42 -> V_109 -> V_249 ,
sizeof( struct V_271 * ) ,
V_274 ) ;
V_259 = - V_260 ;
if ( ! V_42 -> V_250 )
goto V_335;
V_259 = F_72 ( V_42 ) ;
if ( V_259 < 0 )
goto V_335;
V_42 -> V_66 = F_113 ( V_336 ) ;
V_259 = F_79 ( V_42 ) ;
V_335:
while ( F_12 ( V_42 , NULL ) >= 0 ) ;
F_107 ( V_42 ) ;
if ( V_259 == 0 )
V_259 = F_100 ( V_42 ) ;
if ( V_259 == 0 )
V_259 = F_104 ( V_42 ) ;
if ( V_104 && V_329 >= V_328 - 1 ) {
F_17 ( V_329 >= V_328 ) ;
V_259 = - V_337 ;
}
if ( V_104 && F_114 ( V_324 , V_327 , V_329 + 1 ) != 0 ) {
V_259 = - V_154 ;
goto V_338;
}
if ( V_259 == 0 && V_42 -> V_295 ) {
V_42 -> V_109 -> V_123 -> V_296 = F_115 ( V_42 -> V_295 ,
sizeof( V_42 -> V_296 [ 0 ] ) ,
V_83 ) ;
if ( ! V_42 -> V_109 -> V_123 -> V_296 ) {
V_259 = - V_260 ;
goto V_338;
}
memcpy ( V_42 -> V_109 -> V_123 -> V_296 , V_42 -> V_296 ,
sizeof( V_42 -> V_296 [ 0 ] ) * V_42 -> V_295 ) ;
V_42 -> V_109 -> V_123 -> V_295 = V_42 -> V_295 ;
F_94 ( V_42 ) ;
}
V_338:
if ( V_104 )
F_97 ( V_327 ) ;
if ( ! V_42 -> V_109 -> V_123 -> V_296 )
F_92 ( V_42 ) ;
* V_109 = V_42 -> V_109 ;
V_331:
F_116 ( & V_326 ) ;
F_97 ( V_42 -> V_126 ) ;
V_325:
F_13 ( V_42 ) ;
return V_259 ;
}
int F_117 ( struct V_289 * V_109 , const struct V_339 * V_124 ,
void * V_340 )
{
struct V_41 * V_42 ;
int V_259 ;
V_42 = F_109 ( sizeof( struct V_41 ) , V_83 ) ;
if ( ! V_42 )
return - V_260 ;
V_42 -> V_126 = F_96 ( sizeof( struct V_195 ) *
V_109 -> V_249 ) ;
V_259 = - V_260 ;
if ( ! V_42 -> V_126 )
goto V_325;
V_42 -> V_109 = V_109 ;
V_42 -> V_122 = V_124 ;
V_42 -> V_341 = V_340 ;
F_110 ( & V_326 ) ;
V_104 = 0 ;
V_42 -> V_132 = false ;
if ( ! F_112 ( V_334 ) )
V_42 -> V_132 = true ;
V_42 -> V_250 = F_73 ( V_42 -> V_109 -> V_249 ,
sizeof( struct V_271 * ) ,
V_83 ) ;
V_259 = - V_260 ;
if ( ! V_42 -> V_250 )
goto V_335;
V_259 = F_72 ( V_42 ) ;
if ( V_259 < 0 )
goto V_335;
V_42 -> V_66 = F_113 ( V_336 ) ;
V_259 = F_79 ( V_42 ) ;
V_335:
while ( F_12 ( V_42 , NULL ) >= 0 ) ;
F_107 ( V_42 ) ;
F_116 ( & V_326 ) ;
F_97 ( V_42 -> V_126 ) ;
V_325:
F_13 ( V_42 ) ;
return V_259 ;
}
