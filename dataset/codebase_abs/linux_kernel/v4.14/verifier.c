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
if ( ( V_9 == V_15 || V_9 == V_16 ) &&
F_6 ( V_7 -> V_17 ) ) {
F_5 ( L_3 , V_7 -> V_17 . V_18 + V_7 -> V_19 ) ;
} else {
F_5 ( L_4 , V_7 -> V_1 ) ;
if ( V_9 != V_15 )
F_5 ( L_5 , V_7 -> V_19 ) ;
if ( V_9 == V_20 )
F_5 ( L_6 , V_7 -> V_21 ) ;
else if ( V_9 == V_22 ||
V_9 == V_23 ||
V_9 == V_24 )
F_5 ( L_7 ,
V_7 -> V_25 -> V_26 ,
V_7 -> V_25 -> V_27 ) ;
if ( F_6 ( V_7 -> V_17 ) ) {
F_5 ( L_8 , V_7 -> V_17 . V_18 ) ;
} else {
if ( V_7 -> V_28 != V_7 -> V_29 &&
V_7 -> V_28 != V_30 )
F_5 ( L_9 ,
( long long ) V_7 -> V_28 ) ;
if ( V_7 -> V_31 != V_7 -> V_32 &&
V_7 -> V_31 != V_33 )
F_5 ( L_10 ,
( long long ) V_7 -> V_31 ) ;
if ( V_7 -> V_29 != 0 )
F_5 ( L_11 ,
( unsigned long long ) V_7 -> V_29 ) ;
if ( V_7 -> V_32 != V_34 )
F_5 ( L_12 ,
( unsigned long long ) V_7 -> V_32 ) ;
if ( ! F_7 ( V_7 -> V_17 ) ) {
char V_35 [ 48 ] ;
F_8 ( V_35 , sizeof( V_35 ) , V_7 -> V_17 ) ;
F_5 ( L_13 , V_35 ) ;
}
}
F_5 ( L_14 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] == V_39 )
F_5 ( L_15 , - V_36 + V_10 ,
V_14 [ V_5 -> V_40 [ V_10 / V_37 ] . type ] ) ;
}
F_5 ( L_16 ) ;
}
static void F_9 ( const struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
T_1 V_45 = F_10 ( V_44 -> V_46 ) ;
if ( V_45 == V_47 || V_45 == V_48 ) {
if ( F_11 ( V_44 -> V_46 ) == V_49 )
F_5 ( L_17 ,
V_44 -> V_46 , V_45 == V_47 ? L_18 : L_19 ,
V_44 -> V_50 ,
V_51 [ F_12 ( V_44 -> V_46 ) >> 4 ] ,
V_45 == V_47 ? L_18 : L_19 ,
V_44 -> V_52 ) ;
else
F_5 ( L_20 ,
V_44 -> V_46 , V_45 == V_47 ? L_18 : L_19 ,
V_44 -> V_50 ,
V_51 [ F_12 ( V_44 -> V_46 ) >> 4 ] ,
V_45 == V_47 ? L_18 : L_19 ,
V_44 -> V_53 ) ;
} else if ( V_45 == V_54 ) {
if ( F_13 ( V_44 -> V_46 ) == V_55 )
F_5 ( L_21 ,
V_44 -> V_46 ,
V_56 [ F_14 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_50 ,
V_44 -> V_19 , V_44 -> V_52 ) ;
else if ( F_13 ( V_44 -> V_46 ) == V_57 )
F_5 ( L_22 ,
V_44 -> V_46 ,
V_56 [ F_14 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_50 , V_44 -> V_19 ,
V_44 -> V_52 ) ;
else
F_5 ( L_23 , V_44 -> V_46 ) ;
} else if ( V_45 == V_58 ) {
if ( F_13 ( V_44 -> V_46 ) != V_55 ) {
F_5 ( L_24 , V_44 -> V_46 ) ;
return;
}
F_5 ( L_25 ,
V_44 -> V_46 ,
V_56 [ F_14 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_50 ,
V_44 -> V_19 , V_44 -> V_53 ) ;
} else if ( V_45 == V_59 ) {
if ( F_13 ( V_44 -> V_46 ) != V_55 ) {
F_5 ( L_26 , V_44 -> V_46 ) ;
return;
}
F_5 ( L_27 ,
V_44 -> V_46 , V_44 -> V_50 ,
V_56 [ F_14 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_52 , V_44 -> V_19 ) ;
} else if ( V_45 == V_60 ) {
if ( F_13 ( V_44 -> V_46 ) == V_61 ) {
F_5 ( L_28 ,
V_44 -> V_46 ,
V_56 [ F_14 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_53 ) ;
} else if ( F_13 ( V_44 -> V_46 ) == V_62 ) {
F_5 ( L_29 ,
V_44 -> V_46 ,
V_56 [ F_14 ( V_44 -> V_46 ) >> 3 ] ,
V_44 -> V_52 , V_44 -> V_53 ) ;
} else if ( F_13 ( V_44 -> V_46 ) == V_63 &&
F_14 ( V_44 -> V_46 ) == V_64 ) {
T_2 V_53 = ( ( T_2 ) ( V_44 + 1 ) -> V_53 << 32 ) | ( V_65 ) V_44 -> V_53 ;
bool V_25 = V_44 -> V_52 == V_66 ;
if ( V_25 && ! V_42 -> V_67 )
V_53 = 0 ;
F_5 ( L_30 , V_44 -> V_46 ,
V_44 -> V_50 , ( unsigned long long ) V_53 ) ;
} else {
F_5 ( L_31 , V_44 -> V_46 ) ;
return;
}
} else if ( V_45 == V_68 ) {
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
if ( V_69 == V_70 ) {
F_5 ( L_32 , V_44 -> V_46 ,
F_1 ( V_44 -> V_53 ) , V_44 -> V_53 ) ;
} else if ( V_44 -> V_46 == ( V_68 | V_71 ) ) {
F_5 ( L_33 ,
V_44 -> V_46 , V_44 -> V_19 ) ;
} else if ( V_44 -> V_46 == ( V_68 | V_72 ) ) {
F_5 ( L_34 , V_44 -> V_46 ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
F_5 ( L_35 ,
V_44 -> V_46 , V_44 -> V_50 ,
V_73 [ F_12 ( V_44 -> V_46 ) >> 4 ] ,
V_44 -> V_52 , V_44 -> V_19 ) ;
} else {
F_5 ( L_36 ,
V_44 -> V_46 , V_44 -> V_50 ,
V_73 [ F_12 ( V_44 -> V_46 ) >> 4 ] ,
V_44 -> V_53 , V_44 -> V_19 ) ;
}
} else {
F_5 ( L_37 , V_44 -> V_46 , V_74 [ V_45 ] ) ;
}
}
static int F_15 ( struct V_41 * V_42 , int * V_75 )
{
struct V_76 * V_77 ;
int V_78 ;
if ( V_42 -> V_79 == NULL )
return - 1 ;
memcpy ( & V_42 -> V_80 , & V_42 -> V_79 -> V_81 , sizeof( V_42 -> V_80 ) ) ;
V_78 = V_42 -> V_79 -> V_78 ;
if ( V_75 )
* V_75 = V_42 -> V_79 -> V_75 ;
V_77 = V_42 -> V_79 -> V_82 ;
F_16 ( V_42 -> V_79 ) ;
V_42 -> V_79 = V_77 ;
V_42 -> V_83 -- ;
return V_78 ;
}
static struct V_4 * F_17 ( struct V_41 * V_42 ,
int V_78 , int V_75 )
{
struct V_76 * V_77 ;
V_77 = F_18 ( sizeof( struct V_76 ) , V_84 ) ;
if ( ! V_77 )
goto V_85;
memcpy ( & V_77 -> V_81 , & V_42 -> V_80 , sizeof( V_42 -> V_80 ) ) ;
V_77 -> V_78 = V_78 ;
V_77 -> V_75 = V_75 ;
V_77 -> V_82 = V_42 -> V_79 ;
V_42 -> V_79 = V_77 ;
V_42 -> V_83 ++ ;
if ( V_42 -> V_83 > V_86 ) {
F_5 ( L_38 ) ;
goto V_85;
}
return & V_77 -> V_81 ;
V_85:
while ( F_15 ( V_42 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_19 ( struct V_6 * V_7 , T_2 V_53 )
{
V_7 -> V_1 = 0 ;
V_7 -> V_17 = F_20 ( V_53 ) ;
V_7 -> V_28 = ( V_87 ) V_53 ;
V_7 -> V_31 = ( V_87 ) V_53 ;
V_7 -> V_29 = V_53 ;
V_7 -> V_32 = V_53 ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_19 ( V_7 , 0 ) ;
}
static void F_22 ( struct V_6 * V_12 , V_65 V_88 )
{
if ( F_23 ( V_88 >= V_11 ) ) {
F_5 ( L_39 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_11 ; V_88 ++ )
F_24 ( V_12 + V_88 ) ;
return;
}
F_21 ( V_12 + V_88 ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
V_7 -> V_28 = F_26 ( V_87 , V_7 -> V_28 ,
V_7 -> V_17 . V_18 | ( V_7 -> V_17 . V_89 & V_30 ) ) ;
V_7 -> V_31 = F_27 ( V_87 , V_7 -> V_31 ,
V_7 -> V_17 . V_18 | ( V_7 -> V_17 . V_89 & V_33 ) ) ;
V_7 -> V_29 = F_28 ( V_7 -> V_29 , V_7 -> V_17 . V_18 ) ;
V_7 -> V_32 = F_29 ( V_7 -> V_32 ,
V_7 -> V_17 . V_18 | V_7 -> V_17 . V_89 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
if ( V_7 -> V_28 >= 0 || V_7 -> V_31 < 0 ) {
V_7 -> V_28 = V_7 -> V_29 = F_26 ( T_2 , V_7 -> V_28 ,
V_7 -> V_29 ) ;
V_7 -> V_31 = V_7 -> V_32 = F_27 ( T_2 , V_7 -> V_31 ,
V_7 -> V_32 ) ;
return;
}
if ( ( V_87 ) V_7 -> V_32 >= 0 ) {
V_7 -> V_28 = V_7 -> V_29 ;
V_7 -> V_31 = V_7 -> V_32 = F_27 ( T_2 , V_7 -> V_31 ,
V_7 -> V_32 ) ;
} else if ( ( V_87 ) V_7 -> V_29 < 0 ) {
V_7 -> V_28 = V_7 -> V_29 = F_26 ( T_2 , V_7 -> V_28 ,
V_7 -> V_29 ) ;
V_7 -> V_31 = V_7 -> V_32 ;
}
}
static void F_31 ( struct V_6 * V_7 )
{
V_7 -> V_17 = F_32 ( V_7 -> V_17 ,
F_33 ( V_7 -> V_29 ,
V_7 -> V_32 ) ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
V_7 -> V_28 = V_30 ;
V_7 -> V_31 = V_33 ;
V_7 -> V_29 = 0 ;
V_7 -> V_32 = V_34 ;
}
static void F_35 ( struct V_6 * V_7 )
{
V_7 -> type = V_15 ;
V_7 -> V_1 = 0 ;
V_7 -> V_19 = 0 ;
V_7 -> V_17 = V_90 ;
F_34 ( V_7 ) ;
}
static void F_36 ( struct V_6 * V_12 , V_65 V_88 )
{
if ( F_23 ( V_88 >= V_11 ) ) {
F_5 ( L_40 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_11 ; V_88 ++ )
F_24 ( V_12 + V_88 ) ;
return;
}
F_35 ( V_12 + V_88 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
F_35 ( V_7 ) ;
V_7 -> type = V_13 ;
}
static void F_37 ( struct V_6 * V_12 , V_65 V_88 )
{
if ( F_23 ( V_88 >= V_11 ) ) {
F_5 ( L_41 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_11 ; V_88 ++ )
F_24 ( V_12 + V_88 ) ;
return;
}
F_24 ( V_12 + V_88 ) ;
}
static void F_38 ( struct V_6 * V_12 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
F_37 ( V_12 , V_10 ) ;
V_12 [ V_10 ] . V_91 = V_92 ;
}
V_12 [ V_93 ] . type = V_16 ;
F_22 ( V_12 , V_93 ) ;
V_12 [ V_94 ] . type = V_95 ;
F_22 ( V_12 , V_94 ) ;
}
static void F_39 ( const struct V_4 * V_5 , V_65 V_88 )
{
struct V_4 * V_96 = V_5 -> V_96 ;
if ( V_88 == V_93 )
return;
while ( V_96 ) {
if ( V_5 -> V_12 [ V_88 ] . V_91 & V_97 )
break;
V_96 -> V_12 [ V_88 ] . V_91 |= V_98 ;
V_5 = V_96 ;
V_96 = V_5 -> V_96 ;
}
}
static int F_40 ( struct V_41 * V_42 , V_65 V_88 ,
enum V_99 V_9 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
if ( V_88 >= V_11 ) {
F_5 ( L_42 , V_88 ) ;
return - V_100 ;
}
if ( V_9 == V_101 ) {
if ( V_12 [ V_88 ] . type == V_13 ) {
F_5 ( L_43 , V_88 ) ;
return - V_102 ;
}
F_39 ( & V_42 -> V_80 , V_88 ) ;
} else {
if ( V_88 == V_93 ) {
F_5 ( L_44 ) ;
return - V_102 ;
}
V_12 [ V_88 ] . V_91 |= V_97 ;
if ( V_9 == V_103 )
F_36 ( V_12 , V_88 ) ;
}
return 0 ;
}
static bool F_41 ( enum V_8 type )
{
switch ( type ) {
case V_23 :
case V_24 :
case V_16 :
case V_95 :
case V_20 :
case V_104 :
case V_22 :
return true ;
default:
return false ;
}
}
static int F_42 ( struct V_4 * V_5 , int V_19 ,
int V_105 , int V_106 )
{
int V_10 , V_107 = ( V_36 + V_19 ) / V_37 ;
if ( V_106 >= 0 &&
F_41 ( V_5 -> V_12 [ V_106 ] . type ) ) {
if ( V_105 != V_37 ) {
F_5 ( L_45 ) ;
return - V_102 ;
}
V_5 -> V_40 [ V_107 ] = V_5 -> V_12 [ V_106 ] ;
V_5 -> V_40 [ V_107 ] . V_91 |= V_97 ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ )
V_5 -> V_38 [ V_36 + V_19 + V_10 ] = V_39 ;
} else {
V_5 -> V_40 [ V_107 ] = (struct V_6 ) {} ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ )
V_5 -> V_38 [ V_36 + V_19 + V_10 ] = V_108 ;
}
return 0 ;
}
static void F_43 ( const struct V_4 * V_5 , int V_109 )
{
struct V_4 * V_96 = V_5 -> V_96 ;
while ( V_96 ) {
if ( V_5 -> V_40 [ V_109 ] . V_91 & V_97 )
break;
V_96 -> V_40 [ V_109 ] . V_91 |= V_98 ;
V_5 = V_96 ;
V_96 = V_5 -> V_96 ;
}
}
static int F_44 ( struct V_4 * V_5 , int V_19 , int V_105 ,
int V_106 )
{
T_1 * V_110 ;
int V_10 , V_107 ;
V_110 = & V_5 -> V_38 [ V_36 + V_19 ] ;
if ( V_110 [ 0 ] == V_39 ) {
if ( V_105 != V_37 ) {
F_5 ( L_45 ) ;
return - V_102 ;
}
for ( V_10 = 1 ; V_10 < V_37 ; V_10 ++ ) {
if ( V_110 [ V_10 ] != V_39 ) {
F_5 ( L_46 ) ;
return - V_102 ;
}
}
V_107 = ( V_36 + V_19 ) / V_37 ;
if ( V_106 >= 0 ) {
V_5 -> V_12 [ V_106 ] = V_5 -> V_40 [ V_107 ] ;
F_43 ( V_5 , V_107 ) ;
}
return 0 ;
} else {
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
if ( V_110 [ V_10 ] != V_108 ) {
F_5 ( L_47 ,
V_19 , V_10 , V_105 ) ;
return - V_102 ;
}
}
if ( V_106 >= 0 )
F_36 ( V_5 -> V_12 , V_106 ) ;
return 0 ;
}
}
static int F_45 ( struct V_41 * V_42 , V_65 V_88 , int V_19 ,
int V_105 )
{
struct V_111 * V_112 = V_42 -> V_80 . V_12 [ V_88 ] . V_25 ;
if ( V_19 < 0 || V_105 <= 0 || V_19 + V_105 > V_112 -> V_27 ) {
F_5 ( L_48 ,
V_112 -> V_27 , V_19 , V_105 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_46 ( struct V_41 * V_42 , V_65 V_88 ,
int V_19 , int V_105 )
{
struct V_4 * V_5 = & V_42 -> V_80 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_88 ] ;
int V_85 ;
if ( V_113 )
F_4 ( V_5 ) ;
if ( V_7 -> V_28 < 0 ) {
F_5 ( L_49 ,
V_88 ) ;
return - V_102 ;
}
V_85 = F_45 ( V_42 , V_88 , V_7 -> V_28 + V_19 , V_105 ) ;
if ( V_85 ) {
F_5 ( L_50 , V_88 ) ;
return V_85 ;
}
if ( V_7 -> V_32 >= V_114 ) {
F_5 ( L_51 ,
V_88 ) ;
return - V_102 ;
}
V_85 = F_45 ( V_42 , V_88 , V_7 -> V_32 + V_19 , V_105 ) ;
if ( V_85 )
F_5 ( L_52 , V_88 ) ;
return V_85 ;
}
static bool F_47 ( struct V_41 * V_42 ,
const struct V_115 * V_116 ,
enum V_117 V_9 )
{
switch ( V_42 -> V_118 -> type ) {
case V_119 :
case V_120 :
if ( V_9 == V_121 )
return false ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
if ( V_116 )
return V_116 -> V_127 ;
V_42 -> V_128 = true ;
return true ;
default:
return false ;
}
}
static int F_48 ( struct V_41 * V_42 , V_65 V_88 ,
int V_19 , int V_105 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
struct V_6 * V_7 = & V_12 [ V_88 ] ;
if ( V_19 < 0 || V_105 <= 0 || ( T_2 ) V_19 + V_105 > V_7 -> V_21 ) {
F_5 ( L_53 ,
V_19 , V_105 , V_88 , V_7 -> V_1 , V_7 -> V_19 , V_7 -> V_21 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_49 ( struct V_41 * V_42 , V_65 V_88 , int V_19 ,
int V_105 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
struct V_6 * V_7 = & V_12 [ V_88 ] ;
int V_85 ;
if ( V_7 -> V_28 < 0 ) {
F_5 ( L_49 ,
V_88 ) ;
return - V_102 ;
}
V_85 = F_48 ( V_42 , V_88 , V_19 , V_105 ) ;
if ( V_85 ) {
F_5 ( L_54 , V_88 ) ;
return V_85 ;
}
return V_85 ;
}
static int F_50 ( struct V_41 * V_42 , int V_78 , int V_19 , int V_105 ,
enum V_117 V_9 , enum V_8 * V_129 )
{
struct V_130 V_131 = {
. V_129 = * V_129 ,
} ;
if ( V_42 -> V_132 )
return 0 ;
if ( V_42 -> V_118 -> V_133 -> V_134 -> V_135 &&
V_42 -> V_118 -> V_133 -> V_134 -> V_135 ( V_19 , V_105 , V_9 , & V_131 ) ) {
V_42 -> V_136 [ V_78 ] . V_137 = V_131 . V_137 ;
* V_129 = V_131 . V_129 ;
if ( V_42 -> V_118 -> V_133 -> V_138 < V_19 + V_105 )
V_42 -> V_118 -> V_133 -> V_138 = V_19 + V_105 ;
return 0 ;
}
F_5 ( L_55 , V_19 , V_105 ) ;
return - V_102 ;
}
static bool F_51 ( bool V_67 ,
const struct V_6 * V_7 )
{
if ( V_67 )
return false ;
return V_7 -> type != V_15 ;
}
static bool F_52 ( struct V_41 * V_42 , int V_88 )
{
return F_51 ( V_42 -> V_67 , & V_42 -> V_80 . V_12 [ V_88 ] ) ;
}
static int F_53 ( const struct V_6 * V_7 ,
int V_19 , int V_105 , bool V_139 )
{
struct V_140 V_141 ;
int V_142 ;
if ( ! V_139 || V_105 == 1 )
return 0 ;
V_142 = 2 ;
V_141 = F_54 ( V_7 -> V_17 , F_20 ( V_142 + V_7 -> V_19 + V_19 ) ) ;
if ( ! F_55 ( V_141 , V_105 ) ) {
char V_35 [ 48 ] ;
F_8 ( V_35 , sizeof( V_35 ) , V_7 -> V_17 ) ;
F_5 ( L_56 ,
V_142 , V_35 , V_7 -> V_19 , V_19 , V_105 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_56 ( const struct V_6 * V_7 ,
const char * V_143 ,
int V_19 , int V_105 , bool V_139 )
{
struct V_140 V_141 ;
if ( ! V_139 || V_105 == 1 )
return 0 ;
V_141 = F_54 ( V_7 -> V_17 , F_20 ( V_7 -> V_19 + V_19 ) ) ;
if ( ! F_55 ( V_141 , V_105 ) ) {
char V_35 [ 48 ] ;
F_8 ( V_35 , sizeof( V_35 ) , V_7 -> V_17 ) ;
F_5 ( L_57 ,
V_143 , V_35 , V_7 -> V_19 , V_19 , V_105 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_57 ( struct V_41 * V_42 ,
const struct V_6 * V_7 ,
int V_19 , int V_105 )
{
bool V_139 = V_42 -> V_144 ;
const char * V_143 = L_19 ;
switch ( V_7 -> type ) {
case V_20 :
return F_53 ( V_7 , V_19 , V_105 , V_139 ) ;
case V_23 :
V_143 = L_58 ;
break;
case V_95 :
V_143 = L_59 ;
break;
case V_16 :
V_143 = L_60 ;
break;
default:
break;
}
return F_56 ( V_7 , V_143 , V_19 , V_105 , V_139 ) ;
}
static int F_58 ( struct V_41 * V_42 , int V_78 , V_65 V_88 , int V_19 ,
int V_145 , enum V_117 V_9 ,
int V_106 )
{
struct V_4 * V_5 = & V_42 -> V_80 ;
struct V_6 * V_7 = & V_5 -> V_12 [ V_88 ] ;
int V_105 , V_85 = 0 ;
V_105 = F_59 ( V_145 ) ;
if ( V_105 < 0 )
return V_105 ;
V_85 = F_57 ( V_42 , V_7 , V_19 , V_105 ) ;
if ( V_85 )
return V_85 ;
V_19 += V_7 -> V_19 ;
if ( V_7 -> type == V_23 ) {
if ( V_9 == V_121 && V_106 >= 0 &&
F_52 ( V_42 , V_106 ) ) {
F_5 ( L_61 , V_106 ) ;
return - V_102 ;
}
V_85 = F_46 ( V_42 , V_88 , V_19 , V_105 ) ;
if ( ! V_85 && V_9 == V_146 && V_106 >= 0 )
F_36 ( V_5 -> V_12 , V_106 ) ;
} else if ( V_7 -> type == V_95 ) {
enum V_8 V_129 = V_15 ;
if ( V_9 == V_121 && V_106 >= 0 &&
F_52 ( V_42 , V_106 ) ) {
F_5 ( L_62 , V_106 ) ;
return - V_102 ;
}
if ( V_7 -> V_19 ) {
F_5 ( L_63 ,
V_88 , V_7 -> V_19 , V_19 - V_7 -> V_19 ) ;
return - V_102 ;
}
if ( ! F_6 ( V_7 -> V_17 ) || V_7 -> V_17 . V_18 ) {
char V_35 [ 48 ] ;
F_8 ( V_35 , sizeof( V_35 ) , V_7 -> V_17 ) ;
F_5 ( L_64 ,
V_35 , V_19 , V_105 ) ;
return - V_102 ;
}
V_85 = F_50 ( V_42 , V_78 , V_19 , V_105 , V_9 , & V_129 ) ;
if ( ! V_85 && V_9 == V_146 && V_106 >= 0 ) {
if ( V_129 == V_15 )
F_36 ( V_5 -> V_12 , V_106 ) ;
else
F_22 ( V_5 -> V_12 , V_106 ) ;
V_5 -> V_12 [ V_106 ] . V_1 = 0 ;
V_5 -> V_12 [ V_106 ] . V_19 = 0 ;
V_5 -> V_12 [ V_106 ] . V_21 = 0 ;
V_5 -> V_12 [ V_106 ] . type = V_129 ;
}
} else if ( V_7 -> type == V_16 ) {
if ( ! F_6 ( V_7 -> V_17 ) ) {
char V_35 [ 48 ] ;
F_8 ( V_35 , sizeof( V_35 ) , V_7 -> V_17 ) ;
F_5 ( L_65 ,
V_35 , V_19 , V_105 ) ;
return - V_102 ;
}
V_19 += V_7 -> V_17 . V_18 ;
if ( V_19 >= 0 || V_19 < - V_36 ) {
F_5 ( L_66 , V_19 , V_105 ) ;
return - V_102 ;
}
if ( V_42 -> V_118 -> V_133 -> V_147 < - V_19 )
V_42 -> V_118 -> V_133 -> V_147 = - V_19 ;
if ( V_9 == V_121 ) {
if ( ! V_42 -> V_67 &&
V_5 -> V_38 [ V_36 + V_19 ] == V_39 &&
V_105 != V_37 ) {
F_5 ( L_67 ) ;
return - V_102 ;
}
V_85 = F_42 ( V_5 , V_19 , V_105 , V_106 ) ;
} else {
V_85 = F_44 ( V_5 , V_19 , V_105 , V_106 ) ;
}
} else if ( V_7 -> type == V_20 ) {
if ( V_9 == V_121 && ! F_47 ( V_42 , NULL , V_9 ) ) {
F_5 ( L_68 ) ;
return - V_102 ;
}
if ( V_9 == V_121 && V_106 >= 0 &&
F_52 ( V_42 , V_106 ) ) {
F_5 ( L_69 , V_106 ) ;
return - V_102 ;
}
V_85 = F_49 ( V_42 , V_88 , V_19 , V_105 ) ;
if ( ! V_85 && V_9 == V_146 && V_106 >= 0 )
F_36 ( V_5 -> V_12 , V_106 ) ;
} else {
F_5 ( L_70 ,
V_88 , V_14 [ V_7 -> type ] ) ;
return - V_102 ;
}
if ( ! V_85 && V_105 < V_37 && V_106 >= 0 && V_9 == V_146 &&
V_5 -> V_12 [ V_106 ] . type == V_15 ) {
V_5 -> V_12 [ V_106 ] . V_17 = F_60 (
V_5 -> V_12 [ V_106 ] . V_17 , V_105 ) ;
F_25 ( & V_5 -> V_12 [ V_106 ] ) ;
}
return V_85 ;
}
static int F_61 ( struct V_41 * V_42 , int V_78 , struct V_43 * V_44 )
{
int V_85 ;
if ( ( F_14 ( V_44 -> V_46 ) != V_148 && F_14 ( V_44 -> V_46 ) != V_64 ) ||
V_44 -> V_53 != 0 ) {
F_5 ( L_71 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( F_52 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_72 , V_44 -> V_52 ) ;
return - V_102 ;
}
V_85 = F_58 ( V_42 , V_78 , V_44 -> V_50 , V_44 -> V_19 ,
F_14 ( V_44 -> V_46 ) , V_146 , - 1 ) ;
if ( V_85 )
return V_85 ;
return F_58 ( V_42 , V_78 , V_44 -> V_50 , V_44 -> V_19 ,
F_14 ( V_44 -> V_46 ) , V_121 , - 1 ) ;
}
static bool F_62 ( struct V_6 V_7 )
{
return V_7 . type == V_15 && F_63 ( V_7 . V_17 , 0 ) ;
}
static int F_64 ( struct V_41 * V_42 , int V_88 ,
int V_149 , bool V_150 ,
struct V_115 * V_116 )
{
struct V_4 * V_5 = & V_42 -> V_80 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_19 , V_10 ;
if ( V_12 [ V_88 ] . type != V_16 ) {
if ( V_150 && V_149 == 0 &&
F_62 ( V_12 [ V_88 ] ) )
return 0 ;
F_5 ( L_73 , V_88 ,
V_14 [ V_12 [ V_88 ] . type ] ,
V_14 [ V_16 ] ) ;
return - V_102 ;
}
if ( ! F_6 ( V_12 [ V_88 ] . V_17 ) ) {
char V_35 [ 48 ] ;
F_8 ( V_35 , sizeof( V_35 ) , V_12 [ V_88 ] . V_17 ) ;
F_5 ( L_74 ,
V_88 , V_35 ) ;
}
V_19 = V_12 [ V_88 ] . V_19 + V_12 [ V_88 ] . V_17 . V_18 ;
if ( V_19 >= 0 || V_19 < - V_36 || V_19 + V_149 > 0 ||
V_149 <= 0 ) {
F_5 ( L_75 ,
V_88 , V_19 , V_149 ) ;
return - V_102 ;
}
if ( V_42 -> V_118 -> V_133 -> V_147 < - V_19 )
V_42 -> V_118 -> V_133 -> V_147 = - V_19 ;
if ( V_116 && V_116 -> V_151 ) {
V_116 -> V_149 = V_149 ;
V_116 -> V_88 = V_88 ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_149 ; V_10 ++ ) {
if ( V_5 -> V_38 [ V_36 + V_19 + V_10 ] != V_108 ) {
F_5 ( L_76 ,
V_19 , V_10 , V_149 ) ;
return - V_102 ;
}
}
return 0 ;
}
static int F_65 ( struct V_41 * V_42 , int V_88 ,
int V_149 , bool V_150 ,
struct V_115 * V_116 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 , * V_7 = & V_12 [ V_88 ] ;
switch ( V_7 -> type ) {
case V_20 :
return F_49 ( V_42 , V_88 , V_7 -> V_19 , V_149 ) ;
case V_23 :
return F_46 ( V_42 , V_88 , V_7 -> V_19 , V_149 ) ;
default:
return F_64 ( V_42 , V_88 , V_149 ,
V_150 , V_116 ) ;
}
}
static int F_66 ( struct V_41 * V_42 , V_65 V_88 ,
enum V_152 V_153 ,
struct V_115 * V_116 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 , * V_7 = & V_12 [ V_88 ] ;
enum V_8 V_154 , type = V_7 -> type ;
int V_85 = 0 ;
if ( V_153 == V_155 )
return 0 ;
V_85 = F_40 ( V_42 , V_88 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( V_153 == V_156 ) {
if ( F_52 ( V_42 , V_88 ) ) {
F_5 ( L_77 , V_88 ) ;
return - V_102 ;
}
return 0 ;
}
if ( type == V_20 &&
! F_47 ( V_42 , V_116 , V_146 ) ) {
F_5 ( L_78 ) ;
return - V_102 ;
}
if ( V_153 == V_157 ||
V_153 == V_158 ) {
V_154 = V_16 ;
if ( type != V_20 && type != V_154 )
goto V_159;
} else if ( V_153 == V_160 ||
V_153 == V_161 ) {
V_154 = V_15 ;
if ( type != V_154 )
goto V_159;
} else if ( V_153 == V_162 ) {
V_154 = V_22 ;
if ( type != V_154 )
goto V_159;
} else if ( V_153 == V_163 ) {
V_154 = V_95 ;
if ( type != V_154 )
goto V_159;
} else if ( V_153 == V_164 ||
V_153 == V_165 ) {
V_154 = V_16 ;
if ( F_62 ( * V_7 ) )
;
else if ( type != V_20 && type != V_23 &&
type != V_154 )
goto V_159;
V_116 -> V_151 = V_153 == V_165 ;
} else {
F_5 ( L_79 , V_153 ) ;
return - V_166 ;
}
if ( V_153 == V_162 ) {
V_116 -> V_25 = V_7 -> V_25 ;
} else if ( V_153 == V_157 ) {
if ( ! V_116 -> V_25 ) {
F_5 ( L_80 ) ;
return - V_102 ;
}
if ( type == V_20 )
V_85 = F_49 ( V_42 , V_88 , V_7 -> V_19 ,
V_116 -> V_25 -> V_26 ) ;
else
V_85 = F_64 ( V_42 , V_88 ,
V_116 -> V_25 -> V_26 ,
false , NULL ) ;
} else if ( V_153 == V_158 ) {
if ( ! V_116 -> V_25 ) {
F_5 ( L_81 ) ;
return - V_102 ;
}
if ( type == V_20 )
V_85 = F_49 ( V_42 , V_88 , V_7 -> V_19 ,
V_116 -> V_25 -> V_27 ) ;
else
V_85 = F_64 ( V_42 , V_88 ,
V_116 -> V_25 -> V_27 ,
false , NULL ) ;
} else if ( V_153 == V_160 ||
V_153 == V_161 ) {
bool V_150 = ( V_153 == V_161 ) ;
if ( V_88 == 0 ) {
F_5 ( L_82 ) ;
return - V_102 ;
}
if ( ! F_6 ( V_7 -> V_17 ) )
V_116 = NULL ;
if ( V_7 -> V_28 < 0 ) {
F_5 ( L_83 ,
V_88 ) ;
return - V_102 ;
}
if ( V_7 -> V_29 == 0 ) {
V_85 = F_65 ( V_42 , V_88 - 1 , 0 ,
V_150 ,
V_116 ) ;
if ( V_85 )
return V_85 ;
}
if ( V_7 -> V_32 >= V_167 ) {
F_5 ( L_84 ,
V_88 ) ;
return - V_102 ;
}
V_85 = F_65 ( V_42 , V_88 - 1 ,
V_7 -> V_32 ,
V_150 , V_116 ) ;
}
return V_85 ;
V_159:
F_5 ( L_73 , V_88 ,
V_14 [ type ] , V_14 [ V_154 ] ) ;
return - V_102 ;
}
static int F_67 ( struct V_111 * V_112 , int V_168 )
{
if ( ! V_112 )
return 0 ;
switch ( V_112 -> V_169 ) {
case V_170 :
if ( V_168 != V_171 )
goto error;
break;
case V_172 :
if ( V_168 != V_173 &&
V_168 != V_174 )
goto error;
break;
case V_175 :
if ( V_168 != V_176 )
goto error;
break;
case V_177 :
if ( V_168 != V_178 &&
V_168 != V_179 )
goto error;
break;
case V_180 :
if ( V_168 != V_181 )
goto error;
break;
case V_182 :
case V_183 :
if ( V_168 != V_184 )
goto error;
break;
case V_185 :
if ( V_168 != V_186 &&
V_168 != V_187 &&
V_168 != V_188 )
goto error;
break;
default:
break;
}
switch ( V_168 ) {
case V_171 :
if ( V_112 -> V_169 != V_170 )
goto error;
break;
case V_173 :
case V_174 :
if ( V_112 -> V_169 != V_172 )
goto error;
break;
case V_176 :
if ( V_112 -> V_169 != V_175 )
goto error;
break;
case V_179 :
case V_178 :
if ( V_112 -> V_169 != V_177 )
goto error;
break;
case V_181 :
if ( V_112 -> V_169 != V_180 )
goto error;
break;
case V_186 :
if ( V_112 -> V_169 != V_185 )
goto error;
break;
case V_187 :
if ( V_112 -> V_169 != V_185 )
goto error;
break;
default:
break;
}
return 0 ;
error:
F_5 ( L_85 ,
V_112 -> V_169 , F_1 ( V_168 ) , V_168 ) ;
return - V_100 ;
}
static int F_68 ( const struct V_189 * V_190 )
{
int V_191 = 0 ;
if ( V_190 -> V_192 == V_165 )
V_191 ++ ;
if ( V_190 -> V_193 == V_165 )
V_191 ++ ;
if ( V_190 -> V_194 == V_165 )
V_191 ++ ;
if ( V_190 -> V_195 == V_165 )
V_191 ++ ;
if ( V_190 -> V_196 == V_165 )
V_191 ++ ;
return V_191 > 1 ? - V_100 : 0 ;
}
static void F_69 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = & V_42 -> V_80 ;
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_20 ||
V_12 [ V_10 ] . type == V_104 )
F_36 ( V_12 , V_10 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
V_7 = & V_5 -> V_40 [ V_10 / V_37 ] ;
if ( V_7 -> type != V_20 &&
V_7 -> type != V_104 )
continue;
F_35 ( V_7 ) ;
}
}
static int F_70 ( struct V_41 * V_42 , int V_168 , int V_78 )
{
struct V_4 * V_5 = & V_42 -> V_80 ;
const struct V_189 * V_190 = NULL ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_115 V_116 ;
bool V_197 ;
int V_10 , V_85 ;
if ( V_168 < 0 || V_168 >= V_3 ) {
F_5 ( L_86 , F_1 ( V_168 ) , V_168 ) ;
return - V_100 ;
}
if ( V_42 -> V_118 -> V_133 -> V_134 -> V_198 )
V_190 = V_42 -> V_118 -> V_133 -> V_134 -> V_198 ( V_168 ) ;
if ( ! V_190 ) {
F_5 ( L_87 , F_1 ( V_168 ) , V_168 ) ;
return - V_100 ;
}
if ( ! V_42 -> V_118 -> V_199 && V_190 -> V_200 ) {
F_5 ( L_88 ) ;
return - V_100 ;
}
V_197 = F_71 ( V_190 -> V_201 ) ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_127 = V_190 -> V_127 ;
V_85 = F_68 ( V_190 ) ;
if ( V_85 ) {
F_5 ( L_89 ,
F_1 ( V_168 ) , V_168 ) ;
return V_85 ;
}
V_85 = F_66 ( V_42 , V_94 , V_190 -> V_192 , & V_116 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_66 ( V_42 , V_202 , V_190 -> V_193 , & V_116 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_66 ( V_42 , V_203 , V_190 -> V_194 , & V_116 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_66 ( V_42 , V_204 , V_190 -> V_195 , & V_116 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_66 ( V_42 , V_205 , V_190 -> V_196 , & V_116 ) ;
if ( V_85 )
return V_85 ;
for ( V_10 = 0 ; V_10 < V_116 . V_149 ; V_10 ++ ) {
V_85 = F_58 ( V_42 , V_78 , V_116 . V_88 , V_10 , V_206 , V_121 , - 1 ) ;
if ( V_85 )
return V_85 ;
}
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ ) {
F_37 ( V_12 , V_208 [ V_10 ] ) ;
F_40 ( V_42 , V_208 [ V_10 ] , V_209 ) ;
}
if ( V_190 -> V_210 == V_211 ) {
F_36 ( V_12 , V_212 ) ;
} else if ( V_190 -> V_210 == V_213 ) {
V_12 [ V_212 ] . type = V_13 ;
} else if ( V_190 -> V_210 == V_214 ) {
struct V_215 * V_216 ;
V_12 [ V_212 ] . type = V_24 ;
F_22 ( V_12 , V_212 ) ;
V_12 [ V_212 ] . V_19 = 0 ;
if ( V_116 . V_25 == NULL ) {
F_5 ( L_90 ) ;
return - V_100 ;
}
V_12 [ V_212 ] . V_25 = V_116 . V_25 ;
V_12 [ V_212 ] . V_1 = ++ V_42 -> V_217 ;
V_216 = & V_42 -> V_136 [ V_78 ] ;
if ( ! V_216 -> V_25 )
V_216 -> V_25 = V_116 . V_25 ;
else if ( V_216 -> V_25 != V_116 . V_25 )
V_216 -> V_25 = V_218 ;
} else {
F_5 ( L_91 ,
V_190 -> V_210 , F_1 ( V_168 ) , V_168 ) ;
return - V_100 ;
}
V_85 = F_67 ( V_116 . V_25 , V_168 ) ;
if ( V_85 )
return V_85 ;
if ( V_197 )
F_69 ( V_42 ) ;
return 0 ;
}
static void F_72 ( struct V_6 * V_7 )
{
V_7 -> V_17 = F_60 ( V_7 -> V_17 , 4 ) ;
F_25 ( V_7 ) ;
}
static bool F_73 ( V_87 V_219 , V_87 V_220 )
{
V_87 V_221 = ( V_87 ) ( ( T_2 ) V_219 + ( T_2 ) V_220 ) ;
if ( V_220 < 0 )
return V_221 > V_219 ;
return V_221 < V_219 ;
}
static bool F_74 ( V_87 V_219 , V_87 V_220 )
{
V_87 V_221 = ( V_87 ) ( ( T_2 ) V_219 - ( T_2 ) V_220 ) ;
if ( V_220 < 0 )
return V_221 < V_219 ;
return V_221 > V_219 ;
}
static int F_75 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
const struct V_6 * V_222 ,
const struct V_6 * V_223 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 , * V_50 ;
bool V_224 = F_6 ( V_223 -> V_17 ) ;
V_87 V_225 = V_223 -> V_28 , V_226 = V_223 -> V_31 ,
V_227 = V_222 -> V_28 , V_228 = V_222 -> V_31 ;
T_2 V_229 = V_223 -> V_29 , V_230 = V_223 -> V_32 ,
V_231 = V_222 -> V_29 , V_232 = V_222 -> V_32 ;
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
V_65 V_233 = V_44 -> V_50 ;
V_50 = & V_12 [ V_233 ] ;
if ( F_76 ( V_224 && ( V_225 != V_226 ) ) ) {
F_4 ( & V_42 -> V_80 ) ;
F_5 ( L_92 ) ;
return - V_100 ;
}
if ( F_76 ( V_224 && ( V_229 != V_230 ) ) ) {
F_4 ( & V_42 -> V_80 ) ;
F_5 ( L_93 ) ;
return - V_100 ;
}
if ( F_10 ( V_44 -> V_46 ) != V_48 ) {
if ( ! V_42 -> V_67 )
F_5 ( L_94 ,
V_233 ) ;
return - V_102 ;
}
if ( V_222 -> type == V_24 ) {
if ( ! V_42 -> V_67 )
F_5 ( L_95 ,
V_233 ) ;
return - V_102 ;
}
if ( V_222 -> type == V_22 ) {
if ( ! V_42 -> V_67 )
F_5 ( L_96 ,
V_233 ) ;
return - V_102 ;
}
if ( V_222 -> type == V_104 ) {
if ( ! V_42 -> V_67 )
F_5 ( L_97 ,
V_233 ) ;
return - V_102 ;
}
V_50 -> type = V_222 -> type ;
V_50 -> V_1 = V_222 -> V_1 ;
switch ( V_69 ) {
case V_234 :
if ( V_224 && ( V_222 -> V_19 + V_225 ==
( V_87 ) ( V_235 ) ( V_222 -> V_19 + V_225 ) ) ) {
V_50 -> V_28 = V_227 ;
V_50 -> V_31 = V_228 ;
V_50 -> V_29 = V_231 ;
V_50 -> V_32 = V_232 ;
V_50 -> V_17 = V_222 -> V_17 ;
V_50 -> V_19 = V_222 -> V_19 + V_225 ;
V_50 -> V_21 = V_222 -> V_21 ;
break;
}
if ( F_73 ( V_227 , V_225 ) ||
F_73 ( V_228 , V_226 ) ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 = V_227 + V_225 ;
V_50 -> V_31 = V_228 + V_226 ;
}
if ( V_231 + V_229 < V_231 ||
V_232 + V_230 < V_232 ) {
V_50 -> V_29 = 0 ;
V_50 -> V_32 = V_34 ;
} else {
V_50 -> V_29 = V_231 + V_229 ;
V_50 -> V_32 = V_232 + V_230 ;
}
V_50 -> V_17 = F_54 ( V_222 -> V_17 , V_223 -> V_17 ) ;
V_50 -> V_19 = V_222 -> V_19 ;
if ( V_222 -> type == V_20 ) {
V_50 -> V_1 = ++ V_42 -> V_217 ;
V_50 -> V_21 = 0 ;
}
break;
case V_236 :
if ( V_50 == V_223 ) {
if ( ! V_42 -> V_67 )
F_5 ( L_98 ,
V_233 ) ;
return - V_102 ;
}
if ( V_222 -> type == V_16 ) {
if ( ! V_42 -> V_67 )
F_5 ( L_99 ,
V_233 ) ;
return - V_102 ;
}
if ( V_224 && ( V_222 -> V_19 - V_225 ==
( V_87 ) ( V_235 ) ( V_222 -> V_19 - V_225 ) ) ) {
V_50 -> V_28 = V_227 ;
V_50 -> V_31 = V_228 ;
V_50 -> V_29 = V_231 ;
V_50 -> V_32 = V_232 ;
V_50 -> V_17 = V_222 -> V_17 ;
V_50 -> V_1 = V_222 -> V_1 ;
V_50 -> V_19 = V_222 -> V_19 - V_225 ;
V_50 -> V_21 = V_222 -> V_21 ;
break;
}
if ( F_74 ( V_227 , V_226 ) ||
F_74 ( V_228 , V_225 ) ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 = V_227 - V_226 ;
V_50 -> V_31 = V_228 - V_225 ;
}
if ( V_231 < V_230 ) {
V_50 -> V_29 = 0 ;
V_50 -> V_32 = V_34 ;
} else {
V_50 -> V_29 = V_231 - V_230 ;
V_50 -> V_32 = V_232 - V_229 ;
}
V_50 -> V_17 = F_77 ( V_222 -> V_17 , V_223 -> V_17 ) ;
V_50 -> V_19 = V_222 -> V_19 ;
if ( V_222 -> type == V_20 ) {
V_50 -> V_1 = ++ V_42 -> V_217 ;
if ( V_225 < 0 )
V_50 -> V_21 = 0 ;
}
break;
case V_237 :
case V_238 :
case V_239 :
if ( ! V_42 -> V_67 )
F_5 ( L_100 ,
V_233 , V_51 [ V_69 >> 4 ] ) ;
return - V_102 ;
default:
if ( ! V_42 -> V_67 )
F_5 ( L_101 ,
V_233 , V_51 [ V_69 >> 4 ] ) ;
return - V_102 ;
}
F_25 ( V_50 ) ;
F_30 ( V_50 ) ;
F_31 ( V_50 ) ;
return 0 ;
}
static int F_78 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
struct V_6 * V_50 ,
struct V_6 V_52 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
bool V_240 , V_241 ;
V_87 V_225 , V_226 ;
T_2 V_229 , V_230 ;
if ( F_10 ( V_44 -> V_46 ) != V_48 ) {
F_72 ( V_50 ) ;
F_72 ( & V_52 ) ;
}
V_225 = V_52 . V_28 ;
V_226 = V_52 . V_31 ;
V_229 = V_52 . V_29 ;
V_230 = V_52 . V_32 ;
V_240 = F_6 ( V_52 . V_17 ) ;
V_241 = F_6 ( V_50 -> V_17 ) ;
switch ( V_69 ) {
case V_234 :
if ( F_73 ( V_50 -> V_28 , V_225 ) ||
F_73 ( V_50 -> V_31 , V_226 ) ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 += V_225 ;
V_50 -> V_31 += V_226 ;
}
if ( V_50 -> V_29 + V_229 < V_229 ||
V_50 -> V_32 + V_230 < V_230 ) {
V_50 -> V_29 = 0 ;
V_50 -> V_32 = V_34 ;
} else {
V_50 -> V_29 += V_229 ;
V_50 -> V_32 += V_230 ;
}
V_50 -> V_17 = F_54 ( V_50 -> V_17 , V_52 . V_17 ) ;
break;
case V_236 :
if ( F_74 ( V_50 -> V_28 , V_226 ) ||
F_74 ( V_50 -> V_31 , V_225 ) ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 -= V_226 ;
V_50 -> V_31 -= V_225 ;
}
if ( V_50 -> V_29 < V_230 ) {
V_50 -> V_29 = 0 ;
V_50 -> V_32 = V_34 ;
} else {
V_50 -> V_29 -= V_230 ;
V_50 -> V_32 -= V_229 ;
}
V_50 -> V_17 = F_77 ( V_50 -> V_17 , V_52 . V_17 ) ;
break;
case V_242 :
V_50 -> V_17 = F_79 ( V_50 -> V_17 , V_52 . V_17 ) ;
if ( V_225 < 0 || V_50 -> V_28 < 0 ) {
F_34 ( V_50 ) ;
F_25 ( V_50 ) ;
break;
}
if ( V_230 > V_243 || V_50 -> V_32 > V_243 ) {
F_34 ( V_50 ) ;
F_25 ( V_50 ) ;
break;
}
V_50 -> V_29 *= V_229 ;
V_50 -> V_32 *= V_230 ;
if ( V_50 -> V_32 > V_33 ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 = V_50 -> V_29 ;
V_50 -> V_31 = V_50 -> V_32 ;
}
break;
case V_237 :
if ( V_240 && V_241 ) {
F_19 ( V_50 , V_50 -> V_17 . V_18 &
V_52 . V_17 . V_18 ) ;
break;
}
V_50 -> V_17 = F_80 ( V_50 -> V_17 , V_52 . V_17 ) ;
V_50 -> V_29 = V_50 -> V_17 . V_18 ;
V_50 -> V_32 = F_29 ( V_50 -> V_32 , V_230 ) ;
if ( V_50 -> V_28 < 0 || V_225 < 0 ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 = V_50 -> V_29 ;
V_50 -> V_31 = V_50 -> V_32 ;
}
F_25 ( V_50 ) ;
break;
case V_238 :
if ( V_240 && V_241 ) {
F_19 ( V_50 , V_50 -> V_17 . V_18 |
V_52 . V_17 . V_18 ) ;
break;
}
V_50 -> V_17 = F_81 ( V_50 -> V_17 , V_52 . V_17 ) ;
V_50 -> V_29 = F_28 ( V_50 -> V_29 , V_229 ) ;
V_50 -> V_32 = V_50 -> V_17 . V_18 |
V_50 -> V_17 . V_89 ;
if ( V_50 -> V_28 < 0 || V_225 < 0 ) {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
} else {
V_50 -> V_28 = V_50 -> V_29 ;
V_50 -> V_31 = V_50 -> V_32 ;
}
F_25 ( V_50 ) ;
break;
case V_244 :
if ( V_230 > 63 ) {
F_36 ( V_12 , V_44 -> V_50 ) ;
break;
}
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
if ( V_50 -> V_32 > 1ULL << ( 63 - V_230 ) ) {
V_50 -> V_29 = 0 ;
V_50 -> V_32 = V_34 ;
} else {
V_50 -> V_29 <<= V_229 ;
V_50 -> V_32 <<= V_230 ;
}
if ( V_240 )
V_50 -> V_17 = F_82 ( V_50 -> V_17 , V_229 ) ;
else
V_50 -> V_17 = F_82 ( V_90 , V_229 ) ;
F_25 ( V_50 ) ;
break;
case V_245 :
if ( V_230 > 63 ) {
F_36 ( V_12 , V_44 -> V_50 ) ;
break;
}
if ( V_50 -> V_28 < 0 ) {
if ( V_229 ) {
V_50 -> V_28 = 0 ;
} else {
V_50 -> V_28 = V_30 ;
V_50 -> V_31 = V_33 ;
}
} else {
V_50 -> V_28 =
( T_2 ) ( V_50 -> V_28 ) >> V_230 ;
}
if ( V_240 )
V_50 -> V_17 = F_83 ( V_50 -> V_17 ,
V_229 ) ;
else
V_50 -> V_17 = F_83 ( V_90 , V_229 ) ;
V_50 -> V_29 >>= V_230 ;
V_50 -> V_32 >>= V_229 ;
F_25 ( V_50 ) ;
break;
default:
F_36 ( V_12 , V_44 -> V_50 ) ;
break;
}
F_30 ( V_50 ) ;
F_31 ( V_50 ) ;
return 0 ;
}
static int F_84 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 , * V_50 , * V_52 ;
struct V_6 * V_222 = NULL , V_223 = { 0 } ;
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
int V_246 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
V_52 = NULL ;
if ( V_50 -> type != V_15 )
V_222 = V_50 ;
if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
V_52 = & V_12 [ V_44 -> V_52 ] ;
if ( V_52 -> type != V_15 ) {
if ( V_50 -> type != V_15 ) {
if ( ! V_42 -> V_67 ) {
F_5 ( L_102 ,
V_44 -> V_50 ,
V_51 [ V_69 >> 4 ] ) ;
return - V_102 ;
}
F_36 ( V_12 , V_44 -> V_50 ) ;
return 0 ;
} else {
V_246 = F_75 ( V_42 , V_44 ,
V_52 , V_50 ) ;
if ( V_246 == - V_102 && V_42 -> V_67 ) {
F_35 ( & V_223 ) ;
return F_78 (
V_42 , V_44 ,
V_50 , V_223 ) ;
}
return V_246 ;
}
} else if ( V_222 ) {
V_246 = F_75 ( V_42 , V_44 ,
V_50 , V_52 ) ;
if ( V_246 == - V_102 && V_42 -> V_67 ) {
F_35 ( V_50 ) ;
return F_78 (
V_42 , V_44 , V_50 , * V_52 ) ;
}
return V_246 ;
}
} else {
V_223 . type = V_15 ;
F_19 ( & V_223 , V_44 -> V_53 ) ;
V_52 = & V_223 ;
if ( V_222 ) {
V_246 = F_75 ( V_42 , V_44 ,
V_222 , V_52 ) ;
if ( V_246 == - V_102 && V_42 -> V_67 ) {
F_35 ( V_50 ) ;
return F_78 (
V_42 , V_44 , V_50 , V_223 ) ;
}
return V_246 ;
}
}
if ( F_76 ( V_222 ) ) {
F_4 ( & V_42 -> V_80 ) ;
F_5 ( L_103 ) ;
return - V_100 ;
}
if ( F_23 ( ! V_52 ) ) {
F_4 ( & V_42 -> V_80 ) ;
F_5 ( L_104 ) ;
return - V_100 ;
}
return F_78 ( V_42 , V_44 , V_50 , * V_52 ) ;
}
static int F_85 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
int V_85 ;
if ( V_69 == V_247 || V_69 == V_248 ) {
if ( V_69 == V_248 ) {
if ( F_11 ( V_44 -> V_46 ) != 0 ||
V_44 -> V_52 != V_212 ||
V_44 -> V_19 != 0 || V_44 -> V_53 != 0 ) {
F_5 ( L_105 ) ;
return - V_100 ;
}
} else {
if ( V_44 -> V_52 != V_212 || V_44 -> V_19 != 0 ||
( V_44 -> V_53 != 16 && V_44 -> V_53 != 32 && V_44 -> V_53 != 64 ) ||
F_10 ( V_44 -> V_46 ) == V_48 ) {
F_5 ( L_106 ) ;
return - V_100 ;
}
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( F_52 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_107 ,
V_44 -> V_50 ) ;
return - V_102 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_103 ) ;
if ( V_85 )
return V_85 ;
} else if ( V_69 == V_249 ) {
if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_53 != 0 || V_44 -> V_19 != 0 ) {
F_5 ( L_108 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
} else {
if ( V_44 -> V_52 != V_212 || V_44 -> V_19 != 0 ) {
F_5 ( L_108 ) ;
return - V_100 ;
}
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_103 ) ;
if ( V_85 )
return V_85 ;
if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
if ( F_10 ( V_44 -> V_46 ) == V_48 ) {
V_12 [ V_44 -> V_50 ] = V_12 [ V_44 -> V_52 ] ;
V_12 [ V_44 -> V_50 ] . V_91 |= V_97 ;
} else {
if ( F_52 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_109 ,
V_44 -> V_52 ) ;
return - V_102 ;
}
F_36 ( V_12 , V_44 -> V_50 ) ;
V_12 [ V_44 -> V_50 ] . V_17 = F_60 (
V_12 [ V_44 -> V_50 ] . V_17 , 4 ) ;
F_25 ( & V_12 [ V_44 -> V_50 ] ) ;
}
} else {
V_12 [ V_44 -> V_50 ] . type = V_15 ;
F_19 ( V_12 + V_44 -> V_50 , V_44 -> V_53 ) ;
}
} else if ( V_69 > V_247 ) {
F_5 ( L_110 , V_69 ) ;
return - V_100 ;
} else {
if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_53 != 0 || V_44 -> V_19 != 0 ) {
F_5 ( L_111 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
} else {
if ( V_44 -> V_52 != V_212 || V_44 -> V_19 != 0 ) {
F_5 ( L_111 ) ;
return - V_100 ;
}
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( ( V_69 == V_250 || V_69 == V_251 ) &&
F_11 ( V_44 -> V_46 ) == V_252 && V_44 -> V_53 == 0 ) {
F_5 ( L_112 ) ;
return - V_100 ;
}
if ( ( V_69 == V_244 || V_69 == V_245 ||
V_69 == V_253 ) && F_11 ( V_44 -> V_46 ) == V_252 ) {
int V_105 = F_10 ( V_44 -> V_46 ) == V_48 ? 64 : 32 ;
if ( V_44 -> V_53 < 0 || V_44 -> V_53 >= V_105 ) {
F_5 ( L_113 , V_44 -> V_53 ) ;
return - V_100 ;
}
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_209 ) ;
if ( V_85 )
return V_85 ;
return F_84 ( V_42 , V_44 ) ;
}
return 0 ;
}
static void F_86 ( struct V_4 * V_5 ,
struct V_6 * V_50 ,
bool V_254 )
{
struct V_6 * V_12 = V_5 -> V_12 , * V_7 ;
T_3 V_255 ;
int V_10 ;
if ( V_50 -> V_19 < 0 ||
( V_50 -> V_19 == 0 && V_254 ) )
return;
if ( V_50 -> V_32 > V_256 ||
V_50 -> V_32 + V_50 -> V_19 > V_256 )
return;
V_255 = V_50 -> V_19 ;
if ( V_254 )
V_255 -- ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] . type == V_20 && V_12 [ V_10 ] . V_1 == V_50 -> V_1 )
V_12 [ V_10 ] . V_21 = F_28 ( V_12 [ V_10 ] . V_21 , V_255 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
V_7 = & V_5 -> V_40 [ V_10 / V_37 ] ;
if ( V_7 -> type == V_20 && V_7 -> V_1 == V_50 -> V_1 )
V_7 -> V_21 = F_28 ( V_7 -> V_21 , V_255 ) ;
}
}
static void F_87 ( struct V_6 * V_257 ,
struct V_6 * V_258 , T_2 V_259 ,
T_1 V_69 )
{
if ( F_51 ( false , V_258 ) )
return;
switch ( V_69 ) {
case V_260 :
F_19 ( V_257 , V_259 ) ;
break;
case V_261 :
F_19 ( V_258 , V_259 ) ;
break;
case V_262 :
V_258 -> V_32 = F_29 ( V_258 -> V_32 , V_259 ) ;
V_257 -> V_29 = F_28 ( V_257 -> V_29 , V_259 + 1 ) ;
break;
case V_263 :
V_258 -> V_31 = F_27 ( V_87 , V_258 -> V_31 , V_259 ) ;
V_257 -> V_28 = F_26 ( V_87 , V_257 -> V_28 , V_259 + 1 ) ;
break;
case V_264 :
V_258 -> V_29 = F_28 ( V_258 -> V_29 , V_259 ) ;
V_257 -> V_32 = F_29 ( V_257 -> V_32 , V_259 - 1 ) ;
break;
case V_265 :
V_258 -> V_28 = F_26 ( V_87 , V_258 -> V_28 , V_259 ) ;
V_257 -> V_31 = F_27 ( V_87 , V_257 -> V_31 , V_259 - 1 ) ;
break;
case V_266 :
V_258 -> V_32 = F_29 ( V_258 -> V_32 , V_259 - 1 ) ;
V_257 -> V_29 = F_28 ( V_257 -> V_29 , V_259 ) ;
break;
case V_267 :
V_258 -> V_31 = F_27 ( V_87 , V_258 -> V_31 , V_259 - 1 ) ;
V_257 -> V_28 = F_26 ( V_87 , V_257 -> V_28 , V_259 ) ;
break;
case V_268 :
V_258 -> V_29 = F_28 ( V_258 -> V_29 , V_259 + 1 ) ;
V_257 -> V_32 = F_29 ( V_257 -> V_32 , V_259 ) ;
break;
case V_269 :
V_258 -> V_28 = F_26 ( V_87 , V_258 -> V_28 , V_259 + 1 ) ;
V_257 -> V_31 = F_27 ( V_87 , V_257 -> V_31 , V_259 ) ;
break;
default:
break;
}
F_30 ( V_258 ) ;
F_30 ( V_257 ) ;
F_31 ( V_258 ) ;
F_31 ( V_257 ) ;
F_25 ( V_258 ) ;
F_25 ( V_257 ) ;
}
static void F_88 ( struct V_6 * V_257 ,
struct V_6 * V_258 , T_2 V_259 ,
T_1 V_69 )
{
if ( F_51 ( false , V_258 ) )
return;
switch ( V_69 ) {
case V_260 :
F_19 ( V_257 , V_259 ) ;
break;
case V_261 :
F_19 ( V_258 , V_259 ) ;
break;
case V_262 :
V_257 -> V_32 = F_29 ( V_257 -> V_32 , V_259 - 1 ) ;
V_258 -> V_29 = F_28 ( V_258 -> V_29 , V_259 ) ;
break;
case V_263 :
V_257 -> V_31 = F_27 ( V_87 , V_257 -> V_31 , V_259 - 1 ) ;
V_258 -> V_28 = F_26 ( V_87 , V_258 -> V_28 , V_259 ) ;
break;
case V_264 :
V_257 -> V_29 = F_28 ( V_257 -> V_29 , V_259 + 1 ) ;
V_258 -> V_32 = F_29 ( V_258 -> V_32 , V_259 ) ;
break;
case V_265 :
V_257 -> V_28 = F_26 ( V_87 , V_257 -> V_28 , V_259 + 1 ) ;
V_258 -> V_31 = F_27 ( V_87 , V_258 -> V_31 , V_259 ) ;
break;
case V_266 :
V_257 -> V_32 = F_29 ( V_257 -> V_32 , V_259 ) ;
V_258 -> V_29 = F_28 ( V_258 -> V_29 , V_259 + 1 ) ;
break;
case V_267 :
V_257 -> V_31 = F_27 ( V_87 , V_257 -> V_31 , V_259 ) ;
V_258 -> V_28 = F_26 ( V_87 , V_258 -> V_28 , V_259 + 1 ) ;
break;
case V_268 :
V_257 -> V_29 = F_28 ( V_257 -> V_29 , V_259 ) ;
V_258 -> V_32 = F_29 ( V_258 -> V_32 , V_259 - 1 ) ;
break;
case V_269 :
V_257 -> V_28 = F_26 ( V_87 , V_257 -> V_28 , V_259 ) ;
V_258 -> V_31 = F_27 ( V_87 , V_258 -> V_31 , V_259 - 1 ) ;
break;
default:
break;
}
F_30 ( V_258 ) ;
F_30 ( V_257 ) ;
F_31 ( V_258 ) ;
F_31 ( V_257 ) ;
F_25 ( V_258 ) ;
F_25 ( V_257 ) ;
}
static void F_89 ( struct V_6 * V_52 ,
struct V_6 * V_50 )
{
V_52 -> V_29 = V_50 -> V_29 = F_28 ( V_52 -> V_29 ,
V_50 -> V_29 ) ;
V_52 -> V_32 = V_50 -> V_32 = F_29 ( V_52 -> V_32 ,
V_50 -> V_32 ) ;
V_52 -> V_28 = V_50 -> V_28 = F_28 ( V_52 -> V_28 ,
V_50 -> V_28 ) ;
V_52 -> V_31 = V_50 -> V_31 = F_29 ( V_52 -> V_31 ,
V_50 -> V_31 ) ;
V_52 -> V_17 = V_50 -> V_17 = F_32 ( V_52 -> V_17 ,
V_50 -> V_17 ) ;
F_25 ( V_52 ) ;
F_25 ( V_50 ) ;
F_30 ( V_52 ) ;
F_30 ( V_50 ) ;
F_31 ( V_52 ) ;
F_31 ( V_50 ) ;
F_25 ( V_52 ) ;
F_25 ( V_50 ) ;
}
static void F_90 ( struct V_6 * V_270 ,
struct V_6 * V_271 ,
struct V_6 * V_272 ,
struct V_6 * V_273 ,
T_1 V_69 )
{
switch ( V_69 ) {
case V_260 :
F_89 ( V_270 , V_271 ) ;
break;
case V_261 :
F_89 ( V_272 , V_273 ) ;
break;
}
}
static void F_91 ( struct V_6 * V_12 , V_65 V_88 , V_65 V_1 ,
bool V_274 )
{
struct V_6 * V_7 = & V_12 [ V_88 ] ;
if ( V_7 -> type == V_24 && V_7 -> V_1 == V_1 ) {
if ( F_76 ( V_7 -> V_28 || V_7 -> V_31 ||
! F_63 ( V_7 -> V_17 , 0 ) ||
V_7 -> V_19 ) ) {
F_21 ( V_7 ) ;
V_7 -> V_19 = 0 ;
}
if ( V_274 ) {
V_7 -> type = V_15 ;
} else if ( V_7 -> V_25 -> V_275 ) {
V_7 -> type = V_22 ;
V_7 -> V_25 = V_7 -> V_25 -> V_275 ;
} else {
V_7 -> type = V_23 ;
}
V_7 -> V_1 = 0 ;
}
}
static void F_92 ( struct V_4 * V_5 , V_65 V_88 ,
bool V_274 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
V_65 V_1 = V_12 [ V_88 ] . V_1 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_91 ( V_12 , V_10 , V_1 , V_274 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 += V_37 ) {
if ( V_5 -> V_38 [ V_10 ] != V_39 )
continue;
F_91 ( V_5 -> V_40 , V_10 / V_37 , V_1 , V_274 ) ;
}
}
static int F_93 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int * V_78 )
{
struct V_4 * V_276 , * V_277 = & V_42 -> V_80 ;
struct V_6 * V_12 = V_277 -> V_12 , * V_50 ;
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
int V_85 ;
if ( V_69 > V_269 ) {
F_5 ( L_114 , V_69 ) ;
return - V_100 ;
}
if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
if ( V_44 -> V_53 != 0 ) {
F_5 ( L_115 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( F_52 ( V_42 , V_44 -> V_52 ) ) {
F_5 ( L_116 ,
V_44 -> V_52 ) ;
return - V_102 ;
}
} else {
if ( V_44 -> V_52 != V_212 ) {
F_5 ( L_115 ) ;
return - V_100 ;
}
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_50 = & V_12 [ V_44 -> V_50 ] ;
if ( F_11 ( V_44 -> V_46 ) == V_252 &&
( V_69 == V_260 || V_69 == V_261 ) &&
V_50 -> type == V_15 &&
F_63 ( V_50 -> V_17 , V_44 -> V_53 ) ) {
if ( V_69 == V_260 ) {
* V_78 += V_44 -> V_19 ;
return 0 ;
} else {
return 0 ;
}
}
V_276 = F_17 ( V_42 , * V_78 + V_44 -> V_19 + 1 , * V_78 ) ;
if ( ! V_276 )
return - V_166 ;
if ( F_11 ( V_44 -> V_46 ) == V_49 ) {
if ( V_50 -> type == V_15 &&
V_12 [ V_44 -> V_52 ] . type == V_15 ) {
if ( F_6 ( V_12 [ V_44 -> V_52 ] . V_17 ) )
F_87 ( & V_276 -> V_12 [ V_44 -> V_50 ] ,
V_50 , V_12 [ V_44 -> V_52 ] . V_17 . V_18 ,
V_69 ) ;
else if ( F_6 ( V_50 -> V_17 ) )
F_88 ( & V_276 -> V_12 [ V_44 -> V_52 ] ,
& V_12 [ V_44 -> V_52 ] ,
V_50 -> V_17 . V_18 , V_69 ) ;
else if ( V_69 == V_260 || V_69 == V_261 )
F_90 ( & V_276 -> V_12 [ V_44 -> V_52 ] ,
& V_276 -> V_12 [ V_44 -> V_50 ] ,
& V_12 [ V_44 -> V_52 ] ,
& V_12 [ V_44 -> V_50 ] , V_69 ) ;
}
} else if ( V_50 -> type == V_15 ) {
F_87 ( & V_276 -> V_12 [ V_44 -> V_50 ] ,
V_50 , V_44 -> V_53 , V_69 ) ;
}
if ( F_11 ( V_44 -> V_46 ) == V_252 &&
V_44 -> V_53 == 0 && ( V_69 == V_260 || V_69 == V_261 ) &&
V_50 -> type == V_24 ) {
F_92 ( V_277 , V_44 -> V_50 , V_69 == V_261 ) ;
F_92 ( V_276 , V_44 -> V_50 , V_69 == V_260 ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_262 &&
V_50 -> type == V_20 &&
V_12 [ V_44 -> V_52 ] . type == V_104 ) {
F_86 ( V_277 , V_50 , false ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_262 &&
V_50 -> type == V_104 &&
V_12 [ V_44 -> V_52 ] . type == V_20 ) {
F_86 ( V_276 , & V_12 [ V_44 -> V_52 ] , true ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_264 &&
V_50 -> type == V_20 &&
V_12 [ V_44 -> V_52 ] . type == V_104 ) {
F_86 ( V_276 , V_50 , true ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_264 &&
V_50 -> type == V_104 &&
V_12 [ V_44 -> V_52 ] . type == V_20 ) {
F_86 ( V_277 , & V_12 [ V_44 -> V_52 ] , false ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_266 &&
V_50 -> type == V_20 &&
V_12 [ V_44 -> V_52 ] . type == V_104 ) {
F_86 ( V_277 , V_50 , true ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_266 &&
V_50 -> type == V_104 &&
V_12 [ V_44 -> V_52 ] . type == V_20 ) {
F_86 ( V_276 , & V_12 [ V_44 -> V_52 ] , false ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_268 &&
V_50 -> type == V_20 &&
V_12 [ V_44 -> V_52 ] . type == V_104 ) {
F_86 ( V_276 , V_50 , false ) ;
} else if ( F_11 ( V_44 -> V_46 ) == V_49 && V_69 == V_268 &&
V_50 -> type == V_104 &&
V_12 [ V_44 -> V_52 ] . type == V_20 ) {
F_86 ( V_277 , & V_12 [ V_44 -> V_52 ] , true ) ;
} else if ( F_52 ( V_42 , V_44 -> V_50 ) ) {
F_5 ( L_116 , V_44 -> V_50 ) ;
return - V_102 ;
}
if ( V_113 )
F_4 ( V_277 ) ;
return 0 ;
}
static struct V_111 * F_94 ( struct V_43 * V_44 )
{
T_2 V_278 = ( ( T_2 ) ( V_65 ) V_44 [ 0 ] . V_53 ) | ( ( T_2 ) ( V_65 ) V_44 [ 1 ] . V_53 ) << 32 ;
return (struct V_111 * ) ( unsigned long ) V_278 ;
}
static int F_95 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
int V_85 ;
if ( F_14 ( V_44 -> V_46 ) != V_64 ) {
F_5 ( L_117 ) ;
return - V_100 ;
}
if ( V_44 -> V_19 != 0 ) {
F_5 ( L_118 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_103 ) ;
if ( V_85 )
return V_85 ;
if ( V_44 -> V_52 == 0 ) {
T_2 V_53 = ( ( T_2 ) ( V_44 + 1 ) -> V_53 << 32 ) | ( V_65 ) V_44 -> V_53 ;
V_12 [ V_44 -> V_50 ] . type = V_15 ;
F_19 ( & V_12 [ V_44 -> V_50 ] , V_53 ) ;
return 0 ;
}
F_96 ( V_44 -> V_52 != V_66 ) ;
V_12 [ V_44 -> V_50 ] . type = V_22 ;
V_12 [ V_44 -> V_50 ] . V_25 = F_94 ( V_44 ) ;
return 0 ;
}
static bool F_97 ( enum V_279 type )
{
switch ( type ) {
case V_280 :
case V_122 :
case V_123 :
return true ;
default:
return false ;
}
}
static int F_98 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_12 = V_42 -> V_80 . V_12 ;
T_1 V_281 = F_13 ( V_44 -> V_46 ) ;
int V_10 , V_85 ;
if ( ! F_97 ( V_42 -> V_118 -> type ) ) {
F_5 ( L_119 ) ;
return - V_100 ;
}
if ( V_44 -> V_50 != V_212 || V_44 -> V_19 != 0 ||
F_14 ( V_44 -> V_46 ) == V_64 ||
( V_281 == V_61 && V_44 -> V_52 != V_212 ) ) {
F_5 ( L_120 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_282 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( V_12 [ V_282 ] . type != V_95 ) {
F_5 ( L_121 ) ;
return - V_100 ;
}
if ( V_281 == V_62 ) {
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
}
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ ) {
F_37 ( V_12 , V_208 [ V_10 ] ) ;
F_40 ( V_42 , V_208 [ V_10 ] , V_209 ) ;
}
F_36 ( V_12 , V_212 ) ;
return 0 ;
}
static int F_99 ( int V_9 , int V_283 , int V_284 , struct V_41 * V_42 )
{
if ( V_284 == V_285 && V_286 [ V_9 ] >= ( V_287 | V_285 ) )
return 0 ;
if ( V_284 == V_288 && V_286 [ V_9 ] >= ( V_287 | V_288 ) )
return 0 ;
if ( V_283 < 0 || V_283 >= V_42 -> V_118 -> V_289 ) {
F_5 ( L_122 , V_9 , V_283 ) ;
return - V_100 ;
}
if ( V_284 == V_288 )
V_42 -> V_290 [ V_283 ] = V_291 ;
if ( V_286 [ V_283 ] == 0 ) {
V_286 [ V_9 ] = V_287 | V_284 ;
V_286 [ V_283 ] = V_287 ;
if ( V_292 >= V_42 -> V_118 -> V_289 )
return - V_293 ;
V_294 [ V_292 ++ ] = V_283 ;
return 1 ;
} else if ( ( V_286 [ V_283 ] & 0xF0 ) == V_287 ) {
F_5 ( L_123 , V_9 , V_283 ) ;
return - V_100 ;
} else if ( V_286 [ V_283 ] == V_295 ) {
V_286 [ V_9 ] = V_287 | V_284 ;
} else {
F_5 ( L_124 ) ;
return - V_166 ;
}
return 0 ;
}
static int F_100 ( struct V_41 * V_42 )
{
struct V_43 * V_296 = V_42 -> V_118 -> V_297 ;
int V_298 = V_42 -> V_118 -> V_289 ;
int V_299 = 0 ;
int V_10 , V_9 ;
V_286 = F_101 ( V_298 , sizeof( int ) , V_84 ) ;
if ( ! V_286 )
return - V_300 ;
V_294 = F_101 ( V_298 , sizeof( int ) , V_84 ) ;
if ( ! V_294 ) {
F_16 ( V_286 ) ;
return - V_300 ;
}
V_286 [ 0 ] = V_287 ;
V_294 [ 0 ] = 0 ;
V_292 = 1 ;
V_301:
if ( V_292 == 0 )
goto V_302;
V_9 = V_294 [ V_292 - 1 ] ;
if ( F_10 ( V_296 [ V_9 ] . V_46 ) == V_68 ) {
T_1 V_69 = F_12 ( V_296 [ V_9 ] . V_46 ) ;
if ( V_69 == V_72 ) {
goto V_303;
} else if ( V_69 == V_70 ) {
V_299 = F_99 ( V_9 , V_9 + 1 , V_285 , V_42 ) ;
if ( V_299 == 1 )
goto V_301;
else if ( V_299 < 0 )
goto V_304;
if ( V_9 + 1 < V_298 )
V_42 -> V_290 [ V_9 + 1 ] = V_291 ;
} else if ( V_69 == V_71 ) {
if ( F_11 ( V_296 [ V_9 ] . V_46 ) != V_252 ) {
V_299 = - V_100 ;
goto V_304;
}
V_299 = F_99 ( V_9 , V_9 + V_296 [ V_9 ] . V_19 + 1 ,
V_285 , V_42 ) ;
if ( V_299 == 1 )
goto V_301;
else if ( V_299 < 0 )
goto V_304;
if ( V_9 + 1 < V_298 )
V_42 -> V_290 [ V_9 + 1 ] = V_291 ;
} else {
V_42 -> V_290 [ V_9 ] = V_291 ;
V_299 = F_99 ( V_9 , V_9 + 1 , V_285 , V_42 ) ;
if ( V_299 == 1 )
goto V_301;
else if ( V_299 < 0 )
goto V_304;
V_299 = F_99 ( V_9 , V_9 + V_296 [ V_9 ] . V_19 + 1 , V_288 , V_42 ) ;
if ( V_299 == 1 )
goto V_301;
else if ( V_299 < 0 )
goto V_304;
}
} else {
V_299 = F_99 ( V_9 , V_9 + 1 , V_285 , V_42 ) ;
if ( V_299 == 1 )
goto V_301;
else if ( V_299 < 0 )
goto V_304;
}
V_303:
V_286 [ V_9 ] = V_295 ;
if ( V_292 -- <= 0 ) {
F_5 ( L_125 ) ;
V_299 = - V_166 ;
goto V_304;
}
goto V_301;
V_302:
for ( V_10 = 0 ; V_10 < V_298 ; V_10 ++ ) {
if ( V_286 [ V_10 ] != V_295 ) {
F_5 ( L_126 , V_10 ) ;
V_299 = - V_100 ;
goto V_304;
}
}
V_299 = 0 ;
V_304:
F_16 ( V_286 ) ;
F_16 ( V_294 ) ;
return V_299 ;
}
static bool F_102 ( struct V_6 * V_305 ,
struct V_6 * V_306 )
{
return V_305 -> V_29 <= V_306 -> V_29 &&
V_305 -> V_32 >= V_306 -> V_32 &&
V_305 -> V_28 <= V_306 -> V_28 &&
V_305 -> V_31 >= V_306 -> V_31 ;
}
static bool F_103 ( V_65 V_307 , V_65 V_308 , struct V_309 * V_310 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_311 ; V_10 ++ ) {
if ( ! V_310 [ V_10 ] . V_305 ) {
V_310 [ V_10 ] . V_305 = V_307 ;
V_310 [ V_10 ] . V_306 = V_308 ;
return true ;
}
if ( V_310 [ V_10 ] . V_305 == V_307 )
return V_310 [ V_10 ] . V_306 == V_308 ;
}
F_76 ( 1 ) ;
return false ;
}
static bool F_104 ( struct V_6 * V_312 , struct V_6 * V_313 ,
struct V_309 * V_310 )
{
if ( ! ( V_312 -> V_91 & V_98 ) )
return true ;
if ( memcmp ( V_312 , V_313 , F_105 ( struct V_6 , V_91 ) ) == 0 )
return true ;
if ( V_312 -> type == V_13 )
return true ;
if ( V_313 -> type == V_13 )
return false ;
switch ( V_312 -> type ) {
case V_15 :
if ( V_313 -> type == V_15 ) {
return F_102 ( V_312 , V_313 ) &&
F_106 ( V_312 -> V_17 , V_313 -> V_17 ) ;
} else {
return V_312 -> V_29 == 0 &&
V_312 -> V_32 == V_34 &&
V_312 -> V_28 == V_30 &&
V_312 -> V_31 == V_33 &&
F_7 ( V_312 -> V_17 ) ;
}
case V_23 :
return memcmp ( V_312 , V_313 , F_105 ( struct V_6 , V_1 ) ) == 0 &&
F_102 ( V_312 , V_313 ) &&
F_106 ( V_312 -> V_17 , V_313 -> V_17 ) ;
case V_24 :
if ( V_313 -> type != V_24 )
return false ;
if ( memcmp ( V_312 , V_313 , F_105 ( struct V_6 , V_1 ) ) )
return false ;
return F_103 ( V_312 -> V_1 , V_313 -> V_1 , V_310 ) ;
case V_20 :
if ( V_313 -> type != V_20 )
return false ;
if ( V_312 -> V_21 > V_313 -> V_21 )
return false ;
if ( V_312 -> V_19 != V_313 -> V_19 )
return false ;
if ( V_312 -> V_1 && ! F_103 ( V_312 -> V_1 , V_313 -> V_1 , V_310 ) )
return false ;
return F_102 ( V_312 , V_313 ) &&
F_106 ( V_312 -> V_17 , V_313 -> V_17 ) ;
case V_95 :
case V_22 :
case V_16 :
case V_104 :
default:
return false ;
}
F_76 ( 1 ) ;
return false ;
}
static bool F_107 ( struct V_41 * V_42 ,
struct V_4 * V_305 ,
struct V_4 * V_306 )
{
struct V_309 * V_310 ;
bool V_299 = false ;
int V_10 ;
V_310 = F_101 ( V_311 , sizeof( struct V_309 ) , V_84 ) ;
if ( ! V_310 )
return false ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ! F_104 ( & V_305 -> V_12 [ V_10 ] , & V_306 -> V_12 [ V_10 ] , V_310 ) )
goto V_314;
}
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
if ( V_305 -> V_38 [ V_10 ] == V_315 )
continue;
if ( V_305 -> V_38 [ V_10 ] != V_306 -> V_38 [ V_10 ] )
goto V_314;
if ( V_10 % V_37 )
continue;
if ( V_305 -> V_38 [ V_10 ] != V_39 )
continue;
if ( ! F_104 ( & V_305 -> V_40 [ V_10 / V_37 ] ,
& V_306 -> V_40 [ V_10 / V_37 ] ,
V_310 ) )
goto V_314;
else
continue;
}
V_299 = true ;
V_314:
F_16 ( V_310 ) ;
return V_299 ;
}
static bool F_108 ( const struct V_4 * V_5 ,
struct V_4 * V_96 )
{
bool V_316 = V_96 == V_5 -> V_96 ;
bool V_317 = false ;
int V_10 ;
if ( ! V_96 )
return V_317 ;
F_2 ( V_93 + 1 != V_11 ) ;
for ( V_10 = 0 ; V_10 < V_93 ; V_10 ++ ) {
if ( V_96 -> V_12 [ V_10 ] . V_91 & V_98 )
continue;
if ( V_316 && ( V_5 -> V_12 [ V_10 ] . V_91 & V_97 ) )
continue;
if ( V_5 -> V_12 [ V_10 ] . V_91 & V_98 ) {
V_96 -> V_12 [ V_10 ] . V_91 |= V_98 ;
V_317 = true ;
}
}
for ( V_10 = 0 ; V_10 < V_36 / V_37 ; V_10 ++ ) {
if ( V_96 -> V_38 [ V_10 * V_37 ] != V_39 )
continue;
if ( V_5 -> V_38 [ V_10 * V_37 ] != V_39 )
continue;
if ( V_96 -> V_40 [ V_10 ] . V_91 & V_98 )
continue;
if ( V_316 && ( V_5 -> V_40 [ V_10 ] . V_91 & V_97 ) )
continue;
if ( V_5 -> V_40 [ V_10 ] . V_91 & V_98 ) {
V_96 -> V_40 [ V_10 ] . V_91 |= V_98 ;
V_317 = true ;
}
}
return V_317 ;
}
static void F_109 ( const struct V_4 * V_5 ,
struct V_4 * V_96 )
{
while ( F_108 ( V_5 , V_96 ) ) {
V_5 = V_96 ;
V_96 = V_5 -> V_96 ;
}
}
static int F_110 ( struct V_41 * V_42 , int V_78 )
{
struct V_318 * V_319 ;
struct V_318 * V_320 ;
int V_10 ;
V_320 = V_42 -> V_290 [ V_78 ] ;
if ( ! V_320 )
return 0 ;
while ( V_320 != V_291 ) {
if ( F_107 ( V_42 , & V_320 -> V_5 , & V_42 -> V_80 ) ) {
F_109 ( & V_320 -> V_5 , & V_42 -> V_80 ) ;
return 1 ;
}
V_320 = V_320 -> V_82 ;
}
V_319 = F_18 ( sizeof( struct V_318 ) , V_321 ) ;
if ( ! V_319 )
return - V_300 ;
memcpy ( & V_319 -> V_5 , & V_42 -> V_80 , sizeof( V_42 -> V_80 ) ) ;
V_319 -> V_82 = V_42 -> V_290 [ V_78 ] ;
V_42 -> V_290 [ V_78 ] = V_319 ;
V_42 -> V_80 . V_96 = & V_319 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_93 ; V_10 ++ )
V_42 -> V_80 . V_12 [ V_10 ] . V_91 = V_92 ;
for ( V_10 = 0 ; V_10 < V_36 / V_37 ; V_10 ++ )
if ( V_42 -> V_80 . V_38 [ V_10 * V_37 ] == V_39 )
V_42 -> V_80 . V_40 [ V_10 ] . V_91 = V_92 ;
return 0 ;
}
static int F_111 ( struct V_41 * V_42 ,
int V_78 , int V_75 )
{
if ( ! V_42 -> V_132 || ! V_42 -> V_132 -> V_322 )
return 0 ;
return V_42 -> V_132 -> V_322 ( V_42 , V_78 , V_75 ) ;
}
static int F_112 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = & V_42 -> V_80 ;
struct V_43 * V_296 = V_42 -> V_118 -> V_297 ;
struct V_6 * V_12 = V_5 -> V_12 ;
int V_298 = V_42 -> V_118 -> V_289 ;
int V_78 , V_75 = 0 ;
int V_323 = 0 ;
bool V_324 = false ;
F_38 ( V_12 ) ;
V_5 -> V_96 = NULL ;
V_78 = 0 ;
for (; ; ) {
struct V_43 * V_44 ;
T_1 V_45 ;
int V_85 ;
if ( V_78 >= V_298 ) {
F_5 ( L_127 ,
V_78 , V_298 ) ;
return - V_166 ;
}
V_44 = & V_296 [ V_78 ] ;
V_45 = F_10 ( V_44 -> V_46 ) ;
if ( ++ V_323 > V_325 ) {
F_5 ( L_128 ,
V_323 ) ;
return - V_293 ;
}
V_85 = F_110 ( V_42 , V_78 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( V_85 == 1 ) {
if ( V_113 ) {
if ( V_324 )
F_5 ( L_129 ,
V_75 , V_78 ) ;
else
F_5 ( L_130 , V_78 ) ;
}
goto V_326;
}
if ( F_113 () )
F_114 () ;
if ( V_113 > 1 || ( V_113 && V_324 ) ) {
if ( V_113 > 1 )
F_5 ( L_131 , V_78 ) ;
else
F_5 ( L_132 ,
V_75 , V_78 ) ;
F_4 ( & V_42 -> V_80 ) ;
V_324 = false ;
}
if ( V_113 ) {
F_5 ( L_133 , V_78 ) ;
F_9 ( V_42 , V_44 ) ;
}
V_85 = F_111 ( V_42 , V_78 , V_75 ) ;
if ( V_85 )
return V_85 ;
if ( V_45 == V_47 || V_45 == V_48 ) {
V_85 = F_85 ( V_42 , V_44 ) ;
if ( V_85 )
return V_85 ;
} else if ( V_45 == V_59 ) {
enum V_8 * V_327 , V_328 ;
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_209 ) ;
if ( V_85 )
return V_85 ;
V_328 = V_12 [ V_44 -> V_52 ] . type ;
V_85 = F_58 ( V_42 , V_78 , V_44 -> V_52 , V_44 -> V_19 ,
F_14 ( V_44 -> V_46 ) , V_146 ,
V_44 -> V_50 ) ;
if ( V_85 )
return V_85 ;
V_327 = & V_42 -> V_136 [ V_78 ] . V_329 ;
if ( * V_327 == V_13 ) {
* V_327 = V_328 ;
} else if ( V_328 != * V_327 &&
( V_328 == V_95 ||
* V_327 == V_95 ) ) {
F_5 ( L_134 ) ;
return - V_100 ;
}
} else if ( V_45 == V_54 ) {
enum V_8 * V_330 , V_331 ;
if ( F_13 ( V_44 -> V_46 ) == V_57 ) {
V_85 = F_61 ( V_42 , V_78 , V_44 ) ;
if ( V_85 )
return V_85 ;
V_78 ++ ;
continue;
}
V_85 = F_40 ( V_42 , V_44 -> V_52 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_331 = V_12 [ V_44 -> V_50 ] . type ;
V_85 = F_58 ( V_42 , V_78 , V_44 -> V_50 , V_44 -> V_19 ,
F_14 ( V_44 -> V_46 ) , V_121 ,
V_44 -> V_52 ) ;
if ( V_85 )
return V_85 ;
V_330 = & V_42 -> V_136 [ V_78 ] . V_329 ;
if ( * V_330 == V_13 ) {
* V_330 = V_331 ;
} else if ( V_331 != * V_330 &&
( V_331 == V_95 ||
* V_330 == V_95 ) ) {
F_5 ( L_134 ) ;
return - V_100 ;
}
} else if ( V_45 == V_58 ) {
if ( F_13 ( V_44 -> V_46 ) != V_55 ||
V_44 -> V_52 != V_212 ) {
F_5 ( L_135 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_44 -> V_50 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_58 ( V_42 , V_78 , V_44 -> V_50 , V_44 -> V_19 ,
F_14 ( V_44 -> V_46 ) , V_121 ,
- 1 ) ;
if ( V_85 )
return V_85 ;
} else if ( V_45 == V_68 ) {
T_1 V_69 = F_12 ( V_44 -> V_46 ) ;
if ( V_69 == V_70 ) {
if ( F_11 ( V_44 -> V_46 ) != V_252 ||
V_44 -> V_19 != 0 ||
V_44 -> V_52 != V_212 ||
V_44 -> V_50 != V_212 ) {
F_5 ( L_136 ) ;
return - V_100 ;
}
V_85 = F_70 ( V_42 , V_44 -> V_53 , V_78 ) ;
if ( V_85 )
return V_85 ;
} else if ( V_69 == V_71 ) {
if ( F_11 ( V_44 -> V_46 ) != V_252 ||
V_44 -> V_53 != 0 ||
V_44 -> V_52 != V_212 ||
V_44 -> V_50 != V_212 ) {
F_5 ( L_137 ) ;
return - V_100 ;
}
V_78 += V_44 -> V_19 + 1 ;
continue;
} else if ( V_69 == V_72 ) {
if ( F_11 ( V_44 -> V_46 ) != V_252 ||
V_44 -> V_53 != 0 ||
V_44 -> V_52 != V_212 ||
V_44 -> V_50 != V_212 ) {
F_5 ( L_138 ) ;
return - V_100 ;
}
V_85 = F_40 ( V_42 , V_212 , V_101 ) ;
if ( V_85 )
return V_85 ;
if ( F_52 ( V_42 , V_212 ) ) {
F_5 ( L_139 ) ;
return - V_102 ;
}
V_326:
V_78 = F_15 ( V_42 , & V_75 ) ;
if ( V_78 < 0 ) {
break;
} else {
V_324 = true ;
continue;
}
} else {
V_85 = F_93 ( V_42 , V_44 , & V_78 ) ;
if ( V_85 )
return V_85 ;
}
} else if ( V_45 == V_60 ) {
T_1 V_281 = F_13 ( V_44 -> V_46 ) ;
if ( V_281 == V_61 || V_281 == V_62 ) {
V_85 = F_98 ( V_42 , V_44 ) ;
if ( V_85 )
return V_85 ;
} else if ( V_281 == V_63 ) {
V_85 = F_95 ( V_42 , V_44 ) ;
if ( V_85 )
return V_85 ;
V_78 ++ ;
} else {
F_5 ( L_140 ) ;
return - V_100 ;
}
} else {
F_5 ( L_141 , V_45 ) ;
return - V_100 ;
}
V_78 ++ ;
}
F_5 ( L_142 ,
V_323 , V_42 -> V_118 -> V_133 -> V_147 ) ;
return 0 ;
}
static int F_115 ( struct V_111 * V_112 )
{
return ( V_112 -> V_169 != V_332 &&
V_112 -> V_169 != V_333 &&
V_112 -> V_169 != V_183 ) ||
! ( V_112 -> V_334 & V_335 ) ;
}
static int F_116 ( struct V_111 * V_112 ,
struct V_336 * V_118 )
{
if ( V_118 -> type == V_337 ) {
if ( ! F_115 ( V_112 ) ) {
F_5 ( L_143 ) ;
return - V_100 ;
}
if ( V_112 -> V_275 &&
! F_115 ( V_112 -> V_275 ) ) {
F_5 ( L_144 ) ;
return - V_100 ;
}
}
return 0 ;
}
static int F_117 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_118 -> V_297 ;
int V_298 = V_42 -> V_118 -> V_289 ;
int V_10 , V_338 , V_85 ;
V_85 = F_118 ( V_42 -> V_118 ) ;
if ( V_85 )
return V_85 ;
for ( V_10 = 0 ; V_10 < V_298 ; V_10 ++ , V_44 ++ ) {
if ( F_10 ( V_44 -> V_46 ) == V_59 &&
( F_13 ( V_44 -> V_46 ) != V_55 || V_44 -> V_53 != 0 ) ) {
F_5 ( L_145 ) ;
return - V_100 ;
}
if ( F_10 ( V_44 -> V_46 ) == V_54 &&
( ( F_13 ( V_44 -> V_46 ) != V_55 &&
F_13 ( V_44 -> V_46 ) != V_57 ) || V_44 -> V_53 != 0 ) ) {
F_5 ( L_146 ) ;
return - V_100 ;
}
if ( V_44 [ 0 ] . V_46 == ( V_60 | V_63 | V_64 ) ) {
struct V_111 * V_112 ;
struct V_339 V_340 ;
if ( V_10 == V_298 - 1 || V_44 [ 1 ] . V_46 != 0 ||
V_44 [ 1 ] . V_50 != 0 || V_44 [ 1 ] . V_52 != 0 ||
V_44 [ 1 ] . V_19 != 0 ) {
F_5 ( L_147 ) ;
return - V_100 ;
}
if ( V_44 -> V_52 == 0 )
goto V_341;
if ( V_44 -> V_52 != V_66 ) {
F_5 ( L_148 ) ;
return - V_100 ;
}
V_340 = F_119 ( V_44 -> V_53 ) ;
V_112 = F_120 ( V_340 ) ;
if ( F_121 ( V_112 ) ) {
F_5 ( L_149 ,
V_44 -> V_53 ) ;
return F_122 ( V_112 ) ;
}
V_85 = F_116 ( V_112 , V_42 -> V_118 ) ;
if ( V_85 ) {
F_123 ( V_340 ) ;
return V_85 ;
}
V_44 [ 0 ] . V_53 = ( V_65 ) ( unsigned long ) V_112 ;
V_44 [ 1 ] . V_53 = ( ( T_2 ) ( unsigned long ) V_112 ) >> 32 ;
for ( V_338 = 0 ; V_338 < V_42 -> V_342 ; V_338 ++ )
if ( V_42 -> V_343 [ V_338 ] == V_112 ) {
F_123 ( V_340 ) ;
goto V_341;
}
if ( V_42 -> V_342 >= V_344 ) {
F_123 ( V_340 ) ;
return - V_293 ;
}
V_112 = F_124 ( V_112 , false ) ;
if ( F_121 ( V_112 ) ) {
F_123 ( V_340 ) ;
return F_122 ( V_112 ) ;
}
V_42 -> V_343 [ V_42 -> V_342 ++ ] = V_112 ;
F_123 ( V_340 ) ;
V_341:
V_44 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_125 ( struct V_41 * V_42 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_42 -> V_342 ; V_10 ++ )
F_126 ( V_42 -> V_343 [ V_10 ] ) ;
}
static void F_127 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_118 -> V_297 ;
int V_298 = V_42 -> V_118 -> V_289 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_298 ; V_10 ++ , V_44 ++ )
if ( V_44 -> V_46 == ( V_60 | V_63 | V_64 ) )
V_44 -> V_52 = 0 ;
}
static int F_128 ( struct V_41 * V_42 , V_65 V_345 ,
V_65 V_19 , V_65 V_346 )
{
struct V_215 * V_347 , * V_348 = V_42 -> V_136 ;
if ( V_346 == 1 )
return 0 ;
V_347 = F_129 ( sizeof( struct V_215 ) * V_345 ) ;
if ( ! V_347 )
return - V_300 ;
memcpy ( V_347 , V_348 , sizeof( struct V_215 ) * V_19 ) ;
memcpy ( V_347 + V_19 + V_346 - 1 , V_348 + V_19 ,
sizeof( struct V_215 ) * ( V_345 - V_19 - V_346 + 1 ) ) ;
V_42 -> V_136 = V_347 ;
F_130 ( V_348 ) ;
return 0 ;
}
static struct V_336 * F_131 ( struct V_41 * V_42 , V_65 V_19 ,
const struct V_43 * V_349 , V_65 V_289 )
{
struct V_336 * V_350 ;
V_350 = F_132 ( V_42 -> V_118 , V_19 , V_349 , V_289 ) ;
if ( ! V_350 )
return NULL ;
if ( F_128 ( V_42 , V_350 -> V_289 , V_19 , V_289 ) )
return NULL ;
return V_350 ;
}
static int F_133 ( struct V_41 * V_42 )
{
const struct V_351 * V_134 = V_42 -> V_118 -> V_133 -> V_134 ;
int V_10 , V_346 , V_105 , V_137 , V_352 = 0 ;
const int V_298 = V_42 -> V_118 -> V_289 ;
struct V_43 V_353 [ 16 ] , * V_44 ;
struct V_336 * V_350 ;
enum V_117 type ;
bool V_354 ;
V_65 V_355 ;
if ( V_134 -> V_356 ) {
V_346 = V_134 -> V_356 ( V_353 , V_42 -> V_128 ,
V_42 -> V_118 ) ;
if ( V_346 >= F_3 ( V_353 ) ) {
F_5 ( L_150 ) ;
return - V_100 ;
} else if ( V_346 ) {
V_350 = F_131 ( V_42 , 0 , V_353 , V_346 ) ;
if ( ! V_350 )
return - V_300 ;
V_42 -> V_118 = V_350 ;
V_352 += V_346 - 1 ;
}
}
if ( ! V_134 -> V_357 )
return 0 ;
V_44 = V_42 -> V_118 -> V_297 + V_352 ;
for ( V_10 = 0 ; V_10 < V_298 ; V_10 ++ , V_44 ++ ) {
if ( V_44 -> V_46 == ( V_59 | V_55 | V_206 ) ||
V_44 -> V_46 == ( V_59 | V_55 | V_358 ) ||
V_44 -> V_46 == ( V_59 | V_55 | V_148 ) ||
V_44 -> V_46 == ( V_59 | V_55 | V_64 ) )
type = V_146 ;
else if ( V_44 -> V_46 == ( V_54 | V_55 | V_206 ) ||
V_44 -> V_46 == ( V_54 | V_55 | V_358 ) ||
V_44 -> V_46 == ( V_54 | V_55 | V_148 ) ||
V_44 -> V_46 == ( V_54 | V_55 | V_64 ) )
type = V_121 ;
else
continue;
if ( V_42 -> V_136 [ V_10 + V_352 ] . V_329 != V_95 )
continue;
V_137 = V_42 -> V_136 [ V_10 + V_352 ] . V_137 ;
V_105 = F_134 ( V_44 ) ;
V_354 = V_105 < V_137 ;
if ( V_354 ) {
V_65 V_19 = V_44 -> V_19 ;
T_1 V_359 ;
if ( type == V_121 ) {
F_5 ( L_151 ) ;
return - V_100 ;
}
V_359 = V_358 ;
if ( V_137 == 4 )
V_359 = V_148 ;
else if ( V_137 == 8 )
V_359 = V_64 ;
V_44 -> V_19 = V_19 & ~ ( V_137 - 1 ) ;
V_44 -> V_46 = V_59 | V_55 | V_359 ;
}
V_355 = 0 ;
V_346 = V_134 -> V_357 ( type , V_44 , V_353 , V_42 -> V_118 ,
& V_355 ) ;
if ( V_346 == 0 || V_346 >= F_3 ( V_353 ) ||
( V_137 && ! V_355 ) ) {
F_5 ( L_150 ) ;
return - V_100 ;
}
if ( V_354 && V_105 < V_355 ) {
if ( V_137 <= 4 )
V_353 [ V_346 ++ ] = F_135 ( V_237 , V_44 -> V_50 ,
( 1 << V_105 * 8 ) - 1 ) ;
else
V_353 [ V_346 ++ ] = F_136 ( V_237 , V_44 -> V_50 ,
( 1 << V_105 * 8 ) - 1 ) ;
}
V_350 = F_131 ( V_42 , V_10 + V_352 , V_353 , V_346 ) ;
if ( ! V_350 )
return - V_300 ;
V_352 += V_346 - 1 ;
V_42 -> V_118 = V_350 ;
V_44 = V_350 -> V_297 + V_10 + V_352 ;
}
return 0 ;
}
static int F_137 ( struct V_41 * V_42 )
{
struct V_336 * V_118 = V_42 -> V_118 ;
struct V_43 * V_44 = V_118 -> V_297 ;
const struct V_189 * V_190 ;
const int V_298 = V_118 -> V_289 ;
struct V_43 V_353 [ 16 ] ;
struct V_336 * V_350 ;
struct V_111 * V_25 ;
int V_10 , V_346 , V_352 = 0 ;
for ( V_10 = 0 ; V_10 < V_298 ; V_10 ++ , V_44 ++ ) {
if ( V_44 -> V_46 != ( V_68 | V_70 ) )
continue;
if ( V_44 -> V_53 == V_360 )
V_118 -> V_361 = 1 ;
if ( V_44 -> V_53 == V_362 )
F_138 () ;
if ( V_44 -> V_53 == V_171 ) {
V_118 -> V_363 = 1 ;
V_42 -> V_118 -> V_133 -> V_147 = V_36 ;
V_44 -> V_53 = 0 ;
V_44 -> V_46 = V_68 | V_364 ;
continue;
}
if ( F_139 () && V_365 == 64 &&
V_44 -> V_53 == V_184 ) {
V_25 = V_42 -> V_136 [ V_10 + V_352 ] . V_25 ;
if ( V_25 == V_218 ||
! V_25 -> V_134 -> V_366 )
goto V_367;
V_346 = V_25 -> V_134 -> V_366 ( V_25 , V_353 ) ;
if ( V_346 == 0 || V_346 >= F_3 ( V_353 ) ) {
F_5 ( L_150 ) ;
return - V_100 ;
}
V_350 = F_131 ( V_42 , V_10 + V_352 , V_353 ,
V_346 ) ;
if ( ! V_350 )
return - V_300 ;
V_352 += V_346 - 1 ;
V_42 -> V_118 = V_118 = V_350 ;
V_44 = V_350 -> V_297 + V_10 + V_352 ;
continue;
}
if ( V_44 -> V_53 == V_181 ) {
T_2 V_368 = ( unsigned long ) V_118 -> V_133 ;
struct V_43 V_369 [] = {
F_140 ( V_204 , V_368 ) ,
* V_44 ,
} ;
V_346 = F_3 ( V_369 ) ;
V_350 = F_131 ( V_42 , V_10 + V_352 , V_369 , V_346 ) ;
if ( ! V_350 )
return - V_300 ;
V_352 += V_346 - 1 ;
V_42 -> V_118 = V_118 = V_350 ;
V_44 = V_350 -> V_297 + V_10 + V_352 ;
}
V_367:
V_190 = V_118 -> V_133 -> V_134 -> V_198 ( V_44 -> V_53 ) ;
if ( ! V_190 -> V_201 ) {
F_5 ( L_89 ,
F_1 ( V_44 -> V_53 ) , V_44 -> V_53 ) ;
return - V_166 ;
}
V_44 -> V_53 = V_190 -> V_201 - V_370 ;
}
return 0 ;
}
static void F_141 ( struct V_41 * V_42 )
{
struct V_318 * V_320 , * V_371 ;
int V_10 ;
if ( ! V_42 -> V_290 )
return;
for ( V_10 = 0 ; V_10 < V_42 -> V_118 -> V_289 ; V_10 ++ ) {
V_320 = V_42 -> V_290 [ V_10 ] ;
if ( V_320 )
while ( V_320 != V_291 ) {
V_371 = V_320 -> V_82 ;
F_16 ( V_320 ) ;
V_320 = V_371 ;
}
}
F_16 ( V_42 -> V_290 ) ;
}
int F_142 ( struct V_336 * * V_118 , union V_372 * V_373 )
{
char T_4 * V_374 = NULL ;
struct V_41 * V_42 ;
int V_299 = - V_100 ;
V_42 = F_143 ( sizeof( struct V_41 ) , V_84 ) ;
if ( ! V_42 )
return - V_300 ;
V_42 -> V_136 = F_129 ( sizeof( struct V_215 ) *
( * V_118 ) -> V_289 ) ;
V_299 = - V_300 ;
if ( ! V_42 -> V_136 )
goto V_375;
V_42 -> V_118 = * V_118 ;
F_144 ( & V_376 ) ;
if ( V_373 -> V_113 || V_373 -> V_377 || V_373 -> V_378 ) {
V_113 = V_373 -> V_113 ;
V_374 = ( char T_4 * ) ( unsigned long ) V_373 -> V_377 ;
V_378 = V_373 -> V_378 ;
V_379 = 0 ;
V_299 = - V_100 ;
if ( V_378 < 128 || V_378 > V_380 >> 8 ||
V_113 == 0 || V_374 == NULL )
goto V_381;
V_299 = - V_300 ;
V_377 = F_145 ( V_378 ) ;
if ( ! V_377 )
goto V_381;
} else {
V_113 = 0 ;
}
V_42 -> V_144 = ! ! ( V_373 -> V_382 & V_383 ) ;
if ( ! F_146 ( V_384 ) )
V_42 -> V_144 = true ;
V_299 = F_117 ( V_42 ) ;
if ( V_299 < 0 )
goto V_385;
V_42 -> V_290 = F_101 ( V_42 -> V_118 -> V_289 ,
sizeof( struct V_318 * ) ,
V_321 ) ;
V_299 = - V_300 ;
if ( ! V_42 -> V_290 )
goto V_385;
V_299 = F_100 ( V_42 ) ;
if ( V_299 < 0 )
goto V_385;
V_42 -> V_67 = F_147 ( V_386 ) ;
V_299 = F_112 ( V_42 ) ;
V_385:
while ( F_15 ( V_42 , NULL ) >= 0 ) ;
F_141 ( V_42 ) ;
if ( V_299 == 0 )
V_299 = F_133 ( V_42 ) ;
if ( V_299 == 0 )
V_299 = F_137 ( V_42 ) ;
if ( V_113 && V_379 >= V_378 - 1 ) {
F_96 ( V_379 >= V_378 ) ;
V_299 = - V_387 ;
}
if ( V_113 && F_148 ( V_374 , V_377 , V_379 + 1 ) != 0 ) {
V_299 = - V_166 ;
goto V_388;
}
if ( V_299 == 0 && V_42 -> V_342 ) {
V_42 -> V_118 -> V_133 -> V_343 = F_149 ( V_42 -> V_342 ,
sizeof( V_42 -> V_343 [ 0 ] ) ,
V_84 ) ;
if ( ! V_42 -> V_118 -> V_133 -> V_343 ) {
V_299 = - V_300 ;
goto V_388;
}
memcpy ( V_42 -> V_118 -> V_133 -> V_343 , V_42 -> V_343 ,
sizeof( V_42 -> V_343 [ 0 ] ) * V_42 -> V_342 ) ;
V_42 -> V_118 -> V_133 -> V_342 = V_42 -> V_342 ;
F_127 ( V_42 ) ;
}
V_388:
if ( V_113 )
F_130 ( V_377 ) ;
if ( ! V_42 -> V_118 -> V_133 -> V_343 )
F_125 ( V_42 ) ;
* V_118 = V_42 -> V_118 ;
V_381:
F_150 ( & V_376 ) ;
F_130 ( V_42 -> V_136 ) ;
V_375:
F_16 ( V_42 ) ;
return V_299 ;
}
int F_151 ( struct V_336 * V_118 , const struct V_389 * V_134 ,
void * V_390 )
{
struct V_41 * V_42 ;
int V_299 ;
V_42 = F_143 ( sizeof( struct V_41 ) , V_84 ) ;
if ( ! V_42 )
return - V_300 ;
V_42 -> V_136 = F_129 ( sizeof( struct V_215 ) *
V_118 -> V_289 ) ;
V_299 = - V_300 ;
if ( ! V_42 -> V_136 )
goto V_375;
V_42 -> V_118 = V_118 ;
V_42 -> V_132 = V_134 ;
V_42 -> V_391 = V_390 ;
F_144 ( & V_376 ) ;
V_113 = 0 ;
V_42 -> V_144 = false ;
if ( ! F_146 ( V_384 ) )
V_42 -> V_144 = true ;
V_42 -> V_290 = F_101 ( V_42 -> V_118 -> V_289 ,
sizeof( struct V_318 * ) ,
V_84 ) ;
V_299 = - V_300 ;
if ( ! V_42 -> V_290 )
goto V_385;
V_299 = F_100 ( V_42 ) ;
if ( V_299 < 0 )
goto V_385;
V_42 -> V_67 = F_147 ( V_386 ) ;
V_299 = F_112 ( V_42 ) ;
V_385:
while ( F_15 ( V_42 , NULL ) >= 0 ) ;
F_141 ( V_42 ) ;
F_150 ( & V_376 ) ;
F_130 ( V_42 -> V_136 ) ;
V_375:
F_16 ( V_42 ) ;
return V_299 ;
}
